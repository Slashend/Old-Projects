package edu.dlsu.mobidev.gem;
// package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;

public class ActivityStartScreen2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start_screen2);
        Handler hd = new Handler();
        hd.postDelayed(new Runnable() {
            @Override
            public void run() {
                Intent i = new Intent();
                i.setClass(getBaseContext(), ActivityStartScreen3.class);
                startActivity(i);
                overridePendingTransition(0,0);
                finish();
            }
        },3000);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if(event.getAction() == MotionEvent.ACTION_UP)
        {
            Intent intent = new Intent();
            intent.setClass(getBaseContext(), MainMenuActivity.class);
            startActivity(intent);
            finish();
        }

        return false;
    }
}
