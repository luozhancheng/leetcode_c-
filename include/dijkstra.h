//
// Created by lelezi on 2019-07-07.
//

#ifndef LEETCODE_DIJKSTRA_H
#define LEETCODE_DIJKSTRA_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Edge {
public:
  Edge(const int &sid, const int &tid, const int &w) : sid(sid), tid(tid), w(w) {
  }

public:
  int sid;
  int tid;
  int w;
};

class Graph {
public:
  Graph(const int &v) : v(v) {
    for (int i = 0; i < v; i++) {
      adj.push_back(vector<Edge>());
    }
  }

  void AddEdge(int s, int t, int w) {
    adj[s].push_back(Edge(s, t, w));
  }

public:
  vector<std::vector<Edge>> adj;
  int v;
};

class Vertex {
public:
  Vertex() {}
  Vertex(int id, int dist) : id(id), dist(dist) {

  }

public:
  int id;
  int dist;
};

class Comparison {
public:
  bool operator() (const Vertex& lhs, const Vertex& rhs) const {
    return lhs.dist > rhs.dist;
  }
};

class Dijkstra {
public:
  Dijkstra(const Graph &g) : graph(g) {
    if (g.v <= 0) {
      return;
    }
    vertexes = new Vertex[graph.v];
    predDecessor = new int[graph.v];
    inQueue = new bool[graph.v];
    for (int i = 0; i < graph.v; i++) {
      vertexes[i].id = i;
      vertexes[i].dist = INT_MAX;
      predDecessor[i] = -1;
      inQueue[i] = false;
    }
  }

  ~Dijkstra() {
    delete []vertexes;
    delete []predDecessor;
    delete []inQueue;
  }

  void Calculate(int s, int t) {
    vertexes[s].dist = 0;
    pq.push(vertexes[s]);
    inQueue[s] = true;

    while (!pq.empty()) {
      Vertex minV = pq.top();
      pq.pop();
      inQueue[minV.id] = false;
      if (minV.id == t) {
        break;
      }
      for (int i = 0; i < graph.adj[minV.id].size(); i++) {
        Edge e = graph.adj[minV.id][i];
        Vertex &nextV = vertexes[e.tid];
        if (minV.dist + e.w < nextV.dist) {
          cout << "cal = " << minV.dist + e.w << endl;
          cout << "cur = " << nextV.dist << endl;
          nextV.dist = minV.dist + e.w;
          std::cout << "next id " << nextV.id << " <-- " << minV.id << endl;

          predDecessor[nextV.id] = minV.id;
          if (inQueue[nextV.id]) {
            UpdatPQ(nextV);
          } else {
            pq.push(nextV);
            inQueue[nextV.id] = true;
          }
        }
      }
    }

    std::cout << "result = ";
    print(s, t, predDecessor);
  }

  void UpdatPQ(const Vertex& v) {
    priority_queue<Vertex, vector<Vertex>, Comparison> tmp;
    while (pq.size() != 0) {
      Vertex top = pq.top();
      pq.pop();
      if (top.id == v.id) {
        top.dist = v.dist;
      }
      tmp.push(top);
    }
    pq = tmp;
  }

  void print(int s, int t, const int* p) {
    if (s == t || p[t] == -1) {
      cout << s;
      return;
    }
    print(s, p[t], p);
    std::cout << "->" << t;
  }

public:
  Graph graph;
  Vertex* vertexes = nullptr;
  priority_queue<Vertex, vector<Vertex>, Comparison> pq;
  int* predDecessor = nullptr;
  bool* inQueue = nullptr;
};

class Solution {
public:
  static void run() {
    Graph graph(6);
    graph.AddEdge(0, 1, 10);
    graph.AddEdge(0, 4, 15);
    graph.AddEdge(1, 2, 15);
    graph.AddEdge(1, 3, 2);
    graph.AddEdge(2, 5, 5);
    graph.AddEdge(3, 5, 12);
    graph.AddEdge(4, 5, 10);
    graph.AddEdge(3, 2, 1);
    Dijkstra d(graph);
    d.Calculate(0, 5);

  }
};

#endif //LEETCODE_DIJKSTRA_H
