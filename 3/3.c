#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){

    FILE *f1;
    int textlen=0;
	char textrec[80],address[20],temp[80],startaddr[20];
	char label[10],instruction[10],operand[10],objcode[10];
	int len=0,start=0,addr=0;

    f1=fopen("output2.txt","r");

    fscanf(f1,"%X %s %s %s %s",&addr,label,instruction,operand,objcode);

    start=addr;
    while(strcmp(instruction,"END")!=0)
    {
        fscanf(f1,"%X %s %s %s %s",&addr,label,instruction,operand,objcode);
    }
    len=addr-start;
    fclose(f1);

	printf("\nObject Program:-\n\n");
	f1=fopen("output2.txt","r");

	fscanf(f1,"%s %s %s %s %s",address,label,instruction,operand,objcode);
	strcpy(startaddr,address);

	printf("H %s %s %06X\n",label,address,len);

	fscanf(f1,"%s %s %s %s %s",address,label,instruction,operand,objcode);

	strcpy(temp,"");
	strcpy(textrec,"T 00");
	strcat(textrec,address);
	while(strcmp(instruction,"END")!=0)
	{
		if((textlen==30)||(strcmp(instruction,"RESW")==0)||(strcmp(instruction,"RESB")==0)||(((strlen(objcode)/2)+textlen)>30))
		{
			printf("%s %02X %s\n",textrec,textlen,temp);
			textlen=0;
			strcpy(temp,"");
			strcpy(textrec,"T 00");
			fscanf(f1,"%s %s %s %s %s",address,label,instruction,operand,objcode);
			if(strcmp(objcode,"-")!=0)
			{
				strcat(textrec,address);
				strcat(temp,objcode);
				strcat(temp," ");
				textlen=textlen+(strlen(objcode)/2);
			}
		}
		else
		{
			textlen=textlen+(strlen(objcode)/2);
			strcat(temp,objcode);
			strcat(temp," ");
		}
		fscanf(f1,"%s %s %s %s %s",address,label,instruction,operand,objcode);
	}
	if(textlen!=0)
		printf("%s %x %s\n",textrec,textlen,temp);

	printf("E 00%s\n\n",startaddr);
	fclose(f1);
}
