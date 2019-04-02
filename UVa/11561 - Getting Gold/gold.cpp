#include <iostream>
using namespace std;

int find_max_points(char board[][50], int currentX, int currentY, int H, int W);
bool isSafe(char board[][50], int currentX, int currentY);

int main() {
	
	// W and H, width and height of the board.
	// Next H lines with W characters, the content of the board for each cell.
	// Symbols:
	// P (starting position)
	// G piece of gold.
	// T trap.	
	// # a wall.
	// V for a visited node.
	// . normal floor (safe).
	// The input contains severeal test cases.
	string input = "";
	int W, H, res;
	int startX, startY;
	
	char board[50][50];
	
	do {
		input = "";
		
		getline(cin, input);
		
		if (input == "") {
			break;
		}
		
		sscanf(input.c_str(), "%d %d", &W, &H);
		
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'P') {
					startX = i;
					startY = j;
				}					
			}
		}
		
		
		res = find_max_points(board, startX, startY, H, W);
		cout << res <<endl;
		// Hallar resultado;
		cin.ignore();
		
		
	} while(true);
	
	return 0;
}

int find_max_points(char board[][50], int currentX, int currentY, int H, int W) {
	int points = 0;
	
	if (currentX == 0 || currentY == 0) return 0;
	else if (currentY + 1 == W || currentX + 1 == H) return 0;
	// Valid position.
	else if (board[currentX][currentY] == '#' ||
				board[currentX][currentY] == 'V' ||
				board[currentX][currentY] == 'T')
		return 0;

	// Position with points.
	if (board[currentX][currentY] == 'G') points++;
	
	board[currentX][currentY] = 'V';
	
	if (!isSafe(board, currentX, currentY)) return points;
	
	points += find_max_points(board, currentX+1, currentY, H, W);
	points += find_max_points(board, currentX-1, currentY, H, W);
	points += find_max_points(board, currentX, currentY+1, H, W);
	points += find_max_points(board, currentX, currentY-1, H, W);
	
	return points;
}

bool isSafe(char board[][50], int currentX, int currentY) {
	// Left
	if (board[currentX][currentY-1] == 'T') return false;
	// Right
	else if (board[currentX][currentY+1] == 'T') return false;
	// Up
	else if (board[currentX-1][currentY] == 'T') return false;
	// Down
	else if (board[currentX+1][currentY] == 'T') return false;
	
	return true;
}
