#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *multi_tok(char *input, char *delimiter);
int main()
{
    FILE *inputStream;
    FILE *outputStream;
    char buffer[4000];
    int count = 0;

	inputStream = fopen("input.txt", "r");
	outputStream = fopen("output.txt", "a");
	
	while (fgets(buffer, sizeof buffer, inputStream) != NULL)
	{
	    // makes first token(sliced string)
	    char *token = multi_tok(buffer, ". ");
	   
	    // Keep slicing tokens until the delimiter is present (delimiter = ". ")
	    while (token != NULL)
	    {
	    	// left trim
	    	while(isspace((unsigned char)*token)) token++;
	    	count++;
	    	//printing
	        printf("%d. %s.\n",count, token);
	        //writing
	        fprintf(outputStream, "%d. %s.\n", count, token);
	        token = multi_tok(NULL, ". ");
	    }
	}
	fclose(inputStream);
	fclose(outputStream);
    return 0;
}

char *multi_tok(char *input, char *delimiter) {
    static char *string;
    if (input != NULL)
        string = input;

    if (string == NULL)
        return string;

    char *end = strstr(string, delimiter);
    if (end == NULL) {
        char *temp = string;
        string = NULL;
        return temp;
    }

    char *temp = string;

    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}
