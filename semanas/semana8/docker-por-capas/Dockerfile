# Capa 1: base de sistema + python
FROM python:3.12-slim AS base
# Capa 2: directorio de trabajo
WORKDIR /app
# Capa 3: primero solo requeriments para cachear instalacion
COPY requirements.txt .
# Capa 4: instalar dependencias python
RUN pip install --no-cache-dir -r requirements.txt
# Capa 5: Se copia el codigo por aparte
COPY app.py .
# Capa 6 : variable de entorno por defecto
ENV SALUDO="Hola desde la imagen"
# Capa 7: documentacion de puertos
EXPOSE 5000
# Capa 8: Healtcheck para saber si responde
HEALTHCHECK --interval=30s --timeout=3s --retries=3 CMD \
    python -c "import urllib.request; urllib.request.urlopen('http://127.0.0.1:5000/', timeout=2)"
# Capa 9 
CMD ["python","app.py"]
