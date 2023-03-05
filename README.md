# Analyse syntaxique et évaluation d'une expression arithmétique

Automate LALR permettant l'analyse de la grammaire suivante
```
1. E' -> E
2. E -> E + E
3. E -> E * E
4. E -> ( E )
5. E -> val 
```

## Utilisation 
1. Executer la commande: ```make```
2. Lancer l'analyseur avec la commande: ```./bin/main```
