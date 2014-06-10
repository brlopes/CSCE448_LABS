/*
Bruno Lopes -- CSCE 448 HW1
Square Matrix multiply benchmark test

current time enlapsed:
5x5 matrix: .01s
10x10 matrix: .05s
15x15 matrix: .15s

to run: 
~$ gcc matrix_mult.c -o mm
~$ ./mm

*/

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
 

#define SIZE 256
void get_time()
{
       printf("TIME CHECK:");
       char buffer[SIZE];
       time_t curtime;
       struct tm *loctime;
     
       /* Get the current time. */
       curtime = time (NULL);
     
       /* Convert it to local time representation. */
       loctime = localtime (&curtime);
     
       /* Print out the date and time in the standard format. */
       fputs (asctime (loctime), stdout);
     
       /* Print it out in a nice format. */
       strftime (buffer, SIZE, "Today is %A, %B %d.\n", loctime);
       fputs (buffer, stdout);
       strftime (buffer, SIZE, "The time is %I:%M %p.\n", loctime);
       fputs (buffer, stdout);
}




int main()
{
  //get_time();//testing time.c

  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
  srand(time(NULL));
  int r,t , run5, loop;

clock_t start, end;
start = clock();

  printf("INPUT square matrix size: ");
  scanf("%d", &n);
  printf("How many loops? (x10000): ");
  scanf("%d", &loop);

  loop = loop*10000;

  printf("\nMatrix size selected size %d by %d\n", n, n);
  printf("Matrix multiply looping %d times\n\n", loop);

  m = n;
  p = n;
  q = n;

  printf("MATRIX A:\n\t");
  for (  c = 0 ; c < m ; c++ )
    for ( d = 0 ; d < n ; d++ )
	{
 	first[c][d] = rand() % 10;
	r = first[c][d];
	printf("%d \t", r);
	}


  
  if ( n != p )
    printf("ERROR - non-squared matrix \n");
  else
  {
      printf("\nMATRIX B:\n\t");
 
    	for ( c = 0 ; c < p ; c++ )
      		for ( d = 0 ; d < q ; d++ )
		{
		second[c][d] = rand() % 10;
		t = first[c][d];
		printf("%d \t", t);
		}


///multiply////////////////////////////////////////////////////////////////////
for (run5 = 0; run5 < loop; run5++)
{
     for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      {
        for ( k = 0 ; k < p ; k++ )
        {
          sum = sum + first[c][k]*second[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
      }
    }
}
///////////////////////////////////////////////////////////////////////////////


    printf("\nRESULT A*B: \n");
 
    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
        printf("%d\t", multiply[c][d]);
 
      printf("\n");
    }
  }
	end   = clock();
	double diff = (end - start);
	int cclock = CLOCKS_PER_SEC;
	diff = diff/cclock;
	printf("\n\nTIME ELAPSED: %e \n", diff);

  return 0;

}
