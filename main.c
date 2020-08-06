#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include "struct.txt"
#include "enqueue.txt"
#include "queueenqueue.txt"
#include "dequeue.txt"
#include "copyqueue.txt"
#include "display_queue.txt"
#include "enter_data.txt"
#include "find_country.txt"
#include "checker.txt"
#include "date.txt"
#include "alert.txt"

int main()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	struct queue* qdup=(struct queue*)malloc(sizeof(struct queue));
	q->front=NULL;
	q->rear=NULL;
	qdup->front=NULL;
	qdup->rear=NULL;
	struct queue* qcompleted=(struct queue*)malloc(sizeof(struct queue));
	qcompleted->front=NULL;
	qcompleted->rear=NULL;
	struct queue* qpending=(struct queue*)malloc(sizeof(struct queue));
	qpending->front=NULL;
	qpending->rear=NULL;
	char opt;
	int c=1;
	do
	{
		printf("\n\nENTER THE DETAILS OF THE CUSTOMERS -%d\n",c);
		enter_data(q);
		printf("\n DO YOU WANT TO ADD ANY OTHER CONTRACT DETAILS  : ( Y / N ) ? ");
		scanf(" %c",&opt);
		c++;
	}while(opt=='y'|| opt=='Y');
	printf("\n**********************************************\n");
	printf("\n  THE DETAILS OF THE CUSTOMERS ARE AS FOLLOWS - \n");
	CopyQueue(q,qdup);
	Display_Queue(q);
	printf("\n **********************************************\n");
	printf("\n COMPLETION STATUS  -\n");
	checker(q,qcompleted,qpending);
	printf("\n ***********************************************\n");
	printf("\n COMPLETED CONTRACTS DISPLAY \n");
	Display_Queue(qcompleted);
	printf("\n PENDING CONTRACTS DISPLAY \n");
	Display_Queue(qpending);
	printf("\n ***********************************************\n");
	//Display_Queue(qdup);
	printf("\n ************************************************\n");
	printf("\n COUNTRY DETAILS SEARCH \n");
	char searchoption;
	do{
	printf("\n ENTER THE COUNTRY NAME WHOSE DETAILS ARE TO BE SEARCHED  : ");
	char country_name[30];
	scanf(" %[^\n]",country_name);
	find_country(country_name,qdup);
	printf("\n DO YOU WANT TO CONTINUE SEARCHING FOR COUNTRY DETAILS ? ( Y / N ) ");
	scanf(" %c",&searchoption);
	}while(searchoption=='y' || searchoption=='Y');
	printf("***************************************************\n");
	struct Date *d=(struct Date*)malloc(sizeof(struct Date));
	getCurrentDate(d);
	if(qpending->front!=NULL)
	{	
		printf("\n !!! OVERDUE CONTRACTS !!! \n");
		alert(qpending,d);
	}
	return 0;
}

