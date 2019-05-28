#include<stdio.h>
#include<string.h>
void main(){
	//open input file to read, output and symbol table to write into
	FILE *input,*output,*optab,*symtab;
	input=fopen("input.txt","r");
	output=fopen("pa1out.txt","w");
	symtab=fopen("symtab.txt","w");
	char label[20],opcode[20],operand[20];
	//sa=start address; lc=location counter
	int sa,lc;

	//Read first line of input:ex. COPY START 2000
	fscanf(input,"%s %s %s",label,opcode,operand);
	if(strcmp(opcode,"START")==0){
		//convert 2000 from  string to long(strtol)
		sa=strtol(operand,NULL,16);
		fprintf(output,"%X\t%s\t%s\t %s\n",sa,label,opcode,operand); 
		
	}else{
		sa=0;
	}
	lc=sa;
	fscanf(input,"%s %s %s",label,opcode,operand);
	//Read until "END"
	while(strcmp(opcode,"END")!=0){
		fprintf(output,"%X\t%s\t%s\t %s\n",lc,label,opcode,operand);
		//If label exists, print into symbol table with its address
		if(strcmp(label,"-")!=0){ 
			fprintf(symtab,"%s\t%X\n",label,lc);
		}
			optab=fopen("optab.txt","r");
			char tempcode[20],tempval[20];
			fscanf(optab,"%s %s",tempcode,tempval);

			//Read optab contents and search for the opcode in input. Once found, lc+=3, break
			while(!feof(optab)){
				
				if(strcmp(opcode,tempcode)==0){
					lc+=3;
					break; 

				}
				fscanf(optab,"%s %s",tempcode,tempval);
			}
			fclose(optab);
			
			//Update lc for each opcode type
			if(strcmp(opcode,"WORD")==0){
				lc+=3;
			}
			else if(strcmp(opcode,"RESW")==0){
				lc=lc+3*(strtol(operand,NULL,10));
			}
			else if(strcmp(opcode,"RESB")==0){
				lc=lc+(strtol(operand,NULL,10));
			}
			else if(strcmp(opcode,"BYTE")==0){
					if(operand[0]=='X'){
						lc=lc+(strlen(operand)-3)/2;
					}else{
						lc=lc+strlen(operand)-3;
					}
			
			
		
		}
		//scan next line of input 
		fscanf(input,"%s %s %s",label,opcode,operand);
		
	
	}
	//print last line into output
	fprintf(output,"%X\t%s\t%s\t %s\n",lc,label,opcode,operand);
	fclose(input);
	fclose(symtab);
	fclose(output);
	
}
