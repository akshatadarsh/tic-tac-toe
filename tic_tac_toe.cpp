#include <bits/stdc++.h>
using namespace std;

class tic_tac_toe {
   private:
    char board[3][3];
    int remaining_size = 9;
    bool turn = true;  // true -> x

   public:
    bool get_player_move(int r, int c) {
        if (is_valid(r, c)) {
            update_board(r, c);
            return false;
        } else {
            cout << "Invalid move"
                 << "\n";
            return true;
        }
    }
    bool is_valid(int r, int c) {
        if(r > 2 || r < 0 || c > 2 || c < 0) return false;
        else if (board[r][c] == '*')
            return true;
        else
            return false;
    }
    bool is_board_full() {
        if (remaining_size == 0) {
            cout << "MATCH OVER NO ONE WIN"
                 << "\n";
            return true;
        } else {
            return false;
        }
    }
    void update_board(int r, int c) {
        if (turn) {
            board[r][c] = 'x';
            turn = false;
        } else {
            board[r][c] = 'o';
            turn = true;
        }
        remaining_size--;
    }
    bool check_row() {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) &&
                board[i][1] != '*') {
                cout << board[i][0] << " is victories";
                return 1;
            }
        }
        return 0;
    }
    bool check_column() {
        for (int i = 0; i < 3; i++) {
            if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) &&
                board[1][i] != '*') {
                cout << board[0][i] << " is victories";
                return 1;
            }
        }
        return 0;
    }
    bool check_digonal() {
        if (((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
             (board[0][2] == board[1][1] && board[1][1] == board[2][0])) &&
            (board[1][1] != '*')) {
            cout << board[1][1] << " is victories";
            return 1;
        }
        return 0;
    }
    void show_board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    void clean_board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '*';
            }
        }
    }
};

int main() {
    tic_tac_toe v;
    v.clean_board();
    v.show_board();
    while (1) {
        int r, c;
        cin >> r >> c;
        while (v.get_player_move(r, c)) {
            cin >> r >> c;
        }
        v.show_board();
        if (v.check_column()) return 0;
        if (v.check_row()) return 0;
        if (v.check_digonal()) return 0;
        if (v.is_board_full()) return 0;
    }
}
