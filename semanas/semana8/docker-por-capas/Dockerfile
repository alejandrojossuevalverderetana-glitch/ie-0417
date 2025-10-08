# Etapa de build: prepara wheels 
FROM python:3.12-slim AS build 
WORKDIR /app 
COPY requirements.txt . 
RUN pip wheel --no-cache-dir --wheel-dir /wheels -r requirements.txt 

# Etapa final: runtime mínimo 
FROM python:3.12-slim AS runtime 
WORKDIR /app 
COPY --from=build /wheels /wheels 
RUN pip install --no-cache-dir /wheels/* 
COPY app.py . 
ENV SALUDO="Hola desde multi-stage" 
EXPOSE 5000 
CMD ["python", "app.py"]