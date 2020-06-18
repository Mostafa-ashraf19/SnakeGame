#include "MessageBoxes.h"

MessageBoxes::MessageBoxes(/* args */)
{
}

MessageBoxes::~MessageBoxes()
{
}

bool MessageBoxes::DeadMessage(int&& score, int&& size) const{
std::string msg{"Score: " + std::to_string(score) + "\nSize: " + std::to_string(size)+ +"\nWant To Play Again"};
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
     return true; // play agin
    } else if(buttonid == 1) {
      return false; // terminate
    }
}
/*template<class T>
void MessageBoxes:: MainSelectionWindow(T& Wall) const
{
    const SDL_MessageBoxButtonData buttons[] = {
        {  //.flags, .buttonid, .text         0, 0, "Wall" },
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
    }
    if (buttonid == 0) {
      Wall = true;
    } else if(buttonid == 1) {
      Wall = false;
    }

}*/