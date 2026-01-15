#include<iostream>
#include<algorithm>
#include<vector>
std::ostream & operator<<(std::ostream & cout, const std::pair<int, int> & x)
{
  std::cout << '<' << x.first << ", " << x.second << '>';         
  return cout;
}
void randgen(std::vector< std::pair<int, int> > & x);

void check_candidate(std::vector< std::pair<int, int> > & x, const std::pair<int, int> & c, const std::pair<int, int> & d, const int N);

std::pair<int, int> check_loop(const std::vector< std::pair<int, int> > & x, std::vector< std::pair<int, int> > & y, const int N);

int main()
{
  for (int i = 0; i < 10; ++i)
  {
    const int N = rand() % 10;
    std::vector< std::pair<int, int> > nums;
    std::vector< std::pair<int, int> > candidates;
    randgen(nums);
    std::pair<int, int> index = check_loop(nums, candidates, N);
  }
}

void check_candidate(std::vector< std::pair<int, int> > & x, const std::pair<int, int> & c, const std::pair<int, int> & d, const int N)
{
  if (c.first + d.first == N)
  {
    x.push_back({c.second, d.second});
  }
}

void randgen(std::vector< std::pair<int, int> > & x)
{
  int n = rand() % 15 + 5;
  for (int i = 0; i < n; ++i)
  {
    x.push_back({rand() % 10, i});
  }
}

//this list should be sorted
std::pair<int, int> check_loop(const std::vector< std::pair<int, int> > & x, std::vector< std::pair<int, int> > & y, const int N)
{
  for (int i = 0; i < x.size() || x[i].first >= N; ++i)
  {
    check_candidate(y, x[i], x[i + 1], N);
  }
  
  std::sort(y.begin(), y.end());
  std::pair<int, int> deft = {-1, -1}; 
  return (y.empty() ? deft : y[0]);
}

