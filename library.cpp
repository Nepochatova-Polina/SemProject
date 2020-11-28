#include "library.h"
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

double Lagranz(double **matrix, int number) {
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


string ThreeOfPif() {
    int j, counter = 0;
    string res;
    double candidate, sqrnbr;
    for (int i = 400; i <= 500; i++) {
        for (j = i; j <= 500; j++) {
            candidate = i * i + j * j;
        }
        sqrnbr = sqrt(candidate);
        if (candidate / sqrnbr == sqrnbr) {
            res+=to_string(i) + " and " + to_string(j) + " and " + to_string(sqrnbr) + " ";
            counter++;
        }
    }

    return res;
}

vector<int>  find_dividers(int x) {
    vector<int> dividers;

    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            dividers.push_back(i);
            if (i * i != x) {
                dividers.push_back(x / i);
            }
        }
    }

    return dividers;
}

bool is_prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}


int AriphmeticSum(int n, int res) {
    int a1 = 2, d = 2;
    res = ((2 * a1 + d * (n - 1)) / 2) * n;
    return res + 1;
}


int GeometrySum(int n, int k) {
    int r = 1;
    for (int i = n; i > 0; i--) {
        if (r > k) r -= k;
        r *= 2;
    }
    return r;
}

string naturNum(int n) {
    string res;
    int lim1 = (n / 3) + 1;
    int lim2;
    for (int i = 0; i < lim1; i++) {
        lim2 = ((n - i) / 2) + 1;
        for (int j = i; j < lim2; j++) {
            res += to_string(i) +  " " + to_string(j) + " " + to_string(n - i - j) + " ";
        }
    }
    return res;
}


string CarperRes(int x) {
    int K = 0, xm = 0, xM = 0, n = 0;
    int N[11];
    string res;
    while (x != 0) {
        N[n] = abs(x % 10);
        n++;
        x /= 10;
    }
    bool t = true;
    for (int i = 0; i < 11 - 1; i++) {
        for (int j = 0; j < 11 - i - 1; j++) {
            if (N[j] > N[j + 1]) {
                swap(N[j], N[j + 1]);
            }
        }
    }
    int ten = 1;
    for (int j = 0; j < n - 1; j++) {
        ten *= 10;
    }
    int ten_copy = ten;
    for (int i = 0; i < n; i++) {
        xm += N[i] * ten;
        ten /= 10;
    }
    for (int i = n - 1; i >= 0; i--) {
        xM += N[i] * ten_copy;
        ten_copy /= 10;
    }
    K = xM - xm;
    int c = 0;
    int K_tmp = K;
    while (K_tmp != 0) {
        c++;
        K_tmp /= 10;
    }
    for (int i = 0; i < n - c; i++) {
        if (K != 0){
            res += to_string(K);
        }
    }
    return res;
}

int BellNum(int n, int p) {
    int k = 0;
    for (int i = 1; i <= n; i++) {
        int fact = i;
        while (fact) {
            fact /= p;
            k += fact;
        }
    }
    return k;
}

int ChineeseTheo(int a[], int n[], int m[], int mi[], int i, int size) {
    int M = 1, Y = 0;
    for (i = 0; i < size; i++) {
        M = M * n[i];
    }
    for (i = 0; i < size; i++) {
        m[i] = M / n[i];
    }

    for (i = 0; i < size; i++) {
        mi[i] = m[i] % n[i];
    }
    for (i = 0; i < size; i++) {
    }

    return Y = Y % M;
}

double factorial(int num){
    if(num < 0)
        return 0;
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}