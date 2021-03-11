/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 4
* Description : main file
*/
/**
 * CS 202 - HW 4
 * A main file
 */
#include "graph.h"
#include <string>
#include <iostream>
/*You can add additional libraries here to read and process the dataset*/
#include <fstream>
#include <sstream>

using namespace std;

int  main()
{
    ifstream input("flightDataset.txt");
    Graph grap;
    string airport1 = "";
    string airport2 = "";
    int passengers = 0;
    int curr = 0;
    string data;
    //getting data from file
    while (getline(input,data))
    {
        int sub = data.find(';');
        airport1 = data.substr(0,sub);
        int subs = data.find(';', sub+1);
        airport2 = data.substr(sub+1,subs - sub-1);
        string temp = data.substr(subs+1);
        istringstream(temp) >> passengers;
        grap.addConnection(airport1, airport2, passengers);
    }

    list<string> lis = grap.getAdjacentAirports("HEATHROW");
    cout<<"adj airports of heathrow: ";
    for (list<string>::iterator iter = lis.begin(); iter != lis.end(); ++iter)
    {
        cout<<(*iter)<<" ";
    }
    cout<< "" <<endl;

    cout<<"total passengers at HEATHROW: " << grap.getTotalPassengers("HEATHROW")<<endl;

    lis = grap.findShortestPath("HEATHROW","EXETER");
    cout<<"HEATHROW to EXETER shortest path: ";
    for (list<string>::iterator iter = lis.begin(); iter != lis.end(); ++iter)
    {
        cout<< (*iter)<<" ";
    }
    cout<< "" <<endl;
    list< pair<string, string> > los = grap.findMST();
    cout<<"MST: ";
    for (list< pair<string, string> >::iterator iter = los.begin(); iter != los.end(); ++iter)
    {
            cout<<(*iter).first<< (*iter).second<<" ";
    }
    cout<< "" <<endl;

    grap.deleteAirport("NEWQUAY");

    lis = grap.getAdjacentAirports("HEATHROW");
    cout<< "adjacent airports to heathrow: ";
    for (list<string>::iterator iter = lis.begin(); iter != lis.end(); ++iter)
    {
        cout<<(*iter)<<" ";
    }
    cout<< "" <<endl;

    cout<<"total passengers at HEATHROW: " << grap.getTotalPassengers("HEATHROW")<<endl;

    lis = grap.findShortestPath("HEATHROW","EXETER");
    cout<<"HEATHROW to EXETER shortest path: ";
    for (list<string>::iterator iter = lis.begin(); iter != lis.end(); ++iter)
    {
        cout<<(*iter)<<" ";
    }
    cout<< "" <<endl;
    los = grap.findMST();
    cout<<"MST: ";
    for (list< pair<string, string> >::iterator iter = los.begin(); iter != los.end(); ++iter)
    {
            cout<<(*iter).first<< (*iter).second<<" ";
    }
    cout<< "" <<endl;
    return 0;
}

// End of main file

