package com.badlogic.androidgames.mainGame;

import com.badlogic.androidgames.framework.Screen;
import com.badlogic.androidgames.framework.impl.AndroidGame;

public class GameStartup extends AndroidGame
{
    @Override
    public Screen getStartScreen()
    {
        return new LoadingScreen(this); 
    }
}