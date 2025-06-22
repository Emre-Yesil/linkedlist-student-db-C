#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int studentNumber;
    char name[64];
    char surname[64];
    struct student* next;
}student;

student* createNode(student* head, int num, char name[], char surname[]){
    student* newNode = (student*)malloc(sizeof(student));

    newNode->studentNumber = num;
    strcpy(newNode->name, name);
    strcpy(newNode->surname, surname);

    if(head == NULL){
        newNode->next = NULL; //it causes segmantation fault at printf wow C
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void showNodes(student* head){
    student* tmp = head;
    while(tmp != NULL){
        printf("student num: %d\n", tmp->studentNumber);
        printf("student name is %s\n", tmp->name);
        printf("student surname is %s\n", tmp->surname);
        tmp = tmp->next;
    }
}

void editNode(student* head,int num){
    if(head == NULL)
        return;
    student* tmp = head;
    printf("editing\n");
    while(tmp != NULL){
        if(tmp->studentNumber == num){
            char tmpName[64], tmpSurname[64];
            printf("\nnew num : ");
            scanf("%d", &tmp->studentNumber);

            printf("\nnew name : ");
            scanf("%s", tmpName);
            strcpy(tmp->name, tmpName);

            printf("new surname : ");
            scanf("%s", tmpSurname);
            strcpy(tmp->surname, tmpSurname);
            return;
        }
        tmp = tmp->next;
    }
    printf("not found\n");
}

student* deleteNode(student* head, int num){
    if(head == NULL)
        return head;
    student* tmp = head;
    student* last = NULL;
    while(tmp != NULL){
        if(tmp->studentNumber == num){
            if(last == NULL){
                head = head->next; 
            }else{
                last->next = tmp->next;
            }
            free(tmp);
            return head;
        }
        last = tmp;
        tmp = tmp->next;
    }
    printf("not fount\n");
    return head;
}

void freeList(student * ptr){
    while (ptr != NULL) {
        student *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

int main(){
    student* head = NULL;
    
    int i;
    while(i != 4){
        printf("0 : edit node\n1 : delete node\n2 : create node\n3 : show nodes\n4 : exit\n");
        scanf("%d", &i);
    
        int e;
        if(i == 0 || i == 1){
            printf("\nstudent num : ");
            scanf("%d", &e);
        }
        switch (i)
        {
        
        case 0:
            editNode(head, e);
            break;
        case 1:
            head = deleteNode(head, e);
            break;
    
        case 2:
            int num;
            char name[64], surname[64];
    
            printf("\nstudent num : ");
            scanf("%d", &num);
    
            printf("\nname : ");
            scanf("%s", name);
    
            printf("\nsurname : ");
            scanf("%s", surname);
    
            head =createNode(head, num, name, surname);
            break;
        case 3: 
            showNodes(head);
            break;
        case 4: 
            return 0;
            break;
    
        default:
            break;
        }
    }

    freeList(head);

    return 0;
}