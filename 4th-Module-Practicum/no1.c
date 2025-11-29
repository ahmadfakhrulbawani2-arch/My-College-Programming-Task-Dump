#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i;
    int j;
    int trail;
    int cmdlen;
    char cmd[105];
} Blob;

int main(void) {
    int n; scanf("%d", &n);
    int r, c; scanf("%d %d", &r, &c);
    
    int **map = calloc(r, sizeof(int*));
    for(int i = 0; i < r; i++) {
        map[i] = calloc(c, sizeof(int));
    }

    Blob *blob = malloc(n * sizeof(Blob));

    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &blob[i].i, &blob[i].j, &blob[i].trail, &blob[i].cmdlen);
        scanf("%s", blob[i].cmd);
        map[blob[i].i][blob[i].j] += blob[i].trail;
    }

    int q; scanf("%d", &q);
    for(int i = 0; i < q; i++) {

        int qid; scanf("%d", &qid);
        Blob *temp = &blob[qid];
        int tmpLen = temp->cmdlen;

        for(int j = 0; j < tmpLen; j++) {
            if(temp->trail % 2 == 0) temp->trail /= 2;
            else {
                temp->trail *= 3;
                temp->trail++;
            }

            char tmpCmd = temp->cmd[j];
            switch (tmpCmd) {
            case 'W':
                temp->i--;
                break;
            case 'A':
                temp->j--;
                break;
            case 'S':
                temp->i++;
                break;
            case 'D':
                temp->j++;
                break;
            default:
                break;
            }

            map[temp->i][temp->j] += temp->trail;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    free(map);
    return 0;
}