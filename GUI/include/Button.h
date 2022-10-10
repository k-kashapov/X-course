#pragma once

#include <raylib.h>
#include "Vector.h"

class Button
{
private:
    const bool StatePressed = 1;
    const bool StateRelease = 0;

    const int DefaultWidth  = 60;
    const int DefaultHeight = 30;

    bool state_  = StateRelease;
    int  width_  = DefaultWidth,
         height_ = DefaultHeight;

    Vector pos_;

public:
    Button (int width, int height, int x, int y):
        width_  (width),
        height_ (height)
    {
        pos_.SetCoord (x, y);
    }

    Button (int x, int y)
    {
        pos_.SetCoord (x, y);
    }

    Button (int width, int height, int x, int y, bool init_state):
        state_  (init_state),
        width_  (width),
        height_ (height)
    {
        pos_.SetCoord (x, y);
    }

    ~Button ()
    {}

    bool GetState()  const { return state_; }
    int  GetWidth()  const { return width_; }
    int  GetHeight() const { return height_; }
    
    const Vector& GetPos() const { return pos_; }

    bool SwitchState() 
    { 
        state_ = !state_;
        return state_; 
    }
    
    bool SetState (bool new_state) 
    { 
        state_ = new_state;
        return state_; 
    }

    void SetSize (int width, int height)
    {
        width_ = width;
        height_ = height;

        return;
    }

    void SetCoord (int x, int y)
    {
        pos_.SetCoord (x, y);
        return;
    }

    int Draw();
    int Draw (int x, int y);
    int Draw (int x, int y, int width, int height);

    bool Overlaps (int x, int y);
    bool Overlaps (const Vector&);

    int OnClick();
};

class BtnSwitch : public Button
{
public:
    BtnSwitch (int width, int height, int x, int y):
        Button (width, height, x, y)
    {}

    BtnSwitch (int x, int y):
        Button (x, y)
    {}

    BtnSwitch (int width, int height, int x, int y, bool init_state):
        Button (width, height, x, y, init_state)
    {}

    ~BtnSwitch ()
    {}

    template <typename T>
    int OnClick (T param)
    {
        std::cout << param << std::endl;
        return SwitchState();
    }
};