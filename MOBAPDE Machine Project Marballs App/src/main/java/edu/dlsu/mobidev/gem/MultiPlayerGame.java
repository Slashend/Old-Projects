package edu.dlsu.mobidev.gem;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.widget.LinearLayout;

public class MultiPlayerGame extends AppCompatActivity {

    LinearLayout game;
    GamePanel panel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        Constants.SCREEN_WIDTH = dm.widthPixels;
        Constants.SCREEN_HEIGHT = dm.heightPixels;
        setContentView(R.layout.activity_multi_player_game);


        game = (LinearLayout) findViewById(R.id.ll_game);
        panel = new GamePanel(this,1);
        Constants.ACTIVITY = this;

        game.addView(panel);
    }
}
