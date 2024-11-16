import numpy as np

def obtenerExperimento(X : np.ndarray, U : np.ndarray, sizeExp : np.ndarray, numExperimento : int):
    """
    Extrae los datos de un experimento específico a partir de matrices de datos y tamaños de experimento.

    :param X: Matriz de estados del sistema
    :type X: numpy.ndarray
    
    :param U: Matriz de entradas del sistema
    :type U: numpy.ndarray
    
    :param sizeExp: Array que contiene el tamaño de cada experimento
    :type sizeExp: numpy.ndarray
    
    :param numExperimento: Índice del experimento que se desea extraer (comienza desde 0)
    :type numExperimento: int

    :return: Subconjunto de la matriz de estados y entradas correspondiente al experimento seleccionado
    :rtype: tuple[numpy.ndarray, numpy.ndarray]
    """

    if numExperimento == 0:
        return X.T[:,:sizeExp[numExperimento]], U.T[:,:sizeExp[numExperimento]]
    else:
        return X.T[:,sum(sizeExp[:numExperimento]):sum(sizeExp[:numExperimento+1])], U.T[:,sum(sizeExp[:numExperimento]):sum(sizeExp[:numExperimento+1])]