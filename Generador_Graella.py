import networkx as nx
import matplotlib.pyplot as plt
import random
import numpy as np
import csv

def generar_graella(n):
    G = nx.Graph()

    # Afegir nodes i arestes
    for i in range(n):
        for j in range(n):
            node = (i, j)  # Cada node és una tupla (fila, columna)
            G.add_node(node)
        
            # Connectar amb el node de la dreta
            if j < n - 1:
                G.add_edge((i, j), (i, j + 1))
            #Connectar amb el node de l'esquerra
            if j > 0:
                G.add_edge((i,j), (i, j - 1))
            # Connectar amb el node de baix
            if i < n - 1:
                G.add_edge((i, j), (i + 1, j))
            if i > 0:
            # Connectar amb el node de dalt
                G.add_edge((i, j), (i - 1, j))
    return G

def guardar_graella_en_fitxer(G, fitxer):
    nodes = list(G.nodes())
    node_index = {nodes[i]: i for i in range(len(nodes))}  # Diccionari per a obtenir l'índex de cada node

    with open(fitxer, 'w') as f:
        for node in nodes:
            # Obtenim els veïns (nodes amb els que comparteix aresta)
            veins = list(G.neighbors(node))
            # Escrivim la línia al fitxer
            f.write(f"{node_index[node]}," + ",".join(str(node_index[v]) for v in veins) + "\n")


n = int(input("Introdueix el nombre de grafs a generar\n")) # Numero de grafs creats
nom_resultat_csv = './docs/graf_graella'  # Nom del fitxer de sortida per al CSV

for i in range(n):
    nom_csv = nom_resultat_csv+str(i)
    num_nodes = int(input("Introdueix la mida desitjada del graf " + str(i) + " (rang [2..9])\n")) #Alçada
    if (num_nodes > 1 and num_nodes < 10):
        G = generar_graella(num_nodes)
        guardar_graella_en_fitxer(G,nom_csv+'.csv')
    else: print("Error: Mida invàlida")