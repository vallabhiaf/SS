#include<stdio.h>
#include<string.h>
void main(){
	//Absolute loader takes object program as input
	FILE *inputabs;
	inputabs=fopen("abs.txt","r");
	char type,name[20],input[20];
	int sa,len,addr;
	//Scan first line of input. Ex: H COPY 001000 000013
	fscanf(inputabs,"%c %s %X %X",&type,name,&sa,&len);
	printf("Loading program %s of length %X",name,len);
	//scan next line. Input=E or T
	fscanf(inputabs,"%s",input);
	//Ex: input=T 001000 09 142033 483039 102036 220044
	while(strcmp(input,"E")!=0){
		if(strcmp(input,"T")==0){
			
			fscanf(inputabs,"%X",&addr);     //here addr=00100
			fscanf(inputabs,"%X",&len);      //here len=09
			fscanf(inputabs,"%s",input);     //here input=142033
		
		}//end of if T
		int i=0;

		//for the length of 142033,
		while(i<strlen(input)-1){
			//print 00100 14 i.e input[0]input[1]
			printf("%06X\t%c%c\n",addr,input[i],input[i+1]);
			addr++;
			i+=2;

		}//end of inner while

		fscanf(inputabs,"%s",input);    //scan next line of input
	}//end of while

	fclose(inputabs);

}//end of main
