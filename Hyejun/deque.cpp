#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct deqNode{
  int data;
  deqNode *f_Node;
  deqNode *b_Node;
} deqNode;

class myDeque{
private:
  deqNode *f_dqNode = NULL;
  deqNode *b_dqNode = NULL;
  int dqSize = 0;

public:
  myDeque()
  {
    this -> f_dqNode = NULL;
    this -> b_dqNode = NULL;
    dqSize = 0;
  }

  ~myDeque()
  {
  }

  int at(int num)
  {
    if(num < 0 || num >= dqSize)
    {
      cout << "오류: 해당 " << num << "번째 값을 불러올 수 없습니다." << endl;
      return -1;
    }
      else{
    deqNode * p_Node = f_dqNode;
    for(int i = 0; i < num; i++)
      p_Node = p_Node->b_Node;

    return p_Node -> data;
  }
  }

  int back()
  {
    if(b_dqNode == NULL)
    {
      cout << "출력할 값이 없습니다." << endl;
      return -1;
    }
    else
      return b_dqNode -> data;
  }

  int front()
  {
    if(f_dqNode == NULL)
    {
      cout << "출력할 값이 없습니다." << endl;
      return -1;
    }
    else
      return f_dqNode -> data;
  }

  void clear()
  {
    for(int i = 0; i < dqSize-1; i++)
    {
      f_dqNode = f_dqNode -> b_Node;
      free (f_dqNode -> f_Node);
    }

    free(b_dqNode);

    f_dqNode = NULL;
    b_dqNode = NULL;
    dqSize = 0;
  }

  void pop_back()
  {
    if(b_dqNode == NULL)
    cout << "삭제할 값이 없습니다." << endl;
    else
  {
    if(dqSize == 1)
      clear();
      else{
    b_dqNode = b_dqNode -> f_Node;
    free (b_dqNode -> b_Node);
    b_dqNode -> b_Node = NULL;
    dqSize--;
  }
  }
  }

  void pop_front()
  {
    if(f_dqNode == NULL)
      cout << "삭제할 값이 없습니다." << endl;
    else
    {
      if(dqSize == 1)
        clear();
        else{
    f_dqNode = f_dqNode -> b_Node;
    free (f_dqNode -> f_Node);
    f_dqNode -> f_Node = NULL;
    dqSize--;
  }
  }
  }

  void push_back(int num)
  {
    deqNode *newNode;
    newNode = (deqNode *) malloc(sizeof(deqNode));
    newNode->data = num;
    newNode->b_Node = NULL;

    if(dqSize)
    {
      newNode->f_Node = b_dqNode;
      b_dqNode -> b_Node = newNode;
    }
    else
    {
      newNode->f_Node = NULL;
      f_dqNode = newNode;
    }

  b_dqNode = newNode;
  dqSize++;
  }

  void push_front(int num)
  {
    deqNode *newNode;
    newNode = (deqNode *) malloc(sizeof(deqNode));
    newNode->data = num;
    newNode->f_Node = NULL;

    if(dqSize)
    {
      newNode->b_Node = f_dqNode;
	    f_dqNode -> f_Node = newNode;
    }
    else
    {
      newNode->b_Node = NULL;
      b_dqNode = newNode;
    }

    f_dqNode = newNode;
    dqSize++;
  }

  void insert(int num, int data)
  {

    if( num < 0 || num > dqSize)
      cout << "오류: 해당 " << num << "번째에 값을 저장할 수 없습니다." << endl;
    else
      {
    deqNode * newNode = (deqNode *) malloc(sizeof(deqNode));
    newNode -> data = data;

    if(num == 0)
      push_front(data);
    else if(num == dqSize)
      push_back(data);
    else
    {
    deqNode * p_Node = f_dqNode;
    for(int i = 0; i < num; i++)
      p_Node = p_Node->b_Node;

      newNode -> b_Node = p_Node;
      p_Node -> f_Node -> b_Node = newNode;
      newNode -> f_Node = p_Node -> f_Node;
      p_Node -> f_Node = newNode;
      dqSize ++;
    }
    }
  }

  int size()
  {
    return dqSize;
  }

  bool empty()
  {
    return (dqSize == 0);
  }

};
myDeque mydeque;

void checkList(){
  for(int i=0; i< mydeque.size(); i++){
    cout << i<<" : " << mydeque.at(i) << endl;
  }
}

int main(void)
{
  int menu, data, num;

  while(1)
  {
    cout << endl;
  cout << "메뉴를 선택하세요" << endl;
  cout << "1. push_front, 2. push_back, 3. insert,\n" << endl;
  cout << "4. front, 5. back, 6. at," << endl;
  cout << "7. pop_front, 8. pop_back, 9. clear," << endl;
  cout << "10. empty, 11. size, 12. checklinst, 13. exit : ";
  cin >> menu;

  switch(menu)
  {
    case 1:
      cout << "값 입력: ";
      cin >> data;
      mydeque.push_front(data);
      break;
    case 2:
      cout << "값 입력: ";
      cin >> data;
      mydeque.push_back(data);
      break;
    case 3:
      cout << "순서, 값 입력: ";
      cin >> num >> data;
      mydeque.insert(num, data);
      break;
    case 4:
      cout << mydeque.front() << endl;
      break;
    case 5:
      cout << mydeque.back() << endl;
      break;
    case 6:
      cin >> num;
      cout << mydeque.at(num) << endl;
      break;
    case 7:
      mydeque.pop_front();
      break;
    case 8:
      mydeque.pop_back();
      break;
    case 9:
      mydeque.clear();
      break;
    case 10:
      if(mydeque.empty())
        cout << "mydeque is empty" << endl;
      else
        cout << "mydeque is not empty" << endl;
      break;
    case 11:
      cout << mydeque.size() << endl;
      break;
    case 12:
      checkList();
      break;
    default:
      exit(1);
  }

}

	return 0;
}
