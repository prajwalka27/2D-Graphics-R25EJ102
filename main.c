#include <stdio.h>
#include <stdlib.h>

#define ROWS 15
#define COLS 30

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

void drawPoint(int x,int y)
{
    if(x>=0 && x<ROWS && y>=0 && y<COLS)
    {
        canvas[x][y]='*';
    }
}

void drawRectangle(int x,int y,int width,int height)
{
    for(int i=x;i<x+height;i++)
    {
        for(int j=y;j<y+width;j++)
        {
            drawPoint(i,j);
        }
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;

    int steps=(abs(dx)>abs(dy)) ? abs(dx) : abs(dy);

    float xInc=dx/(float)steps;
    float yInc=dy/(float)steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++)
    {
        drawPoint((int)(x+0.5),(int)(y+0.5));
        x+=xInc;
        y+=yInc;
    }
}

void drawTriangle(int x,int y,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<=i;j++)
        {
            drawPoint(x+i,y+j);
        }
    }
}

int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Display Canvas\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,w,h;
                scanf("%d%d%d%d",&x,&y,&w,&h);
                drawRectangle(x,y,w,h);
                displayCanvas();
                break;
            }

            case 2:
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                drawLine(x1,y1,x2,y2);
                displayCanvas();
                break;
            }

            case 3:
            {
                int x,y,size;
                scanf("%d%d%d",&x,&y,&size);
                drawTriangle(x,y,size);
                displayCanvas();
                break;
            }

            case 4:
                displayCanvas();
                break;

            case 5:
                return 0;
        }
    }
}