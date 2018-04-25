package com.badlogic.androidgames.mainGame;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import com.badlogic.androidgames.framework.FileIO;

public class Settings
{
    public static boolean soundEnabled = true;
    public static boolean musicEnabled = true;
    public static boolean colorsEnabled = true;
    public static boolean classicControlsEnabled = true;
    public static int speed = 3;
    public static int[] highscores = new int[] { 25, 20, 15, 10, 5 };

    public static void load(FileIO files)
    {
        BufferedReader in = null;
        try
        {
            in = new BufferedReader(new InputStreamReader(files.readFile("Mr. Green Byte")));
            soundEnabled = Boolean.parseBoolean(in.readLine());
            musicEnabled = Boolean.parseBoolean(in.readLine());
            colorsEnabled = Boolean.parseBoolean(in.readLine());
            classicControlsEnabled = Boolean.parseBoolean(in.readLine());
            speed = Integer.parseInt(in.readLine());
            for (int i = 0; i < 5; i++)
            {
                highscores[i] = Integer.parseInt(in.readLine());
            }
        }
        catch (IOException e)
        {
            //It's fine there are defaults
        }
        catch (NumberFormatException e)
        {
        	//It's fine there are defaults
        }
        finally
        {
            try
            {
                if (in != null)
                    in.close();
            }
            catch (IOException e)
            {
            }
        }
    }

    public static void save(FileIO files)
    {
        BufferedWriter out = null;
        try
        {
        	out = new BufferedWriter(new OutputStreamWriter(files.writeFile("Mr. Green Byte")));
            out.write(Boolean.toString(soundEnabled));
            out.write("\n");
            out.write(Boolean.toString(musicEnabled));
            out.write("\n");
            out.write(Boolean.toString(colorsEnabled));
            out.write("\n");
            out.write(Boolean.toString(classicControlsEnabled));
            out.write("\n");
            out.write(Integer.toString(speed));
            out.write("\n");
            for (int i = 0; i < 5; i++)
            {
                out.write(Integer.toString(highscores[i]));
                out.write("\n");
            }

        }
        catch (IOException e)
        {
        }
        finally
        {
            try
            {
                if (out != null)
                    out.close();
            }
            catch (IOException e)
            {
            }
        }
    }

    public static void addScore(int score)
    {
        for (int i = 0; i < 5; i++)
        {
            if (highscores[i] < score)
            {
                for (int j = 4; j > i; j--)
                    highscores[j] = highscores[j - 1];
                highscores[i] = score;
                break;
            }
        }
    }
}
