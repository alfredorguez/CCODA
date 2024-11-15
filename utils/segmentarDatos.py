import numpy as np

def obtenerExperimento(X : np.ndarray, U : np.ndarray, sizeExp : np.ndarray, numExperimento : int):

    if numExperimento == 0:
        return X.T[:,:sizeExp[numExperimento]], U.T[:,:sizeExp[numExperimento]]
    else:
        return X.T[:,sum(sizeExp[:numExperimento]):sum(sizeExp[:numExperimento+1])], U.T[:,sum(sizeExp[:numExperimento]):sum(sizeExp[:numExperimento+1])]