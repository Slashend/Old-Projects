package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

public class MainMenuActivity extends AppCompatActivity {

    TextView title;
    Button single,multi,credits;
    ImageButton highScore, setting;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        setContentView(R.layout.activity_main_menu);

        Constants.CURRENT_CONTEXT = getBaseContext();

//        title = (TextView) findViewById(R.id.textView);
        single = (Button) findViewById(R.id.singlePlayer);
        multi = (Button) findViewById(R.id.multiplayer);
        credits = (Button) findViewById(R.id.credits);
        setting = (ImageButton) findViewById(R.id.settings);
        highScore = (ImageButton) findViewById(R.id.highScore);

        single.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),ActivityCustomizeSinglePlayer.class);
                startActivity(i);
                finish();
            }
        });

        multi.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),ActivityCustomizeBlue.class);
                startActivity(i);
                finish();
            }
        });

        credits.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),credits.class);
                startActivity(i);
                finish();
            }
        });

        setting.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),ActivityCustomizeSettings.class);
                startActivity(i);
                finish();
            }
        });

        highScore.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),highScoreActivity.class);
                startActivity(i);
                finish();
            }
        });
    }
}
