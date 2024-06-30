#include<stdio.h>
int main()
{
    int n,nm,p,x=0,y=1,t=300,offset,i;
    printf("\nEnter the memory size -- ");
    scanf("%d", &nm);
    printf("\nEnter the no. of segments -- ");
    scanf("%d", &n);
    int s[n];
    for(i=0;i<n;i++)
    {
    printf("\nEnter the segment size of %d -- ",i+1);
    scanf("%d", &s[i]);
	x += s[i];
	if(x>nm)
	{
		
    printf("\nMemoeru is full segment %d is not allocated", i+1);
    x -= s[i];
    s[i]=0;
	}	
	}
	printf("\n-----------------Operation-------------------\n");
	while(y==1)
	{
		printf("Enter the no. of operations -- \n");
		scanf("%d",&p);
		printf("Enter the offset -- \n");
		scanf("%d",&offset);
        if(s[p-1]==0)
        {
        	printf("Segment is not allowed\n");
		}
		else if(offset>s[p-1])
		{
			printf("Out of order\n");
		}
		else
		{
			printf("The segment %d the physical address is range from %d to %d the address of operation is %d\n",p,t,t+s[p-i],t+offset);			
		}
		printf("press 1 to continue\n");
		scanf("%d",&y);
	}
    return 0;
}
