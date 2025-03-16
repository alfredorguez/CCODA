import matplotlib.pyplot as plt
import numpy as np

def visualizarPerfiles(matriz, title : str = "", colormap : str = "jet", tm : float = 5e-3):
    """
    Visualiza una matriz de datos como si fuera una imagen.

    :param matrix: Matriz de datos donde cada columna es un perfil y cada fila un punto específico del perfil
    :type matrix: numpy.ndarray
    
    :param title: Título de la gráfica (por defecto "Matriz de datos")
    :type title: str
    
    :param colormap: Mapa de colores a utilizar (por defecto "jet")
    :type colormap: str
    
    :param tm: Tiempo de muestreo en segundos (por defecto 5e-3 segundos)
    :type tm: float

    :return: None
    """

    if not isinstance(matriz, np.ndarray):
        raise ValueError("La matriz debe ser un numpy.ndarray")

    tiempo = np.linspace(0,matriz.shape[1]*tm,10).astype(int)

    plt.figure(figsize=(10, 6))
    plt.imshow(matriz, aspect='auto', cmap=colormap, origin='lower')
    plt.colorbar(label="Produndidad [mm]")
    plt.title(title)
    plt.xlabel("Tiempo [s]")
    plt.ylabel("Ancho [mm]")
    plt.xticks(np.linspace(0,matriz.shape[1],len(tiempo)),[f"{t:.3f}" for t in tiempo])
    plt.tight_layout()
    plt.show()
