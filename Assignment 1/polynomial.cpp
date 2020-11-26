/*  Implemented the complete program in Dev C++ using C++14 compiler   
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #1		 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//This is the Menu functions which invokes to make the program interactive
void menu(){
	cout<<"This is Menu"<<endl;
	cout<<"What do you want to perform?"<<endl;
	cout<<"Press 1 for Adding a polynomial (Overloaded += operator)"<<endl;
	cout<<"Press 2 for Adding two polynomials (Overloaded + operator)"<<endl;
	cout<<"Press 3 for subtracting a polynomial (Overloaded -= operator)"<<endl;
	cout<<"Press 4 for subtracting two polynomials (Overloaded - operator)"<<endl;
	cout<<"Press 5 for multiplying a constant to the polynomial (Overloaded *= operator)"<<endl;
	cout<<"Press 6 for calculating the value of polynomial (Implemented at() function)"<<endl;
	cout<<"Press 7 for exit"<<endl<<endl;
}

//sec() is the function which sorts the vector in descending order of the exponents.
bool sec(const pair<double,double> &x, const pair<double,double> &y){
	return (x.second>y.second);
}
//Implemented class Poly with several functions and operators.
class Poly{
	public :

		double coefficient;
		double exponent;
		vector<pair<double,double> > result; //This is the vector of pairs which stores the polynomial whenever we add or subtract any other polynomial.
		
		
		//Constructor which takes coefficient and exponent as parameters and initializes it in class variables.
		Poly(double coeff, double expo){
			coefficient = coeff;
			exponent = expo;
		}
        
        //Contructor for initializing the initial object of the class Poly so that it does not store any garbage value.
        Poly(){
            coefficient = 0;
            exponent = 0;
        }
        
        //Overloaded + operator to add two polynomials.
        Poly operator +(Poly p1){
			Poly temp;        //Created a temporary polynomial which stores the result equation which we have to finally return and store.
			bool flag = 0;      //Boolean variable to check if the term is already added in the result equation or not.
			temp.result.swap(result);
			for(vector<pair<double,double> > :: iterator it = temp.result.begin(); it!= temp.result.end(); ++it){
			    if(it->second == p1.exponent){
			        it->first+=p1.coefficient;
			        flag=1;      //this is set to 1 so that we could know that the term with this exponent is already being added to the resulting polynomial.
			    }
			}
			if(!flag){
			    temp.result.push_back(make_pair(p1.coefficient,p1.exponent));    //If the term is not added then we push in to the result vector.
			}
			return temp;  //return the temp polynomial. This will return to the object we have created in the main function
			
		}
        
        //Overloaded += operator to add a polynomial to the result.
		Poly operator +=(Poly p1){
		    bool flag = 0;    //Boolean variable to check if the term is already added in the result equation or not.
			for(vector<pair<double,double> > :: iterator it = result.begin(); it!=result.end(); it++){
			    if(it->second == p1.exponent){
			        it->first += p1.coefficient;
			        flag = 1;     //this is set to 1 so that we could know that the term with this exponent is already being added to the resulting polynomial.
			    }
			}
			if(!flag){
			    result.push_back(make_pair(p1.coefficient,p1.exponent));  //If the term is not added then we push in to the result vector.
			}
		    return *this;
		}


        //Overloaded - operator to subtract two polynomials.
        Poly operator -(Poly p1){
			Poly temp;      //Created a temporary polynomial which stores the result equation which we have to finally return and store.
			bool flag = 0;   //Boolean variable to check if the term is already added in the result equation or not.
			temp.result.swap(result);
			for( vector<pair<double,double> > :: iterator it = temp.result.begin(); it!= temp.result.end(); ++it){
			    if(it->second == p1.exponent){
			        it->first-=p1.coefficient;
			        flag=1;       //this is set to 1 so that we could know that the term with this exponent is already being added to the resulting polynomial.
			    }
			}
			if(!flag){
			    temp.result.push_back(make_pair(-p1.coefficient,p1.exponent));  //If the term is not subtracted then we push in to the result vector.
			}
			return temp;
			
		}
        
        
        //Overloaded -= operator to subtract a polynomial from the result.
		Poly operator -=(Poly p1){
		    bool flag = 0;    //Boolean variable to check if the term is already added in the result equation or not.
			for(vector<pair<double,double> > :: iterator it = result.begin(); it!=result.end(); it++){
			    if(it->second == p1.exponent){
			        it->first -= p1.coefficient;
			        flag = 1;    //this is set to 1 so that we could know that the term with this exponent is already being added to the resulting polynomial.
			    }
			}
			if(!flag){
			    result.push_back(make_pair(-p1.coefficient,p1.exponent));  //If the term is not subtracted then we push in to the result vector.
			}
		    return *this;
		}


        //Overloaded *= operator to multiply a constant to the polynomial.
		Poly operator *=(double constant){
			for(vector<pair<double,double> > :: iterator it = result.begin(); it!=result.end(); ++it){
				it->first = (it->first)*constant;    //Multiplying the constant with every coefficient of the result equation.
			}
			return *this;
		}


        //Implemented at() member function which takes a double value as an argument, 
        //and returns the value of the polynomial at the value inputted by the user.
		double at(double value){
			double answer = 0;    //Final answer of the evaluation will be stored in this double variable.
			for(vector<pair<double,double> > :: iterator it = result.begin(); it!=result.end(); ++it){
				answer += (it->first)*(pow(value,it->second));   //multiply the coefficient with the value to the power exponent.
			}
			return answer;
		}
		
		
		//This is a member function which is used to display the polynomial stored in the vector of pairs.
		void showpoly(){
			cout<<result[0].first<<"*(x^"<<result[0].second<<")";
            for(vector<pair<double,double> > :: iterator it = result.begin()+1; it!=result.end(); ++it){
				if(it->second == 0 && it->first!=0){
					if(it->first > 0){
						cout<<" + "<<it->first;
					}
					else if(it->first < 0){
						cout<<it->first;
					}
				}
				else if(it->first == 0){
				    continue;
				}
				else if(it->first>0){
					cout<<" + "<<it->first<<"*(x^"<<it->second<<")";	
				}
				else{
					cout<<" "<<it->first<<"*(x^"<<it->second<<")";
				}
            }
            cout<<endl<<endl<<endl;
        }
};


int main(){
	double coeff1,expo1;   //These variables are used for taking input in the cases
	Poly p;   //This is the object of the class Poly in which every operation will take place.
	         //This will call the default constructor set the values of exponent and coefficient to zero.
	        //This will make sure no garbage value is entered in our result vector.

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Assignment Number : Programming Assignment #1"<<endl;
	cout<<"======================================================================="<<endl<<endl;

	bool flag = 0; //flag for checking whether the user wants the while loop.

	int opt;   //Used in switch statement to know which option the user has chosen.

	char decision;  //Used for knowing if the user wants to perform more operations or not.

	double value;  //This variable will used for multiplying to the polynomial or evaluating the value of the polynomial. 
    
    int num;     //This will take input the number of terms user wants to enter.


    //Now we are entering in to the main body of the program.
    //This consists of a do-while loop which will be used to know whether the user wants to perform more operation or not.
    //If the user wants to perform more operations on the polynomial, an option to continue will appear for the user.
	do{
	    
		menu(); //this calls the menu() function.
		cout<<"Choose any one option : ";
		cin>>opt; //Select the option given from the menu.
		cout<<endl;
		switch(opt){    //switch statement begins
		    
		    
		    //Case 1 is for Overloading += operator
			case 1 : {
			         cout<<"Enter the number of terms : ";
					 cin>>num;    //This will take input the number of terms user wants to enter.
					 while(num--){
					 	cout<<"Enter the coefficient and exponent respectively: ";
					 	cin>>coeff1>>expo1;   
					 	p += Poly(coeff1,expo1);   //Overloading += operator
					 }
					 sort(p.result.begin(),p.result.end(),sec);   //Sorting the polynomial vector according to the exponent values in descending order.
					 cout<<"Entered polynomial is : ";
					 p.showpoly();      //Display the polynomial.
					 break;
					 }
					 
			
			//Case 2 is for Overloading + operator		 
		    case 2 : {
		             cout<<"Enter the number of terms : ";
					 cin>>num;  //This will take input the number of terms user wants to enter.
					 while(num--){
					 	cout<<"Enter the coefficient and exponent respectively: ";
					 	cin>>coeff1>>expo1;
					 	p = p + Poly(coeff1,expo1);   //Overloading + operator 
					 }
					 sort(p.result.begin(),p.result.end(),sec);   //Sorting the polynomial vector according to the exponent values in descending order.
					 cout<<"Entered polynomial is : ";
					 p.showpoly();      //Display the polynomial.
					 break;
					 }
					 
			
			//Case 3 is for Overloading -= operator		 
		    case 3 : {
		             cout<<"Enter the number of terms : ";
					 cin>>num;   //This will take input the number of terms user wants to enter.
					 while(num--){
					 	cout<<"Enter the coefficient and exponent respectively: ";
					 	cin>>coeff1>>expo1;
					 	p -= Poly(coeff1,expo1);    //Overloading -= operator
					 }
					 sort(p.result.begin(),p.result.end(),sec);   //Sorting the polynomial vector according to the exponent values in descending order.
					 cout<<"The polynomial is : ";
					 p.showpoly();      //Display the polynomial.
					 break;
					 }
					 
			
			//Case 4 is for Overloading - operator
		    case 4 : {
		             cout<<"Enter the number of terms : ";
					 cin>>num;    //This will take input the number of terms user wants to enter.
					 while(num--){
					 	cout<<"Enter the coefficient and exponent respectively: ";
					 	cin>>coeff1>>expo1;
					 	p = p - Poly(coeff1,expo1);    //Overloading - operator
					 }
					 sort(p.result.begin(),p.result.end(),sec);   //Sorting the polynomial vector according to the exponent values in descending order.
					 cout<<"The polynomial is : ";
					 p.showpoly();      //Display the polynomial.
					 break;
					 }
					 
			
			//Case 5 is for Overloading *= operator	 
		    case 5 : {
		             cout<<"Enter the value to which the polynomial should be multiplied : ";
			         cin>>value;   //Taking input the value to which the polynomial should be multiplied.
			         cout<<endl;
			         if(value == 0){
			         	cout<<"Value of the polynomial after multiplying "<<value<<" is : "<<"0"<<endl;
			         	break;
					 }
			         if(p.result.size()==0){   //If the vector is empty then the user first needs to enter the vector and then multiply it with constant.
			             cout<<"First you should enter the polynomial"<<endl;
			             cout<<"Enter the number of terms : ";
					        cin>>num;    //This will take input the number of terms user wants to enter.
					        while(num--){
					 	        cout<<"Enter the coefficient and exponent respectively: ";
					 	        cin>>coeff1>>expo1;
					 	        p += Poly(coeff1,expo1);   //Overloading += operator 
					        }
					        sort(p.result.begin(),p.result.end(),sec);   //Sorting the polynomial vector according to the exponent values in descending order.
					        cout<<"Entered polynomial is : ";
					        p.showpoly();      //Display the polynomial.
					        cout<<endl;
					        p*=value;      //Overloading *= operator
			                cout<<"Value of the polynomial after multiplying "<<value<<" is : ";
			                p.showpoly();      //Display the polynomial.
			         }
			         else{
			             p*=value;     //Overloading *= operator
			             cout<<"Value of the polynomial after multiplying "<<value<<" is : ";
			             p.showpoly();      //Display the polynomial.
			         }
			         break;
					}					 

            
            //Case 6 is for Implementing at() member function
		    case 6 :{
		             cout<<"Enter the value at which the polynomial should be evaluated : ";
			         cin>>value;   //Taking input the value at which the polynomial should be evaluated.
			         cout<<endl;
			         if(p.result.size()==0){      //If the vector is empty then the user first needs to enter the vector and then multiply it with constant.
			             cout<<"First you should enter the polynomial"<<endl;
			             cout<<"Enter the number of terms : ";
					        cin>>num;    //This will take input the number of terms user wants to enter.
					        while(num--){
					 	        cout<<"Enter the coefficient and exponent respectively: ";
					 	        cin>>coeff1>>expo1;
					 	        p += Poly(coeff1,expo1);    //Overloading += operator
					        }
					        sort(p.result.begin(),p.result.end(),sec);   //Sorting the polynomial vector according to the exponent values in descending order.
					        cout<<"Entered polynomial is : ";
					        p.showpoly();      //Display the polynomial.
					        cout<<"Value of the polynomial at "<<value<<" is : "<<p.at(value)<<endl;  //Calling at() member function for object p of class Poly.
			         }
			         else{
			             cout<<"Value of the polynomial at "<<value<<" is : "<<p.at(value)<<endl;    //Calling at() member function for object p of class Poly.
			         }
			         break;
					}
					
			//Case 7 is for exiting the do-while loop	
			case 7 :{
			         flag=1;  //flag is set to 1 so that the program can exit the while condition. 
			         break;
			        }
			        
			        
			default :{
			          cout<<"Entered option is incorrect. Please enter the option mentioned in the Menu."<<endl;
			          break;
        			 } 
        			 
		}
		//switch statement ends here.
		
		if(flag){
			break;
		}
		
		cout<<endl<<"Do you want to perform more operations?(y/n) : ";
		
		cin>>decision;  //Here user selects y/n on the basis if user wants to perform more operations or exit the while loop.
		cout<<endl<<endl<<endl;
		if(decision == 'y'){
		   continue;
		}
		else{
		   break;
		}
		cout<<endl;
		
		
	}while(1);   //Infinite loop until the break statement occurs

	return 0;
}
