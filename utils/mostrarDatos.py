import matplotlib.pyplot as plt
import numpy as np

def visualizarPerfiles(matriz, title : str = "", colormap : str = "viridis", tm : float = 5e-3):
    """
    Visualiza una matriz de datos como si fuera una imagen.

    :param matrix: Matriz de datos donde cada columna es un perfil y cada fila un punto específico del perfil
    :type matrix: numpy.ndarray
    
    :param title: Título de la gráfica (por defecto "Matriz de datos")
    :type title: str
    
    :param colormap: Mapa de colores a utilizar (por defecto "viridis")
    :type colormap: str
    
    :param tm: Tiempo de muestreo en segundos (por defecto 5e-3 segundos)
    :type tm: float

    :return: None
    """

    if not isinstance(matriz, np.ndarray):
        raise ValueError("La matriz debe ser un numpy.ndarray")

    tiempo = np.arange(0, matriz.shape[1] * tm, 10)

    plt.figure(figsize=(10, 6))
    plt.imshow(matriz, aspect='auto', cmap=colormap, origin='lower')
    plt.colorbar(label="Produndidad [mm]")
    plt.title(title)
    plt.xlabel("Tiempo [s]")
    plt.ylabel("Ancho [mm]")
    plt.xticks(tiempo, np.round(tiempo, 3))
    plt.tight_layout()
    plt.show()
