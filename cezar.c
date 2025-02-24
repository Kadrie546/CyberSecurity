#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 1000


// (str[i] - 'a') + shift %26 + 'a'
char* cezar_cioher(char* str, int key){
int lenght = (strlen(str));
char* cipher = (char*) malloc (sizeof(char)*(lenght+1));
for(int i=0; i<=lenght; i++){
    if(str[i]>= 'a' && str[i]<='z')
    {
        cipher[i] = ((str[i]- 'a')+key) %26+'a';
    }
    else
    {
        cipher[i] = str[i];

    }
}
return cipher;
}

int main()
{
    char str[MAXN];
    scanf("%s", str);

    int key;
    scanf("%d", &key);

    char* cipher = cezar_cioher(str,key);
    printf("%s", cipher);
    return EXIT_SUCCESS;

}
