#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lim = 0;


int Input_reader(char ipfile[30], char opfile[30]);
void Main_Time_Table(char opfile[30], char Main_data[20][50][80],int course_count[15],int dept_count);
int reorder_data(char opfile[30], char Main_data[20][50][80],int num_course[15],int ana_count_data[80],int dept_count,char ana_course_data[80][40], int total_course);
int sub_count(char Main_data[20][50][80],int num_course[15],int ana_count_data[80],char ana_course_data[80][40],int dept_count);
void std_timetable(char opfile[30], char room_data[100][100],int std_count);
void staff_timetable(char opfile[30], char staff_data[100][100],char room_data[100][100]);



//======================================================================


// // Student Time table Block - 4.3
void std_timetable(char opfile[30], char room_data[100][100],int std_count)
{

	int i,j=1;
    FILE *opfp = fopen(opfile, "a");

    fprintf(opfp,"\nStudent time table:\n");
	fprintf(opfp,"|---------------------------------|\n");
	fprintf(opfp,"|   Room No  |        Reg no      |\n");
	fprintf(opfp,"|------------|--------------------|\n");
	for (i=0; i<= std_count; i=i+25){
		if (i==0)fprintf(opfp,"");
		else if (i==1) fprintf(opfp,"| %4s   |  %4d   to   %4d   |\n",room_data[j++],i,i);
		else fprintf(opfp,"| %-8s   |  %-4d   to   %-4d  |\n",room_data[j++],i-24,i);
        lim++;
    }
	fprintf(opfp,"|---------------------------------|\n");
	fclose(opfp);
}



// //=======================================================================


//staff_tmetable Block 4.2
void staff_timetable(char opfile[30], char staff_data[100][100],char room_data[100][100])
{

	int i;
    FILE *opfp = fopen(opfile, "a");

	fprintf(opfp,"\nStaff time table:\n");
	fprintf(opfp,"---------------------------------\n");
	fprintf(opfp,"|	Staff name	|    Room No    |\n");
	fprintf(opfp,"---------------------------------\n");
	for(i=1;i<lim;i++){
		fprintf(opfp,"|	%-15s	|   %-5s	|\n",staff_data[i],room_data[i]);
	}
	fprintf(opfp,"---------------------------------\n");
	fclose(opfp);
	lim=0;
}


// //=======================================================================


// // Block - 3 the main block that order the Main data. for TT
int reorder_data(char opfile[30], char Main_data[20][50][80],int num_course[15],int ana_count_data[80],int dept_count,char ana_course_data[80][40], int total_course)
{
	int main_count[20][20]={0},p=0,i=0,j=0,k=0,sw=0,loop=0;
	char swap[20];

		// Giving the grade dependes on the Main_data.
    FILE *opfp = fopen(opfile, "a");
	for(p=0; p<=dept_count; p++){
	   for (i=0;i<=num_course[p];i++){
	       for (j=0; j< total_course; j++){   // ana_course_data
	            	if (strcmp(Main_data[p][i],ana_course_data[j])==0){
	            		main_count[p][i]=ana_count_data[j];
	            		break;
					}
	        }
	   }
	}

		// sorting the data
	for (i = 0; i <= dept_count; ++i){
        for (j = 1; j <= num_course[i]; ++j){
            for (k =(j + 1); k <= num_course[i]; ++k){
                if (main_count[i][j] < main_count[i][k]){

                    int a = main_count[i][j];
                    main_count[i][j] = main_count[i][k];
                    main_count[i][k] = a;

					strcpy(swap, Main_data[i][j]);
					strcpy(Main_data[i][j],  Main_data[i][k]);
					strcpy(Main_data[i][k], swap);
                }
            }
        }
	}


		// finding the max val max is 
	int max;
	for (i = 1; i < dept_count-2; i++)
        if (num_course[i] > max)
            max = num_course[i];
		

		// the main work done by this sorting.
		// ordering the data in correct format.
	for(i=0; i<= max; i++){
		for(j=0; j <= max; j++){
			char temp[30];
			strcpy(temp, Main_data[i][j+1]);
			for(k=0; k <= max; k++){
				int count=0;
				if(strcmp(temp,Main_data[i+1][k])==0){
					
					strcpy(swap, Main_data[i+1][k]);
					strcpy(Main_data[i+1][k], Main_data[i+1][j+1]);
					strcpy(Main_data[i+1][j+1], swap);
				}
			}
		 }
	}
	
	
	Main_Time_Table(opfile, Main_data,num_course,dept_count+3);
	fclose(opfp);
	return 0;
}

// //=======================================================================



// // Block - 2 to find the subject count total num of sublect.
int sub_count(char Main_data[20][50][80],int num_course[15],int ana_count_data[80],char ana_course_data[80][40],int dept_count)
{
	
	int i,j,k,count=0,p,sum=0,sum1=0,a=0;


	for(p=0; p<dept_count; p++){
	   for (i=1;i<=num_course[p];i++){
	       for (j=0; j<= num_course[p]; j++){
	           for(k=1; k<= num_course[j];k++){
	            	if (strcmp(Main_data[p][i],Main_data[j][k])==0)count++;
	            }
	        }
	        strcpy(ana_course_data[a],Main_data[p][i]);
	        ana_count_data[a]=count;count=0;a++;
	   }
	}
	
printf("\n\n");

	i=0;
    int total_course=0;
    for(i=0; ana_count_data[i]!=0; i++){
		total_course++;
		// printf("%s --> %d\n",ana_course_data[i],ana_count_data[i]);
    }

	// to see the main data.
	// for (i=0; i<= dept_count; i++){
	// 	for(j=0; j <= num_course[i]; j++){
	// 		printf("%-7s  ",Main_data[i][j]);
	// 	}
	// 	printf("\n");
	// }


	// printf("\nTotal number of courses : %d \n\n",total_course);
	
    
    return total_course; 
}

// //=======================================================================


// Block 1
int Input_reader(char ipfile[30], char opfile[30]) 
{

	char Main_data[20][50][80],Room_data[100][100],Staff_data[100][100];
    int i=0,j=0,k=0,dept_count=0,std_count=0;
    int num_course[15], cc[15], ana_count_data[80];
    char ana_course_data[80][40];

	// reading all input file name.
    FILE *ipfp = fopen(ipfile, "r");
    FILE *opfp = fopen(opfile, "a");

    if(ipfp == NULL) {
        perror("\n\n\t\t\t\t\t\aUnable to open file!\a\n\n\n");
        exit(1);
    }
	if(opfp == NULL) {
        perror("\n\n\t\t\t\t\t\aUnable to open file!\a\n\n\n");
        exit(1);
    }

    fgets(Main_data[i][dept_count], 150, ipfp);// ignore the first line.
    fgets(Main_data[i][dept_count], 150, ipfp);// ignore the second line.

    while(fgets(Main_data[dept_count][i], 150, ipfp) != NULL) {  // reading all data and counting num of dept. 
    	int count=0;
        for(j=0; j< strlen(Main_data[dept_count][i]); j++){
        	if (Main_data[dept_count][i][j]==',')count+=1;
		}
		
		num_course[dept_count]=count-1;   // finding the number of course hear
		
		dept_count++;
        
    }
    
    fclose(ipfp);
    
	
    num_course[dept_count-2]=0; // this is not course this is room data
    num_course[dept_count-1]=0; // this is staff data
    
    
    // split the string and put it in main data
    for(i=0; i<dept_count; i++){

    	char line[75];
    	strcpy(line,Main_data[i][0]);
	 	char newString[10][10];
    	int a=0,b=0,c=0,v=0;

		for(a=0;a<=(strlen(line));a++){
		    if(line[a]==','||line[a]=='\0'){
		        newString[c][b]='\0';
		        c++;
		        b=0;
		    }
		    else{
		        newString[c][b]=line[a];
		        b++;
		    }
		}
		if (i<=dept_count-2) for(v=0;v < c;v++)strcpy(Main_data[i][v],newString[v]);
		if (i==dept_count-2) for(v=0;v < c;v++)strcpy(Room_data[v],newString[v]);
		if(i==dept_count-1) for(v=0;v < c;v++)strcpy(Staff_data[v],newString[v]);
	}
	
	// to count the number of student
	for(i=0;i < dept_count-2;i++) {
		int q=0;
		q = num_course[1];
		std_count+=atoi(Main_data[i][q+1]);
	}
	// printf("student Count %d \n",std_count);


			//		print main data. before sorting.
	// for (i=0; i<= dept_count-3; i++){
	// 	for(j=0; j <= num_course[i]; j++){
	// 		printf("%-7s  ",Main_data[i][j]);
	// 	}
	// 	printf("\n");
	// }

	int total_course=0;
	total_course = sub_count(Main_data,num_course,ana_count_data,ana_course_data,dept_count-3);
	
	reorder_data(opfile, Main_data,num_course,ana_count_data,dept_count-3,ana_course_data, total_course);
	
	std_timetable(opfile, Room_data,std_count);

	staff_timetable(opfile, Staff_data,Room_data);
    
	fprintf(opfp,"\n==============================================================================\n\n");
	fclose(opfp);
	return 0;
}
	
