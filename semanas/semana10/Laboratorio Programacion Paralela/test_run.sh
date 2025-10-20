#!/bin/bash

# Script para medir rendimiento del productor-consumidor
# Ejecuta el programa con distinto número de hilos

g++ -std=c++20 -O2 -pthread productor_consumidor.cpp -o productor_consumidor

for n in 1 2 4 8 16
do
  echo "Ejecutando con $n hilos de productores y consumidores..."
  start=$(date +%s.%N)
  ./productor_consumidor > /dev/null
  end=$(date +%s.%N)
  runtime=$(echo "$end - $start" | bc)
  echo "Tiempo: $runtime segundos"
  echo ""
done
