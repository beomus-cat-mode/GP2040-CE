#ifndef _BUTTON_LATCH_ADDON_H_
#define _BUTTON_LATCH_ADDON_H_

#include "addons/addonbase.h"

class ButtonLatchAddon : public Addon {
public:
    void setup() override;
    void process() override;
    bool available() override;

private:
    bool latchedState;
    bool lastButtonState;
};

#endif