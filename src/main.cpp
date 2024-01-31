#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/cocos/CCScheduler.h>
using namespace geode::prelude;

bool isPauseTriggerable = true;

class $modify(PauseLayer)
{
    virtual void keyDown(cocos2d::enumKeyCodes keyCode) override
    {
        PauseLayer::keyDown(keyCode);

        if (!Mod::get()->getSettingValue<bool>("toggle-enabled")) return;

        if (keyCode == cocos2d::KEY_Z && isPauseTriggerable) 
        {
            togglePauseMenuVisibility();
            isPauseTriggerable = false;
        }
        else if (keyCode == cocos2d::KEY_Z && !isPauseTriggerable)
        {
            togglePauseMenuVisibility();
            isPauseTriggerable = true;
        }
    }

    void togglePauseMenuVisibility()
    {
        bool isPauseMenuVisible = this->isVisible();
        this->setVisible(!isPauseMenuVisible);
    }
};