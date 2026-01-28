
#include<iostream>
#include<vector>

bool is_valid(const std::vector<int> &x);

void randgen(std::vector<int> & x);

void print(const std::vector<int> & x);
void print_line(const std::vector<int> & x, const int start);

int main()
{
  std::vector<int> sudoku;
  randgen(sudoku);
  print(sudoku);
  for (int i = 0; i < sudoku.size(); ++i)
  {
    if (i > 0 && i % 9 == 0)
      std::cout << " | ";
    std::cout << sudoku[i] << ' ';
  }
  std::cout << std::endl << "size = " << sudoku.size() << std::endl;
  return 0;
}

bool is_valid(const std::vector<int> & x, const int inquiry)
{
  //checks if "inquiry" is at a specified location, tries to move to another valid location if it has no avaliable spot 
  for (int i = 0; i < 9; ++i)
  {
    
  }
  return true;
}

void randgen(std::vector<int> & x)
{
  for (int i = 0; i < 9; ++i)
  {
    //bool checklist of nums
    bool nums[10] = {0};
    
    //set 0 to true
    nums[0] = 1;
    
    int valid_bool_row = 0;
    while (valid_bool_row < 9)
    {
      int f = rand() % 10;
      if (!nums[f])
      {
        x.push_back(f);
        nums[f] = true;
        ++valid_bool_row;
      }
      else if (f == 0)
      {
        x.push_back(0);
        ++valid_bool_row;
      }
      std::cout << "\n";
    }
  }
}

//prints a line of the first 3 triples of digits, 9 nums
void print_line(const std::vector<int> & x, const int start)
{
  int offset = start;
  for (int i = 0; i < 3; ++i)
  {
    for (int k = 0; k < 3; ++k)
    {
      if (x[offset + k] > 0)
        std::cout << " " << x[offset + k];
      else
        std::cout << " .";
    }
    offset += 9;
    std::cout << " |";
  }
  std::cout << std::endl;
}

void print(const std::vector<int> & x)
{
  const std::string bar = "+-------+-------+-------+";

  std::cout << bar << "\n";

  int offset = 0;
  for (int i = 0; i < 9; ++i)
  {
    std::cout << "|";

    print_line(x, i * 3);
    
    //horizontal divider
    if ((i + 1) % 3 == 0 && i < 8)
    {
      std::cout << bar << "\n";
    }
    offset += 3;
  }
  
  std::cout << bar << "\n";
}
