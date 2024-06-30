#include<stdio.h>
#include<conio.h>

int main()
{
    int ms, ps, nop, np, rempages, i, j, x, y, offset, pa;
    int s[10], fno[10][20];

    printf("\nEnter the memory size --");
    scanf("%d", &ms);

    printf("\nEnter the page size --");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("\nThe no. of pages available in memory are -- %d", nop);

    printf("\nEnter the number of process --");
    scanf("%d", &np);

    rempages = nop;

    for (i = 1; i <= np; i++)
    {
        printf("\nEnter the no. of pages required for P[%d] --", i);
        scanf("%d", &s[i]);

        if (s[i] > rempages)
        {
            printf("\nMemory is full");
            break;
        }

        rempages = rempages - s[i];

        printf("\nEnter pagetable for P[%d]", i);
        for (j = 0; j < s[i]; j++)
            scanf("%d", &fno[i][j]);
    }

    printf("\nEnter the logic address to find the physical address");
    printf("\nEnter process no. and page no. and offset --");
    scanf("%d %d %d", &x, &y, &offset);

    if (x > np || y >= s[x] || offset >= ps)
        printf("\nInvalid");
    else
    {
        pa = fno[x][y] * ps + offset;
        printf("\nThe physical address is -- %d", pa);
    }

    getch();
    return 0;
}
