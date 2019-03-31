#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int graph[10000][10000];
int dp[10000][10000];

int find_max_path(int parent, int current, int nvill);
int longest_path(int start, int nvill);

int main() {
	int vill1 = 0, vill2 = 0, len = 0;
	int nvill = 0;
	int max = 0, curr = 0;
	
	string sep="";
	
	do {
		sep="";
		getline(cin, sep);
		
		if (sep == "" && nvill != 0) {
				
			for(int i = 0; i < nvill; i++) {
				curr = longest_path(i, nvill);

				if (curr > max) max = curr;				
			}
			
			cout << max <<endl;
			
//			memset(graph, 0, sizeof(graph[0][0]) * nvill * nvill);
//			memset(dp, 0, sizeof(dp[0][0]) * nvill * nvill);

			for (int i = 0; i < nvill; i++) {
				for (int j = 0; j < nvill; j++) {
					graph[i][j] = 0;
					dp[i][j] = 0;
				}
			}
			max = 0, curr = 0, nvill = 0;
			// reiniciar todo		
			continue;
		}
		else if (sep == "" && nvill == 0) {
			break;
		}
		
		// vill1 = atoi(sep);
		sscanf(sep.c_str(), "%d %d %d", &vill1, &vill2, &len);
		
		if (vill1 > vill2 && vill1 > nvill) nvill = vill1;
		else if (vill1 < vill2 && vill2 > nvill) nvill = vill2;
		
		vill1--; vill2--;
		
		graph[vill1][vill2] = len;
		graph[vill2][vill1] = len;
		
	} while(true);

	return 0;
}

int longest_path(int start, int nvill) {
	int max = 0, curr = 0;
	for(int i = 0; i < nvill; i++) {
		if (graph[start][i] != 0) {
			if (dp[start][i] != 0) {
				curr = dp[start][i];
//				printf("Dp usados para: %d,%d=%d \n", start+1, i+1, dp[start][i]);
			}
			else {
				curr = find_max_path(start, i, nvill);
				dp[start][i] = curr;				
			}
			if (curr > max) max = curr;
		}
	}
	
	return max;
}

int find_max_path(int parent, int current, int nvill) {
	int res = graph[parent][current];
	int curr = 0, max = 0;
	
	for(int i = 0; i < nvill; i++) {
		if (i == parent) continue;
		
		if (graph[current][i] != 0) {
			if (dp[current][i] == 0) {
				curr = find_max_path(current, i, nvill);
				dp[current][i] = curr;
			}
			else {
//				printf("Dp usados para: %d,%d=%d \n", current+1, i+1, dp[current][i]);
				curr = dp[current][i];		
			}
		}
		if (curr > max) max = curr;
	}
	
	return res + max;
}
