#include <iostream>
#include <cstring>
using namespace std;

// Bugs intencionales: overflow, use-after-free y fuga de memoria.

char* copiar (const char* src) {
    size_t n = strlen(src);     
    char* buf = (char*) malloc(n);  // Error: no reserva espacio para '\0'  
    memcpy (buf, src, n + 1);       // Error: copia n+1 en buffer de n
    return buf;                     // Fuga si no se libera



}
int main() {
    const char* msg = "hola mundo";
    char* a = copiar(msg);  // Overflow al copiar
    cout << a << endl;

    free(a);
    cout << "Acceso posterior a free:" << a << endl; // Use-after-free

    char* leak = (char*) malloc(128);
    strcpy(leak, "leak detectado");     // Fuga de memoria
    
    return 0;
}