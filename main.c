#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Process.h"

struct date{
	int day;
	int mon;
	int year;
};
int io=1;

void Arrear_input(char opfile[30],char Main_data[20][50][80],int tot_cou,int dept_count, struct date d);
void Main_Time_Table(char opfile[30], char Main_data[20][50][80],int course_count[15],int dept_count);



// Block 6 find sunday 
const int wd(int year, int month, int day) {
  
  return ((const int [])
          {0, 0, 0, 0, 0, 0, 1})
		  [(day+ ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)+ (365 * (year + 4800 - 
		  ((14 - month) / 12)))+ ((year + 4800 - ((14 - month) / 12)) / 4)- ((year + 4800 - ((14 - month) / 12)) / 100)+ 
		  ((year + 4800 - ((14 - month) / 12)) / 400)- 32045) % 7];
}
 
//======================================================================


// Block 5 printing the arrear TT as per the Main TT
void Arrear_input(char opfile[30],char Main_data[20][50][80],int tot_cou,int dept_count, struct date d)
{
	FILE *fptr;
	char filename[30];

	// geting arrear input file name.
	printf("\aEnter the arrear Input file : ");
	scanf("%s",&filename);
	fptr=fopen(filename,"r");

	FILE *opfp = fopen(opfile, "a");
	int p=0, i=0, j=0, k=0, b=0, c=0, v=0, l=0, a=0;
	char arr_data[100][100], line[75], st[10][50];

	fprintf(opfp,"\t\t\t\t\t\tSemester - %d\n\n",io);

	fgets(arr_data[i],150,fptr);
	fgets(arr_data[i],150,fptr);
	fgets(arr_data[i],150,fptr);


    strcpy(line,arr_data[i]);

	for(a=0;a<=(strlen(line));a++){
	    if(line[a]==','||line[a]=='\0'){
	        arr_data[c][b]='\0';
	        c++;
	        b=0;
	    }
	    else{
	        arr_data[c][b]=line[a];
	        b++;
	    }
	}
	fprintf(opfp,"\nArrear Time Table : \n");
	fprintf(opfp,".------------.-------------------------------------\n");
	fprintf(opfp,"|   Date     |              Course\n");
	fprintf(opfp,"|------------|-------------------------------------\n");
	for(p=1; p<= dept_count; p++){
		if (p < dept_count){
			int sun = wd(d.year,d.mon,d.day);
			if(sun==1){
				d.day+=1;
				fprintf(opfp,"| %-2d/%-2d/%-4d ",d.day,d.mon,d.year);
				d.day+=2;
			}
			else {
				fprintf(opfp,"| %-2d/%-2d/%-4d ",d.day,d.mon,d.year);
				d.day+=2;
			}
		}
		else fprintf(opfp,"---------------------------------------------------\n");
	    for (i=0; i<= dept_count; i++){
	        for (j=0; j< c ; j++){
					if ( strcmp(Main_data[i][p],arr_data[j])==0){
	            	for( l=0;l<c;l++){
						if(strcmp(st[k],arr_data[j])!=0){
							fprintf(opfp,"| %-8s ",arr_data[j]);
						}
						strcpy(st[k],arr_data[j]);
					}
				}
	        }
	    }
	   
		fprintf(opfp,"\n");
	}
	fclose(fptr);
	fclose(opfp);
	
}


// //=======================================================================


// printing the main data in order and checking sunday 
// //  Block - 4.1
void Main_Time_Table(char opfile[30], char Main_data[20][50][80],int course_count[15],int dept_count)
{
	int i,j;
	char Time[5]="";
    struct date d,d1;
    FILE *opfp = fopen(opfile, "a");
    fprintf(opfp,"\nMain TIme Table\n");
	printf("\n");

		// Geting date and time as input.
	printf("Enter the Exam starting Date (dd/mm/yyyy) : ");
	scanf("%d/%d/%d",&d.day,&d.mon,&d.year);
	printf("Enter the Exam starting Time : ");
	scanf("%s",Time);


	d1.day = d.day;
	d1.mon = d.mon;
	d1.year = d.year;
	int max = course_count[0];


    for (i = 1; i < dept_count-2; i++)
        if (course_count[i] > max)
            max = course_count[i];
            
    fprintf(opfp,".");       
    for(j=0; j<max+1; j++) fprintf(opfp,"------------.");
    fprintf(opfp,"\n");
    

    for(i=0; i<max+1; i++){
    	if (i==0) fprintf(opfp,"|    Date    |");
    	else {
			// checking sunday.
			int sun =wd(d.year,d.mon,d.day);
			if(sun==1){
				d.day+=1;
				fprintf(opfp,"  %-2d/%-2d/%-4d|",d.day,d.mon,d.year);
				d.day+=2;
			}
			else {
				fprintf(opfp,"  %-2d/%-2d/%-4d|",d.day,d.mon,d.year);
				d.day+=2;
			}
			
		}
	}


	fprintf(opfp,"\n");
	int t_len=strlen(Time);
    for(i=0; i<max+1; i++){
		
		if (i==0) fprintf(opfp,"|    Time    |");
		else fprintf(opfp," %4s-%2d:%c%c |",Time,atoi(Time)+4,Time[t_len-2],Time[t_len-1]);
		if (i==max) fprintf(opfp,"\n|");
		if (i==max) for(j=0; j<max+1; j++) fprintf(opfp,"------------|");
	}
	fprintf(opfp,"\n");
	
	for(i=0; i<max+1; i++){
		if (i==0) fprintf(opfp,"|     Dept   ");
		else fprintf(opfp,"|  Course %2d ",i);
		if (i==max) fprintf(opfp,"|\n|");
		if (i==max) for(j=0; j<max+1; j++) fprintf(opfp,"------------|");
	}
	fprintf(opfp,"\n");
	
	int tot_cou = i;
	
	for(i=0; i<dept_count-1; i++){
		if (i==dept_count-2) for(j=0; j<max+1; j++) if(j==0)fprintf(opfp,"`------------`");else fprintf(opfp,"------------`");
		if (i==dept_count-2) break;
    	for(j=0; j<max+1; j++){
    		if (j<=course_count[i]) fprintf(opfp,"|  %-10s",Main_data[i][j]);
    		else fprintf(opfp,"|            ");
		}
		fprintf(opfp,"|\n");
	}
	fprintf(opfp,"\n");

	// arrear Time Table.
	Arrear_input(opfile,Main_data, tot_cou, dept_count, d1);
	fclose(opfp);
	return ;
}


// //=======================================================================


int main(int argc, char *argv[])
{
	printf("\n\n\t\t\tWelcome to Exam Time Tabling Scheduler\n\n\a");

	char infile[30]="test.txt", opfile[30]="o";
	int sem_count=1;

	printf("How Many SEMESTER : ");
	scanf("%d",&sem_count);
	printf("Enter the Output File name : ");
	scanf("%s",&opfile);

	// this loop is use to print more then one semester TT.
	for (io=1; io<=sem_count; io++)
	{
		printf("\a\nEnter the Sem %d Input file : ",io);
		scanf("%s",&infile);

		// call the fun to read input from file.
		Input_reader(infile, opfile);
	}

	printf("\n\n\t\t Please Check The \"%s\" :)\n\n",opfile);
	printf("\t\t\t\a Thank You :)\n\n\n");
	return 0;
}


//                                Thank You.