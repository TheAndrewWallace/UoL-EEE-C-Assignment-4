#include <stdio.h>
#include <stdlib.h>

#define MAX	500

int display_menu(void);
void check_exists(FILE *checkFile);

void encrypt(FILE *inputFile, char *string3, FILE *outputFile);
void decrypt(FILE *inputFile, char *string3, FILE *outputFile);


void main(void)
{
	FILE *inputFile;
	FILE *keyFile;
	FILE *outputFile;
	int option;
	char input[MAX];
	char key[MAX];
	char output[MAX];
	int i, j;
	char key_final[MAX];
	char string3[MAX];
	
	//Get option to encrypt or decrypt
	option = display_menu();
	
	//Get input file name
	printf("Enter input file name: ");
	fflush(stdin);
	scanf("%s", &input);
	inputFile = fopen(input, "r");
	
	
	//Check if file exists
	check_exists(inputFile);
	
	//Get key file name
	printf("\n\nEnter key file name: ");
	fflush(stdin);
	scanf("%s", &key);
	keyFile = fopen(key, "r");
	
	//Check if file exists
	check_exists(keyFile);
	
	//Get output file name
	printf("\n\nEnter output file name: ");
	fflush(stdin);
	scanf("%s", &output);
	outputFile = fopen(output, "w");
	
	//Make key longer
	while((fgets(string3, sizeof(string3), keyFile)) != NULL)
	{
		
		for(i=0; string3[i] !=  0; i++)
		{
			j=i;
		}
		

		for(i=i; i != MAX; i++)
		{
			string3[i] = string3[i - j];
		}
	}
	
	//Switch based on encrypt or decrypt
	switch(option)
	{
		case 1:
			encrypt(inputFile, string3, outputFile);
			break;
			
		case 2:
			decrypt(inputFile, string3, outputFile);
			break;
	}
	
	//Close file
	fclose(outputFile);
}

int display_menu(void)
{
	int option = 0;
	
	do
	{
		printf("Select desired operation:");
		printf("\n1 - Encrypt");
		printf("\n2 - Decrypt");
		printf("\nSelect an option: ");
		fflush(stdin);
		scanf("%d", &option);
	}while(option != 1 && option != 2);
	
	return option;
}

void check_exists(FILE *checkFile)
{
	if(checkFile == NULL)
	{
		printf("\nCannot open file\nEnd program");
		exit(1);
	}
	
	printf("\nFile found!");
}

void encrypt(FILE *inputFile, char *string3, FILE *outputFile)
{
	int y = 0, i, j;
	char x;
	char string[500], encryption[500];
	
	while((fgets(string, sizeof(string), inputFile)) != NULL)
	{
		//MIght need to move y = 0 to here ON BOTH
		
		for(i=0; i<MAX; i++)
		{
			if(string[i] == '\n')
			{
				i = 501;
				fprintf(outputFile, "\n");
				y = 1;
			}
			
			else
			{				
				encryption[i] = string[i] + string3[i];
				fprintf(outputFile, "%c", encryption[i]);	
			}
		}
	}
}

void decrypt(FILE *inputFile, char *string3, FILE *outputFile)
{
	int y = 0, i, j;
	char x;
	char string[500], encryption[500];
	
	while((fgets(string, sizeof(string), inputFile)) != NULL)
	{
		for(i=0; i<MAX; i++)
		{			
			if(string[i] == '\n')
			{
				i = 501;
				fprintf(outputFile, "\n");
				y = 1;
			}
			
			else
			{
				encryption[i] = string[i] - string3[i];
				fprintf(outputFile, "%c", encryption[i]);
			}
		}
	}
}
