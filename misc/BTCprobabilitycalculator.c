#include <stdio.h>
#include <math.h>
 
double AttackerSuccessProbability(double q, int z) //q is the attacker percentage of network CPU power, z is number of blocks to wait
   {
       double p = 1.0 - q;
       double lambda = z * (q / p);
       double sum = 1.0;
       int i, k;
       for (k = 0; k <= z; k++)
       {
           double poisson = exp(-lambda);
           for (i = 1; i <= k; i++)
               poisson *= lambda / i;
           sum -= poisson * (1 - pow(q / p, z - k));
   }
 
   return sum; 
}
 
int main(void) {
	float a = AttackerSuccessProbability(0.2, 10);
 
	printf("%.9f", a);
 
	return 0;
}

//based on original whitepaper available at: https://bitcoin.org/bitcoin.pdf
