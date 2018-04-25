package com.badlogic.androidgames.mainGame;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Graphics;
//import com.badlogic.androidgames.framework.Pixmap;
import com.badlogic.androidgames.framework.Graphics.PixmapFormat;
import com.badlogic.androidgames.framework.Screen;

public class LoadingScreen extends Screen
{
    public LoadingScreen(Game game)
    {
        super(game);
    }

    @Override
    public void update(float deltaTime)
    {
        Graphics g = game.getGraphics();
        
        //Help
        Assets.help1 = g.newPixmap("help/help1.png", PixmapFormat.ARGB4444);
        Assets.help2 = g.newPixmap("help/help2.png", PixmapFormat.ARGB4444);
        Assets.help3 = g.newPixmap("help/help3.png", PixmapFormat.ARGB4444);
        Assets.help4 = g.newPixmap("help/help4.png", PixmapFormat.ARGB4444);
        
        //Music
        Assets.music_gameTheme = game.getAudio().newMusic("music/gameTheme.mp3");
        Assets.music_menuTheme = game.getAudio().newMusic("music/menuTheme.mp3");
        
        //Non-World
        Assets.buttons = g.newPixmap("non-world/buttons.png", PixmapFormat.ARGB4444);
        Assets.emptyBlock = g.newPixmap("non-world/emptyBlock.png", PixmapFormat.ARGB4444);
        Assets.gameOver = g.newPixmap("non-world/gameOver.png", PixmapFormat.ARGB4444);
        Assets.logo = g.newPixmap("non-world/logo.png", PixmapFormat.ARGB4444);
        Assets.madeBy = g.newPixmap("non-world/madeBy.png", PixmapFormat.ARGB4444);
        Assets.mainMenu = g.newPixmap("non-world/mainMenu.png", PixmapFormat.ARGB4444);
        Assets.numbers = g.newPixmap("non-world/numbers.png", PixmapFormat.ARGB4444);
        Assets.pauseMenu = g.newPixmap("non-world/pauseMenu.png", PixmapFormat.ARGB4444);
        Assets.ready = g.newPixmap("non-world/ready.png", PixmapFormat.ARGB4444);
        
        //Sounds
        Assets.bitten = game.getAudio().newSound("sounds/bitten.ogg");
        Assets.click = game.getAudio().newSound("sounds/click.ogg");
        Assets.clickBack = game.getAudio().newSound("sounds/clickBack.ogg");
        Assets.clickExit = game.getAudio().newSound("sounds/clickExit.ogg");
        Assets.clickNext = game.getAudio().newSound("sounds/clickNext.ogg");
        Assets.clickSettings = game.getAudio().newSound("sounds/clickSettings.ogg");
        Assets.eat = game.getAudio().newSound("sounds/eat.ogg");
        Assets.gameStarted = game.getAudio().newSound("sounds/gameStarted.ogg");
        Assets.turnSnake = game.getAudio().newSound("sounds/turnSnake.ogg");
        
        //World
        Assets.background = g.newPixmap("world/background.png", PixmapFormat.RGB565);
        Assets.head = g.newPixmap("world/head.png", PixmapFormat.ARGB4444);
        Assets.stain = g.newPixmap("world/stain.png", PixmapFormat.ARGB4444);
        Assets.tail = g.newPixmap("world/tail.png", PixmapFormat.ARGB4444);
        
        Settings.load(game.getFileIO());
        Assets.music_menuTheme.play(true, 100);
        game.setScreen(new MainMenuScreen(game));
    }

    @Override
    public void present(float deltaTime)
    {
    }

    @Override
    public void pause()
    {
    }

    @Override
    public void resume()
    {
    }

    @Override
    public void dispose()
    {
    }
}