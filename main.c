#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 15
#define COLS 30

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawPoint(int x, int y)
{
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
    {
        canvas[x][y] = '*';
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    for(int i = x; i < x + height; i++)
    {
        for(int j = y; j < y + width; j++)
        {
            drawPoint(i, j);
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    if(steps == 0)
    {
        drawPoint(x1, y1);
        return;
    }

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        drawPoint((int)(x + 0.5), (int)(y + 0.5));
        x += xInc;
        y += yInc;
    }
}

void drawTriangle(int x, int y, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            drawPoint(x + i, y + j);
        }
    }
}

void drawCircle(int xc, int yc, int r)
{
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < COLS; y++)
        {
            int dx = x - xc;
            int dy = y - yc;

            int dist = dx*dx + dy*dy;

            if(dist >= r*r - r && dist <= r*r + r)
            {
                drawPoint(x, y);
            }
        }
    }
}

void eraseRectangle(int x, int y, int width, int height)
{
    for(int i = x; i < x + height; i++)
    {
        for(int j = y; j < y + width; j++)
        {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS)
            {
                canvas[i][j] = '_';
            }
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
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Display Canvas\n");
        printf("7. Clear Canvas\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x, y, w, h;
                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &w, &h);

                drawRectangle(x, y, w, h);

                printf("\nRectangle Drawn:\n");
                displayCanvas();
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

                drawLine(x1, y1, x2, y2);

                printf("\nLine Drawn:\n");
                displayCanvas();
                break;
            }

            case 3:
            {
                int x, y, size;
                printf("Enter x y size: ");
                scanf("%d%d%d", &x, &y, &size);

                drawTriangle(x, y, size);

                printf("\nTriangle Drawn:\n");
                displayCanvas();
                break;
            }

            case 4:
            {
                int x, y, r;
                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d", &x, &y, &r);

                drawCircle(x, y, r);

                printf("\nCircle Drawn:\n");
                displayCanvas();
                break;
            }

            case 5:
            {
                int x, y, w, h;
                printf("Enter delete area (x y width height): ");
                scanf("%d%d%d%d", &x, &y, &w, &h);

                eraseRectangle(x, y, w, h);

                printf("\nArea Deleted:\n");
                displayCanvas();
                break;
            }

            case 6:
            {
                printf("\nCanvas:\n");
                displayCanvas();
                break;
            }

            case 7:
            {
                initializeCanvas();

                printf("\nCanvas Cleared:\n");
                displayCanvas();
                break;
            }

            case 8:
            {
                printf("Exiting Program...\n");
                return 0;
            }

            default:
            {
                printf("Invalid Choice!\n");
            }
        }
    }

    return 0;
}