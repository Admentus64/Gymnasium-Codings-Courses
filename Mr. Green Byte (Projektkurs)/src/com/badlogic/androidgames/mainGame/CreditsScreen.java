package com.badlogic.androidgames.mainGame;

import java.util.List;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Graphics;
import com.badlogic.androidgames.framework.Input.TouchEvent;
import com.badlogic.androidgames.framework.Screen;

public class CreditsScreen extends Screen
{      
    public CreditsScreen(Game game)
    {
        super(game);
    }

    @Override
    public void update(float deltaTime)
    {
        List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
        game.getInput().getKeyEvents();
        
        int len = touchEvents.size();
        for(int i = 0; i < len; i++)
        {
            TouchEvent event = touchEvents.get(i);
            if(event.type == TouchEvent.TOUCH_UP)
            {
            	if(event.x < 64 && event.y > 416 )
                {
                	Assets.clickNext.play(1);
                	game.setScreen(new MainMenuScreen(game));
                    return;
                }
            }
        }
    }

    @Override
    public void present(float deltaTime)
    {
        Graphics g = game.getGraphics();      
        g.drawPixmap(Assets.background, 0, 0);
        g.drawPixmap(Assets.madeBy, 10, 50);
        g.drawPixmap(Assets.buttons, 0, 416, 64, 256, 64, 64); //Button Back
    }

    @Override
    public void pause()
    {
    	Assets.music_menuTheme.stop();
    }

    @Override
    public void resume()
    {
    	Assets.music_menuTheme.play(true, 1);
    }

    @Override
    public void dispose()
    {
    }
}