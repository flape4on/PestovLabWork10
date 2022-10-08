#include <stdio.h>
#include <pthread.h>
void main ()
{
	pthread_t f2_thread, f1_thread;
	void *f2 (), *f1();
	int i1 = 10, i2 = 10;
	pthread_create(&f1_thread, NULL, f1, &i1);
	pthread_create(&f2_thread, NULL, f2, &i2);
	pthread_join(f1_thread, NULL);
	pthread_join(f2_thread, NULL);
}
void *f1(int *x)
{
	int i,n;
	n = *x;
	for (i=1;i<n;i++)
	{
		printf("Pestov f1: %d\n", i);
		sleep (1);
	}
	pthread_exit (0) ;
}
void *f2(int *x)
{
	int i,n;
	n = *x;
	for (i=1;i<n; i++)
	{
		printf("Pestov f2: %d\n", i);
		sleep (1);
	}
	pthread_exit (0);
}
