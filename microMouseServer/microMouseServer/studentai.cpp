
#include "micromouseserver.h"

void microMouseServer::studentAI()
{
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
    int Lturns = 0; //streak counter for left turns
    int Rturns = 0; //streak counter for left turns
    int forward = 0; //streak counter for left turns
    while(Rturns != 3 && Lturns != 3) //end of maze is found when 3 left turns or right turns have been made in a row
    {
        if(!isWallLeft()) //prioritize left turns
        {
            turnLeft();
            Lturns++; //add 1 to left turn streak
            forward = 0; //kill forward streak
            Rturns = 0; //kill right turn streak
        }
        if(!isWallForward())
        {
            moveForward();
            forward++;
            if(forward == 2){ // if move forwards twice in a row, then kill streaks
                Lturns = 0;
                Rturns = 0;
                forward = 0;
            }
        }
        else if(!isWallRight())
        {
            turnRight();
            Rturns++;
            forward = 0;
            Lturns = 0;
        }
        else // if cant go forward, turn right, or turn left, dead end - turn 180
        {
            turnLeft();
            turnLeft();
            Lturns = 0;
            Rturns = 0;
            forward = 0;
        }
    }
    foundFinish();
}
