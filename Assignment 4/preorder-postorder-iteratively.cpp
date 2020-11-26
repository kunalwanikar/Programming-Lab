/*  Implemented the complete program in Dev C++ using C++14 compiler
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #4
	Question Number 1
*/
#include<iostream>
#define MAXSIZE 9999

using namespace std;

bool var = 0;  //Variable to check of the stack is empty;


//Implemented a template class stack which takes X as the datatype. Here X xan be anything like int, float, double etc.
template<class X>

class stack{

	private:
		X arr[MAXSIZE];  //Initialize the array with the max size.
		int sp = -1;  //Initializing the stack pointer equal to -1 which denotes that initially the stack is empty.

	public:

		//push operation of stack is being implemented in this function.
		bool push(X a){
			if((sp+1)>=MAXSIZE){  //If the stack is full then it outputs stack overflow.
				cout<<"Stack Overflow";
				return false;
			}
			sp++;
			arr[sp] = a;  //Enters the element in to the stack
			return true;
		}

		//pop operation of stack is being implemented in this function.
		bool pop(){
			if(sp == -1){  //Checks if the stack is empty. If yes then pop operation cannot be performed hence return false.
			    sp = -1;
				return false;
			}

			arr[sp--] = 0;
			if(sp<-1){
			    sp = -1;
			}
			return true;
		}

		//top operation of stack is being implemented in this function, which returns the topmost element of the stack.
		X top(){
			if(sp == -1){  //This checks if the queue is underflow or not.
				var = 1;
				return NULL;
			}
			return arr[sp];
		}

		//empty operation of stack is being implemented in this function. Returns true if the stack is empty.
		bool empty(){
			if(sp==-1){
				return true;
			}
			else{
				return false;
			}
		}

		//full operation of stack is being implemented in this function. Returns true if the stacksize exceeds MAXSIZE.
		bool full(){
			if(sp+1>=MAXSIZE){  //Checks if the stack is full or not i.e. stack size reached the MAXSIZE.
				return true;
			}
			else{
				return false;
			}
		}

		//size operation of stack is being implemented in this function. Returns the size of the stack.
		int size(){
		    return sp+1;
		}

};


//Created the structure of a node we want to implement in the Binary Tree.
struct node{
	struct node* left;  //Stores the pointer to the left child.
	long double data;  //Stores the data contained in the node.
	struct node* right;  //Stores the pointer to the right child.
};

//This function is used to contruct the binary tree by taking input from the user interactively. 
//This takes the parent node(head node) as the input and then creates the right child and the left child(if they exist).
//After calling this function, we will finally obtain the binary tree given input by the user.
struct node* constructTree(struct node* parent){
	
	//Checks if the parent node is set to NULL. If yes then returns the parent node.
	if(parent == NULL){
		return parent;
	}

	parent->left = NULL;  //Initially set the left child of parent as NULL.
	parent->right = NULL;  //Initially set the right child of parent as NULL.

	long double numl,numr;  //These variables are used to take the node data as input for the leftchild and right child repectively.

	cout<<"Enter the left child of the "<<parent->data<<" node : ";
	cin>>numl;  //Takes the left node data as input from the user.

	
	//If the user enters -1 as the left node data then it is clear that its left child is NULL.
	//Else it creates a new node and enter the data in that node.
	if(numl!=-1){
		struct node *leftchild = new node();  //This creates the new leftchild node.
		parent->left = leftchild;  //Create a link from the parent's left to the new node.
		leftchild->data = numl;  //Enter the data given as input by the user in the newly node created.
	}

	constructTree(parent->left);  //Recursive call to constructTree() method to again check if there is any left or right child node to the current node.


	cout<<"Enter the right child of the "<<parent->data<<" node : ";
	cin>>numr;  //Takes the right node data as input from the user.

	//If the user enters -1 as the left node data then it is clear that its left child is NULL.
	//Else it creates a new node and enter the data in that node.
	if(numr!=-1){
		struct node *rightchild = new node();  //This creates the new rightchild node.
		parent->right = rightchild;  //Create a link from the parent's right to the new node.
		rightchild->data = numr;  //Enter the data given as input by the user in the newly node created.
	}
	constructTree(parent->right);   //Recursive call to constructTree() method to again check if there is any left or right child node to the current node.

	//After all the recursive calls we will be back to the root node which was given as input to the constructTree() function initially. 
	return parent;  //Hence we return that value.
}

//This function is used for computing the preorder of the binary tree iteratively.
//PREORDER follows the rule of Root-Left-Right.
//The implementation also shows the same that we first print the root data and then traverse the left node and then move to the right node.
void preorder(struct node *head){
	
	//This stack will be used to store the nodes which are not yet visited in the traversal of the tree.
	stack<node*> s;  //This is a stack which will hold the address of the node which is to be returned in the computation of preorder.
    
    //Checks if the head is NULL. If yes then we have reached the end of the binary tree hence return.
    if(head == NULL){
        return;
    }

    //This do while() loop checks whether the binary tree is completely traversed or not, and also checks if the stack is empty or not.
    do{

    	//Until we have a left node we will first print the node data and traverse the left node till we get a NULL value.
    	while(head!=NULL){

    		s.push(head);  //Here we push the current node in the stack.
    		cout<<head->data<<" ";  //As it is a preorder traversal hence we first print the data present in the root.
    		head = head->left;  //Again we move left until we dont find a NULL.
    	}

    	//Checks if the stack is not empty then pops the topmost element (the address of it).
    	if(!s.empty()){
    		head = s.top();  //Stores the topmost element in the head node.
    		s.pop();  //Pops the topmost element.
    		head = head->right;  //We move one step towards the right node of the current node.
    	}

    }while(!s.empty() || head!=NULL);

}


//This function is used for computing the postorder of the binary tree iteratively.
//POSTORDER follows the rule of Left-Right-Root.
//The implementation also shows the same that we first traverse the left node then move to the right node and then print the root data.
void postorder(struct node *head){

	//Checks if the head is NULL. If yes then we have reached the end of the binary tree hence return.
    if(head == NULL){
        return;
    }

    //For computing the postorder we need 2 stacks.
    //One stack will be used for knowing which element is currently being traversed and other stack for the visited nodes of the tree.
    stack<node*> s1,s2;
    s1.push(head);  //Push the root node in the stack.
    node* cur;  //This holds the node which is currently being traversed.

    // Run while first stack is not empty
    while (!s1.empty()) {
        // Popping an item from s1 and push it to s2.
       	cur = s1.top();
        s1.pop();
        s2.push(cur);

        // If left child of current node is available then we push left child of removed item to s1.
        if (cur->left){
            s1.push(cur->left);
        }

        // If right child of current node is available then we push right child of removed item to s1.
        if (cur->right){
            s1.push(cur->right);
        }
    }
    //Stack s2 stores the postorder of the binary tree.
    // Print all elements of second stack until it is empty.
    while (!s2.empty()) {
        cur = s2.top();  //Stores the topmost element in the cur node.
        s2.pop();  //Pops the topmost element.
        cout << cur->data << " ";
    }
}


//This function is used for printing the binary tree given as input by the user. It prints the inorder traversal of the binary tree.
//INORDER follows the rule of Left-Root-Right.
//The implementation also shows the same that we first print the root data and then traverse the left node and then move to the right node.
void display(struct node* head){
    //This stack will be used to store the nodes which are not yet visited in the traversal of the tree.
	stack<node*> s;  //This is a stack which will hold the address of the node which is to be returned in the computation of inorder.
    
    //Checks if the head is NULL. If yes then we have reached the end of the binary tree hence return.
    if(head == NULL){
        return;
    }

    //This do while() loop checks whether the binary tree is completely traversed or not, and also checks if the stack is empty or not.
    do{

    	//Until we have a left node we will traverse the left node till we get a NULL value.
    	while(head!=NULL){
    		s.push(head);  //Here we push the current node in the stack.
    		head = head->left;  //Again we move left until we dont find a NULL.
    	}

    	//Checks if the stack is not empty then pops the topmost element (the address of it) and stores it in the head node.
    	//Prints the data present in the head and traverses right.
    	if(!s.empty()){
    		head = s.top();  //Stores the topmost element in the head node.
    		s.pop();  //Pops the topmost element.
    		cout<<head->data<<" ";  //Prints the data of the head node.
    		head = head->right;  //Moves one step right to the head node.
    	}

    }while(!s.empty() || head!=NULL);
}


int main(){

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Programming Assignment #4"<<endl<<"Question Number : 1"<<endl;
	cout<<"======================================================================="<<endl<<endl;

	int num;  //This variable is used for storing the input data of the node.
	char decision; //flag for checking whether the user wants to exit the while loop.

 	//This is the main logic of the code where we call the preorder and postorder functions.
 	//This is a do while loop which continues until the user wants to stop the input.
	do{

        struct node* head = new node();  //This creates the root node of the tree.
        head->left = NULL;  //Initially sets the left child of the root node as NULL.
        head->right = NULL;  //Initially sets the right child of the root node as NULL.

        //Important : If the node does not have either of the child, then we enter that child as -1 which indicates the NULL value.
        cout<<"NOTE : If the node does not have a child, then enter that child as -1 which indiactes the NULL value."<<endl;
        cout<<"Enter the root node : ";
        cin>>num;  //Takes the root node as input.

        //This handles the corner case of when the root node is set to NULL.
        if(num == -1){
            cout<<"The tree you have entered is EMPTY as you've entered root node of tree as NULL."<<endl<<endl;
            cout<<"Do you want to enter the tree again? (y/n) : ";
            
            //Asks if the user wants to enter another tree with different root node.
            cin>>decision;  //Here user selects y/n on the basis if user wants to try a new tree or exit the while loop.
			
			if(decision == 'y'){  //If the user wants to try for a new tree then continue. Otherwise break from the loop.
				cout<<endl<<endl;
				continue;
			}
			else{
				cout<<endl<<endl;
				break;
			}
        }

        head->data = num;  //Sets the data part of the head node as the number given as input by the user.
        head = constructTree(head);  //This function creates the binary tree and returns the pointer to the head node in the head pointer of struct type.
        cout<<endl;
        cout<<"The tree(inorder) looks like : ";
        display(head);  //This displays the tree which the user have entered in inorder.
        cout<<endl<<endl;

        cout<<"PREORDER Traversal : ";
        preorder(head);  //This function will print the tree in PREORDER.
        cout<<endl<<endl;
        
        cout<<"POSTORDER Traversal : ";
        postorder(head);  //This function will print the tree in POSTORDER.
        cout<<endl<<endl;

        //Asks again if the user wants to try again for a different tree.
        cout<<"Do you want to enter another tree? (y/n) : ";
        cin>>decision;  //Here user selects y/n on the basis if user wants to perform more operations or exit the while loop.
		
		if(decision == 'y'){  //If the user wants try for a new tree then continue. Otherwise break from the loop.
			cout<<endl<<endl;
			continue;
		}
		else{
			cout<<endl<<endl;
			break;
		}

	}while(1);

	return 0;
}
