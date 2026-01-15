//O(1)
#include <iostream>
#include <algorithm>
int * arrgen(const int n);
void print(const int * arr, const int n);
int comp(const int * x, const int n);

int main()
{
  srand((unsigned int) time (NULL));
  for (int i = 0; i < 10; ++i)
  {
    int n = 10;//rand() % 20;
    int * arr = arrgen(n);

    std::sort(arr, arr + n);
    print(arr, n);

    std::cout << "distance = " <<comp(arr, n) << std::endl;
  }
}

//0, 2, 4, 8, 9, 11, 100
int comp(const int * x, const int n)
{
  int total = 0;
  int distance = -1;
  int med = n / 2;
  for (int i = 0; i < n; ++i)
  {
    total += abs(x[i] - x[med]);
  }
  return total;
}
void print(const int * arr, const int n)
{
  std::cout << '[';
  for (int i = 0; i < n - 1; ++i)
  {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[n - 1] << ']' << std::endl;
}

int * arrgen(const int n)
{
  int * arr = new int[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = rand() % 20;
  }
  return arr;
}
// //runtime: O(n lg n)
// #include<iostream>
// #include<algorithm>
// int * arrgen(const int n);
// void print(const int * arr, const int n);
// int comp(const int x, const int y);
// int * distribution_sort(const int * x, const int n);

// int main()
// {
//   srand((unsigned int) time (NULL));
//   for (int i = 0; i < 10; ++i)
//   {
//     int n = rand() % 10 + 2;
//     int * arr = arrgen(n);
//     print(arr, n);
//     std::sort(arr, arr + n);
    
//   }
// }

// int comp_arr(const int * arr, const int n)
// {
  
// }

// int * distribution_sort(const int * x, const int n)
// {
//   int max = x[0];
//   //find largest value in original array
//   for (int i = 0; i < n; ++i)
//   {
//     max = (max < x[i] ? x[i] : max);
//   }
//   //initialize a zero array of largest possible int in max
//   int * t = new int[max]();
  
//   return t;
// }

// //returns the most populous element in the original array
// int get_max(const int * original, const int * distro, const int n)
// {
  
//   //initialize to first value of distro[0]
//   int min min = distro[0];

//   //scan for elements with larger values if applicable
//   for (int i = 0; i < n; ++i)
//   {
//     distro[original[i]]++;
//     min = (distro[original[i]] > min ? distro[original[i]] : min);
//   }

// }
// int comp(const int x, const int y)
// {
//   int z = x - y;
//   return abs(z);
// }

// void print(const int * arr, const int n)
// {
//   std::cout << '[';
//   for (int i = 0; i < n - 1; ++i)
//   {
//     std::cout << arr[i] << ", ";
//   }
//   std::cout << arr[n - 1] << ']' << std::endl;
// }

// int * arrgen(const int n)
// {
//   int * arr = new int[n];
//   for (int i = 0; i < n; ++i)
//   {
//     arr[i] = rand() % 20;
//   }
//   return arr;
// }
