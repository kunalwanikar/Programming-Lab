/*  Implemented the complete program in Dev C++ using C++14 compiler
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #3
	Question Number 2
*/
#include<iostream>

using namespace std;

//Created the structure of a node we want to implement in the linked list.
struct node{
	long double num;  //takes float value and stores in the data part of the linked list.
	struct node* next;  //Stores the link to the next node of the linked list.
};


//This function is used to merge the two halves of the list we earlier divided in to two parts. This compares the numbers of the two halves and does the actual sorting work.
//If the first half becomes NULL then returns the second half and vice versa.
node* merge(node* firsthalf, node* secondhalf)
{
    node* mergedlist = NULL;  //Used for storing the intermediate result i.e. the sorted portion of the two halves.

    if (firsthalf == NULL)  //If the firsthalf list is NULL then the second half is already sorted.
        return (secondhalf);  //Hence we return the second half.

    else if (secondhalf == NULL)  //If the secondhalf list is NULL then the first half is already sorted.
        return (firsthalf);  //Hence we return the first half.

    if (firsthalf->num >= secondhalf->num) {  //If the number in first half list has higher number than second half.
    	mergedlist = secondhalf;  //We store the intermediate result in the mergedlist pointer.
        mergedlist->next = merge(firsthalf, secondhalf->next);  //And recursively check for the next element of second half.

    }

    else if(firsthalf->num < secondhalf->num){  //If the number in second half list has higher number than first half.
        mergedlist = firsthalf;  //We store the intermediate result in the mergedlist pointer.
        mergedlist->next = merge(firsthalf->next, secondhalf);  //And recursively check for the next element of first half.
    }

    return (mergedlist);  //Returns the final merged list after the sorting is done.
}


//Here we take the address of the head pointer as a parameter and firstly check if it is NULL or not.
//If it is NULL then directly return the control back to the main function.
//Else we divide the list into exactly 2 parts of equal size (If size of list is even. If not then we one list with l elements and other with l+1 elements).
//After this we recursively call the mergesort function on the first half and second half lists to sort them recursively.
//The sorting is done by dividing the halves till each half does not have a single element. now sort each element recursively using the merge() function.
//After this the merge function merges the two sorted halves and returns the head pointer to the sorted list.
//This is how the merge sort is working in my program.
void mergesort(node** headptr){

    node* head = *headptr;  //Store the value of the head of the original list in the newly created head pointer.

	if ((head == NULL) || (head->next == NULL)) {  //Suppose the list has zero or one element then control goes back to main function.
        return;
    }

	node* firsthalf = NULL;  //Set the initial first half list as NULL.
	node* secondhalf = NULL;  //Set the intital second half list as NULL.


	//Here we are dividing the original linked list in to two parts namely firsthalf and secondhalf and recursively sorting the two halves in order to get a sorted list.
	//So for doing that I created two pointers slow and fast.
	//The slow pointer moves only one step where as the fast pointer moves two steps hence we get the node which is the middle of the linked list by taking into consideration the next pointer of slow.
	node* slow = head;  //Initially the slow pointer points towards the head.
	node* fast = head->next;  //Initially the fast pointer towards the next location after head.

	//Checking if the linked list does not end.
	//If we get that either of fast or fast->next is NULL then definitely the list will end and the next of slow pointer will be the middle element.
	while(fast && fast->next){
		fast = fast->next->next;  //Incrementing by two steps.
		slow = slow->next;  //Incrementing by only one step.
	}

	firsthalf = head;  //The firsthalf will start from head till the slow pointer.
	secondhalf = slow->next;  //The second half will start from the next of slow pointer till the end of the linked list.
	slow->next = NULL;  //Set the ending of the first half to be NULL.

	//Now here we are again recursively calling the mergesort function for the first half and second half so that they again get divided till we get each list of size 1 or 2.
	mergesort(&firsthalf);
	mergesort(&secondhalf);

	*headptr = merge(firsthalf,secondhalf);  //After they are sorted merging the result and storing the updated result in the main original list.
	return;
}

int main(){

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Assignment Number : Programming Assignment #3"<<endl<<"Question Number : 2"<<endl;
	cout<<"======================================================================="<<endl<<endl;


    int num_of_ele;  //Used for storing the number of elements to be stored in the linked list.

    cout<<"Enter the number of elements which are to be sorted : ";

    cin>>num_of_ele;
    cout<<endl;

    //Suppose the user entered the number of elements as 0 then the list is already sorted. Hence it gives output to enter a valid number of elements.
    if(num_of_ele <= 0){
        cout<<"List contains zero or less elements. Enter a valid input"<<endl;
        return 0;
    }

    cout<<"Enter the elements to be inserted in the linked list"<<endl<<endl;

    node* head = NULL;  //Initializing the head node of the linked list to be NULL.

	node* last = NULL;  //This is the pointer to the last node of the linked list. This will help in adding the node at the end.

    long double number;  //Used for taking input the number which the user entered.

    //In this for loop I created a linked list by adding the nodes at the end of the list.
	for(int i=0; i<num_of_ele; i++){
		node* newptr = new node();  //Created a new node using this line and stored the address of this node in the pointer of node type named newptr.
		cout<<"Enter the "<<i+1<<" number : ";
        cin>>number;
        cout<<endl;
		newptr->num = number;  //Stores the number entered by the user in the linked list.

		newptr->next = NULL;  //Initializing the link of the node to NULL. This is just a good practice to initialize it with NULL otherwise it may store some garbage value.

		if(head == NULL){  //Checking if there is no node in the linked list. In such case, point the head pointer towards the new node. This is the first node of the linked list.
			head = newptr;  //Initializing head to new node.
			continue;
		}

		last = head;  //The last pointer stores the head of the linked list initially.

		//This is used for inserting the node at the end.
		while(last->next){
			last = last->next;  //The last pointer now points to the last node of the linked list.
		}

		last->next = newptr;  //Adding the new node at the end of the linked list.
	}

	mergesort(&head);  //Calling the mergesort function by passing the address of head as the the reference pointer to the mergesort function.

	cout<<"The list after sorting looks like : "<<endl;

    node* ptr = head;  //ptr pointer for traversing the linked list till the end.

	while(ptr){  //Checking if the list is not NULL. If not then print the element.
		cout<<ptr->num<<"  ";  //Printing the sorted list.
		ptr = ptr->next;  //Incrementing the pointer.
	}
	cout<<endl<<endl;
    return 0;
}


