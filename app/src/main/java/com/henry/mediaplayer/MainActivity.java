package com.henry.mediaplayer;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.henry.mediaplayer.databinding.ActivityMainBinding;
import com.henry.player.GCPlayer;

public class MainActivity extends AppCompatActivity {
    private ActivityMainBinding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

    }

    public void createThread(View view) {
        GCPlayer player = new GCPlayer();
        player.normalThread();
    }

    public void queueThread(View view) {
        GCPlayer player = new GCPlayer();
        player.queueThread();
    }
}