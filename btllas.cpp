#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct btnode{

 int data ;
 struct btnode*right;
 struct btnode*left;

};

btnode*root=NULL;

int countx =1;

#define count 10

btnode*insert(btnode*,int);
void rootdisp(btnode*);
void display(btnode*,int );


int main()
{

   int ch;
   int ch1=1;
   int digit;

   while(1)
   {

      printf(" \n enter the choice from the menu\n 1.insert\n 2.display \n ");
    scanf("%d",&ch);


    switch(ch)
    {

        case 1 :
				 while(ch1==1)
		          {

				   printf(" ENTER THE VALUE OF THE DATA TO BE STORED ");
                   scanf("%d",&digit);



                     root = insert(root,digit);


                    printf("want to enter more(0/1) ");
                    scanf("%d",&ch1);



                  }

                 continue;


          case 2 : rootdisp(root);




    }



   }




    return 0;
}


btnode*insert(btnode*p,int data)
{

   if(p==NULL)
   {

      p=(btnode*)malloc(sizeof(btnode));

      p->data=data;

      p->left=NULL;
      p->right=NULL;


      countx++;

   }

   else{


      if((countx%2)==0)
      {

         p->left= insert(p->left,data);

      }

      else{


       p->right=insert(p->right,data);


      }



   }

  return (p);


}


void display(btnode*p,int space )
{

   if(p==NULL)
   return;


   else{

   space+=count;


    display(p->left,space);

    printf("\n");

    for(int i=count ;i<space;i++)
      printf(" ");

    printf("%d",p->data);

    display(p->right,space );




   }


}


void rootdisp(btnode*root)
{
    display(root,0);


}
