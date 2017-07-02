//C++ program to tokenize a char 2-d array
//use strpbrk to find the delimiters in string
//get the address and convert it to '\0'
//then print that string upto last '\0'
//now repeat these steps on furthur string

#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
char str[3][7] = {"1,2 2","33,444","555,55"};
char *token;
char *ptr;
int i=0;
for (i=0;i<3;i++)
{
    char *s=str[i];
    printf("%s\n",s);
    printf("tokens:  ");
     ptr = strpbrk (s, ", ");//delimiters are (',' ' ') 
     while(ptr)
      {
          *ptr='\0';      //convert the delimiter to '\0'
          printf("%s ",s);//print the token
          s=ptr+1;        //shift the string base address to pointer next to last delimiter found
          ptr=strpbrk(s,", ");//search for delimiters(',' ' ') again in next part of string
          
      }
      if(*s != '\0')//if left over string is not empty -> we print it also
      printf("%s ",s);
      printf("\n");

}

    return(0);
}
