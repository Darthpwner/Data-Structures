//
//  main.cpp
//  Graphs
//
//  Created by Matthew Allen Lin on 11/6/15.
//  Copyright © 2015 Matthew Allen Lin Software. All rights reserved.
//

#include <iostream>

using namespace std;

#define N 5 //Programmatic default for the size of the NxN graph

class Graph {   //Assumes a (undirected) bidirectional graph
public:
    Graph();
    virtual void setGraph(int x, int y);
    virtual void addRelation(int x, int y);
    void printGraph();
    virtual void deleteRelation(int x, int y);
protected:
    bool m_graph[N][N];
};

class DirectedGraph: public Graph {   //Assumes a directed graph
public:
    virtual void setGraph(int x, int y);
    virtual void addRelation(int x, int y);
    virtual void deleteRelation(int x, int y);
};

//Adds a directed graph edge from x to y
void DirectedGraph::setGraph(int x, int y) {
    m_graph[x][y] = true;
}

void DirectedGraph::addRelation(int x, int y) {
    if(x > N - 1) {
        cout << "x is too large\n";
        return;
    } else if (x < 0) {
        cout << "x needs to be a positive number\n";
        return;
    } else if (y > N - 1) {
        cout << "y is too large\n";
        return;
    } else if (y < 0) {
        cout << "y needs to be a positive number\n";
        return;
    }
    
    setGraph(x, y);
}


//Deletes a directed graph edge relation from x to y
void DirectedGraph::deleteRelation(int x, int y) {
    if(x > N - 1) {
        cout << "x is too large\n";
        return;
    } else if (x < 0) {
        cout << "x needs to be a positive number\n";
        return;
    } else if (y > N - 1) {
        cout << "y is too large\n";
        return;
    } else if (y < 0) {
        cout << "y needs to be a positive number\n";
        return;
    }
    
    m_graph[x][y] = false;
}

int main(int argc, const char * argv[]) {
    Graph g;
    g.printGraph();
    
    g.addRelation(1, 4);
    g.addRelation(1, 5);    //Should display failure message
    g.addRelation(2, 3);
    g.deleteRelation(3, 2);
    
    g.printGraph(); //Should only show (1, 4) and (4, 1) relationship
    
    DirectedGraph dg;
    cout << "Printed direct graph\n";
    dg.printGraph();
    
    dg.addRelation(1, 4);
    dg.printGraph();
    
    g.printGraph();

    return 0;
}

Graph::Graph() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            m_graph[i][j] = false;  //Set the entire graph to false for now (no edge connections at the start)
        }
    }
}

//Mutator function that sets a relationship between two nodes (bidrectionally)
void Graph::setGraph(int x, int y) {
    m_graph[x][y] = true;
    m_graph[y][x] = true;
}

//Adds a bidirectional graph edge relation between two nodes
void Graph::addRelation(int x, int y) {
    if(x > N - 1) {
        cout << "x is too large\n";
        return;
    } else if (x < 0) {
        cout << "x needs to be a positive number\n";
        return;
    } else if (y > N - 1) {
        cout << "y is too large\n";
        return;
    } else if (y < 0) {
        cout << "y needs to be a positive number\n";
        return;
    }

    setGraph(x, y); //Assigns values to the graph
}

//Prints out the 2D representation of the graph. "true" means there is a friendship relation between two nodes
//"false" means there is NO friendship relation between two nodes
void Graph::printGraph() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << m_graph[i][j];
        }
        cout << "\n";
    }
    
    cout << "\n";   //Pad an extra line for cleanliness
}

//Deletes a bidirectional graph edge relation between two nodes
void Graph::deleteRelation(int x, int y) {
    if(x > N - 1) {
        cout << "x is too large\n";
        return;
    } else if (x < 0) {
        cout << "x needs to be a positive number\n";
        return;
    } else if (y > N - 1) {
        cout << "y is too large\n";
        return;
    } else if (y < 0) {
        cout << "y needs to be a positive number\n";
        return;
    }
    
    m_graph[x][y] = false;
    m_graph[x][y] = false;
}

