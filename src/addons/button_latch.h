#ifndef _BUTTON_LATCH_ADDON_H_
#define _BUTTON_LATCH_ADDON_H_

#include "addons/addonbase.h"

class ButtonLatchAddon : public Addon {
public:
    virtual void setup();     // Called once at boot
    virtual void process();   // Called every main loop

private:
    bool latchedState;
    bool lastButtonState;
};

#endif