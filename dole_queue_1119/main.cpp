#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
    Node(int data): data(data), next(this), prev(this) {}
};

typedef struct Node node;

void append(node ** head, int data){
    node * current = *head;
    while(current->next != *head){
        current = current->next;
    }
    node * newNode = new node(data);
    newNode->prev = current;
    current->next = newNode;
    newNode->next = *head;
    (*head)->prev = newNode;
}

void display(node ** head){
    node * current = *head;
    do{
        cout << (current)->prev->data << "<=" << current->data << "=>" << (current)->next->data << " ";
        current = current->next;
    }
    while(current != *head);
    cout << endl;
}

void rem(node * n){
    node * prev = n->prev, * next = n->next;
    prev->next = next;
    next->prev = prev;
    delete n;
}

node * getAfter(node ** head, int index){
    node * current = *head;
    for(int i=1;i<index;i++) current = current->next;
    return current;
}

node * getBefore(node ** head, int index){
    node * current = *head;
    for(int i=1;i<index;i++) current = current->prev;
    return current;
}

bool isEmpty(node ** head){
    if((*head)->next == *head || (*head)->prev == *head) return true;
    return false;
}

string make_3_char_string(int num){
    string s = to_string(num);
    string rs;
    for(int i=s.length();i<3;i++) rs += ' ';
    rs+= s;
    return rs;
}

int main()
{
    while(true){
        int n,k,m; cin >> n >> k >> m;
        if(n == 0 && k == 0 && m == 0) break;
        node * head = new node(1);
        for(int i=2;i<=n;i++) append(&head,i);
        display(&head);
        node * start1 = head, * start2 = head->prev;
        display(&start1);
        while(true){
            node *  after = getAfter(&start1, k), * before = getBefore(&start2,m);
            if(after->data == before->data) cout << make_3_char_string(after->data);
            else{
                cout << make_3_char_string(after->data) << make_3_char_string(before->data);
            }
            if(isEmpty(&after) || isEmpty(&before)){
                break;
            }else{
                cout << ",";
                start1 = after->next;
                start2 = before->prev;
                if(after->data == before->data) rem(after);
                else{
                    rem(after);
                    rem(before);
                }
            }
        }
        cout << endl;
    }

    /*
    node * head = new node(0);
    for(int i=1;i<10;i++) append(&head,i);
    display(&head);
    cout << (getAfter(&head, 2))->data;
    */
    return 0;
}








