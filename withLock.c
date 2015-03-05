#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

void * func( void * arg){
	int * p = (int *)arg;
	int j;
	pthread_mutex_lock(&lock);
	for(j=0;j<3;j++){
		printf("%d\n", j);
		sleep(1);
	}
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
	puts("This won't get printed");
}


int main(){
	pthread_t tid[5];
	int i;
	void * exit_status[5];

	pthread_mutex_init(&lock, NULL);

	for( i=0;i<5;i++){
		pthread_create( &tid[i], NULL, func,( void *)&i );
	}

	for(i=0;i<5;i++){
		pthread_join( tid[i], &exit_status[i]);
	}

	pthread_mutex_destroy(&lock);

}