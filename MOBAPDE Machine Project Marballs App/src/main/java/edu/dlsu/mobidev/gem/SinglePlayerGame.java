package edu.dlsu.mobidev.gem;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.SurfaceView;
import android.view.Window;
import android.view.WindowManager;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

public class SinglePlayerGame extends Activity {

    public static boolean sfx;
    public static boolean bgm;

    LinearLayout game;
    GamePanel panel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);

        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        Constants.SCREEN_WIDTH = dm.widthPixels;
        Constants.SCREEN_HEIGHT = dm.heightPixels;
        setContentView(R.layout.activity_game_single);

        Intent i = getIntent();

        game = (LinearLayout) findViewById(R.id.ll_game);
        GamePanel.difficulty = i.getExtras().getInt("difficulty");
        GamePanel.movement = i.getExtras().getBoolean("movement");
        sfx = i.getExtras().getBoolean("sfx");
        bgm = i.getExtras().getBoolean("bgm");

        panel = new GamePanel(this,0);

        Constants.ACTIVITY = this;

        game.addView(panel);


    }
}
