#include <iostream>

using namespace std;

typedef struct Node{
    Node* right;
    Node* left;
    int data;
}Node;

class Tree{
    
public:
    Tree(){
        root = NULL;
    }
    ~Tree(){
        free(root);
    }

    bool insertNode(int data){
        if(root == NULL){
            Node *nNode = createNode(data);
            root->right = nNode;
            root->left = nNode;
        }else{
            thisNode = root;
            Node *p = searchNode(thisNode, data);
            if(p == NULL){
                if(leftRight){
                    thisNode ->left = createNode(data);
                }else{
                    thisNode ->right = createNode(data);
                }
            }else{
                return false;
            }
        }
    }

    Node *createNode(int data) const {
        Node* nNode = (Node *) malloc(sizeof(Node));
        nNode->data = data;
        nNode->left = NULL;
        nNode->right = NULL;
        return nNode;
    }

    int searchData(int data){
        Node* p = searchNode(root, data);
        if(p == NULL){  // 없음
            cout << "데이터 없음" << endl;
        }else{  // 위치를 찾음
            return p->data;
        }
    }
    
    /*
     * 빈자리를 찾는 함수 
     * parameter : p 재귀용도, data  : 넣을값 찾을값
     * return 만약에 넣을값일 경우 NULL 이면 넣어야 할곳
     * NULL 이 아니면 중복값
     * 만약에 찾을 값
     * NULL 이면 못찾음
     * NULL이 아니면 찾은 위치 ->data = 찾은값
     * 
     */
    Node* searchNode(Node* p, int data){    
        if(p == NULL) { // 못찾았을 떄는 NULL
            return p;
        }
        if(p->data > data){
            thisNode = p;
            leftRight = true;
            return searchNode(p->right, data);
        }else if(p->data < data){
            thisNode = p;
            leftRight = false;
            return searchNode(p->left, data);
        }else{
            return p;   // 찾았다!
        }
    }
    void deleteNode(int data){
        thisNode -> left = NULL;
        
        NULL;
        NULL;
        
    }

private:
    Node* root;
    Node* thisNode;
    bool leftRight;
};



int main(){


}