#include <iostream>
#include <thread>
#include <vector>
#include <atomic>   // ✅ para std::atomic
using namespace std;

atomic<int> contador{0}; // ✅ contador atómico, operaciones seguras entre hilos

void trabajo(int n) {
    for (int i = 0; i < n; ++i) {
        contador++; // ✅ operación atómica (sin condición de carrera)
    }
}

int main() {
    int iter = 1'000'000;
    thread t1(trabajo, iter);
    thread t2(trabajo, iter);

    t1.join();
    t2.join();

    cout << "Valor final: " << contador.load() << endl; // ✅ lectura segura
    return 0;
}
