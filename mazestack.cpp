
#include <stack>

using namespace std;


class Coord
{
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
//The parameters are A 2-dimensional 10x10 character array of Xs and dots that represents the maze.
//Each 'X' represents a wall, and each '.' represents a walkway.
//The starting coordinates in the maze: sr, sc; the row number and column number range from 0 to 9.
//The ending coordinates in the maze: er, ec; the row number and column number range from 0 to 9
{
    stack<Coord> coordStack;
    
    coordStack.push(Coord(sr,sc)); //pushed starting coord into stack
    
    
    
    while ( !coordStack.empty() ) //while the stack is not empty
    {
        Coord currentLocation = coordStack.top(); //the current location is saved into coord var currentLocation
        const int currentRow = currentLocation.r();
        const int currentColumn = currentLocation.c();
 
        coordStack.pop(); //remove the top of the stack
        
        

        if (currentRow == er  &&  currentColumn == ec)
            return true;

        if (maze[currentRow+1][currentColumn] == '.'){ //if you can move south
            coordStack.push(Coord(currentRow+1,currentColumn));
            maze[currentRow][currentColumn] = '#';
        }
        if (maze[currentRow][currentColumn-1] == '.'){ //if you can move west
            coordStack.push(Coord(currentRow,currentColumn-1));
            maze[currentRow][currentColumn] = '#';
        }
        if (maze[currentRow-1][currentColumn] == '.'){ //if you can move north
            coordStack.push(Coord(currentRow-1,currentColumn));
            maze[currentRow][currentColumn] = '#';
        }
        if (maze[currentRow][currentColumn+1] == '.'){ //if you can east
            coordStack.push(Coord(currentRow,currentColumn+1));
            maze[currentRow][currentColumn] = '#';
        }
    }
    return false;
}



