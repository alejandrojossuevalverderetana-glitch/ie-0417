#include <iostream>
#include <vector>
using namespace std;

int suma(const vector<int>& v) {
    int total = 0;
    // ✅ Recorremos todos los elementos del vector
    for (size_t i = 0; i < v.size(); ++i) {
        total += v[i];
    }
    return total;
}

int main() {
    vector<int> datos = {1, 2, 3, 4}; // suma esperada = 10
    int s = suma(datos);
    cout << "Suma calculada: " << s << endl;

    // ✅ Evitamos el acceso fuera de rango
    // Último índice válido es size() - 1 = 3
    cout << "Elemento en índice 3: " << datos.at(3) << endl;

    return 0;
}
