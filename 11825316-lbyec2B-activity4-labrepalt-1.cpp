#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dataSet 
{
  float set[20];
  int number;
} data_s;

void input(data_s *x, data_s *y) 
{
   printf("\nNumber of datas? ");
   scanf("%i", &(y -> sampleSpace));
   for (int i = 0; i < y.sampleSapce; i++) 
   {
   	printf("\ndata %d: ", i);
   	scanf("%d", &(x -> datax[i].dataSample))
   }
}


data_s sort(data_s a, data_s b)
{
   complex_t temp;
   temp.real = a.real + b.real;
   temp.imag = a.imag + b.imag;
   return temp;
}


data_s Range(complex_t a, complex_t b)
{
   complex_t temp;
   temp.real = a.real + b.real;
   temp.imag = a.imag + b.imag;
   return temp;
}

data_s subtract_complex(complex_t a, complex_t b)
{
   complex_t temp;
   temp.real = a.real - b.real;
   temp.imag = a.imag - b.imag;
   return temp;
}

void magnitude_complex(complex_t a, complex_t b)
{
   complex_t temp;
   float magA = sqrt(pow(a.real, 2) + pow(a.imag, 2));
   float magB = sqrt(pow(b.real, 2) + pow(b.imag, 2));
   printf("The magnitudes of A and B are %f and %f", magA, magB);
}

void angle_complex(complex_t a, complex_t b)
{

   float angA =  atan2(a.imag,a.real);
   float angB =  atan2(b.imag,b.real);
   printf("The angles of A and B are %f and %f", angA, angB);
}

//prints the menu
int display_menu();
//directs the chosen number to action
void action(int choice, complex_t *a, complex_t * b);
// prints values of a complex number
void print_complex(complex_t a);
// defines a complex value by supplying the real and imag values
complex_t complex(float a, float b);
          
int main() 
{
	int choice;
	data_s sample;
	data_s number;
	
	while (true)
	{
		choice = display_menu();
		action(choice, &sample, &number);
	}
}

int display_menu() 
{
	int choice;
	printf("Measures of Variation Menu\n");
	printf("1. input Data Set\n");
	printf("2. Sort Data Set\n");
	printf("3. Range\n");
	printf("4. Mean\n");
	printf("5. Variance\n");
	printf("6. Standard Deviation\n");	
	printf("7. exit\n");
	printf("choice: ");
	scanf("%d", &choice);
	if (choice < 1 || choice > 7)
	{
		return display_menu();
	}
	
	return choice;
}

void action(int choice, data_s *x, data_s * y)
{
	complex_t result;
	switch (choice)
	{
	case 1:
			input(x, y);
			return;
	case 2:
			sort(*x, *y);
			break;
	case 3:
			result = add_complex(*x,*y);
			break;
	case 4:
			result = subtract_complex(*x,*y);
			break;
	case 5:
			magnitude_complex(*x,*y);
			return;
	case 6:
			angle_complex(*x,*y);
			return;
	case 7:
			print_complex(*x);
			print_complex(*y);
			return;
	case 8:
			exit(0);
	}
	
	printf("The result of the operation is: ");
	print_complex(result);	
}

