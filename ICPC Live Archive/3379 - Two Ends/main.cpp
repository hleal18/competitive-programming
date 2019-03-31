#include <iostream>
#include <string>
#include <map>
using namespace std;

int find_max_lost(int cards[], int start, int end, int dp[][1000]);

int main() {

    int games = 0, input = 0;
    int dp[1000][1000];

    do {
        cin >> input;
        int cards[input];
        int points_lost = 0;

        for (int i = 0; i < input; ++i) {
            cin >> cards[i];
        }

        games++;

        for(int i = 0; i < input; i++) {
            for(int j = 0; j < input; j++) {
                dp[i][j] = -1;
            }
        }
        if (input != 0) {
            points_lost = find_max_lost(cards, 0, input - 1, dp);
            cout << "In game " << games << ", the greedy strategy might lose by as many as " << points_lost
                 << " points." << endl;
        }
    } while(input != 0);


    return 0;
}

int find_max_lost(int cards[], int start, int end, int dp[][1000]) {
    int first_left, first_right, second_left, second_right;
    int result_left, result_right;
    int start_right = start, end_right = end, start_left = start, end_left = end;
    int difference_left = 0, difference_right = 0;
    int result = 0;

    if (start + 1 == end) {
        difference_left = cards[start] - cards[end];
        difference_right = cards[end] - cards[start];
        result = (difference_left > difference_right) ? difference_left : difference_right;
        dp[start][end] = result;
        return result;
    }

    first_left = cards[start_left++];
    second_left = cards[start_left] >= cards[end_left] ? cards[start_left++] : cards[end_left--];
    difference_left = first_left - second_left;

    result_left = (dp[start_left][end_left] != -1) ? dp[start_left][end_left] : find_max_lost(cards, start_left, end_left, dp);
    //result_left = find_max_lost(cards, start_left, end_left, dp);

    first_right = cards[end_right--];
    second_right = cards[end_right] > cards[start_right] ? cards[end_right--] : cards[start_right++];
    difference_right = first_right - second_right;

    result_right = (dp[start_right][end_right] != -1) ? dp[start_right][end_right] : find_max_lost(cards, start_right, end_right, dp);

    //result_right = find_max_lost(cards, start_right, end_right, dp);

    difference_left += result_left;
    difference_right += result_right;

    result = (difference_left > difference_right) ? difference_left : difference_right;
    dp[start][end] = result;
    return result;
}