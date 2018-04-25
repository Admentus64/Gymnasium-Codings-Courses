package com.badlogic.androidgames.mainGame;

import java.util.List;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Graphics;
import com.badlogic.androidgames.framework.Input.TouchEvent;
import com.badlogic.androidgames.framework.Screen;

public class HelpScreen extends Screen
{
	int help = 1;
	static final int helpImages = 4;
	
    public HelpScreen(Game game)
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
                if(event.x > 256 && event.y > 416 )
                {
                    if (help < helpImages)
                    {
                    	Assets.clickNext.play(1);
                    	help += 1;
                    }
                    else
                    {
                    	Assets.clickExit.play(1);
                    	game.setScreen(new MainMenuScreen(game));
                        return;
                    }
                }
                if(event.x > 192 && event.x < 256 && event.y > 416 && help > 1)
                {
                    Assets.clickBack.play(1);
                    help -= 1;
                }
            }
        }
    }

    @Override
    public void present(float deltaTime)
    {
        Graphics g = game.getGraphics();      
        g.drawPixmap(Assets.background, 0, 0);
        
        if (help < helpImages)
        	g.drawPixmap(Assets.buttons, 256, 416, 0, 256, 64, 64); //Button Next
        else
        	g.drawPixmap(Assets.buttons, 256, 416, 0, 384, 64, 64); //Button Exit
        
        if (help > 1)
        	g.drawPixmap(Assets.buttons, 192, 416, 64, 256, 64, 64); //Button Back
        
        if (help == 1)
        	g.drawPixmap(Assets.help1, 64, 100);
        if (help == 2)
        	g.drawPixmap(Assets.help2, 64, 100);
        if (help == 3)
        	g.drawPixmap(Assets.help3, 64, 100);
        if (help == 4)
        	g.drawPixmap(Assets.help4, 5, 62);
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