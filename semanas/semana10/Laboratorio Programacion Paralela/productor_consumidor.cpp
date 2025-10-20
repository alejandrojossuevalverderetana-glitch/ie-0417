#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;
std::condition_variable cv_productor, cv_consumidor;
std::queue<int> buffer;
const unsigned int MAX_BUFFER = 5;
bool terminado = false;

void productor(int id, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_productor.wait(lock, [] { return buffer.size() < MAX_BUFFER; });

        int item = i + id * 100;
        buffer.push(item);
        std::cout << "Productor " << id << " produjo " << item << std::endl;

        cv_consumidor.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::unique_lock<std::mutex> lock(mtx);
    terminado = true;
    cv_consumidor.notify_all();
}

void consumidor(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumidor.wait(lock, [] { return !buffer.empty() || terminado; });

        if (buffer.empty() && terminado) break;

        int item = buffer.front();
        buffer.pop();
        std::cout << "\tConsumidor " << id << " consumió " << item << std::endl;

        cv_productor.notify_all();
        lock.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    std::thread p1(productor, 1, 10);
    std::thread p2(productor, 2, 10);
    std::thread c1(consumidor, 1);
    std::thread c2(consumidor, 2);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    std::cout << "Ejecución completada.\n";
    return 0;
}
