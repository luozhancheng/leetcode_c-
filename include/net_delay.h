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

public:
  int id = -1;
  int dist = INT_MAX;
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

  void Calculate(int s) {
    vertexes[s].dist = 0;
    pq.push(vertexes[s]);
    inQueue[s] = true;

    while (!pq.empty()) {
      Vertex minV = pq.top();
      pq.pop();
      inQueue[minV.id] = false;
      for (int i = 0; i < graph.adj[minV.id].size(); i++) {
        Edge e = graph.adj[minV.id][i];
        Vertex &nextV = vertexes[e.tid];
        if (minV.dist + e.w < nextV.dist) {
          nextV.dist = minV.dist + e.w;

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


public:
  Graph graph;
  Vertex* vertexes = nullptr;
  priority_queue<Vertex, vector<Vertex>, Comparison> pq;
  int* predDecessor = nullptr;
  bool* inQueue = nullptr;
};

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    Graph g(N);
    for (int i = 0; i < times.size(); i++) {
      g.AddEdge(times[i][0] - 1, times[i][1] - 1, times[i][2]);
    }
    Dijkstra d(g);
    d.Calculate(K - 1);

    int max = -1;
    for (int i = 0; i < g.v; i ++) {
      if (d.vertexes[i].dist == INT_MAX) {
        return -1;
      } else {
        if (d.vertexes[i].dist > max) {
          max = d.vertexes[i].dist;
        }
      }
    }

    return max;
  }
  static void run() {
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    int ret = Solution().networkDelayTime(times, 4, 2);
    cout << "ret = " << ret << endl;
  }
};

#endif //LEETCODE_DIJKSTRA_H
