typedef struct nodeClass
{
	int classID;
	double   classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
}nodeClass;

typedef struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
}nodeStudent;
// prototypes:
void createNodeClass(nodeClass **);
void print(nodeClass *);
nodeStudent *insort(nodeStudent *, int, int);

// functions:
void insert(nodeClass ** head, int stdId, int grade){
    if(*head == NULL) {
        createNodeClass(head);
    }
    nodeClass *temp = *head;
    int classID = (int)(stdId / 10000) - 5;
    for (int i = 0; i < classID; ++i) {
        temp = temp -> next;
    }
    temp->studentPtr = insort(temp->studentPtr, stdId, grade);

}

nodeStudent * insort(nodeStudent * head, int id, int grade){
    nodeStudent *temp, *ptr;
    ptr = (nodeStudent*)malloc(sizeof(struct nodeStudent));
    temp = (nodeStudent*)malloc(sizeof(struct nodeStudent));
    temp -> next = NULL;

    ptr -> midterm = grade;
    ptr -> studentID = id;
    ptr -> next = NULL;

    if(head == NULL) {
        //printf("holy shit");
        head = temp;
    }
    else{
        temp = head;
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = ptr;
    }
    return head;

}


void createNodeClass(nodeClass **head){
    *head = (nodeClass *)malloc(sizeof(nodeClass));
    nodeClass *temp = *head;
    for(int i = 0; i < 5; i++) {
        temp->classID = i;
        temp -> studentPtr = NULL;
        if (i < 4)
            temp -> next = (struct nodeClass *) malloc(sizeof(struct nodeClass));
        else
            temp->next = NULL;
        temp = temp->next;
    }
}

void print(nodeClass * head){
    printf("id\tgrade\n");

}
// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.

