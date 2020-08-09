#include<iostream>
#include<string.h>
#include<limits.h>
//#include<graphics.h>
#include<fstream>
using namespace std;

/*function to return value of schoice wheather valid or not*/
int return_choice(string );

/*function to return value of source & destination wheather valid or not*/
int return_sourceAndestination(int);

class MAP
{
	int V=17;
	int graph[17][17];
	string place_Name[17];
	int visited[17];

	public:

		//construction
		MAP()
		{
			place_assign();
			for(int i = 0 ; i < V ; i++)
				for(int j = 0 ; j < V ; j++)
					graph[i][j]=0;
		}

		//finction to create and link edges in map
		void create();

		//function to display map in matrix form
		void display();

		//function to display vailable function
		void display_places();

		//function to assgin place from file
		void place_assign();

		//function to return minimun distance to algorithm
		int minDistance(int dist[],  bool sptSet[]);

		// Function to print shortest path from source to j using parent array
		void printPath(int parent[], int j);

		// A utility function to print the constructed distance array
		int printSolution(int dist[], int n, int parent[],int m);


		/*Funtion that implements Dijkstra's single source shortest path
		algorithm for a graph represented using adjacency matrix representation */
		void dijkstra(int src,int destination) ;

		void make_choice();

};

void MAP :: place_assign()//start of function
{
	ifstream fin;
	string name;
	fin.open("place_name.txt");
	fin >> V;
	for(int i = 0 ; i < V ; i++ ){
		fin >> name;
		place_Name[i] = name;
	}
}//end of functions
int MAP :: minDistance(int dist[],  bool sptSet[]) //start of function
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&
                   dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}  //end of functions

void MAP :: printPath(int parent[], int j) //start of function
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    cout<<" ---> "<<place_Name[j];
} //end of function

int MAP :: printSolution(int dist[], int n, int parent[],int m)  //start of function
{
    int src = n;
    int destination = m;
    //cout<<"\n\nVertex\t\t\t\t Distance\t\t\tPath";
   /* for (int i = 0; i < V; i++)
    {
    	if(i!=src){
        	cout<<"\n"<<place_Name[src]<<"->"<<place_Name[i]<<"\t\t"<<dist[i]<<"\t\t"<<place_Name[src];
        	printPath(parent, i);
        }
    }*/
    cout<<"\n\n\t*******************************************************************";
    cout<<"\n\tStarting Place   : "<<place_Name[src]<<endl;
    cout<<"\n\tDestination Place: "<<place_Name[destination]<<endl;
    cout<<"\n\tTotal Distance   : "<<dist[destination]<<" Meter"<<endl;
    cout<<"\n\tPath             : "<<place_Name[src];
     //cout<<"\n"<<place_Name[src]<<"---->"<<place_Name[destination]<<"\t\t"<<dist[destination]<<" meter"<<"\t\t"<<place_Name[src];
     printPath(parent, destination);
     cout<<"\n\t*******************************************************************"<<endl;
     return 0;
}//end of function

void MAP :: dijkstra(int src,int destination)//start of function
{

    /* The output array. dist[i] will hold the shortest
     distance from src to i */
    int dist[V];

    /* sptSet[i] will true if vertex i is included / in shortest
     path tree or shortest distance  from src to i is finalized*/
    bool sptSet[V];

    // Parent array to store shortest path tree
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        /* Pick the minimum distance vertex from the set of
         vertices not yet processed. u is always equal to src
			in first iteration.*/
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    // print the constructed distance array
    printSolution(dist, src, parent, destination);
}
//end of function
void MAP :: make_choice(){ //start of function
	int source;
	int destination;
	display_places(); //show places to choose

	do{
		cout<<"\n\tEnter Starting Place ( Place Index ) Select from above: ";
		try{
			cin>>source;
			if(return_sourceAndestination(source) != 1 )//check validation of source
				throw source;
		}
		catch(int){
			cout<<"\tSource Place Doesn't EXIST........."<<endl;
			cout<<"\tPlease Enter In Between ( 1 to 18 ).";
			cout<<"\n\tEnter Starting Place ( Place Index ) Select from above: ";
			cin>>source;
		}
	}while(return_sourceAndestination(source) != 1); //check validation of source

	do{
		cout<<"\n\tEnter End Place ( Place Index ) Select from above: ";
		try{
			cin>>destination;
			if(return_sourceAndestination(destination) != 1)//check validation of destination
				throw destination;
		}
		catch(int){
			cout<<"\tDestination Place Doesn't EXIST........."<<endl;
			cout<<"\n\tPlease Enter In Between ( 1 to 18 )."<<endl;
			cout<<"\n\tEnter End Place ( Place Index ) Select from above: ";
			cin>>destination;
		}
	}while(return_sourceAndestination(destination) != 1); //check validation of destination
	source = source - 1;
	destination = destination - 1;
	if( source == destination){
		cout<<"\n\tTotal Distance is 0 meter"<<endl;
		cout<<"\n\tPath: "<<place_Name[source]<<"--->"<<place_Name[destination]<<endl;;
		return;
	}
	dijkstra(source,destination); // call function to find shortest path of given palces
}//start of choice funtion

void MAP::create()//start of create function
{
	ifstream file; //file object declaration
	char ans;
	int v1,v2;
	file.open("nashik_map.txt"); //file open
	do
	{
		//cout << "\n Enter Starting point: ";
		file >> v1;
		//cout << v1;
		//cout << "\n Enter Destination: ";
		file >> v2;
		//cout << v2;
		//cout << "\n Enter distance: ";
		file >> graph[v1][v2];
		//cout << graph[v1][v2];
		graph[v2][v1] = graph[v1][v2];
		//cout<<"\n Do you want to add more MAP?(y or n): ";
		file>>ans;
		//cout<<ans;
	}while(ans=='y'||ans=='Y');
	file.close();//close file
}//end of create function

void MAP::display_places() //start of function
{

		for(int i = 0 ;i <V ; i++)
		{
			cout<<"   ";
			cout<< i+1 << ". "<<place_Name[i]<<endl;
		}
}//end of function

void MAP::display() // start of display finction
{
	cout<<"          ";
	for(int i = 0 ; i < V ; i++)
	{
		cout<<place_Name[i];
		cout<<"     ";
	}
	cout<<"\n";
	for(int i = 0 ; i < V ; i++)
	{
		cout<<place_Name[i];
		cout<<"     ";
		for(int j = 0 ; j < V ; j++)
		{
			cout<<"     "<<graph[i][j];
		}
		cout<<"\n";
	}
}// end of display finction
int main()//Start of Main Funnction
{
	MAP g; //Object declaration of class MAP

	string choice; //variable declaration for choice
	char choice1;
	g.create();
	//g.display(); //to display matrix representaion of map
	while(1){//Start of while loop

		cout<<"\n\t***************************";
		cout<<"\n\t1.Find Distance.";
		cout<<"\n\t2.Display All Places in City.";
		cout<<"\n\t3.Exit From MAP.";
		cout<<"\n\t***************************"<<endl;
		do{

			cout<<"\tEnter Choice: ";
			try{
				cin>>choice;
				if( return_choice(choice)!=1){ //check validity of input choice
					throw choice;
				}
			}
			catch(string ){
				//Initialize_char(choice);
				cout<<"\n\tEnter Valid Choice of 1 or 2 or 3."<<endl;
				cout<<"\n\tEnter Choice: ";
				cin>>choice;
			}

		}while(return_choice(choice)!=1);
		cout<<"\n";
		choice1=choice[0];
		switch(choice1){ //switch case start

			case '1':
				g.make_choice();
				break;
			case '2':
				g.display_places(); //Display available city places
				break;
			case '3':
				exit(1); //Exit from program
		}//switch case end
	}//end of while loop
}//end of main function

/*function to return value of schoice wheather valid or not*/
int return_choice(string choice1){ //start of function
	if(choice1 == "1")
		return 1;
	else if (choice1 == "2")
		return 1;
	else if (choice1 == "3" )
		return 1;
	else
		return 0;
} // end of function

/*function to return value of source & destination wheather valid or not*/
int return_sourceAndestination(int source){ //start of function
	if(source > 0){
		if(source < 18)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}// end of function
