package com.badlogic.androidgames.framework;

public interface Music
{
    public void play(boolean looping, float volume);
    public void stop();
    public void pause();
    public boolean isPlaying();
    public boolean isStopped();
    public boolean isLooping();
    public void dispose();
}
