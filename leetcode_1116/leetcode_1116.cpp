#include <mutex>
#include <functional>

using namespace std;

class ZeroEvenOdd{
private:
    int n;
    mutex m0;
    mutex m1;
    mutex m2;
    int curr;

public:
    ZeroEvenOdd(int n){
      this->n = n;
      m1.lock();
      m2.lock();
      curr = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber){
      while (curr <= n){
        m0.lock();
        if (curr <= n) printNumber(0);
        curr % 2 ? m1.unlock() : m2.unlock();
      }
    }

    void even(function<void(int)> printNumber){
      while (curr <= n){
        m2.lock();
        if (curr <= n && curr % 2 == 0) printNumber(curr++);
        m0.unlock();
      }
    }

    void odd(function<void(int)> printNumber){
      while (curr <= n){
        m1.lock();
        if (curr <= n && curr % 2 == 1) printNumber(curr++);
        m0.unlock();
      }
    }
};