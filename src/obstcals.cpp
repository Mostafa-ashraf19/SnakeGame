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
    
void obstcals::setObstacls(int Shape) // default 
{
    this->Shape = Shape;

}
 void obstcals::setYrOwnObstacl(std::string& filename)
 {
     Shapes.push_back(std::move(filename));
 }