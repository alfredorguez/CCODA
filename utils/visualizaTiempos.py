import pandas as pd
import matplotlib.pyplot as plt

# Leer el archivo de texto
df = pd.read_csv("datos/tiempos.txt", delim_whitespace=True)

# Mostrar el DataFrame por consola
print("Contenido del DataFrame:")
print(df)

# Crear el histograma
plt.figure(figsize=(10, 6))
plt.hist(df["Tiempo(s)"]*1000, bins=20, color='blue', edgecolor='black', alpha=0.7, density=True)
plt.xlabel("Tiempo [ms]", fontsize=14)
plt.ylabel("Frecuencia normalizada", fontsize=14)
plt.grid(True)
plt.tight_layout()
#plt.savefig("tiempos.eps", format="eps")
plt.show()