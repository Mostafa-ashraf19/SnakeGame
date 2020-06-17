#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
class Controller {
 public:
  //void HandleInput(bool &running, Snake &snake) const;
  bool HandleInput(bool &running, Snake &snake) const;
  bool CheckContRender(bool& Button) const;
  void termnaite(bool&) const;


 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;

};

#endif