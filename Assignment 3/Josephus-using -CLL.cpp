/*  Implemented the complete program in Dev C++ using C++14 compiler
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #3
	Question Number 1
*/
#include<iostream>

using namespace std;

//Created the structure of a node we want to implement in the circular linked list.
struct node{
	int person;  //takes integer value as the name of the person.
	struct node* next;  //Stores the link to the next node of the linked list.
};

int main(){

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Assignment Number : Programming Assignment #3"<<endl<<"Question Number : 1"<<endl;
	cout<<"======================================================================="<<endl<<endl;

	int n;  //This variable holds the number of person standing in the circle.

	int k;  //This variable holds the skip number which is being agreed upon previously.



	char decision;  //Used for knowing if the user wants to perform more operations or not.


	//The main logic of the question lies in this do while loop. I have first taken input n and k values and the names of the person from the user.
	//Now I have created a circular linked list out of those names. Creation of circular linked list is given in detail in the further part of the code.
	//After creation, I have traversed the list from the head node till k-1 nodes and then deleted the kth node.
	//After deletion I have stored the location of the kth node in separate pointer and updated the next(link) value of the (k-1)th node to the next value of kth node.
	//Now I have deleted the kth node. This is how I proceeded in the program.
	do{
		cout<<"Enter the number of persons standing in the circle i.e. the value of n : ";
		cin>>n;  //This will take the number of persons standing in circle.
		cout<<endl;

		int name = 1;  //This variable takes the names/number of the person and stores in the person block of the linked list.

		//If suppose the user enters zero person in circle then it will output that the entered input is incorrect.
    	if(n <= 0){
    	    cout<<"Your input is incorrect, please enter valid number of persons "<<endl;
    	    cout<<"Do you want to enter the input again? Enter y/n : ";
			cin>>decision;  //Here user selects y/n on the basis if user wants to perform more operations or exit the while loop.
			if(decision == 'y'){  //If the user wants to enter a valid input then continue. Otherwise break from the loop.
				continue;
			}
			else{
				break;
			}
	    }

		cout<<"Enter the skip number agreed upon advance i.e. the value of k : ";
		cin>>k;  //This will take the number agreed upon advance to kill the person.
		cout<<endl;


		node* head = NULL;  //Initializing the head node of the linked list to be NULL.

		node* last = NULL;  //This is the pointer to the last node of the linked list. This will help in adding the node at the end.

		//In this for loop I created a linked list by adding the nodes at the end of the list.
		for(int i=0; i<n; i++){
			node* newptr = new node();  //Created a new node using this line and stored the address of this node in the pointer of node type named newptr.

			last = head;  //The last pointer stores the head of the linked list initially.

			newptr->person = name++;  //Stores the name of the person in the linked list.

			newptr->next = NULL;  //Initializing the link of the node to NULL. This is just a good practice to initialize it with NULL otherwise it may store some garbage value.

			if(head == NULL){  //Checking if there is no node in the linked list. In such case point the head pointer towards the new node.
				head = newptr;  //Initializing head to new node.
				continue;
			}

			//This is used for inserting the node at the end.
			while(last->next){
				last = last->next;  //The last pointer now points to the last node of the linked list.
			}

			last->next = newptr;  //Adding the new node at the end of the linked list.
		}


		int num = n;  //Storing the value of n in the variable num which will be used for checking if the number of person remaining in the list is greater than 1.

		node* cur_per = head;  //This pointer to a node is used for pointing towards the current person in the linked list.

    	//Suppose the user enters the value of K equal to zero then each person should kill itself and pass the knife to the person next to it.
    	//Hence to implement this logic, the below code is written.
    	if(k==0){
    	    while(num != 1 && cur_per->next){  //Checks if next person is present or not and if the remaining number of person is greater than 1.
    	        cout<<"Person "<<cur_per->person<<" Kills person "<< cur_per->person<<endl;  //The person kills himself as k = 0.
    	        cur_per = cur_per->next;  //The knife passes to next person.
    	        num--;  //Decrements the number of person present in the list.
    	    }
    	    cout<<endl;
			cout<<"Number of links traversed = "<<n-1<<endl;  //The number of links traversed will always be equal to n-1 as the person kills himself and passes the knife by traversing exactly one link.
    		cout<<"Winner is person "<<cur_per->person;  //Winner is the last person as he is the only one left in the list.
			cout<<endl<<endl;

			cout<<"Do you want to perform more such operations? Enter y/n : ";
			cin>>decision;  //Here user selects y/n on the basis if user wants to perform more operations or exit the while loop.
			if(decision == 'y'){  //If the user wants to perform more operations on a new list then continue. Otherwise break from the loop.
				cout<<endl<<endl;
				continue;
			}
			else{
				cout<<endl<<endl;
				break;
			}
			cout<<endl<<endl;
    	}

    	//Traversing the current person pointer till we reach the last node.
		while(cur_per->next){
			cur_per = cur_per->next;
		}
		cur_per->next = head;  //Make the last node link point towards the head. This makes the linked list CIRCULAR.
		cur_per = cur_per->next;  //Now the current person pointer is pointing towards the first node/person of the list.

    	node* ptr = head;  //This pointer will be used for traversing the list one by one.

		int linkstraversed = 0;  //Stores the number of links traversed in the complete problem.

		int ktrav = k-1;  //Used for deleting the kth node from the linked list. This will be used for traversing (k-1) nodes and then deleting the kth node.

		//The main logic of counting the number of links traversed and the uodation of the circular linked list takes place in the below while loop.
		//If the size of the current linked list is greater than k then we traverse k-1 nodes and delete the kth person.
		//Else it checks if the k modulo number of elements in the linked list is zero or not and implements accordingly.
		while(num != 1 && ptr->next){  //Checks if next person is present or not and if the remaining number of person is greater than 1.

			if(num>k){  //If the size of linked list is greater than the skip number i.e. k.
				ktrav = k-1;  //Initializing ktrav to k-1 as we need to move only k-1 nodes.
				cout<<"Person "<<ptr->person<<" Kills person ";  //Prints the person which is killing.

				while(ktrav-- && ptr->next){  //Checking if the next person is present or not.
					ptr = ptr->next;  //Traverses k-1 nodes at the end of this loop.
					linkstraversed++;  //Incrementing the variable as we have traversed the link of the node.
				}

				cout<<ptr->next->person<<endl; //Prints the person which is being killed.
				cur_per = ptr->next;  //Stores the kth node address.
				linkstraversed++;  //As we accessed the next node hence incrementing the count of links traversed.
				ptr->next = ptr->next->next;  //Increments the (k-1)the node address to (k+1)th node, so that it points towards the next node of the kth node.
				cur_per->next = NULL;   //removing the pointer of the kth node.
				ptr = ptr->next;
				linkstraversed++;  //As we accessed the next node hence incrementing the count of links traversed.
				num--;
			}

			if(num<=k){  //If the size of the linked list becomes less than k at any moment while running the program, this condition becomes true.
                ktrav = (k%num);  //Initializing ktrav to k-1 as we need to move only k-1 nodes.
				cout<<"Person "<<ptr->person<<" Kills person ";  //Prints the person which is killing.
				
				//Suppose k is divisible by the size of the linked list, then we kill the person who has the knife.
				if(k%num == 0){ 
                    ktrav = k-1;  //Initializing ktrav to k-1 as we need to move only k-1 nodes.
                    while(ktrav-- && ptr->next){  //Checking if the next person is present or not.
                        ptr = ptr->next;  //Traverses k-1 nodes at the end of this loop.
                    }
				}
				else{  //Else we take a mod and traverse k modulo number of elements in linked list minus 1 and then delete the next element after that.
                    while(ktrav!=1 && ptr->next){  //Checking if the next person is present or not.
                        ptr = ptr->next;  //Traverses k-1 nodes at the end of this loop.
                        linkstraversed++;  //Incrementing the variable as we have traversed the link of the node.
                        ktrav--;
                    }
                linkstraversed++;  //We have traversed ((k%num) - 1) links but the last link is remaining which will be traversed by this line.
				}

				cout<<ptr->next->person<<endl; //Prints the person which is being killed.
				cur_per = ptr->next;  //Stores the kth node address.
				ptr->next = ptr->next->next;  //Increments the (k-1)the node address to (k+1)th node, so that it points towards the next node of the kth node.
				cur_per->next = NULL;  //removing the pointer of the kth node.
				ptr = ptr->next;
				linkstraversed++;  //As we accessed the next node hence incrementing the count of links traversed.
				num--;
			}

		}



		cout<<endl;
		cout<<"Number of links travered = "<<linkstraversed<<endl;  //Prints the number of links traversed.
    	cout<<"Winner is person "<<ptr->person;  //Prints the winner i.e. the person who is left at the end.
		cout<<endl<<endl;

		cout<<"Do you want to perform more such operations? Enter y/n : ";
		cin>>decision;   //Here user selects y/n on the basis if user wants to perform more operations or exit the while loop.
		if(decision == 'y'){  //If the user wants to perform more operations on a new list then continue. Otherwise break from the loop.
			cout<<endl<<endl;
			continue;
		}
		else{
			cout<<endl<<endl;
			break;
		}

		cout<<endl<<endl;

	}while(1);

	return 0;
}
