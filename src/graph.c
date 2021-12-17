#include "dslib.h"

struct graph {
  bool isWeighted;
  int maxVertex;
  int maxDegree;
  int *visited;
  int *degree;
  int **edges;
  int **weights;
};


Graph 
*graphCreate (int maxVertex, int maxDegree, bool isWeighted) {
  Graph *graph = mallocSafe (sizeof(Graph));

  if (graph != NULL) {
    graph->maxVertex = maxVertex;
    graph->maxDegree = maxDegree;
    graph->isWeighted = isWeighted;
    graph->degree = calloc (maxVertex, sizeof(int));
    graph->visited = calloc (maxVertex, sizeof(int));
    graph->edges = mallocSafe (maxVertex * sizeof(int *));

    for (int i = 0; i < maxVertex; i++) {
      graph->edges[i] = mallocSafe (maxDegree * sizeof(int));
    }

    if (graph->isWeighted) {
      graph->weights = mallocSafe (maxVertex * sizeof(int *));
    
      for (int i = 0; i < maxVertex; i++) {
        graph->weights[i] = mallocSafe (maxDegree * sizeof(int));
      }
    }

    return graph;
  }

  return NULL;
}


int 
graphInsertEdge (int initial, int terminal, int weight, bool isDigraph, Graph *graph) {
  if (graph == NULL) { return 0; }
  if (initial < 0 || initial >= graph->maxVertex) { return 0; }
  if (terminal < 0 || terminal >= graph->maxVertex) { return 0; }

  graph->edges[initial][graph->degree[initial]] = terminal;

  if (graph->isWeighted) {
    graph->weights[initial][graph->degree[initial]] = weight;
  }

  graph->degree[initial]++;

  if (isDigraph == false) {
    graphInsertEdge(initial, terminal, weight, true, graph);
  }

  return 1;
}


int 
graphRemoveEdge(int initial, int terminal, int weight, bool isDigraph, Graph *graph) {
  if (graph == NULL) { return 0; }
  if (initial < 0 || initial >= graph->maxVertex) { return 0; }
  if (terminal < 0 || terminal >= graph->maxVertex) { return 0; }

  int i = 0;

  while (i < graph->degree[initial] && graph->edges[initial][i] != terminal) { i++; }
  
  if (i == graph->degree[initial]) { return 0; }

  graph->degree[initial]--;
  graph->edges[initial][i] = graph->edges[initial][graph->degree[initial]];

  if (graph->isWeighted) {
    graph->weights[initial][i] = graph->weights[initial][graph->degree[initial]];
  }

  if (isDigraph == false) {
    graphRemoveEdge(initial, terminal, weight, true, graph);
  }

  return 1;
}


void
graphDisplay (bool isVisited, Graph *graph) {
  if (graph != NULL) {
    if (isVisited) {
      printf("[ ");
      
      for (int i = 0; i < graph->maxVertex; i++) { 
        printf("%i ", graph->visited[i]);
      }

      printf("]\n");
    } else {
      for (int i = 0; i < graph->maxVertex; i++) {
        printf("%i: ", i);
        for (int j = 0; j < graph->degree[i]; j++) {
          if (graph->isWeighted) {
            printf("%i(%.2i), ", graph->edges[i][j], graph->weights[i][j]);
          } else {
            printf("%i, ", graph->edges[i][j]);
          }
        }

        putchar('\n');
      }
    }
  }
}


void
graphDepthFirstSearchLoop (int initial, int count, int *visited, Graph *graph) {
  visited[initial] = count;
  
  for (int i = 0; i < graph->degree[initial]; i++) {
    if (!visited[graph->edges[initial][i]]) {
      graphDepthFirstSearchLoop(graph->edges[initial][i], count + 1, visited, graph);
    }
  }
}


void
graphDepthFirstSearch (int initial, Graph *graph) {
  for (int i = 0; i < graph->maxVertex; i++) {
    graph->visited[i] = 0;
  }

  graphDepthFirstSearchLoop(initial, 1, graph->visited, graph);
}


void 
graphBreadthFirstSearch (int initial, Graph *graph) {
  int *queue, initialQueue = 0, terminalQueue = 0, count = 1;
  for (int i = 0; i < graph->maxVertex; i++) {
    graph->visited[i] = 0;
  }

  int vertexQty = graph->maxVertex;

  queue = mallocSafe (vertexQty * sizeof(int));
  terminalQueue++;
  queue[terminalQueue] = initial;
  graph->visited[initial] = count;

  while (initialQueue != terminalQueue) {
    initialQueue = (initialQueue + 1) % vertexQty;
    int vertex = queue[initialQueue];
    count++;

    for (int i = 0; i < graph->degree[vertex]; i++) {
      if (!graph->visited[graph->edges[vertex][i]]) {
        terminalQueue = (terminalQueue + 1) % vertexQty;
        queue[terminalQueue] = graph->edges[vertex][i];
        graph->visited[graph->edges[vertex][i]] = count;
      }
    }
  }

  free(queue);
}


int
graphMaxVertex (Graph *graph) {
  return graph->maxVertex;
}


void 
graphDestroy (Graph *graph) {
  if (graph != NULL) {
    for (int i = 0; i < graph->maxVertex; i++) {
      free(graph->edges[i]);
    }

    free(graph->edges);

    if (graph->isWeighted) {
      for (int i = 0; i < graph->maxVertex; i++) {
        free(graph->weights[i]);
      }

      free(graph->weights);
    }

    free(graph->visited);
    free(graph->degree);
    free(graph);
  }
}