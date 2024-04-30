#include<stdio.h>
int main()
{
int n,m,i,j,k,p,c;
int alloc[5][5],max[5][5];
int avail[5];
int f[n],ans[n],ind=0;
printf("enter no.of  process and resources ");
scanf("%d%d",&n,&m);
printf("enter allocation and resources ");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&alloc[i][j]);
}
}
printf("enter the max resource process required %dx%d matrix",n,m);
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
       scanf("%d",&max[i][j]);
}
}
printf("enter the available resource");
for(i=0;i<m;i++)
scanf("%d",&avail[i]);
for(k=0;k<n;k++)
{
f[k]==0;
}
int need[n][m];
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
int y=0;
for(k=0;k<5;k++)
{
for(i=0;i<n;i++)
{
if(f[i]==0)
{
int flag=0;
for(j=0;j<m;j++)
{
if(need[i][j]>avail[j])
{
flag=1;
break;
}
}
if(flag==0)
{
ans[ind++]=i;
for(y=0;y<m;y++)
avail[y]+=alloc[i][y];
f[i]=1;
}
}
}
}
int flag=1;
for(i=0;i<n;i++)
{
if(f[i]==0)
{
flag=0;
printf("the following system is not safe");
break;
}
}
if(flag==1)
{
printf("following is the SAFE sequence");
for(i=0;i<n-1;i++)
printf("P%d",ans[i]);
printf("P%d",ans[n-1]);
}
return 0;
}


