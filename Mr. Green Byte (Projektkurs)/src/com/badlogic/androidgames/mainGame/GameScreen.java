package com.badlogic.androidgames.mainGame;

import java.util.List;

import android.graphics.Color;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Graphics;
import com.badlogic.androidgames.framework.Input.TouchEvent;
//import com.badlogic.androidgames.framework.Pixmap;
import com.badlogic.androidgames.framework.Screen;

public class GameScreen extends Screen
{
    enum GameState
    {
        Ready,
        Running,
        Paused,
        GameOver
    }
    
    GameState state = GameState.Ready;
    World world;
    int oldScore = 0;
    String score = "0";
    
    public GameScreen(Game game)
    {
        super(game);
        world = new World();
    }

    @Override
    public void update(float deltaTime)
    {
        List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
        game.getInput().getKeyEvents();
        
        if(state == GameState.Ready)
            updateReady(touchEvents);
        if(state == GameState.Running)
            updateRunning(touchEvents, deltaTime);
        if(state == GameState.Paused)
            updatePaused(touchEvents);
        if(state == GameState.GameOver)
            updateGameOver(touchEvents);        
    }
    
    private void updateReady(List<TouchEvent> touchEvents)
    {
        if(touchEvents.size() > 0)
        {
        	Assets.gameStarted.play(1);
            state = GameState.Running;
        }
    }
    
    private void updateRunning(List<TouchEvent> touchEvents, float deltaTime)
    {        
        int len = touchEvents.size();
        for(int i = 0; i < len; i++)
        {
            TouchEvent event = touchEvents.get(i);
            if(event.type == TouchEvent.TOUCH_UP)
            {
                if(event.x < 64 && event.y < 64)
                {
                    Assets.click.play(1);
                    state = GameState.Paused;
                    return;
                }
            }
            if(event.type == TouchEvent.TOUCH_DOWN)
            {
            	if (Settings.classicControlsEnabled)
            	{
            		//Left
                	if(event.x < 64 && event.y > 416)
                	{
                		Assets.turnSnake.play(1);
                		world.snake.turnLeft();
                	}
                	//Right
                	if(event.x > 256 && event.y > 416)
                	{
                		Assets.turnSnake.play(1);
                		world.snake.turnRight();
                	}
            	}
            	else
            	{
            		//Up
            		if(event.x > 192 && event.x < 256 && event.y > 416 && world.snake.direction != 0)
                	{
            			Assets.turnSnake.play(1);
            			world.snake.direction = 0;
                	}
            		//Left
                	if(event.x < 64 && event.y > 416 && world.snake.direction != 1)
                	{
                		Assets.turnSnake.play(1);
                		world.snake.direction = 1;
                	}
                	//Down
                	if(event.x > 64 && event.x < 128 && event.y > 416 && world.snake.direction != 2)
                	{
                		Assets.turnSnake.play(1);
                		world.snake.direction = 2;
                	}
                	//Right
                	if(event.x > 256 && event.y > 416 && world.snake.direction != 3)
                	{
                		Assets.turnSnake.play(1);
                		world.snake.direction = 3;
                	}
            	}
            }
        }
        
        world.update(deltaTime);
        if(world.gameOver)
        {
        	Assets.bitten.play(1);
            state = GameState.GameOver;
        }
        if(oldScore != world.score)
        {
            oldScore = world.score;
            score = "" + oldScore;
            Assets.eat.play(1);
        }
    }
    
    private void updatePaused(List<TouchEvent> touchEvents)
    {
        int len = touchEvents.size();
        for(int i = 0; i < len; i++) {
            TouchEvent event = touchEvents.get(i);
            if(event.type == TouchEvent.TOUCH_UP)
            {
                if(event.x > 80 && event.x <= 240)
                {
                    if(event.y > 100 && event.y <= 148)
                    {
                        Assets.click.play(1);
                        state = GameState.Running;
                        return;
                    }                    
                    if(event.y > 148 && event.y < 196)
                    {
                        Assets.click.play(1);
                        Assets.music_gameTheme.stop();
                    	Assets.music_menuTheme.play(true, 1);
                    	Settings.addScore(world.score);
                    	Settings.save(game.getFileIO());
                        game.setScreen(new MainMenuScreen(game));                        
                        return;
                    }
                }
            }
        }
    }
    
    private void updateGameOver(List<TouchEvent> touchEvents)
    {
        int len = touchEvents.size();
        for(int i = 0; i < len; i++)
        {
            TouchEvent event = touchEvents.get(i);
            if(event.type == TouchEvent.TOUCH_UP)
            {
                if(event.x >= 128 && event.x <= 192 &&
                   event.y >= 200 && event.y <= 264)
                {
                	Assets.clickExit.play(1);
                	Assets.music_gameTheme.stop();
                	Assets.music_menuTheme.play(true, 1);
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
        drawWorld(world);
        if(state == GameState.Ready) 
            drawReadyUI();
        if(state == GameState.Running)
            drawRunningUI();
        if(state == GameState.Paused)
            drawPausedUI();
        if(state == GameState.GameOver)
            drawGameOverUI();
        
        drawText(g, score, g.getWidth() / 2 - score.length()*20 / 2, g.getHeight() - 42);                
    }
    
    private void drawWorld(World world)
    {
        Graphics g = game.getGraphics();
        Snake snake = world.snake;
        SnakePart head = snake.parts.get(0);
        Stain stain = world.stain;             
        
        //Draw stain
        int x = stain.x * 32;
        int y = stain.y * 32;
        int sourceX = (stain.type * 32);
        int sourceY = (stain.color * 32);
        	g.drawPixmap(Assets.stain, x, y, sourceX, sourceY, 32, 32);
        
        //Draw snake parts
        int len = snake.parts.size();
        for(int i = 1; i < len; i++)
        {	
            SnakePart part = snake.parts.get(i);
            x = part.x * 32;
            y = part.y * 32;
            //Determine which part of the *pgn needs to be used for the correct color of the snake part
            sourceX = (part.color * 32);
            //Drawing the snake part now
            g.drawPixmap(Assets.tail, x, y, sourceX, 0, 32, 32);
        }
        
        //Draw the head of the snake
        x = head.x * 32 + 16;
        y = head.y * 32 + 16;
        sourceX = snake.direction * 42;
        g.drawPixmap(Assets.head, x - 21, y - 21, sourceX, 0, 42, 42);
    }
    
    private void drawReadyUI()
    {
        Graphics g = game.getGraphics();
        g.drawPixmap(Assets.ready, 47, 100);
        g.drawLine(0, 416, 480, 416, Color.BLACK);
    }
    
    private void drawRunningUI()
    {
        Graphics g = game.getGraphics();
        g.drawPixmap(Assets.buttons, 0, 0, 64, 384, 64, 64); //Button Pause
        g.drawLine(0, 416, 480, 416, Color.BLACK);
        g.drawPixmap(Assets.buttons, 0, 416, 64, 256, 64, 64); //LEFT
        g.drawPixmap(Assets.buttons, 256, 416, 0, 256, 64, 64); //RIGHT
        if (!Settings.classicControlsEnabled)
        {
        	g.drawPixmap(Assets.buttons, 192, 416, 64, 320, 64, 64); //UP
        	g.drawPixmap(Assets.buttons, 64, 416, 0, 320, 64, 64); //DOWN
        }
    }
    
    private void drawPausedUI()
    {
        Graphics g = game.getGraphics();
        g.drawPixmap(Assets.pauseMenu, 80, 100);
        g.drawLine(0, 416, 480, 416, Color.BLACK);
    }

    private void drawGameOverUI()
    {
        Graphics g = game.getGraphics();
        g.drawPixmap(Assets.gameOver, 62, 100);
        g.drawPixmap(Assets.emptyBlock, 120, 192);
        g.drawPixmap(Assets.buttons, 128, 200, 0, 384, 64, 64); //Button Exit
        g.drawLine(0, 416, 480, 416, Color.BLACK);
    }
    
    public void drawText(Graphics g, String line, int x, int y)
    {
        int len = line.length();
        for (int i = 0; i < len; i++)
        {
            char character = line.charAt(i);

            if (character == ' ')
            {
                x += 20;
                continue;
            }

            int srcX = 0;
            int srcWidth = 0;
            if (character == '.')
            {
                srcX = 200;
                srcWidth = 10;
            }
            else
            {
                srcX = (character - '0') * 20;
                srcWidth = 20;
            }

            g.drawPixmap(Assets.numbers, x, y, srcX, 0, srcWidth, 32);
            x += srcWidth;
        }
    }

    @Override
    public void pause()
    {
    	Assets.music_gameTheme.stop();
    	
        if (state == GameState.Running)
        	state = GameState.Paused;
        
        if (world.gameOver)
        {
        	Settings.addScore(world.score);
        	Settings.save(game.getFileIO());
        }
    }

    @Override
    public void resume()
    {
    	Assets.music_gameTheme.play(true, 1);
    }

    @Override
    public void dispose()
    {
    }
}