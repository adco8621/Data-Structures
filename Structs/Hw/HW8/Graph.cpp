#include "Graph.hpp"
#include <queue>

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

void Graph::addEdge(string v1, string v2){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::displayEdges(){
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<" --> ";
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout<<endl;
    }
}

void Graph::breadthFirstTraverse(string sourceStr){
    vertex *vStart;

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceStr)
        {
            vStart = vertices[i];
        }
    }

    cout << "Starting vertex (root): " << vStart->name << "-> ";

    vStart->visited = true;

    queue<vertex*> q;

    q.push(vStart);

    vertex *n;

    while(!q.empty()){

        n = q.front();
        q.pop();

        for(unsigned int x = 0; x < n->adj.size(); x++ )
        {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            if(!n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->distance = n->distance + 1;
                q.push(n->adj[x].v);
                cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ") ";
            }
        }

    }
}

int Graph::getConnectedComponents(){
    int connComp = 0;
    for (unsigned int i = 0; i < vertices.size(); i++){
        if (!vertices[i]->visited){
            vertex *vStart = vertices[i];

            vStart->visited = true;

            queue<vertex*> q;

            q.push(vStart);

            vertex *n;

            while(!q.empty()){

                n = q.front();
                q.pop();

                for(unsigned int x = 0; x < n->adj.size(); x++ )
                {
                    // If a adjacent has not been visited, then mark it visited and enqueue it
                    if(!n->adj[x].v->visited)
                    {
                        n->adj[x].v->visited = true;
                        n->adj[x].v->distance = n->distance + 1;
                        q.push(n->adj[x].v);
                    }
                }

            }
            connComp++;
        }
    }
    return connComp;
}

bool Graph::checkBipartite(){
    for (unsigned int i = 0; i < vertices.size(); i++){
        if (!vertices[i]->visited){
            vertex *vStart = vertices[i];

            vStart->visited = true;
            vStart->color = "red";

            queue<vertex*> q;

            q.push(vStart);

            vertex *n;

            while(!q.empty()){

                n = q.front();
                q.pop();

                for(unsigned int x = 0; x < n->adj.size(); x++ )
                {
                    // If a adjacent has not been visited, then mark it visited and enqueue it
                    if(!n->adj[x].v->visited)
                    {
                        n->adj[x].v->visited = true;
                        n->adj[x].v->distance = n->distance + 1;
                        n->color == "red" ? n->adj[x].v->color = "blue" : n->adj[x].v->color = "red";
                        q.push(n->adj[x].v);
                    }
                    if (n->color == n->adj[x].v->color){
                        return false;
                    }
                }

            }
        }
    }
    return true;
}