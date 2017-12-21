package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TextView;

import static edu.dlsu.mobidev.gem.GamePanel.difficulty;

public class matchResultsMulti extends AppCompatActivity {

    Button home, playAgain;
    TextView etHPR, etHPB, etSSFR, etSSFB, etRateR, etRateB, etDiff, etTime, etWin;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        setContentView(R.layout.activity_match_results_multi);

        home = (Button) findViewById(R.id.buttonHomeSingle);
        playAgain = (Button) findViewById(R.id.buttonAgain);

        etHPR = (TextView) findViewById(R.id.etHPRSingle);
        etHPB = (TextView) findViewById(R.id.etHPBSingle);
        etSSFR = (TextView) findViewById(R.id.etSSFRSingle);
        etSSFB = (TextView) findViewById(R.id.etSSFBSingle);
        etRateR = (TextView) findViewById(R.id.etRateRSingle);
        etRateB = (TextView) findViewById(R.id.etRateBSingle);
        etDiff = (TextView) findViewById(R.id.etDiffSingle);
        etTime = (TextView) findViewById(R.id.etTimeSingle);
        etWin = (TextView) findViewById(R.id.etWinSingle);

        home.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),MainMenuActivity.class);
                startActivity(i);
                finish();
            }
        });

        playAgain.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),ActivityCustomizeBlue.class);
                startActivity(i);
                finish();
            }
        });

        Intent intent = getIntent();

        String win = intent.getExtras().getString("winner");
        int time = intent.getExtras().getInt("timeLeft");
        int hp = intent.getExtras().getInt("health");
        int specials = intent.getExtras().getInt("specialFired");
        int accuracy = (int) intent.getExtras().getFloat("accuracy");

        int player2Hp = intent.getExtras().getInt("player2health");
        int player2Specials = intent.getExtras().getInt("player2specialFired");
        int player2Accuracy = (int) intent.getExtras().getFloat("player2accuracy");

        int finalScoreA = 0;

        if ((hp - 2*specials) < 1)
            finalScoreA = 1;
        else {
            finalScoreA = hp - 2 * specials;
        }

        int finalScoreB = accuracy + time;
        int finalScoreC = (difficulty) * 15;

        int finalScore = finalScoreA * finalScoreB + finalScoreC;

        etWin.setText(win);

        etTime.setText(time+"");

        etHPB.setText(hp+"");
        etRateB.setText(accuracy+"%");
        etSSFB.setText(specials+"");

        etRateR.setText(player2Accuracy+""+"%");
        etHPR.setText(player2Hp+"");
        etSSFR.setText(player2Specials+"");


        if(difficulty == 0)
            etDiff.setText("Easy");
        else if(difficulty == 1)
            etDiff.setText("Medium");
        else
            etDiff.setText("Hard");


    }
}
