#include <iostream>
#include <stdio.h>

using namespace std;

int arr[65][65];

void rec(int startx, int starty, int n) {
    for (int i = starty; i < starty + n; i++) {
        for (int j = startx; j < startx + n; j++) {
            if (arr[i][j] != arr[starty][startx]) {
                cout << "(";
                rec(startx, starty, n / 2);
                rec(startx + n / 2, starty, n / 2);
                rec(startx, starty + n / 2, n / 2);
                rec(startx + n / 2, starty + n / 2, n / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << arr[starty][startx];
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    rec(0, 0, n);

    return 0;
}
