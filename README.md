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

## Test des formules
Il est possible d'ajouter des formules dans le fichier *formules.txt*. Chaque formule est écrite sur une ligne séparée.  

> /!\ Il ne doit pas y avoir de ligne vide dans le fichier

### Exemple de fichier formules.txt
```{txt}
1+2
3+5()
31*(5+8)
8+5*31
8*5+6*1+3+6*10
8*
3
```

## Résultat
Le résultat de l'automate sera afficher dans un fichier *resultat.txt*.
> Lorsqu'une expression est incorrect la valeur de retour est -1  

Ainsi l'exemple précédant donnera comme résultat 
```{txt}
3
-1
403
163
109
-1
3
```
