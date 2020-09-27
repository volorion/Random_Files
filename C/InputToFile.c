#include <stdio.h>
#include <string.h>

#define EMPTY_INPUT     -1
#define TOO_LONG        -2

int ReadInput (char *buff, size_t maxSize)
{
    if (NULL == fgets (buff, maxSize, stdin))
    {
        return EMPTY_INPUT;
    }
    
    long buffSize = strlen(buff) - 1;
    if(buffSize > maxSize)
    {
        return TOO_LONG;
    }
    
    buff[strlen(buff)-1] = '\0';
    return buffSize;
}

int WriteToFile (char *buff, int len)
{
    FILE *outFile = fopen ("out.txt", "w");
    if( !outFile )
    {
        perror("out.txt");
        return 0;
    }
    printf("Writing contents into output file.\n");
    fwrite (buff, len, 1, outFile);
    fclose(outFile);
}

int main (void) 
{
    char inputBuffer[1024];
    printf("Please input characters (max len of 1024).\n");
    int response = ReadInput (inputBuffer, 1024);
    
    if (response == EMPTY_INPUT) 
    {
        printf ("\nNo input\n");
        return EMPTY_INPUT;
    }
    else if (response == TOO_LONG) 
    {
        printf ("Input too long (max 1024)\n");
        return TOO_LONG;
    }
    
    WriteToFile(inputBuffer, response);
    printf ("Writing [%s]\n", inputBuffer);
    return 0;
}