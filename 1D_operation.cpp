#include <iostream>
using namespace std;

void create(int [100], int*);
void insert(int [100], int*);
void delet(int [100], int*);
void update(int [100], int*);
void traverse(int [100], int*);
void searching(int [100], int*);
void merging(int [100],int [100],int*, int*);
int main(){
    int a[100], b[100], nel, pos, i;
    int n, m;
    int choice;
    cout<<"\nManual for program:\n"<<endl;
    cout<<"1:Create\n2:Insert\n3:Delete\n4:Update\n5:Traverse\n6:Searching\n7:Merging"<<endl;
    do{
        cout<<"\nEnter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter no of elements of array:\n"<<endl;
                cin>>n;
                create(a, &n);
                break;
            case 2:
                insert(a, &n);
                break;
            case 3:
                delet(a, &n);
                break;
            case 4:
                update(a, &n);
                break;
            case 5:
                traverse(a, &n);
                break;
            case 6:
                searching(a, &n);
                break;
            case 7:
                cout<<"Enter the size of another array"<<endl;
                cin>>m;
                merging(a, b, &n, &m);
                break;
            default:
                cout<<"Invalid entry!!!"<<endl;
        }
    }
    while(choice<8);
    return 0;
}

void create(int a[100], int* n){
    int i;
    cout<<"Enter the elements of the array"<<endl;
    for(i=0;i<*n;i++){
        cin>>a[i];
    }
    for(i=0;i<*n;i++)
        cout<<a[i];
}

void insert(int a[100], int* n){
    int pos, nel, i;
    cout<<"Enter position at which you want to insert new element"<<endl;
    cin>>pos;
    cout<<"Enter the new element"<<endl;
    cin>>nel;
    for(i=*n;i>=pos;i--)
        a[i+1] = a[i];
    a[pos] = nel;
    *n = *n +1;
    for(i=0;i<*n;i++)
        cout<<a[i];
}
void delet(int a[100], int* n){
    int pos, i;
    cout<<"Enter position at which you want to delete an element"<<endl;
    cin>>pos;
    for(i=pos;i<*n;i++)
        a[i] = a[i+1];
    *n = *n +1;
    for(i=0;i<*n;i++)
        cout<<a[i];
}

void update(int a[100], int* n){
    int pos, num, i;
    cout<<"Enter position at which you want to update an element"<<endl;
    cin>>pos;
    cout<<"Enter the new element"<<endl;
    cin>>num;
    a[pos] = num;
    for(i=0;i<*n;i++)
        cout<<a[i];
}

void traverse(int a[100], int* n){
    int i;
    cout<<"Current element of the array are: "<<endl;
    for(i=0;i<*n;i++)
        cout<<a[i]<<endl;
}

void searching(int a[100], int* n){
    int k, i;
    cout<<"Enter item to be searched: "<<endl;
    cin>>k;
    for(i=0;i<*n;i++){
        if(k == a[i]){
            cout<<"Search Successful!!!"<<endl;
            break;
        }
    }
    if(i == *n)
        cout<<"Search Unsuccessful!!!"<<endl;
}

void merging(int a[100], int b[100], int* n, int* m){
    int i;
    int j = *n;
    cout<<"Enter element of the second array"<<endl;
    for(i=0;i<*m;i++){
        cin>>b[i];
        a[j] = b[i];
        j++;
        *n = *n + 1;
    }
    for(j=0;j<*n;j++)
        cout<<a[j];
}
