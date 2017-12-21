package edu.dlsu.mobidev.gem;
// package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;

public class ActivityStartScreen extends AppCompatActivity {
    Handler hd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start_screen);
//        hd = new Handler();
//        hd.postDelayed(new Runnable() {
//            @Override
//            public void run() {
//                Intent i = new Intent();
//                i.setClass(getBaseContext(), ActivityStartScreen2.class);
//                startActivity(i);
//                overridePendingTransition(0,0);
//                finish();
//            }
//        },3000);
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
