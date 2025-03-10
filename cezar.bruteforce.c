#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 100
#define ALPHA_LENGTH 26

//(str[i] - 'a' + key) % 26 + 'a';
char *ceasar_dechipher(char *cipher, int key)
{
    int lenght = strlen(cipher);
    char *plaintext = (char *)malloc(sizeof(char) + (lenght + 1));
    for (int i = 0; i < lenght; i++)
    {
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = ((cipher[i] - 'a') - key + 26) % 26 + 'a';
        }

        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = ((cipher[i] - 'A') - key + 26) % 26 + 'A';
        }
        else if (cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = ((cipher[i] - '0') - key + 10) % 10 + '0';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[lenght] = '\0';
    return plaintext;
}

int read_cipher(char* filename, char*cipher)
{
    FILE *fp=fopen(filename, "r");
    if(fp==NULL){
        printf("error opening the file.");
        return EXIT_SUCCESS;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_SUCCESS;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

int main()
{
     char cipher[MAXN];
     scanf("%s", cipher);
     for(int key=0; key<ALPHA_LENGTH; key++){
        char* plaintext = ceasar_dechipher(cipher, key);
        printf("%s, key=%d -> %s\n", cipher,key,plaintext);
        free(plaintext);
     }
     return EXIT_SUCCESS;
}
