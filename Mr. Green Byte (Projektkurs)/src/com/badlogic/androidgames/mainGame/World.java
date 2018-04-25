package com.badlogic.androidgames.mainGame;

import java.util.Random;

public class World
{
    static final int WORLD_WIDTH = 10;
    static final int WORLD_HEIGHT = 13;
    static final float TICK_DECREMENT = 0.05f;
    static int SCORE_INCREMENT = 1;
    static float TICK_INITIAL;

    public Snake snake;
    public Stain stain;

    public boolean gameOver = false;;
    public int score = 0;

    boolean fields[][] = new boolean[WORLD_WIDTH][WORLD_HEIGHT];
    Random random = new Random();
    float tickTime = 0;

    public World()
    {
        snake = new Snake();
        placeStain();
 
        if (Settings.speed == 1)
        	TICK_INITIAL = 1f;
        if (Settings.speed == 2)
        	TICK_INITIAL = 0.8f;
        if (Settings.speed == 3)
        	TICK_INITIAL = 0.6f;
        if (Settings.speed == 4)
        	TICK_INITIAL = 0.4f;
        if (Settings.speed == 5)
        	TICK_INITIAL = 0.25f;
    }

    private void placeStain()
    {
        for (int x = 0; x < WORLD_WIDTH; x++)
            for (int y = 0; y < WORLD_HEIGHT; y++)
                fields[x][y] = false;

        int len = snake.parts.size();
        for (int i = 0; i < len; i++)
        {
            SnakePart part = snake.parts.get(i);
            fields[part.x][part.y] = true;
        }

        int stainX = random.nextInt(WORLD_WIDTH);
        int stainY = random.nextInt(WORLD_HEIGHT);
        while (true)
        {
            if (fields[stainX][stainY] == false)
                break;
            stainX += 1;
            if (stainX >= WORLD_WIDTH)
            {
                stainX = 0;
                stainY += 1;
                if (stainY >= WORLD_HEIGHT)
                    stainY = 0;
            }
        }
        if (Settings.colorsEnabled)
        	stain = new Stain(stainX, stainY, random.nextInt(3), random.nextInt(4));
        else
        	stain = new Stain(stainX, stainY, random.nextInt(3), 0);
    }

    public void update(float deltaTime)
    {
        if (gameOver)
            return;

        tickTime += deltaTime;
        
        while (tickTime > TICK_INITIAL)
        {
            tickTime -= TICK_INITIAL;
            snake.advance();
            if (snake.checkBitten())
            {
                gameOver = true;
                return;
            }

            SnakePart head = snake.parts.get(0);
            if (head.x == stain.x && head.y == stain.y)
            {
                score += SCORE_INCREMENT;
                snake.eat();
                if (snake.parts.size() == WORLD_WIDTH * WORLD_HEIGHT)
                {
                    gameOver = true;
                    return;
                }
                else
                    placeStain();

                if (score % 100 == 0 && TICK_INITIAL - TICK_DECREMENT > 0)
                	TICK_INITIAL -= TICK_DECREMENT;
            }
        }
    }
}
