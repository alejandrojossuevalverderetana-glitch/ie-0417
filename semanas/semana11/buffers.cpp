#include <iostream>
#include <cstring>
#include <cstdlib>   // para malloc y free
using namespace std;

char* copiar(const char* src) {
    size_t n = strlen(src);
    // ✅ Reservamos espacio para los caracteres + el terminador '\0'
    char* buf = (char*) malloc(n + 1);

    if (!buf) { // comprobación de error por si malloc falla
        cerr << "Error: no se pudo asignar memoria." << endl;
        exit(EXIT_FAILURE);
    }

    // ✅ Copiamos exactamente n caracteres + el '\0'
    memcpy(buf, src, n + 1);
    return buf; // el llamador debe liberar
}

int main() {
    const char* msg = "hola mundo";
    char* a = copiar(msg);
    cout << a << endl;

    // ✅ Liberamos correctamente y no accedemos después de free
    free(a);
    a = nullptr; // buena práctica: anular puntero tras liberar

    // ✅ Asignamos, usamos y liberamos correctamente la memoria
    char* leak = (char*) malloc(128);
    if (!leak) {
        cerr << "Error: no se pudo asignar memoria." << endl;
        return 1;
    }
    strcpy(leak, "memoria manejada correctamente");
    cout << leak << endl;
    free(leak); // liberamos, ya no hay fuga

    return 0;
}
