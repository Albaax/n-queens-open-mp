# N-Queens problem solved in C using OpenMP

## Description

The N-queens problem is the mathematical problem of placing N-queens on a chessboard of dimension NxN, in such a way that none of them is attacked by another.

## Members

<ul>
  <li>Alberto Neuenfeld Helbig</li>
  <li>Giordano de Moraes Rossa</li>
  <li>Lucas Quevedo Garcia</li>
</ul>

## Instructions to use

### 1. Clone the repository

Open a terminal locally in a desired folder and type: 

``git clone https://github.com/Albaax/n-queens-open-mp.git``

After that, you should have all the needed files to compile and run the code.

### 2. To compile

```C
gcc -fopenmp nrainhas.c -o nrainhas
 ```

### 3. To run
Use ./nrainhas N t, where N is the number of queens and t is the number of threads.
```C
./nrainhas 8 8
./nrainhas 10 4
./nrainhas N t
```
### 4. Visualization of the solutions
The lines that display the solutions (29 - 34) are commented because the print function reduces quite a lot the performance of the program. By uncommenting those lines the program shall display all the solutions for a given N integer of queens.
