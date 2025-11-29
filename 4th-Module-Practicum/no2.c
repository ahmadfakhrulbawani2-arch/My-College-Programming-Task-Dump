#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
typedef struct { 
    char name[50]; 
    int priority; 
} task; 
 
int main(){ 
    task *taskPtr = NULL; 
    int index = 0; 
    while (1){ 
        char cmd[20]; 
        scanf(" %s", cmd); 
        if (!strcmp(cmd, "EXIT")) { 
            break; 
        } 
        else if (!strcmp(cmd, "ADD")){ 
            // realloc *taskPtr 
            taskPtr = realloc(taskPtr, (index + 1) * sizeof(task));
            
            scanf(" %s %d", taskPtr[index].name, &taskPtr[index].priority); 
            printf("%s %d is added\n", taskPtr[index].name, taskPtr[index].priority);
            index++; 
        } 
        else if (!strcmp(cmd, "CHECK")){ 
            int idx; scanf("%d", &idx);
            if(strlen(taskPtr[idx].name) > 0 && idx >= 0 && idx < index) {
                printf("%s %d\n", taskPtr[idx].name, taskPtr[idx].priority);
            } else {
                printf("Task at ID %d is empty\n", idx);
            }
        } 
        else if (!strcmp(cmd, "LIST")){ 
            printf("TO DO LIST: \n");
            for(int i = 0; i < index; i++) {
                if(strcmp(taskPtr[i].name, "") == 0) continue;

                printf("%s %d\n", taskPtr[i].name, taskPtr[i].priority);
            }
        } 
        else if (!strcmp(cmd, "CLEAR")){ 
            int idx; scanf("%d", &idx);
            if(strlen(taskPtr[idx].name) > 0 && idx >= 0 && idx < index) {
                printf("Task %s is cleared\n", taskPtr[idx].name);
                strcpy(taskPtr[idx].name, "");
            }
        }
    }
    return 0;
}