#include<iostream>
#define MAX 100
using namespace std;

class floydwarshall {
public:
    int n;
    int D[MAX][MAX];
    floydwarshall(int vertices);
    void read();
    void display();
    void shortestpath();
    void displayshortestpath();


};
floydwarshall:: floydwarshall(int vertices)
{
 n= vertices;
}
void floydwarshall::read(){
cout<<"Enter cost matrix"<<endl;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
      cin>>D[i][j];
  }
}
}

void floydwarshall:: display(){
cout<<"The cost matrix is"<<endl;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
      cout<< D[i][j] <<"\t";
  }
  cout<<endl;
}
}

void floydwarshall::shortestpath(){
for(int k=1;k<=n;k++)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(D[i][k]!=999 && D[k][j]!=999 && (D[i][k]+D[k][j]<D[i][j]))
      {
          D[i][j]=D[i][k]+D[k][j];
      }
    }
  }
}
}
void floydwarshall::displayshortestpath(){
cout<<"All pair shortest pair can be gives as"<<endl;
display();
}
int main()
{
 int vertices;
 cout<<"Enter the number of vertices"<<endl;
 cin>>vertices;
 floydwarshall graph(vertices);
 graph.read();
 graph.display();
 graph.shortestpath();
 graph.displayshortestpath();
  return 0;
}
