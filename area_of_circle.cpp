#include <math.h>
#include <stdio.h>
#define PI 3.14152
int main( )
{
    int c;
    printf("select your shape purpose. \nFor rectangle enter 1, \nfor circle enter 2.\n");
    scanf("%d", &c);
    if(c==1)
    {
        int a, b, f, g ;
        printf("Enter legnth of rectangle (m) : ");
        scanf("%d", &a);
        printf("Enter the width of rectangle : ");
        scanf("%d", &b);
        f= a * b;
        g= (2*a) + ( 2 * b);
        printf("\n Area is = %d", f);
        printf("\n perimetre is = %d", g);
    }else
        if(c==2)
    {
        int r;
        float x, y;
        printf("Enter the radius of circle : ");
        scanf("%d", &r);
        x= 2 * PI * r;
        y= 2 * PI * (r * r);
        printf("\n circumpherence is = %f", x);
        printf("\n area is = %f ", y);

    }else
    {
        printf("Please enter a correct number ! ");
    }
}  