# Syntax Analysis and Evaluation of an Arithmetic Expression

LALR Automaton for analyzing the following grammar:
```
1. E' -> E
2. E -> E + E
3. E -> E * E
4. E -> ( E )
5. E -> val
```

## Usage
1. Execute the command: ```make```
2. Run the parser with the command: ```./bin/main```

## Testing Formulas
You can add formulas to the *formules.txt* file. Each formula should be written on a separate line.

> /!\ There should be no empty lines in the file.

### Example of a formules.txt file
```{txt}
1+2
3+5()
31*(5+8)
8+5*31
8*5+6*1+3+6*10
8*
3
```

## Result
The automaton's result will be displayed in the *resultat.txt* file.

For example, the above input will produce the following output:
```{txt}
3
Expression Error: 3+5() is not valid.
403
163
109
Expression Error: 8* is not valid.
3
```
