#include<bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node *next;
    // if a class has a pointer to class' own object then it's called a self referrential class.

    node(int x){
        data = x;
        next = NULL;
    }

    node(int x, node *y){
        data = x;
        next = y;
    }

    void insertAtBeginning(node* &head, node* &tail, int x){
        if(head == NULL){
            //list is empty
            node *temp = new node(x);
            head = temp;
            tail = temp;
            return;
        }else{
            //list is not empty
            node *temp = new node(x);
            temp->next = head;
            head = temp;
            return;
        }
    }

    void insertAtEnd(node* &head, node* &tail, int x){
        if(head == NULL){
            //list empty
            head = new node(x);
            tail = head;
            return;
        }else{
            //not empty
            node *temp = new node(x);
            tail->next = temp;
            tail = temp;
            return;
        }
    }

    int length(node* head){
        int count=0;
        // node *x = head;
        while(head != NULL){
            count++;
            head= head->next;
        }
        return count;
    }

    void insertAtIndex(node* &head, node* &tail, int pos, int data){
        if(pos == 0){
            insertAtBeginning(head, tail, data);
            return;
        }else if(pos >= length(head)){
            insertAtEnd(head, tail, data);
            return;
        }else{
            node *n = new node(data);
            node *temp = head;
            int count=0;
            while(count<=(pos-1)){
                temp = temp->next;
                count++;
            }
            n->next = temp->next;
            temp->next = n;
            return;
        }
    }

    void print(node* head){
        while(head != NULL){
            cout<<head->data<<"-->";
            head = head->next;
        }
        cout<<"NULL"<<endl;
        return;
    }

    node* searchIteratively(node* head, node* tail, int x){
        node* temp = head;
        while(temp != tail){
            if(temp->data == x){
                return temp;
            }else{
                temp = temp->next;
            }
        }
        return NULL;
    }

    node* searchrecursively(node* head, node* tail, int x){
        if(head->data == x){
            return head;
        }else if(head == NULL){
            return NULL;
        }else{
            return searchrecursively(head->next, tail, x);
        }
    }

    int positionWRTHeadAndTail(node* head, node* tail){
        if(this == NULL){
            return -1;
        }
        int pos=0;
        while(head!=tail && head->data!=data){
            head = head->next;
            pos++;
        }
        if(head==tail->next){
            return -1;
        }
        return pos;
    }

    void DeleteAtBeginning(node* &head, node* &tail){
        if(head==NULL){
            return;
        }else if(head->next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }else{
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
    }

    void DeleteAtEnd(node* &head, node* &tail){
        if(head == NULL){
            return;
        }else if(head->next == NULL){
            delete head;
            head=tail=NULL;
        }else{
            node *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = NULL;
            return;
        }
    }

    void DeleteAtLocation(node* &head, node* &tail, int pos){
        if(pos == 0){
            DeleteAtBeginning(head, tail);
        }else if(pos >= length(head)){
            DeleteAtEnd(head, tail);
        }else{
            node *temp = head;
            int i=1;
            while(i<=pos-1){
                temp = temp->next;
                i++;
            }
            node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            return;
        }
    }

    node* mid(node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        node* slow = head;
        node* fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    node* reverseMe(node* &head, node* &tail){
        //wrong!!!!!!
        if(head->next == NULL || head == NULL){
            return head;
        }
        node *n = head;
        node *m = head->next;
        while(m->next!=NULL){
            node *t = m->next;
            m->next = n;
            n->next = t;
            n=m;
            m=t;
        }
        return head;
    }

    void reverse(node* &head, node* &tail){
        if(head == NULL || head->next == NULL){
            //one or no objects.
            return;
        }else{
            //tail will be head in the end.
            tail = head;

            node *prev = NULL;
            node *current = head;
            node *n; //next, can't name it next coz the next pointer already exists in class.
            while(current!=NULL){
                n = current->next;
                current->next = prev;
                prev = current;
                current = n;
            }
            head = prev;
        }
    }

    // void merge(node* h1, node* h2){
    //     node *t;
    //     while (h1!=NULL && h2 != NULL) {
    //         if(h1>h2){
    //             t=h2->next;
    //         }else{
    //             t=h1
    //         }
    //     }
    // }

    node* merge(node *h1, node *h2){
        //base case;
        //list empty
        if(h1==NULL){
            return h2;
        }
        if(h2==NULL){
            return h1;
        }

        //recursive case;
        node *p;
        if(h1->data < h2->data){
            p=h1;
            p->next = merge(h1->next, h2);
        }else{
            p=h2;
            p->next = merge(h1, h2->next);
        }
        return p;
    }

    node* mergeSort(node* head){
        //base case
        if(head==NULL || head->next==NULL){
            return head;
        }

        //divide
        node *m = mid(head);
        // cout<<m->data;
        node *a = head;
        node *b = m->next;
        m->next = NULL;

        //sort
        a = mergeSort(a);
        b = mergeSort(b);

        //merge
        node *NayaHead = merge(a,b);
        return NayaHead;
    }

    void bubbleSort(node* &head){
        // Head is changed if the first node is swapped and it doesn't change is the next is swapped.
        // So we mantain a PREV pointer that stays behind head.
        // We need a prev pointer to also swap in order and not lose the prev list.

        // if(head==NULL || head->next==NULL){
        //     return head;
        // }
        // node *current = head;
        // node *next = current->next;
        //
        // if(current->data < next->data){
        //     current->next = next->next;
        //     next->next = current;
        // }

        node *current = head;
        node *prev = NULL;
        node *n;
        int l=length(head);
        for(int i=0;i<l-1;i++){
            current = head;
            prev = NULL;
            while(current && current->next){
                if(current->data > current->next->data){
                    //swapping hogi
                    if(prev == NULL){
                        //case 1 - head is swapped
                        n=current->next;
                        current->next=n->next;
                        n->next=current;
                        head=prev=n;
                    }else{
                        //case 2 - head is not swapped
                        n = current->next;
                        current->next = n->next;
                        prev->next = n;
                        n->next = current;
                        prev=n;
                    }
                }else{
                    //swapping nhi hogi
                    n=current->next;
                    prev=current;
                    current=n;
                }
            }
        }
        return;
    }

    bool checkIfCycle(node* head){
        //BTW rupal answered this.
        //fast and slow, they meet only if there's a cycle.

        node* slow = head;
        node* fast = head;

        while (fast!=NULL) {
            fast = fast->next;
            if(fast){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow){
                return true;
            }
        }
        return false;
    }

    void createCycle(node* head){
        node* temp=head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head->next->next;
    }

    void breakCycle(node* head){
        if(!checkIfCycle(head)){
            return;
        }

        node* slow = head;
        node* fast = head;

        while (fast!=NULL) {
            fast = fast->next;
            if(fast){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow){
                break;
            }
        }

        // while (fast!=slow) {
        //     fast=fast->next->next;
        //     slow=slow->next;
        // }

        slow=head;
        node* prev = head;
        while(prev->next!=fast){
            prev=prev->next;
        }
        while(fast!=slow){
            prev=fast;
            fast=fast->next;
            slow=slow->next;
        }
        prev->next=NULL;
    }

};

int main(){

    node *head = NULL;
    node *tail = NULL;

    // head->insertAtBeginning(head, tail, 0);
    // head->insertAtEnd(head, tail, 1);
    // head->insertAtBeginning(head, tail, 2);
    // head->insertAtEnd(head, tail, 3);
    // head->insertAtIndex(head, tail, 2, 5);

    head->insertAtBeginning(head, tail, 1);
    head->insertAtBeginning(head, tail, 2);
    head->insertAtBeginning(head, tail, 3);
    head->insertAtBeginning(head, tail, 4);
    head->insertAtEnd(head, tail, 0);

    head->print(head);

    // cout<<head->searchIteratively(head, tail, 1)->positionWRTHeadAndTail(head, tail)<<endl;
    // cout<<head->searchrecursively(head, tail, 1)->positionWRTHeadAndTail(head, tail)<<endl;
    //
    // head->DeleteAtEnd(head, tail);
    // head->DeleteAtBeginning(head, tail);
    //
    // head->print(head);
    //
    // head->DeleteAtLocation(head, tail, 2);
    //
    // head->print(head);
    //
    // cout<<head->mid(head)->positionWRTHeadAndTail(head,tail)<<endl;

    // head->reverseMe(head, tail);
    //key to handle reversing the linked list is to mantain current and orevious pointers

    // head->reverse(head, tail);
    //
    // head->print(head);

    // node *h1 = NULL, *h2 = NULL, *t1 = NULL, *t2 = NULL;
    // h1->insertAtEnd(h1, t1, 1);
    // h1->insertAtEnd(h1, t1, 3);
    // h1->insertAtEnd(h1, t1, 5);
    // h2->insertAtEnd(h2, t2, 2);
    // h2->insertAtEnd(h2, t2, 4);
    // h2->insertAtEnd(h2, t2, 6);
    // h2->insertAtEnd(h2, t2, 7);
    // h2->insertAtEnd(h2, t2, 8);
    // h2->insertAtEnd(h2, t2, 9);
    
    // h1->print(h1);
    // h2->print(h2);
    //
    // node *p = h1->merge(h1,h2);
    // p->print(p);

    head = head->mergeSort(head);
    // head->bubbleSort(head);
    head->print(head);

    // head->createCycle(head);
    // if(head->checkIfCycle(head)){
    //     cout<<"Cyclic"<<endl;
    //     head->breakCycle(head);
    //     head->print(head);
    // }

    return 0;
}
