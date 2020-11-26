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

bool flag = 0;
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


//Logic : I have initialised three stacks named source, middle and destination. The total number of moves for n disks will be equal to 2^n-1.
//First i have checked whether the number of disks entered is odd or even. 
//I have started the counting of moves from zero and hence check for the remainder when divided by 3.
//Depending on these 2 factors, we then decide the move from S to D or S to M or M to D etc.
int main(){
	
	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Assignment Number : Programming Assignment #2"<<endl<<"Question Number : 2"<<endl;
	cout<<"======================================================================="<<endl<<endl;

	int disks;  //Used for storing the number of disks taken as input from the user.
	cout<<"There are three towers named as :"<<endl;
	cout<<"S : Source"<<endl<<"M : Middle (or auxillary)"<<endl<<"D : Destination"<<endl<<endl;
	cout<<"Enter the number of disks : ";
	cin>>disks;

	cout<<disks<<endl;
	
	stack<int> source;  //Source stack which initially contains all the disks arranged in proper fashion i.e. the highest number disk is at the bottom and least number is at the top.

	stack<int> middle;  //This is the auxillary stack which is used for storing the in between disks.
	
	stack<int> destination;  //This is the destination stack where the final disks will be arranged at the end.
	
	cout<<"Total number of moves = ";

	long long moves = (2<<(disks-1)) - 1;  //This variable stores the total number of moves.
	cout<<moves<<endl;

	for(long long i=disks; i>=1; i--){  //This loop stores the disks numbers in the source stack with the property of higher number of disk is kept below lower number disk.	
		source.push(i);
	}

	int element;  //This variable stores the popped element from source, middle or destination stack.

	int cno; //Indicates the case number.

	if(disks%2==1){  //Here we check if the number of disks is odd.

		for(long long i = 0 ; i<moves; i++){

			if(i%3 == 0){
				//source to destination or vice versa.
				if(source.top() == -1){  //If the source stack is empty then enter case number 1.
					cno = 1;  
				}
				else if(destination.top() == -1){  //If the destination stack is empty then enter case number 2.
					cno = 2;
				}
				else if(source.top()>destination.top()){  //If the topmost element of the source stack is greater than the topmost element of the destination stack then enter case number 3.
					cno = 3;
				}
				else{  //If the topmost element of the destination stack is greater than the topmost element of the source stack then enter case number 4.
					cno = 4;
				}

				switch(cno){  //Switches to the case number which is initialized by one of the above condition. 

					case 1 :{  //When the source stack is empty, we move the destination stacks topmost element to the source stack.
						element = destination.top();
				   	 	destination.pop();
				  	  	source.push(element);
				    	cout<<"Disk no. "<<element<<" moved from D to S"<<endl;
				    	break;
					}

					case 2 :{  //When the destination stack is empty, we move the source stacks topmost element to the destination stack.
						element = source.top();
				    	source.pop();
				    	destination.push(element);
				    	cout<<"Disk no. "<<element<<" moved from S to D"<<endl;
				    	break;
					}

					case 3 :{  //When the source stack contains the element which is greater than the element of the destination stack then we move the lower numbered disk from destionation to source.
						element = destination.top();
				    	destination.pop();
				    	source.push(element);
				    	cout<<"Disk no. "<<element<<" moved from D to S"<<endl;
				    	break;
					}
					case 4 :{  //When the destination stack contains the element which is greater than the element of the source stack then we move the lower numbered disk from source to destination.
					    element = source.top();
				    	source.pop();
				    	destination.push(element);
				    	cout<<"Disk no. "<<element<<" moved from S to D"<<endl;	
				    	break;				
					}
				}
				
			}
			else if(i%3 == 1){  
				//source to middle or vice versa
				if(source.top() == -1){  //If the source stack is empty then enter case number 1.
					cno = 1;
				}
				else if(middle.top() == -1){  //If the middle stack is empty then enter case number 2.
					cno = 2;
				}
				else if(source.top()>middle.top()){  //If the topmost element of the source stack is greater than the topmost element of the middle stack then enter case number 3.
					cno = 3;
				}
				else{  //If the topmost element of the middle stack is greater than the topmost element of the source stack then enter case number 4.
					cno = 4;
				}

				switch(cno){  //Switches to the case number which is initialized by one of the above condition. 

					case 1 :{  //When the source stack is empty, we move the middle stacks topmost element to the source stack.
				    element = middle.top();
				    middle.pop();
				    source.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to S"<<endl;
				    break;
					}

					case 2 :{  //When the middle stack is empty, we move the source stacks topmost element to the middle stack.
					element = source.top();
				    source.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from S to M"<<endl;
				    break;
					}

					case 3 :{  //When the source stack contains the element which is greater than the element of the middle stack then we move the lower numbered disk from middle to source.
				    element = middle.top();
				    middle.pop();
				    source.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to S"<<endl;
				    break;
					}

					case 4 :{  //When the middle stack contains the element which is greater than the element of the source stack then we move the lower numbered disk from source to middle.
					element = source.top();
				    source.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from S to M"<<endl;
				    break;
					}
				}

			}
			else if(i%3 == 2){
				//middle to destination or vice versa

				if(middle.top() == -1){  //If the middle stack is empty then enter case number 1.
					cno = 1;
				}
				else if(destination.top() == -1){  //If the destination stack is empty then enter case number 2.
					cno = 2;
				}
				else if(middle.top()>destination.top()){  //If the topmost element of the middle stack is greater than the topmost element of the destination stack then enter case number 3.
					cno = 3;
				}
				else{  //If the topmost element of the destination stack is greater than the topmost element of the middle stack then enter case number 4.
					cno = 4;
				}

				switch(cno){  //Switches to the case number which is initialized by one of the above condition. 

					case 1 :{  //When the middle stack is empty, we move the destination stacks topmost element to the middle stack.
					element = destination.top();
				    destination.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from D to M"<<endl;
				    break;
					}

					case 2 :{  //When the destination stack is empty, we move the middle stacks topmost element to the destination stack.
					element = middle.top();
				    middle.pop();
				    destination.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to D"<<endl;
				    break;
					}

					case 3 :{  //When the middle stack contains the element which is greater than the element of the destination stack then we move the lower numbered disk from destination to middle.
					element = destination.top();
				    destination.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from D to M"<<endl;
				    break;
					}

					case 4:{  //When the destination stack contains the element which is greater than the element of the middle stack then we move the lower numbered disk from middle to destination.
					element = middle.top();
				    middle.pop();
				    destination.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to D"<<endl;
				    break;
					}
				}
			}
		}
	}
	else{
		for(long long i = 0 ; i<moves; i++){
			if(i%3 == 0){
				//source to middle or vice versa
				if(source.top() == -1){  //If the source stack is empty then enter case number 1.
					cno = 1;
				}
				else if(middle.top() == -1){  //If the middle stack is empty then enter case number 2.
					cno = 2;
				}
				else if(source.top()>middle.top()){  //If the topmost element of the source stack is greater than the topmost element of the middle stack then enter case number 3.
					cno = 3;
				}
				else{  //If the topmost element of the middle stack is greater than the topmost element of the source stack then enter case number 4.
					cno = 4;
				}

				switch(cno){  //Switches to the case number which is initialized by one of the above condition. 

					case 1 :{  //When the source stack is empty, we move the middle stacks topmost element to the source stack.
					element = middle.top();
				    middle.pop();
				    source.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to S"<<endl;
				    break;
					}

					case 2 :{  //When the middle stack is empty, we move the source stacks topmost element to the middle stack.
					element = source.top();
				    source.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from S to M"<<endl;
				    break;
					}

					case 3 :{  //When the source stack contains the element which is greater than the element of the middle stack then we move the lower numbered disk from middle to source.
					element = middle.top();
				    middle.pop();
				    source.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to S"<<endl;
				    break;
					}

					case 4 :{  //When the middle stack contains the element which is greater than the element of the source stack then we move the lower numbered disk from source to middle.
					element = source.top();
				    source.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from S to M"<<endl;
				    break;
					}
				}
			}
			else if(i%3 == 1){
				//source to destination or vice versa
				if(source.top() == -1){  //If the source stack is empty then enter case number 1.
					cno = 1;
				}
				else if(destination.top() == -1){  //If the destination stack is empty then enter case number 2.
					cno = 2;
				}
				else if(source.top()>destination.top()){  //If the topmost element of the source stack is greater than the topmost element of the destination stack then enter case number 3.
					cno = 3;
				}
				else{  //If the topmost element of the destination stack is greater than the topmost element of the source stack then enter case number 4.
					cno = 4;
				}

				switch(cno){  //Switches to the case number which is initialized by one of the above condition. 

					case 1 :{  //When the source stack is empty, we move the destination stacks topmost element to the source stack.
					element = destination.top();
				    destination.pop();
				    source.push(element);
				    cout<<"Disk no. "<<element<<" moved from D to S"<<endl;
				    break;
					}

					case 2 :{  //When the destination stack is empty, we move the source stacks topmost element to the destination stack.
					element = source.top();
				    source.pop();
				    destination.push(element);
				    cout<<"Disk no. "<<element<<" moved from S to D"<<endl;
				    break;
					}

					case 3:{  //When the source stack contains the element which is greater than the element of the destination stack then we move the lower numbered disk from destination to source.
					element = destination.top();
				    destination.pop();
				    source.push(element);
				    cout<<"Disk no. "<<element<<" moved from D to S"<<endl;
				    break;
					}

					case 4 :{    //When the destination stack contains the element which is greater than the element of the source stack then we move the lower numbered disk from source to destination.
					element = source.top();
				    source.pop();
				    destination.push(element);
				    cout<<"Disk no. "<<element<<" moved from S to D"<<endl;
				    break;
					}
				}
			}
			else if(i%3 == 2){
				//middle to destination or vice versa.
				if(destination.top() == -1){  //If the destination stack is empty then enter case number 1.
					cno = 1;
				}
				else if(middle.top() == -1){  //If the middle stack is empty then enter case number 2.
					cno = 2;
				}
				else if(destination.top()>middle.top()){  //If the topmost element of the destination stack is greater than the topmost element of the middle stack then enter case number 3.
					cno = 3;
				}
				else{  //If the topmost element of the middle stack is greater than the topmost element of the destination stack then enter case number 4.
					cno = 4;
				}

				switch(cno){  //Switches to the case number which is initialized by one of the above condition. 
					
					case 1 :{  //When the destination stack is empty, we move the middle stacks topmost element to the destination stack.
				    element = middle.top();
				    middle.pop();
				    destination.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to D"<<endl;
				    break;
					}

					case 2 :{  //When the middle stack is empty, we move the destination stacks topmost element to the middle stack.
					element = destination.top();
				    destination.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from D to M"<<endl;
				    break;
					}

					case 3 :{  //When the destination stack contains the element which is greater than the element of the middle stack then we move the lower numbered disk from middle to destination.
					element = middle.top();
				    middle.pop();
				    destination.push(element);
				    cout<<"Disk no. "<<element<<" moved from M to D"<<endl;
				    break;
					}
					case 4 :{  //When the middle stack contains the element which is greater than the element of the destination stack then we move the lower numbered disk from destionation to middle.
					element = destination.top();
				    destination.pop();
				    middle.push(element);
				    cout<<"Disk no. "<<element<<" moved from D to M"<<endl;
				    break;
					}
				}
			}
		}
	}
}
