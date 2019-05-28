#include<stdio.h>
#include<string.h>
void main(){
	FILE *input,*deftab,*output;
	input=fopen("macro_input.txt","r");
	output=fopen("macro_output.txt","w");
	char label[20],opcode[20],operand[20],macroname[20];
	strcpy(macroname,"");
	//scan first line of input
	fscanf(input,"%s %s %s",label,opcode,operand);

	while(strcmp(opcode,"END")!=0){
	//if it is neither macro definition nor macro call
		if((strcmp(opcode,"MACRO"))!=0 && (strcmp(opcode,macroname))!=0){
			//print it into output
			fprintf(output,"%s\t%s\t%s\n",label,opcode,operand);
			
			}//end of if

		//else if it a macro call
		else if(strcmp(opcode,macroname)==0){
			deftab=fopen("deftab.txt","r");
			//read from deftab and print into output
			fprintf(output,".%s\n",label);
			fscanf(deftab,"%s %s %s",label,opcode,operand);
			fprintf(output,"%s\t%s\n",label,operand);
			fscanf(deftab,"%s %s %s",label,opcode,operand);
			
				while(strcmp(opcode,"MEND")!=0){
					fprintf(output,"%s\t%s\t%s\n",label,opcode,operand);
					fscanf(deftab,"%s %s %s",label,opcode,operand);
				}//inner while end
				
			}//end of 1st else if
		
		//If it is macro definition
		else if(strcmp(opcode,"MACRO")==0){
			deftab=fopen("deftab.txt","w");
			strcpy(macroname,label);
			
			//write contents from input to deftab
			while(strcmp(opcode,"MEND")!=0){
				fprintf(deftab,"%s\t%s\t%s\n",label,opcode,operand);
				fscanf(input,"%s %s %s",label,opcode,operand);
				}
			//print last line	
			fprintf(deftab,"%s\t%s\t%s\n",label,opcode,operand);
			fclose(deftab); 
		}
		//scan next line of input
		fscanf(input,"%s %s %s",label,opcode,operand);
	
	}//end of while
	fprintf(output,"%s\t%s\t%s\n",label,opcode,operand);
	fclose(input);
		fclose(output);
}//end of main

