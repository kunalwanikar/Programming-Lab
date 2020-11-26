/*  Implemented the complete program in Dev C++ using C++14 compiler   
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #2
	Question Number 2 
*/
#include<iostream>
#define MAXSIZE 9999

using namespace std;

bool var = 0;  //Variable to check of the stack is empty;
int capacity;  //This variable takes the size of the queue as input.


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
				return -1;
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

	stack<double> s1;  //Declaring the stack 1 which takes input from the user and stores the queue elements.
	stack<double> s2;  //Declaring the stack 2 which is used for deleting the element from the queue.


//Menu function which displays several options to the user and makes the program interactive.
void menu(){
	cout<<endl;
	cout<<"What do you want to perform?"<<endl;
	cout<<"Press 1 for inserting elements into the queue."<<endl;
	cout<<"Press 2 for deleting the elements from the queue."<<endl;
	cout<<"Press 3 for exit"<<endl;
}


//This function is used for inserting the element into the queue.
void insert(double element){
    cout<<endl<<"Enter the element : ";
	cin>>element;  //Takes the element which is to be inserted
	s1.push(element);  //Push the element in the stack 1.

}

//This function is used to delete elements from the queue
void del(){
    if(s2.size() != 0){  //Checks if the stack is not empty.
        cout<<s2.top()<<" ";  //Printing the top element.
        s2.pop();
    }

	if(var){  //Checks if the stack/queue is empty or not. If yes then returns.

	    var = 0;  //Resets the value of var to be 0.
	    return;
	}

}


//Logic : I have initialized two stacks with MAXSIZE = 9999 and then I have taken the size of the queue as input from the user.
//Now considering this as a linear queue. I have either enqueued or dequeued elements from the stack according to the users instruction.
int main(){

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Assignment Number : Programming Assignment #2"<<endl<<"Question Number : 1"<<endl;
	cout<<"======================================================================="<<endl<<endl;


	double element;  //This variable is used for taking the input from user of what element is to be inserted. It stores the value which is to be inserted in the queue.

    char decision;  //Used for determining if the user wants to perform more operations or not.

	int num;  //It stores the number of elements to be inserted in the queue at one time.

	int option; //Used for choosing the option in the menu.

	int count = 0; //counts the number of elements in the queue.

	bool flag = 0;  //flag for checking whether the user wants the exit the do-while loop.

    cout<<"Enter the size of the queue to be implemented : ";
    cin>>capacity;  //Takes the size of the linear queue as input.


    //This is the main body of the program.
    //This contains the do-while loop which is used for knowing whether the user wants to perform more operations or not.
    //All the main functions like inserting in the queue and deleting from the queue is called here.
	do{
		menu();  //Call the menu and display all the possible choices to the user.
        cout<<"Choose any one option : ";
		cin>>option;  //The user selects the appropriate option here.

		switch(option){  //Switch statement for navigating to the correct option.

			case 1 : {  //This case is used for inserting the elements in to the queue.
				cout<<"How many elements do you want to insert? : ";
				cin>>num;  //Takes input from the user number of elements the user wants to input.
				cout<<endl<<"Insert the elements in order : "<<endl;
                if(num>capacity-s1.size()){  //Checks if the number of places empty in the queue (where elements can be stored) is less than the total number of entered elements by the user.
                    cout<<"Queue Overflow"<<endl;  //If the user inputs more elements than the number of places empty in the queue, then it terminates with a message of queue overflow.
                    cout<<"Space left in linear queue is for "<<capacity-s1.size()<<" elements."<<endl;
                    cout<<"So kindly enter a number less than "<<capacity-s1.size()<<"."<<endl;  //This displays the number of places empty in the queue.
				    break;
                }

				while(num--){
					insert(element);  //Calls the insert element functions which inserts the element in the queue.
				}
				break;
			}

			case 2 : {  //This case is used for deleting the elements from the queue.
				cout<<"How many elements do you want to delete? : ";
				cin>>num;  //The user inputs the number of elements he/she wants to delete.

				//Now here I transfer the complete elements from stack 1 to stack to inorder to maintain the queue property of FIFO.
				//This will make sure that when we pop from the stack 2 the correct order of elements outputted is in FIFO order.

				//Transferring stack 1 data to stack 2.
				while(!s1.empty()){
					element = s1.top();  //Storing the topmost element in the variable element.
					s1.pop();  //popping the element from stack 1.
					s2.push(element);  //Pushing the element in stack 2.
				}
				cout<<endl;
				cout<<"Deleted elements are : ";
				while(num--){

					if(!s2.empty()){
                        capacity--;  // Reducing the size of the queue inorder to maintain the linear queue property.
					}
					else{
                        cout<<endl;
                        cout<<"Queue Underflow"<<endl;
                        break;
					}
					del();  //Calling the del() function num times.

				}

				//After deleting the elements from the front of the queue, we transfer back all the remaining elements back to stack 1.
				//So now if we want to input more elements(incase space is available) then we can do again in the stack 1.

				//Tranferring stack 2 data to stack 1.
				while(!s2.empty()){  //Popping till stack 2 is empty.
					element = s2.top();  //storing the topmost element int the variable element.
					s2.pop();  //popping the element from stack 2.
					s1.push(element);  //Pushing it back in to stack 1.
				}
				break;
			}

			case 3 : {  //This case is used for exiting from the do-while loop.
				flag = 1;  //Sets the flag = 1 to exit from the do-while loop.
				break;
			}
		}

		if(flag){  //If the flag is set to 1 then do-while loop breaks.
			break;
		}

		cout<<endl;

		//The below code is used for displaying the elements of the queue.
		cout<<"The elements of the queue are : ";

		//Transfer the elements from stack 1 to stack 2.
		while(!s1.empty()){
			element = s1.top();
			s1.pop();
			s2.push(element);
		}

		//Print the elements of stack 2 and then push them back to stack 1.
		while(!s2.empty()){
			cout<<s2.top()<<" ";
			element = s2.top();
			s2.pop();
			s1.push(element);
		}

        //If stack 1 is empty then it prints that queue is empty.
        if(s1.empty()){
            cout<<"Queue is empty";
        }
        cout<<endl;

        //Checks if the user wants to perform more operations.
		cout<<"Do you want to perform more operations?(y/n) : ";
		cin>>decision;  //Takes the input the decision of the user.
		if(decision == 'y'){  //If the decision is yes then continues.
			continue;
		}
		else{  //Otherwise breaks.
			break;
		}
	}while(1);
}

