#include<stdio.h>
// ##include<string.h>


int strlengh(char *p){
    int i=0;
    while (p[i]!='\0')
    {
        i++;
    }
    return i;
}
void printstr(char *s){
    for(int i=0;s[i]!='\0';i++){
        printf("\n");
        printf("%c",s[i]);
    }

}
int main(){
    char s[]="abcabc";
    printf("the length %d",strlengh(s));
    printstr(s);
    return 0;
}