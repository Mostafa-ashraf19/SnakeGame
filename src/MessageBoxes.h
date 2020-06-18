#ifndef MESSAGE_BOX
#define MESSAGE_BOX
#include "SDL.h"
#include <string>

class MessageBoxes
{
private:
    /* data */
public:
    MessageBoxes(/* args */);
    ~MessageBoxes();
bool DeadMessage(int&& score,int&& size) const;
    
template<class T>
void MainSelectionWindow(T& Wall) const
{
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
    }
    if (buttonid == 0) {
      Wall = true;
    } else if(buttonid == 1) {
      Wall = false;
    }

}

};

#endif // MESSAGE_BOX