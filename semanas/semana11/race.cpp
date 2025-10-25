#include <iostream>
#include <thread>
#include <vector>
using namespace std;

int contador = 0;

void trabajo(int n) {
    for (int i = 0; i < n; ++i) {
        contador++; // condicion de carrera
    }
}

int main() {
    int iter = 1000000;
    thread t1(trabajo, iter);
    thread t2 (trabajo, iter);
    t1.join();
    t2.join();

    cout << "Valor final: " << contador << endl; // Esperado: 2000000
    return 0;

}