#include <vector>
#include <set>

using namespace std;

class ExamRoom {
private:
    set<int> seats;
    int last_seat;
public:
    ExamRoom(int N): last_seat(N - 1){
    }

    int seat() {
        if(seats.size() == 0){
            seats.insert(0);
            return 0;
        }
        int i = 0;
        auto it = seats.begin();
        int pre_seat = *it;
        int distance = pre_seat - i;
        for(; it != seats.end(); it++){
            if((*it - pre_seat) / 2 > distance) {
                distance = (*it - pre_seat) / 2;
                i = pre_seat + distance;
            }
            pre_seat = *it;
        }
        if(last_seat - pre_seat > distance) {
            i = last_seat;
        }
        seats.insert(i);
        return i;
    }    

    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */ 