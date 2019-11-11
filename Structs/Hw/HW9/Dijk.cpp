#include "Graph.hpp"
#include <vector>
#include <stack>

void Graph::addVertex(string name){
    bool found = false;
    for (unsigned int i = 0; i < vertices.size(); i++){
        if (vertices[i]->name == name){
            found = true;
        }
    }
    if (!found){
        vertex *nv = new vertex;
        nv->name = name;
        vertices.push_back(nv);
    }
}

void Graph::addEdge(string v1, string v2, int weight){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = weight;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = weight;
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::depthFirstTraversal(string source)
{

    vertex *n = NULL;

    unsigned int unvisited = 0;

    for (unsigned int i = 0; i<vertices.size(); i++){
        if (vertices[i]->name == source){
            n = vertices[i];
        }
    }

    for(unsigned int x = 0; x < n->adj.size(); x++ )
    {
        if (!n->adj[x].v->visited){
            unvisited++;
        }
    }

    cout << n->name << " --> ";

    n->visited = true;

    for(unsigned int x = 0; x < n->adj.size(); x++ )
    {
        if (!n->adj[x].v->visited){
            depthFirstTraversal(n->adj[x].v->name);
        }
    }

    if (unvisited == n->adj.size()){
        cout << "Done" << endl;
    }

}

vertex* Graph::DijkstraAlgorithm(string start, string end){
    vertex *v, *u;
    vector <vertex*> vec;
    int currMinDist = (2^31) - 1;
    int totDist = 0;

    for (unsigned int i = 0; i < vertices.size(); i++){
        if (vertices[i]->name == start){
            v = vertices[i];    
            v->visited = true;
            v->distance = 0;
        }
        else{
            vertices[i]->distance = (2^31) - 1;
            vec.push_back(vertices[i]);
        }
    }

    while (vec.size()){
        currMinDist = (2^31) - 1;
        for (unsigned int j = 0; j<v->adj.size(); j++){
            if (v->adj[j].weight < currMinDist && !v->adj[j].v->visited){
                currMinDist = v->adj[j].weight;
                u = v->adj[j].v;
            }
        }
        u->visited = true;
        u->pred = v;
        totDist += currMinDist;
        u->distance = totDist;

        if (u->name == end){
            break;
        }
        else{
            v = u;
        }
    }
    return u;
}

void Graph::shortestpath(string s1, string s2){
    stack <string> path;
    vertex *end;

    for (unsigned int i = 0; i < vertices.size(); i++){
        if (vertices[i]->name == s2){
            end = vertices[i];
        }
    }

    while (end->pred){
        path.push(end->name);
        end = end->pred;
    }

    path.push(end->name);

    while (!path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
}