#include<bits/stdc++.h>
using namespace std;
int const mx=1000+123;
int grid[mx][mx];
int vis[mx][mx];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int result;
int n,m;
bool isvalid(int a,int b)
{
    return a<=n && a>=1 && b<=m && b>=1 && grid[a][b]!=0;
}
int dfs(int i,int j)
{
    int k,x,y;
    vis[i][j]=1;
    result=result+grid[i][j];
    for(k=0;k<4;k++)
    {
        x=i+dx[k];
        y=j+dy[k];
        if(vis[x][y]==-1 && isvalid(x,y))
        {

            dfs(x,y);
        }
    }
    return result;
}
int main()
{
    long long tt;
    cin>>tt;
    while(tt--)
    {
       int i,j;
       cin>>n>>m;
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
           {
               cin>>grid[i][j];
           }
       }
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
           {
               vis[i][j]=-1;
           }
       }
       int ans=0;
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
           {
               if(vis[i][j]==-1 && grid[i][j]!=0)
               {
                   result=0;
                   ans=max(ans,dfs(i,j));
               }
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}
