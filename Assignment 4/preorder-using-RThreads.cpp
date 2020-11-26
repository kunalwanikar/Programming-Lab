/*  Implemented the complete program in Dev C++ using C++14 compiler
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #4
	Question Number 2
*/
#include<iostream>
#define MAXSIZE 9999

using namespace std;


//Created the structure of a node we want to implement in the Binary Tree.
struct node{
	struct node* left;  //Stores the pointer to the left child.
	long double data;  //Stores the data contained in the node.
	struct node* right;  //Stores the pointer to the right child.
	bool thread; //This strores the right thread.
};

node* ptr[MAXSIZE];  //This array holds the address of the preorder successor all the nodes of the tree.
int i = 1;  //This is used for keeping track the size of the ptr array.
int size = 1;  //This variable holds the size of the binary tree. Initially size is set to 1 as only root node is present.

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
		size++;  //Increases the size of the tree whenever a new node is being added.
		ptr[i] = leftchild;  //This helps us to maintain the preorder successor of the leftchild node.
    	i++;  //Increments the pointer of the ptr array.
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
		size++;  //Increases the size of the tree whenever a new node is being added.
		ptr[i] = rightchild;  //This helps us to maintain the preorder successor of the rightchild node.
    	i++;  //Increments the pointer of the ptr array.
	}
	constructTree(parent->right);   //Recursive call to constructTree() method to again check if there is any left or right child node to the current node.

	//After all the recursive calls we will be back to the root node which was given as input to the constructTree() function initially.
	return parent;  //Hence we return that value.
}


//This function is used for computing the preorder of the binary tree iteratively.
//PREORDER follows the rule of Root-Left-Right.
//The implementation also shows the same that we first print the root data and then traverse the left node and then move to the right node.
//This is done without using recursion and stack.
void preorder(struct node* head){
	node* cur = head;  //Temporary pointer which stores the head node address.

    while(cur!=NULL)  //Traverse until the end of the tree.
    {
        cout<<cur->data<<" ";  //As it is preorder, hence print the node and then proceed.

        if(cur->left!=NULL){  //If the left node is not NULL then traverse that node.
            cur=cur->left;
        }

        else if(cur->thread==1){  //If left node is NULL then check if the thread of that node is equal to 1. If yes then there is a right child to it hence move 1 node to the right.
            cur=cur->right;
        }

        else  //If no then do the following logic.
        {
            while(cur->right!=NULL && cur->thread==0){  //checks if right thread exists.
                cur=cur->right;
                cout<<cur->data<<" ";  //Print the data in the current node.
            }

            if(cur->right == NULL){  //This is for the last node
            	break;
            }
            else{  //Otherwise do this.
                cur=cur->right;
            }

        }
    }
}





int main(){
	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Programming Assignment #4"<<endl<<"Question Number : 2"<<endl;
	cout<<"======================================================================="<<endl<<endl;


	int num;  //This variable is used for storing the input data of the node.

	char decision; //flag for checking whether the user wants to exit the while loop.

 	//This is the main logic of the code where we call the preorder and postorder functions.
 	//This is a do while loop which continues until the user wants to stop the input.
	do{

        struct node* head = new node();  //This creates the root node of the tree.
        ptr[0] = head;
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

			if(decision == 'y'){  //If the user wants to perform more operations on a new list then continue. Otherwise break from the loop.
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
        cout<<"The Binary Tree has been constructed along with the preorder threads";
        cout<<endl<<endl;

        bool flag = 0;  //Checks if the thread value should be set to 0 or 1.

        
        
        //In this we are setting up the preorder succesors of all the nodes of the tree.
        //We will run the loop from the head node till thelast 2nd node as we know that for the last node successor does not exist.
        for(int i=0;i<size-1;i++){

   			if(!(ptr[i]->right)){  //If the right node exists then set the flag to 1.
   	 			
   	 			flag = 1;  
   	 			ptr[i]->right = ptr[i+1];  //Set the right pointer of current node as preorder successor.
   	 			
   	 			
			}
			if(flag){  //If flag is 1 then set the thread as 1 because we have updated the link of that node.
				ptr[i]->thread=1;
				flag = 0;
			}
			else{  //Else keep the thread as 0.
				ptr[i]->thread=0;
			}

	   }


        cout<<"PREORDER Traversal using preorder threads: ";
        preorder(head);  //This function will print the tree in PREORDER using preorder threads.
        cout<<endl<<endl;


        //Asks again if the user wants to try again for a different tree.
        cout<<"Do you want to enter another tree? (y/n) : ";
        cin>>decision;  //Here user selects y/n on the basis if user wants to perform more operations or exit the while loop.

		if(decision == 'y'){  //If the user wants to try for another tree then continue. Otherwise break from the loop.
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
