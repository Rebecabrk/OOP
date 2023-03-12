 #include "Canvas.h"
 #include <iostream>
 using namespace std;

Canvas::Canvas(int width, int height) {
    WidthCanvas=width; HeightCanvas=height;
        data = new char*[height];
        for (int i = 1; i <= height; ++i) {
            data[i] = new char[width];
        }
    }
void Canvas::Clear()
{
    Y=0; X=0;
    for(int i=1;i<=HeightCanvas;i++)
        for(int j=1;j<=WidthCanvas;j++)
            data[i][j]=' ';
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    X=x; Y=y;
    if(ray>=WidthCanvas || ray>=HeightCanvas)
        perror("cannot draw a circle with given ray");
    else if(x>HeightCanvas || y>WidthCanvas)
            perror("cannot draw a circle outside the matrix");
            else 
            {
                for(int i=0;i<ray;i++)
                {
                    data[x+i][y]=ch;
                    data[x+i][y+ray+1]=ch;
                    data[x-1][y+i+1]=ch;
                    data[x+ray][y+i+1]=ch;
                }
            }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    if(x==X && y==Y)
    for(int i=1;i<=ray;i++)
        for(int j=0;j<ray;j++)
            data[x+j][y+i]=ch;
    else 
        perror("cannot fill outside an existing circle");
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    int height=right-left+1;
    int width=bottom-top+1;
    Width=width; Height=height;
    if(Height<HeightCanvas&&Width<WidthCanvas)
    {
        for (int i=0;i<width;i++)
        {
        data[top+i][left]=ch;
        data[top+i][right]=ch;
        }
    for(int j=0;j<height;j++)
        {
        data[top][left+j]=ch;
        data[bottom][left+j]=ch;
        }   
    }
    else 
        perror("cannot draw a rectangle outside the matrix");
}    
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    int height=right-left+1;
    int width=bottom-top+1;
    if(Height==height&&Width==width)
        for (int i=1;i<width-1;i++)
            for(int j=1;j<height-1;j++)
                data[top+i][left+j]=ch;
    else 
        perror("cannot fill outside an existent rectangle");
}
void Canvas::SetPoint(int x, int y, char ch)
{
    if(x<=WidthCanvas && y<=HeightCanvas)
        data[x][y]=ch;
    else perror("cannot set a point outside the matrix");
}

void Canvas::Print()
{
    for(int i=1;i<=HeightCanvas;i++)
    {
        for(int j=1;j<=WidthCanvas;j++)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }
}
Canvas::~Canvas() {
        // width/height trebuie sa fie membri
        for (int i = 1; i <= Height; ++i) {
            delete[] data[i];
        }
        delete[] data;
}