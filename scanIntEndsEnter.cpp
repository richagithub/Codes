
/* Link:https://discuss.codechef.com/questions/73459/how-to-scan-integers-until-newline 
   I have also been looking for the answer for a while now.
   Earlier, I did not think properly because people gave hints to use dynamic memory allocation for array.
   But Actually, it can be done just with a simple do-while loop. code:  */

#include <stdio.h>
int main(void) {
    int i=0,size,arr[10000];
    char temp; 
    do{
        scanf("%d%c", &arr[i], &temp); 
        i++; 
        } while(temp!= '\n');

    size=i; 
    for(i=0;i<size;i++){ 
        printf("%d ",arr[i]); 
    } 
return 0;
}

