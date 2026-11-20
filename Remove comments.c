#include <stdio.h>

void remove_comments(char input[], char output[])
{
    int i = 0, j = 0;

    while(input[i] != '\0')
    {
        if(input[i] == '/' && input[i+1] == '/')
        {
            while(input[i] != '\n' && input[i] != '\0')
                i++;
        }
        else if(input[i] == '/' && input[i+1] == '*')
        {
            i = i + 2;

            while(input[i] != '\0')
            {
                if(input[i] == '*' && input[i+1] == '/')
                {
                    i = i + 2;
                    break;
                }
                i++;
            }
        }
        else
        {
            output[j] = input[i];
            i++;
            j++;
        }
    }

    output[j] = '\0';
}

int main()
{
    char input[5000], output[5000];
    FILE *fp1, *fp2;
    int i = 0, ch;

    fp1 = fopen("sample.c", "r");

    if(fp1 == NULL)
    {
        printf("Input file opening error\n");
        return 1;
    }

    while((ch = fgetc(fp1)) != EOF && i < 4999)
    {
        input[i] = ch;
        i++;
    }

    input[i] = '\0';
    fclose(fp1);

    remove_comments(input, output);

    fp2 = fopen("output.c", "w");

    if(fp2 == NULL)
    {
        printf("Output file opening error\n");
        return 1;
    }

    fprintf(fp2, "%s", output);
    fclose(fp2);

    printf("Comments removed successfully!\n");
    printf("Output saved in output.c\n");

    return 0;
}