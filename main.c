/***************************************************************************************************************************************************
*Author		:Emertxe(http://www.emertxe.com)
*Date		:Mon 22 May 2017 14:00:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
//#include "inverted_search.h"
#include "main.h"

int main(int argc, char *argv[])
{
    //Variable declaration
    int i, option;

    char *filelist = "filelist.txt";
    char *f_name;
    FILE *flist;
    char check_char;

    int file_count = argc;


    do
    {
	printf("Enter the option: \n1. Create Database\n2. Search in Database\n3. Display Database\n4. Save Database\n 5. Quit\n\nChoosen option: ");
	scanf("%d", &option);

	while(getchar() != '\n')
	    putchar('\n');


	switch(option)
	{
	    case 1:
		//open filelist to update file names
		flist = fopen(filelist, "w");
		
		//Error checking
		if(flist == NULL)
		{
		    perror("fopen");
		    fprintf(stderr, "ERROR: Unable to open file Filelist\n");
		    return 1;
		}
		
		//Store file name in filelist
		for(i = 1; i < file_count; i++)
		{
		    fprintf(flist, "%s\n", argv[i]);
		}

		//Ask filename from user
		printf("Enter the file name: ");
		fgets(f_name, 10, stdin);

		//Store to filelist
		fprintf(flist, "%s\n", f_name);

		//create database
		create_database(flist);
		fclose(flist);

	    default :
		printf("Enter proper choice!!\n");
	}
	
	printf("\nDo you want to continue? [y/n]: ");
	scanf("%c", &check_char);

	while(getchar() != '\n');

    }while(check_char == 'y' || check_char == 'Y');
}

