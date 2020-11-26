/*  Implemented the complete program in Dev C++ using C++14 compiler
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #5
	Question Number 1
*/
#include<iostream>
#include<math.h>

using namespace std;



//This function is used to swapping the two elements given as input.
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


//This function partition the array into two halves around the given value 'X'
int partition(int *arr, int low, int high)
{  
	//since we have already swapped the 'X' with initial value of array we are taking starting value as pivot 
    int pivot = arr[high];
    int i = - 1; 
  	int j;
  	//this code will run for size of array(n times) 
    for ( j = low; j <= high-1; j++)  
    {    
    	//if array elements are less than or equal to the pivot element then swap the two elements
        if (arr[j] <= pivot)  
        {  
            i++;   
        	swap(&arr[i], &arr[j]);  
        }  
    }  
    
	swap(&arr[i+1], &arr[j]);  
    
	//return the index of pivot after the partition of the array
	return (i+1);  
} 

//This function is used for constructing the min heap following the heap property
void minheapify(int *arr, int n, int i)
{
	int small = i; // The node which will be heapified
	int lc = 2 * i + 1; // left child node value will be stored in lchild
	int rc = 2 * i + 2; // right child node value will be stored in rchild

	// Check if left child is smaller than its parent
	if (arr[lc] < arr[small] && lc < n)
		small = lc;

	// Check if right child is smaller than smallest
	if (arr[rc] < arr[small] && rc < n)
		small = rc;

	// If smallest is not parent
	if (small != i) {
		swap(arr[i], arr[small]);

		// Recursively heapify the affected sub-tree
		minheapify(arr,n, small);
	}
}

//This function is used to build a Min-Heap from the given array
void buildminHeap(int *arr, int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--) {
		minheapify(arr,n, i);
	}
}

//This function deletes the root node and then again heapifies the heap.
void extractmin(int *arr,int size)
{
	int min = arr[0];
	arr[0] = arr[size-1];
	minheapify(arr,--size,0);

}

//This function is used for constructing the max heap following the heap property
void maxheapify(int *arr, int n, int i)
{
    int large = i; // Initialize largest as root
    int lc = 2 * i + 1; // left = 2*i + 1
    int rc = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (lc < n && arr[lc] > arr[large])
        large = lc;

    // If right child is larger than largest so far
    if (rc < n && arr[rc] > arr[large])
        large = rc;

    // If largest is not root
    if (large != i) {
        swap(arr[i], arr[large]);

        // Recursively heapify the affected sub-tree
        maxheapify(arr, n, large);
    }
}

//This function is used to build a Max-Heap from the given array
void buildmaxHeap(int *arr, int n)
{
    for (int i = (n/2)-1; i >= 0; i--) {
        maxheapify(arr, n, i);
    }
}

//This function deletes the root node and then again heapifies the heap.
void extractmax(int *arr,int size)
{
	int max = arr[0];
	arr[0] = arr[size-1];
	maxheapify(arr,--size,0);

}




int main(){

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Programming Assignment #5"<<endl<<"Question Number : 1"<<endl;
	cout<<"======================================================================="<<endl<<endl;

	int n;  //This variable is used to store the number of elements in the array.
	int k;  //This variable stores the value of k i.e. the number of k closest elements.
	int x;  //This variable stores the key value i.e. the value of x.

	cout<<"Enter the number of data items in the array : ";
	cin>>n;
	
	int arr[n];  //This is an array which will store all the n elements given as input by the user.
	cout<<"Enter the "<<n<<" elements of the array : "<<endl;
	for(int i=0; i<n; i++){
		cout<<"Enter the "<<i+1<<" element : ";
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Enter the key value i.e. the value of x : ";
	cin>>x;
	cout<<"Enter the value of k : ";
	cin>>k;
	
    int index;  //Stores the current index value where the key is stored.
    
    //Here we take the index value correctly.
	for(int i=0; i<n; i++){
		if(arr[i] == x){
			index = i;
			break;
		}
	}

	swap(&arr[index],&arr[n-1]);  //Swapping the index value with the last element.

	int new_index;  //This will stpre the index of the key element after the partition is completed.

	new_index = partition(&arr[0],0,n-1);  //Calls the partition function.
	
	//After dividing the array into 2 parts, now we make the left part as the max heap and the right part as the minheap.
    buildmaxHeap(&arr[0],new_index);  //here we are building the maxheap for the left part.

    buildminHeap(&arr[new_index+1],n-new_index-1);  //Here we are building the minheap for the right part.

    int maxheapsize = new_index;  //We take the size of the maxheap as new_index
    int minheapsize = n-new_index-1;  //The size of the min heap will be total elements minus the new index.
    
	cout<<endl;
	cout<<"The "<<k<<" closest elements to the element "<<x<<" are : ";
	
    for(int i=0; i<k; i++)
	{
        
		if(maxheapsize!=0 && minheapsize!=0)  //We check whether any of the heap has become zero. 
		{
		//Here we take the difference between the starting element of both the heaps with the key element.
		
		if(abs(arr[0]-arr[new_index]) >= abs(arr[new_index+1]-arr[new_index])){  //If the difference which is lower will be taken into account and printed and now we delete the root element of the minheap.
			cout<<arr[new_index+1]<<" ";       	
		   	extractmin(&arr[new_index+1],minheapsize);  //here we delete the root element of the max heap and reduce the size of the heap.
       		minheapsize--;
		}
		else  //The difference which is lower will be taken into account and printed and now we delete the root element of the maxheap.
		{
			cout<< arr[0]<<" ";
			extractmax(&arr[0],maxheapsize);  //here we delete the root element of the max heap and reduce the size of the heap.
			maxheapsize--;
		}
		continue;
		}

		else if (maxheapsize!=0 && minheapsize==0)

		{

			cout<< arr[0]<<" ";
			extractmax(&arr[0],maxheapsize);  //Now if the minheap i.e. the right side part becomes NULL and we have used all the values so we delete from the left part i.e. maxheap.
       		maxheapsize--;
       		continue;
		}


		else if (maxheapsize==0 && minheapsize!=0) 
		{
			cout<<arr[new_index+1]<<" ";
			extractmin(&arr[new_index+1],minheapsize);   //Now if the maxheap i.e. the left side part becomes NULL and we have used all the values so we delete from the right part i.e. minheap.
       		
       		minheapsize--;
       		continue;
		}

	}



	return 0;
}
