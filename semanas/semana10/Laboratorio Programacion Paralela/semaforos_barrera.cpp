#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>
#include <barrier>
#include <chrono>

const int N_HILOS = 6;
const int RECURSOS_MAX = 3;

std::counting_semaphore<RECURSOS_MAX> semaforo(RECURSOS_MAX);
std::barrier barrera(N_HILOS, []() noexcept {
    std::cout << "\n--- Ronda completada ---\n";
});

void tarea(int id) {
    for (int ronda = 1; ronda <= 3; ++ronda) {
        semaforo.acquire(); // tomar recurso
        std::cout << "Hilo " << id << " accede al recurso (ronda " << ronda << ")\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        semaforo.release(); // liberar recurso
        barrera.arrive_and_wait(); // esperar a que todos terminen ronda
    }
}

int main() {
    std::vector<std::thread> hilos;
    for (int i = 0; i < N_HILOS; ++i)
        hilos.emplace_back(tarea, i + 1);

    for (auto& t : hilos)
        t.join();

    std::cout << "\nTodas las rondas completadas.\n";
    return 0;
}
