//O(n)
#include <iostream>
#include <forward_list>
class Node
{
public:
  Node(const int n)
    :key(n), next(NULL)
  {}
  
  int key;
  Node * next;
};
void randlist(Node *, const int);
void print(Node * n);

Node * reverse(Node * p)
{
  if (p == NULL || p->next == NULL)
    return p;
  
  Node * fast = p->next, * slow = p;
  slow->next = NULL;
  while (fast != NULL)
  {
    std::cout << fast->key << std::endl;
    Node * t = fast->next;
    fast->next = slow;
    slow = fast;
    fast = t;
  }
  return slow;
}

int main()
{
  srand((unsigned int) time(NULL));
  Node * list = new Node(rand() % 10);
  int n; std::cin >> n;
  randlist(list, n);
  print(list);
  list = reverse(list);
  print(list);
}

void print(Node * n)
{
  Node * p = n;
  if (p == NULL)
  {
    std::cout << "[NULL]\n";
  }
  while (p != NULL)
  {
    std::cout << p->key << ' ';
    p = p->next;
  }
  std::cout << "\n";
}

void randlist(Node * n, const int n)
{
  int z = 5;
  Node * p = n;
  for (int i = 0; i < z; ++i)
  {
    p->next = new Node(rand() % 100);
    p = p->next;
    
  }
}
