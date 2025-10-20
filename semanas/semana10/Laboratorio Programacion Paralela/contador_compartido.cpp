#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int contador = 0;        // variable compartida
std::mutex mtx;          // para proteger la sección crítica

void incrementar(int iteraciones, bool usar_mutex) {
    for (int i = 0; i < iteraciones; ++i) {
        if (usar_mutex) {
            std::lock_guard<std::mutex> lock(mtx);
            ++contador;
        } else {
            ++contador; // sin protección → condición de carrera
        }
    }
}

int main() {
    const int num_hilos = 8;
    const int iteraciones = 100000;
    bool usar_mutex = true; // Cambiar para no utlizar mutex

    std::vector<std::thread> hilos;

    for (int i = 0; i < num_hilos; ++i) {
        hilos.emplace_back(incrementar, iteraciones, usar_mutex);
    }

    for (auto& t : hilos)
        t.join();

    std::cout << "Contador final: " << contador << std::endl;
    return 0;
}
