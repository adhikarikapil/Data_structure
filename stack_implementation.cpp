#include <iostream>
using namespace std;

class Stack{
    public:
        //Pointer allocationg the stack in the heap 
        int* inner;

        //Max index of the stack
        int max_index;

        //Current index of the stack
        int ind;

        //Setting size of the stack 
        Stack(int size){ 
            inner = new int(size);
            max_index = size + 1;
            ind = -1;
        }

        //Add on the top most index of the stack
        //False represent the stackoverflow 
        //True represent you can push the element 
        bool push(int elem){
            if(ind == max_index){
                return false;
                cout<<"The element hasn't been pushed"<<endl;
            }else{
                inner[++ind] = elem;
                cout<<"The element has been pushed"<<endl;
                return true;
            }
        }

        //Remove the element in the current index
        //False represent understack and there is nothing to remove 
        //True represent you can remove the element
        bool pop(int elem){
            if(!isEmpty()){
                ind--;
                cout<<"The data has been removed"<<endl;
                return true;
            }else{
                return false;
            }
        }
        
        //Checking if the stack is empty of not 
        bool isEmpty(){
            return ind < 0;
        }

        void display(){
            if(isEmpty()){
                cout<<"The stack is empty"<<endl;
            }else{
                cout<<"The element of the stack is: "<<inner[ind]<<endl;
            }
        }
};

int menu(Stack* _stack){
    int choice;
    cout<<"1: Push to the stack"<<endl;
    cout<<"2: Pop off the stack"<<endl;
    cout<<"3: Display the stack"<<endl;
    cout<<"4: Exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    
    switch(choice){
        case 1:
            int inp;
            cout<<"Enter the element to push to the stack:"<<endl;
            cin>>inp;
            _stack -> push(inp);
            break;
        case 2:
            int inp1;
            cout<<"Enter the element to pop off the stack: "<<endl;
            cin>>inp1;
            _stack -> pop(inp1);
            break;
        case 3:
            _stack -> display();
            break;
        case 4:
            break;
    }
    return choice;
}

int main(){
    Stack s(10);
    int menu_call = menu(&s);
    while (menu_call != 4){
        menu_call = menu(&s);
    }
    return 0;
}
