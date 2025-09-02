#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
vector<int> board;

vector<int> cal(int num) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            for (int k = 0; k < board.size(); k++) {
                if (board[i] + board[j] + board[k] == num) {
                    vector<int> temp;
                    temp.push_back(board[i]);
                    temp.push_back(board[j]);
                    temp.push_back(board[k]);
                    return temp;
                }
            }
        }
    }
}

int main() {
    int t;
    int now;

    for (int i = 1; i < 1001; i++) {
        arr[i] = i;
    }

    for (int i = 2; i < 1001; i++) {
        if (arr[i] != 0) {
            board.push_back(i);
            for (int j = i + i; j < 1001; j += i) {
                arr[j] = 0;
            }
        }
    }

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> now;
        vector<int> answer = cal(now);
        if (answer.size() > 0) {
            cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
