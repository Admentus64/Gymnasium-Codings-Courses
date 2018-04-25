package com.badlogic.androidgames.framework.impl;

import android.media.SoundPool;

import com.badlogic.androidgames.framework.Sound;
import com.badlogic.androidgames.mainGame.Settings;

public class AndroidSound implements Sound
{
    int soundId;
    SoundPool soundPool;

    public AndroidSound(SoundPool soundPool, int soundId)
    {
        this.soundId = soundId;
        this.soundPool = soundPool;
    }

    @Override
    public void play(float volume)
    {
    	if (!Settings.soundEnabled)
        	return;
    	
        soundPool.play(soundId, volume, volume, 0, 0, 1);
    }

    @Override
    public void dispose()
    {
        soundPool.unload(soundId);
    }

}
