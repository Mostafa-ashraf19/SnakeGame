#ifndef OBSTCALS
#define OBSTCALS
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "SDL.h"

class obstcals //: public Renderer
{
protected:
    /* data */

  std::fstream file;
  std::istringstream Mystream;
  std::vector<SDL_Point> obstcal;
  std::vector<std::string> Shapes;

 

  const std::size_t Screen_width{0};
  const std::size_t Screen_height{0};
  const std::size_t Grid_width{0};
  const std::size_t Grid_height{0};
  int Shape;
  //Renderer r;
  //std::vector<SDL_Rect> walls;
public:
 std::vector<SDL_Rect> walls;
  std::vector<SDL_Rect> GetWalls();

   explicit obstcals() ;

   explicit obstcals(const std::size_t Screen_width, const std::size_t Screen_height,
           const std::size_t Grid_width, const std::size_t Grid_height);
   explicit obstcals(const int figShape);     

    //obstcals operator =(obstcals& ob)=delete;       
    void setYrOwnObstacl(std::string& filename);
    void setObstacls(int Shape = 0);
    ~obstcals();
};





#endif // OBSTCALS