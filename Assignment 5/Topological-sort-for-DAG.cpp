/*  Implemented the complete program in Dev C++ using C++14 compiler
	Name : Kunal Shrikant Wanikar
	Roll No. : 204101070
	Email ID : skunal@iitg.ac.in
	Programming Assignment #5
	Question Number 2
*/
#include<iostream>

using namespace std;

int main(){

	cout<<"======================================================================="<<endl;
	cout<<"Name : Kunal Wanikar"<<endl<<"Roll No.: 204101070"<<endl<<"Programming Assignment #5"<<endl<<"Question Number : 2"<<endl;
	cout<<"======================================================================="<<endl<<endl;

	int num_of_nodes;  //Stores the number of nodes in the graph.
	int num_of_edges;  //Stores the number of edges in the graph.
	int startVertex;  //Stores the start vertex of the directed graph.
	int endVertex;  //Stores the end vertex of the directed graph.
	char decision;  //Stores the decision of the user whether he/she wants to check for any other ordering or not.


	//First we take the number of nodes in the graph as an input.
	cout<<"Enter the number of nodes in the graph : ";
	cin>>num_of_nodes;  
	cout<<endl;

	//We construct a adjacency matrix for storing the directed acyclic graph (DAG) and its edges. 
	//We take a boolean matrix which will store whether the edge exists between the two nodes or not.
	//The diagonal of the matrix will always be zero  as this is a DAG and cycle should not be present.
	bool graph[num_of_nodes][num_of_nodes];

	//Initializing the DAG with zero as intially no node is present.
	for(int i=0; i<num_of_nodes; i++){
		for(int j=0; j<num_of_nodes; j++){
			graph[i][j] = 0;
		}
	}

	//Here we take the number of directed edges as input from the user.
	cout<<"Enter the number of edges in the graph : ";
	cin>>num_of_edges;
	cout<<endl;

	cout<<"The names of nodes start from 1 to "<<num_of_nodes<<endl;
	cout<<"Enter the directed edge as input. ";
	cout<<"For example if edge is from 1->2 then enter '1 2' "<<endl;

	//This will take all the directed edges as input in the format if 3 to 5 we have an edge then we will fill the 3's row with boolean 1 at 5th index.
	//i.e. graph[3][5] = 1.
	for(int i = 0; i<num_of_edges; i++){

		cout<<"Enter the two vertices which are the ends of directed edge (startVertex,endVertex) : ";
		cin>>startVertex;  //Takes the starting vertex as input i.e. 3 as in the above example.
		cin>>endVertex;  //Takes the ending vertex as input i.e. 5 as in the above example.
		graph[startVertex-1][endVertex-1] = 1;  //We store a boolean 1 as we have an edge from the start vertex to the end vertex.

	}

	//Temporary adjacency matrix which stores the same graph as above.
	bool temp[num_of_nodes][num_of_nodes];

	


	//This is the do-while loop which will be used by the user to check for the same graph if a different ordering is given as input.
	do{

		//This stores the original DAG in to temporary adjacency matrix.
        for(int i=0; i<num_of_nodes; i++){
            for(int j=0; j<num_of_nodes; j++){
                temp[i][j] = graph[i][j];
            }
        }

        bool flag = 0;  //This variable will be used to know whether the ordering is NOT a topological sorting. If it is not a topologocal sorting then it will be set to 1.

        int topo[num_of_nodes];  //This will stores the ordering given as input by the user.

        cout<<"Enter the ordering"<<endl;

        //Here we take the ordering given by user as input and store it in the topo array.
        //The user enters the vertices 1 to n as input.
        for(int i=0; i<num_of_nodes; i++){
        	cout<<"Enter the "<<i+1<<" vertex : ";
            cin>>topo[i];
            
        }

        cout<<endl;

        int currentVertex;  //This variable is used to store the current vertex being traversed from the ordering given as input by the user.
        
        //This is the main part of the program where we get to know whether the ordering given by the user is correct or not.
        //The logic is as follows : It first takes a node from the ordering given by the user. 
        //Now for this node it will check if there is any incident vertex on it from any other vertex in the given DAG.
        //We can check this by comparing the column of that vertex with zero. Suppose the complete column is zero then there is no incident vertex, else it has an incident vertex.
        //If any incident vertex is present then definitely the given ordering is NOT a topological sort of that DAG. Hence we comeout of the loop and print false. 
        //If no incident vertex is present then we make the complete row of that vertex as zero and proceed to the next vertex.
        for(int i=0; i<num_of_nodes; i++){

            currentVertex = topo[i];  //Stores the current vertex of the ordering which is being checked for incident property.
            
            for(int j=0; j<num_of_nodes; j++){

            	//If we find that any of the entry in the column of the current vertex is equal to 1 then the current vertex has incident vertex to it and hence this ordering cannot be the topological sort.
                if(temp[j][currentVertex-1] == 1){

                    cout<<"OUTPUT : FALSE"<<endl;  //As we get that the ordering is not possible hence we give the output as false.
                    cout<<"The above ordering is not a topological sort of the given graph"<<endl;
                    
                    flag = 1;  //This tell the further program to exit as it has already given the output as false.
                    break;
                }
            }
            if(flag == 1){  //If we know that the answer is false hence no need to check for other vertices.
                break;
            }

            //In this for loop we set the row of the current vertex as zero because we remove the vertex according to the algorithm.
            for(int j=0; j<num_of_nodes; j++){
                temp[currentVertex-1][j] = 0;
            }

        }

        //If we never get the flag = 1 then we know that such ordering is a topological sort and print true.
        if(flag == 0){
            cout<<"OUTPUT : TRUE"<<endl;
            cout<<"The above ordering is a topological sort of the given graph"<<endl;

        }

        cout<<endl;
        //Asks again if the user wants to try again for a different ordering.
        cout<<"Do you want to try for another ordering? (y/n) : ";
        cin>>decision;  //Here user selects y/n on the basis if user wants to perform for more orderings or exit the while loop.

		if(decision == 'y'){  //If the user wants try for a new ordering then continue. Otherwise break from the loop.
			cout<<"==================================================================================================="<<endl<<endl;
			continue;
		}
		else{
			cout<<"==================================================================================================="<<endl<<endl;
			break;
		}


	}while(1);

	return 0;
}
