//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

void swap(int* a, int* b )
{   
    int t = *a;
    *a = *b;
    *b = t;
}


// } Driver Code Ends
/* a Node of the doubly linked list */


/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/
class Solution{
public:
    Node* partition(Node *l, Node *h){
        Node* pivot = l;
        Node *i = l, *j = h;
        bool flag = false;
        
        while(!flag) {
            while(i != NULL && i->data <= pivot->data){
                if(i == j) flag = true;
                i = i->next;
            }
            
            while(j != NULL && j->data > pivot->data){
                if(i == j) flag = true;
                j = j->prev;
            }
            
            if(!flag)
                swap(i->data,j->data);
        }
        
        if(flag){
            swap(pivot->data, j->data);
        }
        
        return j;
    }
};

//{ Driver Code Starts.

void _quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Solution ob;
        struct Node *p = ob.partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(struct Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

 
/* Driver program to test above function */
int main()
{
    int t,x,n,i;
    scanf("%d",&t);
    while(t--)
    {
        /* Start with the empty list */
        struct Node *p,*temp,*head = NULL;
        scanf("%d",&n);
        scanf("%d",&x);
        head=new Node(x);
        p=head;
        for(i=0;i<n-1;i++){
            scanf("%d",&x);
            /* Let us create the doubly linked list 10<->8<->4<->2 */
        	temp=new Node(x);
        	p->next=temp;
        	temp->prev=p;
            p=p->next;
        }
    
    //printList(head); 
    /* delete Nodes from the doubly linked list */
	
    quickSort(head);
  
    /* Modified linked list will be NULL<-8->NULL */
    printList(head);           
    while(head->next!=NULL)
    {
	  temp=head;
	  head=head->next;
	  free(temp);
	}
	  free(head);
	}
    return 0;
}

// } Driver Code Ends