package com.example.cacheangus.myapplication;



import android.content.Intent;
import android.os.Bundle;


import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;

public class splash extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Intent i = new Intent(this, InstructionActivity.class);
        startActivity(i);
        finish();
    }

}
