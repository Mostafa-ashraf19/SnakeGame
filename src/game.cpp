#include "game.h"
#include <iostream>
#include "SDL.h"
#include<string>

// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
void my_audio_callback(void *userdata, Uint8 *stream, int len) {
	
	if (audio_len ==0)
		return;
	
	len = ( len > audio_len ? audio_len : len );
	//SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another
	
	audio_pos += len;
	audio_len -= len;
}


Game::Game(std::size_t grid_width, std::size_t grid_height) 
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
  PlaceBadFood();
}

bool Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  bool ESCkey = false;

  bool Rwall = true;

    const SDL_MessageBoxButtonData buttons[] = {
        { /* .flags, .buttonid, .text */        0, 0, "Wall" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Without Wall" },
    };  
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, // .flags 
        NULL, // .window 
        "Game Mode", // .title 
        "select Mode", // .message 
        SDL_arraysize(buttons), // .numbuttons 
        buttons, // .buttons 
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
        return false;
    }
    if (buttonid == 0) {
      Rwall = true;
    } else if(buttonid == 1) {
      Rwall = false;
    }

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.

    if(ESCkey)
          {
         if(controller.CheckContRender(ESCkey))
            running = false;           
          continue;
          }
     
    ESCkey = controller.HandleInput(running, snake);
    
    Update();

    if((Rwall && snake.CheckWallCollsion()) || snake.alive == false)
    {
      std::string msg{"Score: " + std::to_string(this->GetScore()) + "\nSize: " + std::to_string(this->GetSize())+ +"\nWant To Play Again"};
      //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "You died!", msg.c_str(), NULL);
          const SDL_MessageBoxButtonData buttons[] = {
        { /* .flags, .buttonid, .text */        0, 0, "Yes" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "No" },
    };  
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, // .flags 
        NULL, // .window 
        "You Died!", // .title 
        msg.c_str(), // .message 
        SDL_arraysize(buttons), // .numbuttons 
        buttons, // .buttons 
    };
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
        return false;
    }
    if (buttonid == 0) {
     return true;
    } else if(buttonid == 1) {
      return false;
    }
      
     // return;
    }
    
    renderer.Render(snake, food, BadFood, Rwall);  //support for badfood 
   
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}
void Game::PlaceBadFood()
{
   int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item && Food before placing
    // badfood.
    if (!snake.SnakeCell(x, y) && food.x != x && food.y != y) {
      BadFood.x = x;
      BadFood.y = y;
      return;
    }
  }
}
void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y) && BadFood.x != x && BadFood.y != y) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    PlaceBadFood();
    
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
  else if(BadFood.x == new_x && BadFood.y == new_y )
  {
    PlaceBadFood();
    PlaceFood();
    // Decay  snake and decrase speed.
    snake.DecayBody();
    if(snake.alive == false)return;
    snake.speed -= 0.02;
    score--;
   
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }