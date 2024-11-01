#include<iostream>
using namespace std;
class element{
    public:int i,j,x;
};
class sparse{
    private:
    int m,n,num;
    element *e;
    public: 
    sparse(int m,int n, int num){
        this->m=m;
        this->n=n;
        this->num=num;
        e=new element[this->num];
    }
    ~sparse(){
        delete [] e;
    }
    void read(){
        cout<<"enter non zero elements \n";
        for (int i = 0; i < num; i++)
        {
            /* code */
            cin>>e[i].i>>e[i].j>>e[i].x;
        }
    }
    void display(){
        int k=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /* code */
                if(i==e[k].i && j==e[k].j)
                cout<<e[k++].x<<" ";
                else
                cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
int main(){
    sparse s1(4 ,4,4);
    s1.read();
    s1.display();
return 0;
}