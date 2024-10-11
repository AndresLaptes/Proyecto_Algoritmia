import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

#SCRIPT PER VISUALITZAR UN GRAF (PER A CANVIAR EL FITXER DEL GRAF CANVIEU AQUESTES VARIABLES)
#CAL QUE NOMÉS HI HAGI UN GRAF A CADA FITXER

nom_fitxer = 'Graf_graella.csv'  # Canvia això pel nom del teu fitxer CSV
nom_resultat = 'out.png' #Canvia això pel nom del resultat

# Llegeix el CSV
def llegir_graf_csv(nom_fitxer):
    df = pd.read_csv(nom_fitxer)  # Llegeix el CSV sense capçalera
    graf = nx.Graph()  # Crea un graf no dirigit

    # Afegeix arestes al graf des de les files del CSV
    for _, fila in df.iterrows():
        print(fila[0])
        origen = fila[0]  # El primer element de la fila és el node origen
        for desti in fila[1:]:  # La resta són nodes destinació
            if pd.notna(desti):  # Ignora els valors NaN
                print("conectat a :" , desti)
                graf.add_edge(origen, desti)  # Afegeix una aresta entre l'origen i el destí
    return graf

# Executa el programa
graf = llegir_graf_csv(nom_fitxer)

#creem el plot
plt.figure(figsize=(8, 6))  # Configura la mida del gràfic
pos = nx.spring_layout(graf)  # Disposa els nodes en un layout "spring"
nx.draw(graf, pos, with_labels=True, node_color='lightblue', node_size=2000, font_size=10, font_weight='bold', edge_color='gray')
plt.title('Visualització del graf des del CSV')
plt.show()
plt.savefig(nom_resultat)  # Guarda el gràfic en un fitxer PNG

