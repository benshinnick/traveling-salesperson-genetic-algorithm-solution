# traveling-salesperson-genetic-algorithm-solution
C++ Project that implements a genetic algorithm solution to the traveling salesperson problem and compares it to the optimal solution found via a brute force approach

# Project Instructions

## Background

A very famous graph/permutation problem is the Traveling Salesman Problem: given n cities with different distances among them and a designated first city, what is the least cost to visit all cities and return to the first one? Unfortunately, the brute-force method of solving this problem requires that we assess (n - 1)! permutations of the cities. How feasible is this?

However, not all is lost. For computationally "hard" problems such as this one, we may employ any of several means to find good if not strictly optimal solutions - say within 5-10%  of optimal. (Note that "computationally hard" problems are formalized as "np-complete" or "np-hard."). One way to address this problem might be based upon a simplified approach to the permutation form of genetic algorithms. As always, Wikipedia has some good information on this technique.

 

Here is a basic approach (based upon an algorithm presented at Wikipedia) to solve our problem:

```
      Choose the initial population of tours (generate a set of permutations of the orderings of the cities)
      Evaluate the fitness (cost) of each individual tour
      Repeat
          Select best-ranking individuals as elites (see below)
          Create additional tours through crossover, mutation or both (genetic operations) and give birth to offspring
          Add new permutations to fill out the current generation
          Evaluate the fitness of each individual tour
      Until termination criteria are met
```

## Subsequent Generations might be made up of:

### Mutations:

Make a minor change (for instance, randomly swap two, three, or four cities) to make a different version of an already good order.

## Crossovers:

Splice the end of one ordering to the end of another. This is not simple to realize with permutation problems (why?)

## Elites

Keep the few best tours as-is.

Make copies of them and mutate the copies.

### Termination of the Algorithm

You will repeat the process of creating a generation of tours, checking for the best, determining elites and creating mutations, until the program reaches a terminating condition. Typical ways to terminate this type of algorithm include:
- A solution is found that satisfies minimum criteria (found a tour that is less than some maximum acceptable cost)
- A fixed number of generations is reached. We will use this approach for this project.
- More iterations do not produce better results
We will use the fixed number of generations approach.

## Program Description

Your task in this assignment will be to write two solutions to the TSP problem, both of which will run in one program:

- a brute-force permutation program that systematically tries all possible permutations, ultimately computing the optimal answer.
- a genetic algorithm-inspired solution.

## Program Inputs

The program will utilize an input file named distances.txt which contains the weights of the edges between cities. You will read distances.txt. For simplicity, we will deal with a problem in which all cities connect to all other - in other words, with a complete graph. We will set up a single graph that can be used for 20 cities, more than we will need for this project. You will ALWAYS just read all values of the distances into a 20 X 20 adjacency matrix.
 
distances.txt will contain the appropriate number of distances between cities (380), one per line. Note - the number of items in the file is 380 rather than 400 because no cities connect to themselves. Read them as doubles.

When your program runs, it will interactively get the following information from the user:

- the number of cities to run
- how many individual tours are in a given generation
- how many generations to run
- what percentage of a generation should be comprised of mutations

Your program will always keep exactly two elites. The program reads the distances.txt file, gets the input from the user and then the two algorithms will grind away until output is produced.

A graphical representation of how the generations should work is available along with this file and distances.txt on the assignment page. The following link MIGHT work:

[Project3TSPGraphic.pdf](https://github.com/benshinnick/traveling-salesperson-genetic-algorithm-solution/files/8144876/Project3TSPGraphic.1.pdf)

Getting tours to try.

You can generate permutations using an iterative permutation algorithm as follows:

```
  void perm1(int permsThisCall) 
  {
     int m, k, p , q, i;
     printS();
     for(i = 1; i < permsThisCall; i++)
     {
       m = NUMELEMENTS-2;
       while(s[m]>s[m+1])
       {
          m = m - 1;
       }
       k = NUMELEMENTS-1;
       while(s[m] > s[k])
       {
          k = k - 1;
       }
       swap(m,k);
       p = m + 1;
       q = NUMELEMENTS-1;
       while( p < q)
       {
         swap(p,q);
         p++;
         q--;
       }
       printS();
     }
   }
```

## Notes on the algorithm:

The algorithm as presented will produce all permutations of NUMELEMENTS ints in the s array if the following is met

- int s[] // an int array external to the function
- NUMELEMENTS is the number of ints in the s array that you are permuting
- the parameter permsThisCall is NUMELEMENTS
- you must implement swap so that the state of s is maintained
- function printS() prints the s array, thereby displaying the next permutation.
- If permsThisCall is fewer that NUMELEMENTS you will get just that amount of permutations, for instance when you are filling out a generation in the GA.


## Experiments:

You will experiment with various values for these parameters to see which provide the best results for a given number of generations. You will incorporate timer capabilities into the programs so that you know how long runs with various parameters took. You will compare performance of the two approaches for different numbers of cities.

Start at 10 cities and go up by 1 from there until you see a runtime of greater than 5 minutes on the brute force solution. You will not have to go far to get there. Create a table that compares the time results from the approximation compared to the brute force from 10 cities up until the brute force method requires more than 5 minutes. Show what percentage of the optimal solution (eg: 120% of optimal) your approximation solution provides at each run.

## A Timer:

```
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
main()
{
  long i;
  struct timeval * t;

  t = (struct timeval *)malloc(sizeof(struct timeval));
  
  gettimeofday(t,NULL);
  
  time_t startSec = t->tv_sec;
  
  
  printf("seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
    
  for (i = 0; i < 3000000000; i++)
  { 
    if(i % 100000000 ==0)
    {
      gettimeofday(t,NULL);
      printf("time is now seconds %d microseconds %d\n",t->tv_sec - startSec,t->tv_usec); 
    } 
  }
  gettimeofday(t,NULL);
  printf("Final: seconds = %d microseconds = %d\n",t->tv_sec - startSec,t->tv_usec); 
}
```

## Output:

When the progam runs, it will display as output:

- The number of cities run
- optimal cost from brute force
- time the brute force algorithm took
- cost from the ga
- time the ga took to run
- percent of optimal (eg: 120%) that the ga produced 

## Deliverables

You will submit the following for this project:
1. A User's manual that describes how to set up and run your program.
2. A UML diagram reflecting the final layout of your program.
3. Your source code in C++.
4. Results file: An Excel spreadsheet containing the results from each run (for 10, 11, 12, etc cities) with one row for the 10 city, 11 city, 12 city, etc run. The column headers should be the 6 items output by a single run. This table is a summary of the data for all the individual  outputs from 10 cities, 11 cities, etc.
5. A makefile for the project
