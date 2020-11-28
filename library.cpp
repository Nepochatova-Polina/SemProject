#include "library.h"
#include <iostream>


#include <iostream>
#include <cmath>
#include "vector"

using namespace std;


int* stringToGray(int number,  int inputString[]) {
    int outputString[number];
    int count = 0;
    while (count < number) {
        if (((inputString[count] == 0 && (inputString[count] >> 1) == 0)) ||
            ((inputString[count] == 1 && (inputString[count] >> 1) == 1))) {
            outputString[count] = 0;
        } else {
            if ((((inputString[count] == 0 && (inputString[count] >> 1) == 1))) ||
                ((inputString[count] == 1 && (inputString[count] >> 1) == 0))) {
                outputString[count] = 1;
            }
        }
        count++;
    }
    return outputString;
}

int NOD(int a, int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return NOD(a % b, b);
    return NOD(a, b % a);
}

int NOK(int a, int b) {
    return (a * b) / NOD(a, b);
}

vector<int> factorize(int x) {
    vector<int> factors;

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }
    if (x != 1) {
        factors.push_back(x);
    }

    return factors;
}

int jacobi(int a, int n) {
    int ans;

    if (a == 0)
        ans = (n == 1) ? 1 : 0;
    else if (a == 2) {
        switch (n % 8) {
            case 1:
            case 7:
                ans = 1;
                break;
            case 3:
            case 5:
                ans = -1;
                break;
        }
    } else if (a >= n)
        ans = jacobi(a % n, n);
    else if (a % 2 == 0)
        ans = jacobi(2, n) * jacobi(a / 2, n);
    else
        ans = (a % 4 == 3 && n % 4 == 3) ? -jacobi(n, a) : jacobi(n, a);
    return ans;
}

string ArmstrongNumber(int number) {
    int sum, new_num, digits;
    int current[100];
    string res;
    int precalcullated[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (number < 10) {
        for (int i = 0; i <= number; i++) {
            res += to_string(precalcullated[i]);
        }
    } else {
        if (number < 153) {
            for (int i : precalcullated) {
                res += to_string(i) + " ";
            }
        } else {
            for (int i : precalcullated) {
                res += to_string(i) + " ";
            }
            for (int i = 153; i < number; i++) {
                digits = 0;
                new_num = i;
                do {
                    current[++digits] = new_num % 10;
                    new_num /= 10;
                } while (new_num > 0);
                sum = 0;
                for (int j = 1; j <= digits; j++) {
                    sum += pow(current[j], digits);
                }
                if (sum == i) {
                    return res = to_string(sum);
                }
            }
        }
    }
    return res;
}

int Lagranz(double **matrix, int number) {
    double t, sum = 0, calc = 1;
    for (int j = 0; j < number; j++) {
        for (int i = 0; i < 2; i++) {
            if (i != j) {
                calc = calc * (t - matrix[0][i]) / (matrix[0][j] - matrix[0][i]);
            }
        }
        sum = sum + matrix[1][j] * calc;
    }
    return sum;
}

