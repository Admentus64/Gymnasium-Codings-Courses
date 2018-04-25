package com.badlogic.androidgames.framework.impl;

import java.io.IOException;

import android.content.res.AssetFileDescriptor;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;

import com.badlogic.androidgames.framework.Music;
import com.badlogic.androidgames.mainGame.Settings;

public class AndroidMusic implements Music, OnCompletionListener
{
    MediaPlayer mediaPlayer;
    boolean isPrepared = false;

    public AndroidMusic(AssetFileDescriptor assetDescriptor)
    {
        mediaPlayer = new MediaPlayer();
        try
        {
            mediaPlayer.setDataSource(assetDescriptor.getFileDescriptor(), assetDescriptor.getStartOffset(), assetDescriptor.getLength());
            mediaPlayer.prepare();
            isPrepared = true;
            mediaPlayer.setOnCompletionListener(this);
        }
        catch (Exception e)
        {
            throw new RuntimeException("Couldn't load music");
        }
    }

    @Override
    public void dispose()
    {
        if (mediaPlayer.isPlaying())
            mediaPlayer.stop();
        mediaPlayer.release();
    }

    @Override
    public boolean isLooping()
    {
        return mediaPlayer.isLooping();
    }

    @Override
    public boolean isPlaying()
    {
        return mediaPlayer.isPlaying();
    }

    @Override
    public boolean isStopped()
    {
        return !isPrepared;
    }

    @Override
    public void pause()
    {
        if (mediaPlayer.isPlaying())
            mediaPlayer.pause();
    }

    @Override
    public void play(boolean isLooping, float volume)
    {
        if (mediaPlayer.isPlaying())
            return;
        
        if (!Settings.musicEnabled)
        	return;

        try
        {
            synchronized (this)
            {
                if (!isPrepared)
                    mediaPlayer.prepare();
                mediaPlayer.start();
                mediaPlayer.setLooping(isLooping);
                mediaPlayer.setVolume(volume, volume);
            }
        }
        catch (IllegalStateException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    @Override
    public void stop()
    {
    	if (!mediaPlayer.isPlaying())
    		return;
    	
        mediaPlayer.stop();
        synchronized (this)
        {
            isPrepared = false;
        }
    }

    @Override
    public void onCompletion(MediaPlayer player)
    {
        synchronized (this)
        {
            isPrepared = false;
        }
    }
}
