#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        string result = "";
        int k=0,r=0,c=0;
        while(k<target.size()) {
            if(board[r][c]=='z' && target[k]!='z') {
                result+="U";
                r=4;
                c=0;
            }
            int ch = target[k]-'a';
            int row = ch/5, col = ch%5;
            while(r!=row){
                if(r>row){
                    result+="U";
                    r--;
                } else if(r<row && r<4){
                    result+="D";
                    r++;
                } else if(r==4 && row==5){
                    break;
                }
            }
            while(c!=col){
                if(c>col){
                    result+="L";
                    c--;
                } else if(c<col){
                    result+="R";
                    c++;
                }
            }
            if(target[k]=='z' && r==4 && c==0) {
                result+="D";
                r++;
            }
            if(r==row && c==col){
                result+="!";
            }
            k++;
        }
        return result;
    }

private:
    vector<string>board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
};