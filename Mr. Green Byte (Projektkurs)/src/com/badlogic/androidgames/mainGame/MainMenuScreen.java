package com.badlogic.androidgames.mainGame;

import java.util.List;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Graphics;
import com.badlogic.androidgames.framework.Input.TouchEvent;
import com.badlogic.androidgames.framework.Screen;

public class MainMenuScreen extends Screen
{
    public MainMenuScreen(Game game)
    {
        super(game);               
    }   

    @Override
    public void update(float deltaTime)
    {
        Graphics g = game.getGraphics();
        List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
        game.getInput().getKeyEvents();       
        
        int len = touchEvents.size();
        for(int i = 0; i < len; i++)
        {
            TouchEvent event = touchEvents.get(i);
            if(event.type == TouchEvent.TOUCH_UP)
            {
                if (inBounds(event, 0, g.getHeight() - 64, 64, 64))
                {
                    Settings.soundEnabled = !Settings.soundEnabled;
                    Assets.clickSettings.play(1);
                }
                if (inBounds(event, 0, g.getHeight() - 128, 64, 64))
                {
                    Settings.musicEnabled = !Settings.musicEnabled;
                    Assets.clickSettings.play(1);
                    Assets.music_menuTheme.stop();
                    Assets.music_menuTheme.play(true, 1);
                }
                if (inBounds(event, 0, g.getHeight() - 192, 64, 64))
                {
                    Settings.colorsEnabled = !Settings.colorsEnabled;
                    Assets.clickSettings.play(1);
                }
                if (inBounds(event, 0, g.getHeight() - 256, 64, 64))
                {
                    Settings.classicControlsEnabled = !Settings.classicControlsEnabled;
                    Assets.clickSettings.play(1);
                }
                if (inBounds(event, 0, g.getHeight() - 320, 64, 64))
                {
                    Settings.speed += 1;
                    if (Settings.speed > 5)
                    	Settings.speed = 1;
                    Assets.clickSettings.play(1);
                }
                if (inBounds(event, 96, 220, 222, 42))
                {
                    Assets.click.play(1);
                    Assets.music_menuTheme.stop();
                	Assets.music_gameTheme.play(true, 1);
                    game.setScreen(new GameScreen(game));
                    return;
                }
                if (inBounds(event, 96, 262, 222, 42))
                {
                    Assets.click.play(1);
                    game.setScreen(new HighscoreScreen(game));
                    return;
                }
                if (inBounds(event, 96, 304, 222, 42))
                {
                    Assets.click.play(1);
                    game.setScreen(new HelpScreen(game));
                    return;
                }
                if (inBounds(event, 96, 346, 222, 42))
                {
                    Assets.click.play(1);
                    game.setScreen(new CreditsScreen(game));
                    return;
                }
            }
        }
    }
    
    private boolean inBounds(TouchEvent event, int x, int y, int width, int height)
    {
        if(event.x > x && event.x < x + width - 1 && 
           event.y > y && event.y < y + height - 1) 
            return true;
        else
            return false;
    }

    @Override
    public void present(float deltaTime)
    {
        Graphics g = game.getGraphics();
        
        g.drawPixmap(Assets.background, 0, 0);
        g.drawPixmap(Assets.logo, 32, 20);
        g.drawPixmap(Assets.mainMenu, 94, 220);
        if(Settings.soundEnabled)
            g.drawPixmap(Assets.buttons, 0, 416, 0, 0, 64, 64); //Button Sound
        else
            g.drawPixmap(Assets.buttons, 0, 416, 64, 0, 64, 64); //Button No Sound
        if(Settings.musicEnabled)
            g.drawPixmap(Assets.buttons, 0, 352, 0, 64, 64, 64); //Button Music
        else
            g.drawPixmap(Assets.buttons, 0, 352, 64, 64, 64, 64); //Button No Music
        if(Settings.colorsEnabled)
            g.drawPixmap(Assets.buttons, 0, 288, 0, 128, 64, 64); //Button Colors
        else
            g.drawPixmap(Assets.buttons, 0, 288, 64, 128, 64, 64); //Button No Colors
        if(Settings.classicControlsEnabled)
            g.drawPixmap(Assets.buttons, 0, 224, 0, 192, 64, 64); //Button Classic Controls
        else
            g.drawPixmap(Assets.buttons, 0, 224, 64, 192, 64, 64); //Button New Controls
        g.drawPixmap(Assets.buttons, 0, 160, 0, 448, 64, 64); //Button Empty
        g.drawPixmap(Assets.numbers, 22, 176, Settings.speed * 20, 0, 20, 32); //Speed text for Button Empty
    }

    @Override
    public void pause()
    {        
        Settings.save(game.getFileIO());
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
