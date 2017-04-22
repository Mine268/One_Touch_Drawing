#include "stdio.h"

typedef enum { false, true } bool;

bool flag = false;
int e[101][101], n, m, c;
void search(int cur);
void printOut();

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		e[i][j] = 0;

	int a, b;
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		e[a][b]++;
		e[b][a]++;
	}

	int k;
	for (k = 1; k <= m; k++)
		search(k);

	if (flag == false)
		printf("false\n");
	else
		printf("true\n");

	getchar();
	getchar();
	return 0;
}

void search(int cur) {
	int i;
	if (c == m) {
		flag = true;
		return;
	}

	for (i = 1; i <= n; i++) {
		if (e[cur][i] > 0) {
			e[cur][i]--;
			e[i][cur]--;
			c++;
			search(i);
			c--;
			e[cur][i]++;
			e[i][cur]++;
		}
	}
	return;
}

void printOut() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%-3d", e[i][j]);
		}
		printf("\n");
	}
	return;
}

