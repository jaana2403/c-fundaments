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
    sparse operator+(sparse &s);
   friend istream & operator>>(istream &is,sparse &s);
    friend ostream & operator<<(ostream &os,sparse &s);
};    
sparse sparse::operator+(sparse &s){
    int i,j,k;
    if(m!=s.m || n!=s.n)
    throw std::invalid_argument("Matrix dimensions must be the same");;
    sparse *sum=new sparse(m,n,num+s.num);
    i=j=k=0;
    while(i<num && j<s.num){
        if(e[i].i<s.e[j].i)
        sum->e[k++]=e[i++];
        else if(e[i].i>s.e[j].i)
        sum->e[k++]=s.e[j++];
        else{
             if(e[i].j<s.e[j].j)
        sum->e[k++]=e[i++];
        else if(e[i].j>s.e[j].j)
        sum->e[k++]=s.e[j++];
        else{
            sum->e[k]=e[i];
            sum->e[k++].x=e[i].x+s.e[i].x;
        }
        }
    }
    for(;i<num;i++)sum->e[k++]=e[i];
    for(;j<s.num;j++)sum->e[k++]=e[j];
    sum->num=k;
    return *sum;
}
istream & operator>>(istream &is,sparse &s){
        cout<<"enter non zero elements \n";
        for (int i = 0; i < s.num; i++)
        {
            /* code */
            cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
        }
        return is;
    }
    ostream & operator<<(ostream &os,sparse &s){
        int k=0;
        for (int i = 0; i < s.m; i++)
        {
            for (int j = 0; j < s.n; j++)
            {
                /* code */
                if(i==s.e[k].i && j==s.e[k].j)
                cout<<s.e[k++].x<<" ";
                else
                cout<<"0 ";
            }
            cout<<endl;
        }
        return os;
    }

int main(){
    sparse s1(4 ,4,4);
    cin>>s1;
    cout<<s1;
    sparse s2(4,4,4);
    cin>>s2;
    cout<<s2;
    sparse sum=s1+s2;
    cout<<sum;
return 0;
}