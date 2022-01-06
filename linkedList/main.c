#include <stdio.h>
#include <stdlib.h>

//------------LINKED LIST-----------------
typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct linkedList{
    struct Node *head;
    struct Node *tail;
    int nodeCount;
}linkedList;


//--------- PROTROTYPE OF FUNC-----------
void insertAtTail(linkedList *,int);
void insertAtHead(linkedList *,int);
void printList(linkedList*);
int linkedListIsEmpty(linkedList *);
void printListDetail(linkedList *);
void initList(linkedList *);
void findData(linkedList *listPtr, int, Node**);
void loadFromFile(linkedList *, char*);
int deletedFirstNode(linkedList *);
void deleteNode(linkedList*,int);



//---------- INITIALIZATION OF LINKED LIST -----
void initList(linkedList *listPtr){
        listPtr->head = '\0';
        listPtr->tail = '\0';
        listPtr->nodeCount =0;
}
//---------- INSERT AT TAIL -------------
void insertAtTail(linkedList *listPtr,int data){
    Node *newNodePtr =(Node*)malloc(sizeof(Node));
    if(newNodePtr == '\0')
    {
        printf("Unable to create Node\n");
        exit(1);
    }
    newNodePtr->data = data;
    newNodePtr->next = '\0';

    if(linkedListIsEmpty(listPtr))
    {
            listPtr->head = newNodePtr;
            listPtr->tail = newNodePtr;
    }

    else{
         listPtr->tail->next = newNodePtr;
         listPtr->tail = newNodePtr;

    }
     listPtr->nodeCount++;
}

//--------- INSERT AT HEAD ------------
void insertAtHead(linkedList *listPtr,int data){
    Node *newNodePtr =(Node*)malloc(sizeof(Node));
    if(newNodePtr == '\0')
    {
        printf("Unable to create Node\n");
        exit(1);
    }
    newNodePtr->data = data;
    newNodePtr->next = '\0';
    if(linkedListIsEmpty(listPtr))
    {
            listPtr->head = newNodePtr;
            listPtr->tail = newNodePtr;

    }
    else
    {
            newNodePtr->next = listPtr->head;
            listPtr->head = newNodePtr;

    }

    listPtr->nodeCount ++;

}

//--------- PRINT LIST ---------
void printList(linkedList *listPtr){
    if(listPtr->nodeCount == 0){
        printf("LinkedList is empty\n");
        return;
    }
    Node *current = listPtr->head;
    while(current != '\0'){
        printf("current data : %d\n",current->data);
        current = current->next;
    }
}

//-------- LINKED LIST ---------
int linkedListIsEmpty(linkedList *listPtr){
    return listPtr->nodeCount == 0;
}

//-------- PRINT LIST DETAIL ------------
void printListDetail(linkedList *listPtr){
if(listPtr->nodeCount == 0){
        printf("LinkedList is empty\n");
        return;
    }
    Node *current = listPtr->head;
    printf("Printing linked list in detail\n");
    printf("HEAD : %p\n",listPtr->head);
    while(current != '\0'){
        printf("(%p) [%d]|(%p)\n",current,current->data,current->next);
        current = current->next;
    }
}

//--------  1 ISSUE : FIND LINKED LIST OPERATION -----
void findData(linkedList *listPtr, int data, Node**prevPtr)
{
    Node *current = listPtr->head;
    *prevPtr = NULL;
    if(linkedListIsEmpty(listPtr))
    {
            printf("Linked List is empty\n");
            return;
    }
    int numNode = 1;

    while(current !='\0')
    {

        if (current->data == data){
            printf("Num of Node : %d\naddr::%p ----> [%d]",numNode,current,current->data);
            return;
        }
        current = current->next;
        numNode ++;

    }

    printf("ERROR:The data is not in the Linked List\n");

}

//------------- LOAD DATA FROM FILE ---------
void loadFromFile(linkedList *listPtr, char *fileName){

    FILE *inputFile = fopen(fileName, "r");
    if(inputFile == NULL){
        printf("File could not be opened, make sure the file exists\n");
        return;
    }
    int data;
    fscanf(inputFile,"%d",&data);
    while(!feof(inputFile)){
        insertAtTail(listPtr, data);
        fscanf(inputFile,"%d",&data);
    }

    fclose(inputFile);

}

//--------- DELETE FIRST NODE IN LINKED LIST -------
int deletedFirstNode(linkedList *listPtr){
    if(listPtr->nodeCount == 0){
            return -9999;
    }

    Node *current = listPtr->head;
    int data = current->data;

    if(listPtr->nodeCount == 1){
        listPtr->head = NULL;
        listPtr->tail = NULL;
        return(1);
    }
    else{
            listPtr->head = current->next;

    }
    free(current);
    listPtr->nodeCount --;
    return data;

}

//-------- DELETE LAST NODE IN LINKED LIST ---------
int deletedLastNode(linkedList *listPtr){
    if(listPtr->nodeCount == 0){
            return -9999;
    }

    Node *current =listPtr->head;
    Node *last = listPtr->tail;
    int data = last->data;

    if(listPtr->nodeCount == 1){
        listPtr->head = NULL;
        listPtr->tail = NULL;
        return(1);
    }
    else{

            while(current != listPtr->tail)
            {
                current = current->next;
            }
            listPtr->tail = current;
            current->next = NULL;

    }
    free(last);
    listPtr->nodeCount --;

    return data;

}


//------ DELETE AN ODE THAZT CONTAINT TARGET SDATA ------
void deleteNode(linkedList *listPtr, int data){
    Node *current = listPtr->head;
    Node *prev=NULL;

    while(current != NULL){
        if(current->data == data){
            break;
        }
         prev = current;
         current = current->next;
    }
    prev->next= current->next;
    free(current);
    listPtr->nodeCount --;
    return;
}

int main()
{
   linkedList llist;
   initList(&llist);// TRES IMPORTANT

   insertAtHead(&llist,10);
   insertAtHead(&llist,20);
   insertAtHead(&llist,30);
   insertAtHead(&llist,40);
   insertAtHead(&llist,50);

   //printList(&llist);
   printListDetail(&llist);
   deleteNode(&llist,30);
   printf("\n");
   //printList(&llist);
   printf("\n");
   printListDetail(&llist);

   //printList(&llist);
   //printListDetail(&llist);
   //findData(&llist,60);

  /* loadFromFile(&llist,"data.txt.txt");
   printf("File closed\n");
   printList(&llist);*/

}
