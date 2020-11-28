#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include <vector>
#include "string"

using namespace std;

static int *stringToGray(int number, int inputString[]);

static int NOD(int a, int b);

static int NOK(int a, int b);

static std::vector<int> factorize(int x);

int jacobi(int a, int n);

static string ArmstrongNumber(int number);

static double Lagranz(double **matrix, int number);

static string ThreeOfPif();

static std::vector<int> find_dividers(int x);

static bool is_prime(int x);

static int AriphmeticSum(int n, int res);

static int GeometrySum(int n, int k);

static string naturNum(int n);

static int BellNum(int n, int p);

static int ChineeseTheo(int *a, int *n, int *m, int *mi, int i, int size);

static string CarperRes(int x);

double factorial(int num);
#endif //LIBRARY_LIBRARY_H
