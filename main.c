#include <stdio.h>

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

int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n1.Draw Rectangle");
        printf("\n2.Display Canvas");
        printf("\n3.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int x,y,w,h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h);
                displayCanvas();
                break;
            }

            case 2:
                displayCanvas();
                break;

            case 3:
                return 0;
        }
    }
}