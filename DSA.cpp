//_____________+______________+_______________DATA_STRUCTURE_AND_ALGORITHM______________+________________+________________//

//adding a node at beginning of a list
/*
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* head;

void insertatbeg(int x){
    node * temp = new node;
    temp->data = x;
    temp->next=head;
    head = temp;
}

void insert(int x,int n){
    if(n==0){
        node* temp = new node();
        (*temp).data=x;
        (*temp).next=NULL;
        head = temp;
    }
    else{
        node*temp = new node;
        temp->data=x;
        temp->next = NULL;
        node* temp1 = head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next = temp;
    }
}

void print(){
    struct node* temp =head;
    cout<<"List is: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    head = NULL;
    cout<<"How many Numbers"<<endl;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter The Num"<<endl;
        cin>>x;
        insertatbeg(x);
        //insert(x,i);
        print();
    }
    return 0;
}          
//adding a node at nth pos and deleting a node at nth pos

#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* head;

void insert(int data,int n){
    node * temp1 = new node();
    temp1->data = data;
    temp1->next=NULL;
    if(n==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    node* temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1; 
}

void print(){
    struct node* temp1 =head;
    cout<<"List is: ";
    while(temp1 != NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
}

void Delete(int n){
    struct node* temp1 = head;
    if(n==1){
        head = temp1->next;
        delete[] temp1;
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    struct node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete[] temp2;
}

int main(){
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();
    int n;
    cin>>n;
    Delete(n);
    print();
    return 0;
}               */   
// REVERSING LINKED LIST USING ITERATIVE METHOD
/*
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
struct node* head;

void insert(int data,int n){
    node * temp1 = new node();
    temp1->data = data;
    temp1->next=NULL;
    if(n==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    node* temp2 = head;
    for(int i=0;i<n-2;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1; 
}

void print(){
    struct node* temp1 =head;
    cout<<"List is: ";
    while(temp1 != NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;
}

void REVERSE(){
    struct node *current, *prev, *Next;
    current = head;
    prev = NULL;
    while(current!=NULL){
         Next = current->next;
         current->next = prev;
         prev = current;
         current = Next;
    }
    head = prev;
    }

int main(){
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();
    REVERSE();
    print();
    return 0;
}    */

// Printing elements of list And reversing a list using recursion
/*

#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
void print(struct node* p){
    if(p == NULL){
        cout<<endl;
        return;
    }
    cout<<" "<<p->data;
    print(p->next);
}

void Reverseprint(struct node* p){//here we are not reversing the linked listt only printing it in reverse order
    if(p == NULL){
        return;
    }
    Reverseprint(p->next);
    cout<<" "<<p->data;
}

void Reverse(struct node* p){
    struct node* head;
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    struct node* q = p->next;
    q->next = p;
    p->next=NULL;
}
struct node* Insert(struct node* head,int data){
    node *temp =new node();
    temp->data = data;
    temp->next= NULL;
    if(head == NULL)head = temp;
    else{
        node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
    }

int main(){
    struct node* head = NULL;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    print(head);
    Reverseprint(head);
    Reverse(head);
    print(head);
    return 0;
}       */

//ARRAY IMPLEMENTATION OF STACK
/*
#include <iostream>
using namespace std;
#define MAX_SIZE 101
#define f(i,n) for(int i=0;i<=n;i++)
int A[MAX_SIZE];
int top = -1;
void Push(int x){
    if(top == MAX_SIZE - 1){
        cout<<"Error: StackOverflow\n";
        return;
    }
    A[++top] = x;
}
void Pop(){
    if(top == -1){
        cout<<"ERROR: NO ELEMENT TO POP\n";
        return;
    }
    top--;
}
void Print(){
    cout<<"stack: ";
    f(i,top)cout<<A[i]<<" ";
    cout<<endl;
}
int main(){
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
    return 0;
}  

//___________________BALANCED_PARENTHESIS______________________//
#include <iostream>
#include <stack>
#include<map>
#include <algorithm>
#include <string>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    stack<char> S;
    map<char,char>B;
    B[')']='(';
    B['}']='{';
    B[']']='[';
    string r="";
    f(i,n){
        if(s[i]=='(' || s[i] == '{' || s[i] == '[')S.push(s[i]);
        else if(s[i]==')' || s[i] == '}' || s[i] == ']'){
            if(S.empty() || B[s[i]] != S.top()){
                r="false";
                break;
            }
            else S.pop();
        }
    }
    if(S.empty()==true && r=="")cout<<"True";
    else if(S.empty()==false || r=="false") cout<<"False";
    return 0;
} */

// BINARY SEARCH TREE(BST) - IMPLEMENTATION
#include<iostream>
#include<queue>
using namespace std;
 
struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

void LevelOrder(Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

//Function to visit nodes in Preorder
void Preorder(struct Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	cout<<root->data; // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout<<root->data;  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	cout<<root->data; // Print data
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
        return root;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

//To search an element in BST, returns true if element is found
bool Search(Node* root,char data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Preorder. 
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"\n";
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	//Print Nodes in Postorder
	cout<<"Postorder: ";
	Postorder(root);
	cout<<"\n";
    cout<<"levelorder: ";
    LevelOrder(root);
    cout<<endl;
    int num;
    cout<<"Enter node to be searched "<<endl;
    cin>>num;
}