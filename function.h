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
//void printA(struct nodeClass * head);
void insert(struct nodeClass ** head, int id, int grade) {

    if (*head == NULL){
        *head = createClass(*head);
        cnode *t = *head;
        int cid = (int)(id/10000) - 6;
        for (int i = 0; i < cid; ++i) {
            t = t -> next;
        }
        t -> studentPtr = insort(t -> studentPtr, id, grade);
        //printA(*head);
    }else{
        cnode * temp = *head;
        snode * sTemp = NULL;
        int stdId = id;
        int classID = (int)(stdId / 10000) - 6 ;
        for (int i = 0; i < classID; ++i) {
            temp = temp -> next;
        }
        temp -> studentPtr = insort(temp -> studentPtr, id, grade);
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
        //printf("passing\n");
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

void computeClassAverage(cnode * head){
    cnode * ptr = head;
    snode *temp = head -> studentPtr;
    double sum = 0, count = 0;
    while(1){
        sum = 0, count = 0;
        while(temp != NULL){
            sum += temp -> midterm;
            //printf("sum is: %.2f\t", sum);
            count++;
            temp = temp -> next;
        }
        //printf("average is: %.2f\n", sum/count);
        if(count != 0)
            ptr -> classMidtermAverage = (sum / count);
        else
            ptr -> classMidtermAverage = 0;
        ptr = ptr -> next;
        if(ptr == NULL)
            break;
        temp = ptr -> studentPtr;
    }
}

void printAll(struct nodeClass *head){
    snode * temp;
    while(head != NULL){
        printf("%d %.2f\n", head -> classID, head -> classMidtermAverage);
        temp = head -> studentPtr;
        while(temp != NULL){
            printf("%d %d\n", temp -> studentID, temp -> midterm);
            temp = temp -> next;
        }
        //printf("averge for class %d: %.2f\n", head -> classID, head -> classMidtermAverage);
        head = head ->next;
    }


}
