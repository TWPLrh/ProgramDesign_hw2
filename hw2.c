#include <stdio.h>
#include <stdlib.h>

void printMonthCalender(int Yea, int Mth);
void printYearCalender(int Yea);
void get_Blankdays(int Yea, int Mth);
void get_Febdays(int Yea);

int _28or29(int Yea);

/*Note -
	1990/1/1 is Monday */


//Global

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Blankturn[13], lockMth;

// --- INT ---

int main(int argc, char* argv[]){

	int Mth, Yea;

	Yea = atoi(argv[1]);
	Mth = atoi(argv[2]);

	if(Yea < 1900){
	printf("Please Input Year after 1900 (include 1900)");
	exit(1);
	}

	if(Mth > 12 || Mth < 1){
	printf ("Please Input Month 1 ~ 12\n");
	exit(1);
	}
	
	if(argc == 2)
	printMonthCalender(Yea,5);

	if(argc == 3)
	printMonthCalender(Yea, Mth);


	return 0;
}

int _28or29(int Yea){ 
	return ( (Yea%400==0) || ((Yea%4==0) && (Yea%100)));	
}

// --- VOID ---

void get_Blankdays(int Yea, int Mth){
	
	int i, firstblank;
	
	for (firstblank = 1, i=0; i<(Yea-1900); i++){
		if(_28or29(i)==1)
			firstblank=(firstblank+366)%7;
		else 
			firstblank=(firstblank+365)%7;
		}
	
	int Blankdays[13] = {0, firstblank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (lockMth=1; lockMth<Mth; lockMth++)
	Blankdays[lockMth+1] = ( Blankdays[lockMth] + days[lockMth] ) %7;
	for(i=0;i<=12;i++)
	Blankturn[i] = Blankdays[i];
}

void get_Febdays(int Yea){
	days[2] += _28or29(Yea);
}

void printMonthCalender(int Yea, int Mth){
	
	int i,j;

	get_Febdays(Yea);
	get_Blankdays(Yea, Mth);

	switch(Mth){
		case 1 : printf("January\n"); break;
		case 2 : printf("February\n"); break;
		case 3 : printf("March\n"); break;
		case 4 : printf("April\n"); break;
		case 5 : printf("May\n"); break;
		case 6 : printf("June\n"); break;
		case 7 : printf("July\n"); break;
		case 8 : printf("Augest\n"); break;
		case 9 : printf("September\n"); break;
		case 10 : printf("October\n"); break;
		case 11 : printf("November\n"); break;
		case 12 : printf("December\n"); break;
		}
	
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n"); 
	for(i=1; i<=Blankturn[lockMth]; i++)
		printf("     ");
	for(j=1; j<=days[lockMth]; j++){
		printf(" %2d  ", j);
		if(j%7 == ( 7-Blankturn[lockMth] % 7) )
		printf("\n");
	}
	printf("\n");
}
