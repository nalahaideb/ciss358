//runtime: O(n lg n)
#include<iostream>
#include<algorithm>

double * arrgen(const int n);
void print(const double * arr, const int n);
double abs(const double x);
double comp(const double x, const double y);
std::pair<double, double> comp_arr(const double * arr, const int n);
int find_idx(const double * arr, const int n, const double target);

int main()
{
  srand((unsigned int) time (NULL));
  for (int i = 0; i < 10; ++i)
  {
    int n = 5;
    double * arr = arrgen(n);
    double copy[n];

    for (int k = 0; k < n; ++k)
    {
      copy[k] = arr[k];
    }

    std::sort(arr, arr + n);
    print(arr, n);

    std::pair<double, double> smallest = comp_arr(arr, n);
    int idx = find_idx(copy, n, smallest.second);

    std::cout << "smallest = " << smallest.first << ", index = " << idx << std::endl<< std::endl<< std::endl;
  }
}

int find_idx(const double * arr, const int n, const double target)
{
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] == target)
      return i;
  }
  return -1;
}

std::pair<double, double> comp_arr(const double * arr, const int n)
{
  std::pair<double, double> smallest = {comp(arr[0], arr[1]), arr[0]};
  for (int i = 1; i < n; ++i)
  {
    double t = comp(arr[i], arr[i - 1]);
    if (smallest.first > t && arr[i] != arr[i - 1])
    {
      smallest.first = t;
      smallest.second = (arr[i] > arr[i - 1] ? arr[i - 1] : arr[i]);
    }
  }
  
  return smallest;
}

double comp(const double x, const double y)
{
  return abs(x - y);
}

double abs(const double x)
{
  return (x < 0 ? x * -1.0 : x);
}

void print(const double * arr, const int n)
{
  std::cout << '[';
  for (int i = 0; i < n - 1; ++i)
  {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[n - 1] << ']' << std::endl;
}

double * arrgen(const int n)
{
  double * arr = new double[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = (double)rand() / RAND_MAX + rand() % 5;
  }
  return arr;
}
