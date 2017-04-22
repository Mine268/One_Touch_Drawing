#include "stdio.h"

typedef enum { false, true } bool;

bool flag = false; // indicate whether the drawing could be drawn in one path
int e[101][101], n, m, c;
/*
 * 'e' for the picture
 * 'n' for points
 * 'm' for lines
 * 'c' for the lines that hace been searched
*/
void search(int cur);
void printOut();

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++) // init the square
		for (j = 1; j <= n; j++)
			e[i][j] = 0;

	int a, b;
	for (i = 1; i <= m; i++) { // read the data
		scanf("%d %d", &a, &b);
		e[a][b]++;
		e[b][a]++;
	}

	int k;
	for (k = 1; k <= n; k++) // begin the search from each point
		search(k);

	if (flag == false)
		printf("false\n");
	else
		printf("true\n");

	getchar();
	getchar();
	return 0;
}

void search(int cur) { // core part
	int i;
	if (c == m) { // examine if all the lines have been searched
		flag = true;
		return;
	}

	for (i = 1; i <= n; i++) {
		if (e[cur][i] > 0) { // the lines No.'e[cur][i]'
			e[cur][i]--; // means that this line has been searched for one time
			e[i][cur]--;
			c++; // means the program has searched one line
			search(i);
			c--;
			e[cur][i]++;
			e[i][cur]++;
		}
	}
	return;
}

void printOut() { // print the square for debugging
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%-3d", e[i][j]);
		}
		printf("\n");
	}
	return;
}

