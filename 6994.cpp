#include <iostream>
#include <vector>
#include <algorithm>


float GetY(float x, float m, float c)
{
    return m*x+c;
}

int main()
{
    // grid size
    int k = 8;

    // inputs
    int x1,y1;
    std::cin >> x1 >> y1;
    int x2,y2;
    std::cin >> x2 >> y2;

    /*
    int x1=1, y1=0;
    int x2=7, y2=1; 
    */

    // steps
    int dx = (x2 - x1);
    int dy = (y2 - y1);

    // slope
    float m = (float) dy/dx;
    // y intercept
    float c = y1 - m *x1;

    dx = std::abs(dx);
    dy = std::abs(dy);
    
    // our box counter
    int boxes = 0;

    // trivial cases
    if(dx==0) boxes = dy+1;
    else if( dy==0) boxes = dx+1;

    else
    {
        int starty = std::min(y2, y1);
        int endy = std::max(y2, y1);
        int startx = std::min(x2, x1);
        int endx = std::max(x2, x1);

        // loop over x axis
        for(int i=startx ; i<=endx; ++i)
        {
            // loop over y axis
            for(int j=starty; j<=endy; ++j)
            {
                //std::cout << i << " , " << j << std::endl;
                // 4 boundaries of a square
                float LEFT = i-0.5;
                float RIGHT = i+0.5;
                float BOTTOM = j-0.5;
                float TOP = j+0.5;

                // get y value on line when x = LEFT
                float line_y_rect_left = GetY(LEFT, m ,c);

                // get y value on line when x = RIGHT
                float line_y_rect_right = GetY(RIGHT, m, c);

                bool intersect = true;

                // check for intersection condition
                if(BOTTOM > line_y_rect_right && BOTTOM > line_y_rect_left)
                    intersect = false;
                
                // if previous fails, check this
                if(TOP < line_y_rect_right && TOP < line_y_rect_left)
                    intersect = false;

                // if intersect, count this square
                if(intersect) boxes++;
            }
        }
    }


    std::cout << "boxes : " << boxes << std::endl;

    return 0;
}






