//Implementing Array as an Abstract Data Type in C Language
#include <stdio.h>
#include<stdlib.h>
struct myarray
{
    /* data */
    int totalsize;//memory to be reserved
    int usedsize;//to be used 
    int *ptr;//base address point phle meomry block ko point krega
    
};
void vreatearray(struct myarray * a,int tsize,int usize){
    // (*a).totalsize=tsize;
    // (*a).usedsize=usize;
    // (*a).ptr=(int *)malloc(tsize*sizeof(int));


    //another method to define 
    a->totalsize=tsize;
    a->usedsize=usize;
    a->ptr=(int *)malloc(tsize*sizeof(int));
}
void show(struct myarray *a){
    for (int i = 0; i <(a->usedsize); i++)
    {
        /* code */
        printf("%d",(a->ptr)[i]);
    } 
}
void setval(struct myarray *a){
    for(int i=0;i<(a->usedsize);i++){
        printf("enter element");
        scanf("%d",(a->ptr[i]));
    }
}
int main()
{
    struct myarray marks;
   vreatearray(&marks,10,5);
   setval(&marks);
   show(&marks);
    free(marks.ptr);
    return 0;
}