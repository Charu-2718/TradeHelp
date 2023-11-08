//linear regression
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class regression {
	vector<float> x;

	vector<float> y;

	float coeff;

	float constTerm;

	float sum_xy;

	float sum_x;

	float sum_y;

	float sum_x_square;

	float sum_y_square;

public:
	regression()
	{
		coeff = 0;
		constTerm = 0;
		sum_y = 0;
		sum_y_square = 0;
		sum_x_square = 0;
		sum_x = 0;
		sum_xy = 0;
	}

	void calculateCoefficient()
	{
		float N = x.size();
		float numerator
			= (N * sum_xy - sum_x * sum_y);
		float denominator
			= (N * sum_x_square - sum_x * sum_x);
		coeff = numerator / denominator;
	}

	void calculateConstantTerm()
	{
		float N = x.size();
		float numerator
			= (sum_y * sum_x_square - sum_x * sum_xy);
		float denominator
			= (N * sum_x_square - sum_x * sum_x);
		constTerm = numerator / denominator;
	}
	int sizeOfData()
	{
		return x.size();
	}

	float coefficient()
	{
		if (coeff == 0)
			calculateCoefficient();
		return coeff;
	}

	float constant()
	{
		if (constTerm == 0)
			calculateConstantTerm();
		return constTerm;
	}

	void PrintBestFittingLine()
	{
		if (coeff == 0 && constTerm == 0) {
			calculateCoefficient();
			calculateConstantTerm();
		}
		cout << "The best fitting line is y = "
			<< coeff << "x + " << constTerm << endl;
	}

	void takeInput(int n)
	{
		for (int i = 0; i < n; i++) {
			char comma;
			float xi;
			float yi;
			cin >> xi >> comma >> yi;
			sum_xy += xi * yi;
			sum_x += xi;
			sum_y += yi;
			sum_x_square += xi * xi;
			sum_y_square += yi * yi;
			x.push_back(xi);
			y.push_back(yi);
		}
	}
	int showData()
	{
		for (int i = 0; i < 62; i++) {
			printf("_");
		}
		printf("\n\n");
		printf("|%15s%5s %15s%5s%20s\n",
			"X", "", "Y", "", "|");

		for (int i = 0; i < x.size(); i++) {
			printf("|%20f %20f%20s\n",
				x[i], y[i], "|");
		}

		for (int i = 0; i < 62; i++) {
			printf("_");
		}
		printf("\n");
	}
    float predict(float x)
	{
		return coeff * x + constTerm;
	}
	float errorSquare()
	{
		float ans = 0;
		for (int i = 0;
			i < x.size(); i++) {
			ans += ((predict(x[i]) - y[i])
					* (predict(x[i]) - y[i]));
		}
		return ans;
	}

	float errorIn(float num)
	{
		for (int i = 0;
			i < x.size(); i++) {
			if (num == x[i]) {
				return (y[i] - predict(x[i]));
			}
		}
		return 0;
	}
};

// Driver code
int main()
{
	freopen("Data2.txt", "r",stdin);
	regression reg;

	
	int n;
	cin >> n;

	
	reg.takeInput(n);


	reg.PrintBestFittingLine();
	cout << "Predicted value at 2009.0316 = "
		<< reg.predict(2014.01) << endl;
	cout << "The errorSquared = "
		<< reg.errorSquare() << endl;
	cout << "Error in 2009.0316 = "
		<< reg.errorIn(2014.01) << endl;
}
