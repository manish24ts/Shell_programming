#include <stdio.h>
#include <conio.h>

int fr[3];

void display() {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("%d\t", fr[i]);
    }
}

int main() {
    int i, j, n, m, page[20], fs[10], max, found = 0, lg[3], index, k, l, flag1 = 0, flag2 = 0, pf = 0;
    float pr;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        fr[i] = -1;
    }
    pf = m;

    for (j = 0; j < n; j++) {
        flag1 = 0;
        flag2 = 0;

        for (i = 0; i < m; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (i = 0; i < m; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            for (i = 0; i < m; i++) {
                lg[i] = 0;
            }
            for (i = 0; i < m; i++) {
                for (k = j + 1; k < n; k++) {
                    if (fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }
            found = 0;
            for (i = 0; i < m; i++) {
                if (lg[i] == 0) {
                    index = i;
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                max = lg[0];
                index = 0;
                for (i = 1; i < m; i++) {
                    if (lg[i] > max) {
                        max = lg[i];
                        index = i;
                    }
                }
            }
            fr[index] = page[j];
            pf++;
        }

        display();
    }

    printf("\nNo. of page faults: %d", pf);
    getch();
    return 0;
}

