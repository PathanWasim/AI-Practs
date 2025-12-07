#include <iostream>
using namespace std;

char b[9] = {'1','2','3','4','5','6','7','8','9'};

void show() {
    cout << "\n";
    for(int i=0;i<9;i++){
        cout << b[i] << " ";
        if(i%3==2) cout << endl;
    }
}

int win() {
    int w[8][3]={{0,1,2},{3,4,5},{6,7,8},
                {0,3,6},{1,4,7},{2,5,8},
                {0,4,8},{2,4,6}};
    for(int i=0;i<8;i++){
        if(b[w[i][0]]==b[w[i][1]] && b[w[i][1]]==b[w[i][2]]) {
            if(b[w[i][0]]=='O') return 1;   // AI win
            else return -1;                // Human win
        }
    }
    return 0;
}

int minimax(bool aiTurn) {
    int result = win();
    if(result!=0) return result;
    bool full=true;
    for(int i=0;i<9;i++) if(b[i]!='X' && b[i]!='O') full=false;
    if(full) return 0;

    if(aiTurn) {
        int best=-9;
        for(int i=0;i<9;i++)
            if(b[i]!='X' && b[i]!='O'){
                char t=b[i]; b[i]='O';
                best=max(best,minimax(false));
                b[i]=t;
            }
        return best;
    }
    else {
        int best=9;
        for(int i=0;i<9;i++)
            if(b[i]!='X' && b[i]!='O'){
                char t=b[i]; b[i]='X';
                best=min(best,minimax(true));
                b[i]=t;
            }
        return best;
    }
}

void bestMove() {
    int best=-9, move=0;
    for(int i=0;i<9;i++)
        if(b[i]!='X' && b[i]!='O'){
            char t=b[i]; b[i]='O';
            int val=minimax(false);
            b[i]=t;
            if(val>best){
                best=val;
                move=i;
            }
        }
    b[move]='O';
}

int main() {
    int pos;
    cout<<"You = X , AI = O\n";
    while(true){
        show();
        cout<<"Enter position: ";
        cin>>pos;
        b[pos-1]='X';

        if(win()==-1){ show(); cout<<"You Win!\n"; break;}
        bestMove();
        if(win()==1){ show(); cout<<"AI Wins!\n"; break;}
    }
    return 0;
}
