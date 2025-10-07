from flask import Flask, jsonify
import os 

app = Flask(__name__)

@app.route("/")
def home():
    saludo = os.getenv("SALUDO", "Hola desde Docker")
    return jsonify({"ok":True, "mensaje":saludo})

if __name__ == "__main__":
    # 0.0.0.0 expone el servidor a la interfaz de red del contenedor
    # necesario para que el host pueda acceder via -p
    app.run(host = 0.0.0.0, port=5000)