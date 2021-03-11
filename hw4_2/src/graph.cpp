/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Hassan Raza
* ID: 21701811
* Section : 1
* Assignment : 4
* Description : implementation of graph
*/
/** @file graph.cpp
 * An adjacency list representation of an undirected weighted graph.
*/
#include "graph.h"
/*Do not add new libraries or files*/
using namespace std;
Graph::Graph()
{}  // end constructor

//adding airport
void Graph::addAirport(const string& airportName)
{
    list<node> khaali;
    adjList.insert(pair<string, list<node> >(airportName, khaali));
}  // end addPerformer

//add connection
void Graph::addConnection(const string& airport1, const string& airport2, int numOfPassengers)
{
    //adding airport if not present
    if(adjList.find(airport1) == adjList.end())
        addAirport(airport1);
    if(adjList.find(airport2) == adjList.end())
        addAirport(airport2);

    //adding connection
    list<node> listing = adjList[airport1];
    node noding;
    noding.numOfPassengers = numOfPassengers;
    noding.airportName = airport2;
    listing.push_back(noding);
    adjList[airport1] = listing;
    listing = adjList[airport2];
    noding.numOfPassengers = numOfPassengers;
    noding.airportName = airport1;
    listing.push_back(noding);
    adjList[airport2] = listing;
}  // end addConnection

list<string> Graph::getAdjacentAirports(const string& airportName)
{
    list<node> noding = adjList[airportName];
    list<string> names;
    for (list<node>::iterator it = noding.begin(); it != noding.end(); ++it)
        names.push_back((*it).airportName);
    return names;
}  // end getAdjacentAirports

int Graph::getTotalPassengers(const string& airportName)
{
    list<node> noding = adjList[airportName];
    int numbers = 0;
    //adding numbers for each airport by iterating
    for (list<node>::iterator it = noding.begin(); it != noding.end(); ++it)
        numbers = numbers + ((*it).numOfPassengers);
    return numbers;
}  // end getTotalPassengers


list<string> Graph::findShortestPath(const string& airport1, const string& airport2)
{
    queue <string> q;
    list<string> listing;
    string curr;
    string hi = airport2;
    string names[adjList.size()];
    string parents[adjList.size()];
    int sizing = 0;
    int sizingP = 0;
	// add v to the queue and mark it
	if(sizing == 0)
    {
        names[sizing] = airport1;
        sizing++;
        parents[sizingP] = "";
        sizingP++;
        q.push(airport1);
    }
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        list<node> iterate;
        //getting element so that we can iterate its list
        for (map< string, list<node> >::iterator it = adjList.begin(); it != adjList.end(); it++)
        {
            if (current == (*it).first)
            {
                iterate = (*it).second;
            }
        }
        //iterating list of its element
        for (list<node>::iterator iter = iterate.begin(); iter != iterate.end(); ++iter)
        {
                int boola = 0;
                //checking if it already exists
                for (int k = 0; k < sizing; k++)
                {
                    if (names[k] == iter->airportName)
                        boola = 1;
                }
                //pushing airport into queue
                if(boola == 0)
                {
                    curr = iter->airportName;
                    names[sizing] = iter->airportName;
                    sizing++;
                    parents[sizingP] = current;
                    sizingP++;
                    q.push(iter->airportName);
                }
                if (curr==airport2)
                    break;
        }
        //if airport2 found empty the queue and go out of while
        if (curr == hi)
        {
            while (!q.empty())
            {
                q.pop();
            }
        }
    }
    listing.push_front(curr);
    string currP = parents[sizing-1];
    //adding elements into list
    while(currP != "")
    {
        int n = 0;
        for(int i = 0; i <= sizing; i++)
        {
            if(currP == names[i] && n == 0)
            {
                sizing = i;
                listing.push_front(currP);
                currP = parents[sizing];
                n = 1;
            }
        }
    }
    return listing;

}  // end findShortestPath

list< pair<string, string> > Graph::findMST()
{
    string names[adjList.size()];
    int sizing = 0;
    string namm = "";
    string first = "";
    list< pair<string, string> > lis;
    list<node>::iterator store;
    if(adjList.size() == 0)
        return lis;
    map< string, list<node> >::iterator ito = adjList.begin();
    if(adjList.size() == 1){
        lis.push_back(pair<string, string> ((*ito).first, namm));
        return lis;
    }
    //adding 1st element
    if(sizing == 0)
    {
        names[sizing] = (*ito).first;
        sizing++;
    }
    //iterating through the graph
    for (int n = 0; n < adjList.size() - 1; n++){
        int mini = 214748367;
        for (map< string, list<node> >::iterator it = adjList.begin(); it != adjList.end(); it++)
        {
            int boo = 0;
            //checking if visited
            for (int k = 0; k < sizing; k++)
            {
                if (names[k] == (*it).first)
                     boo= 1;
            }
            if(boo == 1){
                list<node> iterate = (*it).second;
                //iterating list
                for (list<node>::iterator iter = iterate.begin(); iter != iterate.end(); ++iter)
                {
                    if ((*iter).numOfPassengers < mini){
                        int boola = 0;
                        //checking for visited
                        for (int k = 0; k < sizing; k++)
                        {
                            if (names[k] == iter->airportName)
                                boola = 1;
                        }
                        if(boola == 0)
                        {
                            first = (*it).first;
                            mini = iter->numOfPassengers;
                            namm = iter->airportName;
                            store = iter;
                        }
                    }
                }
            }
        }
        names[sizing] = namm;
        sizing++;
        lis.push_back(pair<string, string>(first, namm));
    }
    return lis;
}


void Graph::deleteAirport(const string& airportName)
{
    adjList.erase(airportName);
    //deleting airport connection in other airports in graph
    for (map< string, list<node> >::iterator it = adjList.begin(); it != adjList.end(); it++)
    {
        list<node> iterate = (*it).second;
        for (list<node>::iterator iter = iterate.begin(); iter != iterate.end(); ++iter)
        {
            if(iter->airportName == airportName)
            {
                iter = iterate.erase(iter);
            }
        }
        (*it).second = iterate;
    }


}  // end deleteAirport

