#include "obstcals.h"

obstcals:: obstcals()=default;

obstcals::obstcals(const std::size_t Screen_width, const std::size_t Screen_height,
           const std::size_t Grid_width, const std::size_t Grid_height):Screen_width(Screen_width),
      Screen_height(Screen_height),
      Grid_width(Grid_width),
      Grid_height(Grid_height)
{
    std::cout << "done\n";
}
obstcals::obstcals(const int figShape):Shape(figShape){}

obstcals::~obstcals()
{
}

std::vector<SDL_Rect> obstcals::GetWalls()
{
    return std::move(this->walls);
}    

void obstcals::setObstacls(int Shape) // default 
{
    this->Shape = Shape;
    file.open("../testcases/"+std::to_string(Shape)+".txt");
    std::string line;
    int x,y,w,h;
    if(file.is_open())
    {
        std::cout << "file found\n";
        SDL_Rect rec;
        while (std::getline(file,line))
        {
        std::istringstream stream(line);
           stream >> h >> w >> x >> y;
           rec.x=x;
           rec.y=y;
           rec.w=w;
           rec.h=h;
           walls.push_back(rec);
        }
    }
    else
        std::cout << "not found\n";
    
}
 void obstcals::setYrOwnObstacl(std::string& filename)
 {
     Shapes.push_back(std::move(filename));
 }