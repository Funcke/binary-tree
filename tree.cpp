#include <iostream>
#include <string>
#include "tree.hpp"

#define __DEBUG__

using namespace std;
using namespace tree;

namespace tree{
        Node::Node(){
            this->val = 0.0;
            this->Left = NULL;
            this->Right = NULL;
        }

        Node::Node(double value){
            this->val = value;
            this->Left = NULL;
            this->Right = NULL;
        }

        Node::Node(Node *begin){
            if(begin != NULL){
                this->val = begin->val;
                if(begin->Left != NULL)
                    this->Left = new Node(begin->Left);
                if(begin->Right != NULL)
                    this->Right = new Node(begin->Right);
            }else{
                this->val = 0;
                this->Left = NULL;
                this->Right = NULL;
            }
        }

        bool Node::Search(const double val){
            cout << this->val << endl;
            if(this->val == val)
                return true;
            else{
#ifdef __DEBUG__
                cout << "in else" << endl;
#endif
                if((this->Left != NULL)){
#ifdef __DEBUG__
                    cout << "in Left" << endl;
#endif
                    if((this->Left->Search(val) == true)){
                        return true;
                    }
                }
                if((this->Right != NULL)){
#ifdef __DEBUG__
                    cout << "in right" << endl;
#endif
                    if((this->Right->Search(val) == true)){
                        return true;
                    }
                }
            }
            return false;
        }

        bool Node::IsBigger(const double val){
            cout << this->val << endl;
            if(this->val < val)
                return true;
            else{
#ifdef __DEBUG__
                cout << "in else" << endl;
#endif
                if((this->Left != NULL)){
#ifdef __DEBUG__
                    cout << "in Left" << endl;
#endif
                    if((this->Left->Search(val) < true)){
                        return true;
                    }
                }
                if((this->Right != NULL)){
#ifdef __DEBUG__
                    cout << "in right" << endl;
#endif
                    if((this->Right->Search(val) < true)){
                        return true;
                    }
                }
            }
            return false;
        }

        bool Node::IsSmaller(const double val){
            cout << this->val << endl;
            if(this->val > val)
                return true;
            else{
#ifdef __DEBUG__
                cout << "in else" << endl;
#endif
                if((this->Left != NULL)){
#ifdef __DEBUG__
                    cout << "in Left" << endl;
#endif
                    if((this->Left->Search(val) > true)){
                        return true;
                    }
                }
                if((this->Right != NULL)){
#ifdef __DEBUG__
                    cout << "in right" << endl;
#endif
                    if((this->Right->Search(val) > true)){
                        return true;
                    }
                }
            }
            return false;
        }

        void Node::HowMany(const double val, int *counter){
            if(this->val == val){
#ifdef __DEBUG__
                cout << "Im Wert" << endl;
#endif
                *counter += 1;
            }
            if(this->Left != NULL){
#ifdef __DEBUG__
                cout << "in left" << endl;
#endif
                this->Left->HowMany(val, counter);
            }
            if(this->Right != NULL){
#ifdef __DEBUG__
                cout << "In Right" << endl;
#endif
                this->Right->HowMany(val, counter);
            }
        }
}

int main(){

    Node *first, *second, *last;
    first = new Node(2.3);
    second = new Node(3.5);
    last = new Node(3.0);

    first->Left = second;
    first->Right = last;
    int counter = 0;

    first->HowMany(3.0, &counter);
    cout << first->IsSmaller(3.0) << endl;
    cout << counter << endl;
    
    delete first;
    delete second;
    delete last;

    return 0;
}