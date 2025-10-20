#include <iostream>
#include <thread>
#include <vector>

void printMessage(int id) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Hilo " << id << " ejecutando iteración " << i << std::endl;
    }
}

int main() {
    std::vector<std::thread> hilos;

    // Crear 4 hilos independientes
    for (int i = 0; i < 4; ++i) {
        hilos.emplace_back(printMessage, i + 1);
    }

    // Esperar a que todos los hilos terminen
    for (auto& t : hilos) {
        t.join();
    }

    std::cout << "Todos los hilos han terminado.\n";
    return 0;
}
