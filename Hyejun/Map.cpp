#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct Node{
  int key;
  int data;
  Node * next;
} Node;

class myMap{
  private:
    Node * hashTable[10];

  public:
    myMap()
    {
      for(int i = 0; i < 10; i++)
      hashTable[i] = NULL;
    }

    ~myMap()
    {
  //    free(hashTable);
    }

    void put(int key, int inputData)
    {
      int hash = key % 10;
      Node * newNode = (Node *) malloc (sizeof(Node));
      newNode -> key = key;
      newNode -> data = inputData;
      newNode -> next = NULL;

      if(hashTable[hash])
      {
        Node * pNode = hashTable[hash];

        while(pNode -> next != NULL)
        {
          if(pNode -> key == key)
            break;

          pNode = pNode -> next;
        }

        if(pNode -> key == key)
        {
          pNode -> data = inputData;
          free(newNode);
        }
        else
        {
          pNode -> next = newNode;
        }
      }
      else
      {
        hashTable[hash] = newNode;
      }
    }

    int get (int key)
    {
      Node * pNode = hashTable[key % 10];
      while(pNode != NULL)
      {
        if(pNode -> key == key)
          break;

        pNode = pNode -> next;
      }

      if(pNode)
        return pNode -> data;
      else
        return false;
    }

    void print()
    {
      Node * pNode;
      for(int i = 0; i < 10; i++)
      {
        pNode = hashTable[i];

        cout << i << "번째 hash: ";
        while(pNode != NULL)
        {
          cout << pNode -> key << "-" << pNode -> data << "/";

          pNode = pNode -> next;
        }
        cout << endl;
      }
    }
};

int main(void)
{
  myMap m;
  int menu, key;
  int data;

  while(1)
  {
    cout << "1. put  2. get  3. print: ";
    cin >> menu;

    switch(menu)
    {
      case 1:
        cout << "키를 입력하세요: ";
        cin >> key;
        cout << "데이터를 입력하세요: ";
        cin >> data;
        m.put(key,data);
        break;

      case 2:
        cout << "키를 입력하세요: ";
        cin >> key;

        if(m.get(key))
          cout << "output: " << m.get(key) << endl;

        break;

      case 3:
        m.print();
        break;

      default:
        exit(1);
    }
  }
  return 0;
}
