package com.badlogic.androidgames.mainGame;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Snake
{
    public static final int UP = 0;
    public static final int LEFT = 1;
    public static final int DOWN = 2;
    public static final int RIGHT = 3;
    public int color;
    public int direction;
    
    public List<SnakePart> parts = new ArrayList<SnakePart>();
    Random random = new Random();
    
    public Snake()
    {
    	//Generating a random number (range: 0-7) to determine the the color of the first 3 snake parts
    	if (Settings.colorsEnabled)
    		color = random.nextInt(8);
    	else
    		color = 0;
    	direction = UP;
        parts.add(new SnakePart(5, 6, color));
        parts.add(new SnakePart(5, 7, color));
        parts.add(new SnakePart(5, 8, color));
    }
    
    public void turnLeft()
    {
        direction += 1;
        if(direction > RIGHT)
            direction = UP;
    }
    
    public void turnRight()
    {
        direction -= 1;
        if(direction < UP)
            direction = RIGHT;
    }
    
    public void eat()
    {
        SnakePart end = parts.get(parts.size()-1);
        //Generating a random number (range: 1-8) to determine the snake part's color
        if (Settings.colorsEnabled)
        	parts.add(new SnakePart(end.x, end.y, random.nextInt(8)));
        else
        	parts.add(new SnakePart(end.x, end.y, 0));
        	
    }
    
    public void advance()
    {
        SnakePart head = parts.get(0);               
        
        int len = parts.size() - 1;
        for(int i = len; i > 0; i--)
        {
            SnakePart before = parts.get(i-1);
            SnakePart part = parts.get(i);
            part.x = before.x;
            part.y = before.y;
        }
        
        if(direction == UP)
            head.y -= 1;
        if(direction == LEFT)
            head.x -= 1;
        if(direction == DOWN)
            head.y += 1;
        if(direction == RIGHT)
            head.x += 1;
        
        if(head.x < 0)
            head.x = 9;
        if(head.x > 9)
            head.x = 0;
        if(head.y < 0)
            head.y = 12;
        if(head.y > 12)
            head.y = 0;
    }
    
    public boolean checkBitten()
    {
        int len = parts.size();
        SnakePart head = parts.get(0);
        for(int i = 1; i < len; i++)
        {
            SnakePart part = parts.get(i);
            if(part.x == head.x && part.y == head.y)
                return true;
        }        
        return false;
    }      
}
