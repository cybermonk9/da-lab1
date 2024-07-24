#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 10
int parent[MAX_VERTICES];
int find(int m) {
int p = m;
while (parent[p] != 0)
p = parent[p];
return p;
}
void union_set(int i, int j) {
if (i < j)
parent[i] = j;
else
parent[j] = i;
}
void kruskal(int a[MAX_VERTICES][MAX_VERTICES], int n) {
int u, v, min, k = 0, i, j, sum = 0;
while (k < n - 1) {
min = INT_MAX;
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (a[i][j] < min && i != j) {
min = a[i][j];
u = i;
v = j;
}
}
}
i = find(u);
j = find(v);
if (i != j) {
union_set(i, j);
printf("(%d,%d)=%d\n", u, v, a[u][v]);
sum = sum + a[u][v];
k++;
}
a[u][v] = a[v][u] = INT_MAX;
}
printf("the cost of minimum spanning tree= %d\n", sum);
}
int main() {
int a[MAX_VERTICES][MAX_VERTICES];
int i, j, n;
printf("Enter the number of vertices of the graph: ");
scanf("%d", &n);
printf("Enter the weighted matrix:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &a[i][j]);
}
}
for (i = 0; i < MAX_VERTICES; i++)
parent[i] = 0;
kruskal(a, n);
return 0;
}
