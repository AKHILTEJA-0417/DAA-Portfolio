#include<iostream>
using namespace std;
int n, a[20],BIT[20];

class fenwick {
public:
 fenwick(int n);
 void tree();
 void update(int x,int delta);
 int query(int x);
 int sum();

};
fenwick::fenwick(int n)
{
 for(int i=0;i<=n;i++)
 {
  BIT[i]=0;
 }
}
void fenwick:: tree()
{
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  update(i,a[i]);
 }

}
void fenwick::update(int x,int delta)
{
 for( ; x <= n; x += x&-x)
   BIT[x] += delta;
}
int fenwick::query(int x)
{
 int sum = 0;
    while (x > 0) {
        sum += BIT[x];
        x -= x & -x;
    }
    return sum;
}
int fenwick::sum()
{
 return(query(n));
}

int main()
{
 cout<<"Enter the size of array"<<endl;
 cin>>n;
 fenwick fen(n);
 cout<<"Enter the array elements"<<endl;
 fen.tree();
 cout<<"The range sum can be gives as:"<<"\t";
 cout<<fen.sum()<<endl;
 return 0;
}
