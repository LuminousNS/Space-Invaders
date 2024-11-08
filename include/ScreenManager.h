#pragma once
#include <SFML/Graphics.hpp>
#include <map>
// #include "GameScreen.h"
#include "ScreenManagerRemoteControl.h"
#include "BitmapStore.h"
#include <iostream>

using namespace sf;
using namespace std;

class ScreenManager : public ScreenManagerRemoteControl {
private:
    // a map with a key-value pair 
    // of string and a unique pointer to Screen
    // This will allow us to grab the functionality of a specific Screen
    // instance by using the corresponding string
    map <string, unique_ptr<Screen>> m_Screens;
    //LevelManager m_LevelManager;

protected:
    string m_CurrentScreen = "Select";

public:
    BitmapStore m_BS;
    ScreenManager(Vector2i res);
    void update(float fps);
    void draw(RenderWindow& window);
    void handleInput(RenderWindow& window);
    /****************************************************
    *****************************************************
    From ScreenManagerRemoteControl interface
    *****************************************************
    *****************************************************/
    void ScreenManagerRemoteControl::
    SwitchScreens(string screenToSwitchTo)
    {
        m_CurrentScreen = "" + screenToSwitchTo;
        m_Screens[m_CurrentScreen]->initialise();
    }

    void ScreenManagerRemoteControl::
        loadLevelInPlayMode(string screenToLoad)
    {
    }
};