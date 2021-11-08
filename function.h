typedef struct nodeClass
{
    int classID;
    double classMidtermAverage;
    struct nodeClass *next;
    struct nodeStudent *studentPtr;
}cnode;

typedef struct nodeStudent
{
    int studentID;
    int midterm;
    struct nodeStudent *next;
}snode;
struct nodeClass *createClass(struct nodeClass * head);
struct nodeStudent * insort(struct nodeStudent * head, int id, int grade);
void printA(struct nodeClass * head);
void insert(struct nodeClass ** head, int id, int grade) {
    if (*head == NULL){
        *head = createClass(*head);
        //printA(*head);
    }else{
        cnode * temp = *head;
        snode * sTemp = NULL;
        int stdId = id;
        int classID = (int)(stdId / 10000) - 6;
        for (int i = 0; i < classID; ++i) {
            temp = temp -> next;
        }
        temp -> studentPtr = insort(temp -> studentPtr, id, grade);
        if(temp -> studentPtr == NULL)
            printf("its nul\n");
    }
}
snode * insort(snode * head, int id, int grade){
    snode *temp, *ptr = (snode*)malloc(sizeof(struct nodeStudent)), *t = (snode*)malloc(sizeof(struct nodeStudent));
    ptr -> midterm = grade;
    ptr -> studentID = id;
    ptr -> next = NULL;
    temp = head;
    if(head == NULL || head -> midterm < grade) {
        ptr->next = head;
        head = ptr;
        return head;
    }
    while(temp -> next != NULL && temp -> next -> midterm > grade){
        printf("passing\n");
        temp = temp->next;
    }
    ptr -> next = temp -> next;
    temp -> next = ptr;
    return head;
}

struct nodeClass* createClass(struct nodeClass *head)
{
    struct nodeClass *tempClassHead = head;
    int i = 0;
    while (i < 4)
    {
        struct nodeClass *newNode = (struct nodeClass *)malloc(sizeof(struct nodeClass));
        newNode->next = NULL;
        newNode->classID = i + 1;
        newNode->studentPtr = NULL;
        if (tempClassHead == NULL)
        {
            tempClassHead = newNode;
            head=newNode;
            i++;
            continue;
        }
        if (tempClassHead->next == NULL)
        {
            tempClassHead->next = newNode;
            tempClassHead = newNode;
        }
        i++;
    }
    return head;
}

void printA(struct nodeClass *head){
    printf("id\tgrade\n");
    snode * temp;
    while(head != NULL){
        temp = head -> studentPtr;

        if(temp == NULL)
            printf("null, won't print\n");
        while(temp != NULL){
            printf("%d\t%d\n", temp -> studentID, temp -> midterm);
            temp = temp -> next;
        }printf("classid: %d^^\n", head -> classID);
        head = head ->next;
    }


}
