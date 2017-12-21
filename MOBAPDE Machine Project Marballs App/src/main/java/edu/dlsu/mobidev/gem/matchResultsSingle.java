package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.TextView;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;

import static edu.dlsu.mobidev.gem.GamePanel.difficulty;

public class matchResultsSingle extends AppCompatActivity {

    Button home, playAgain;
    TextView etHPR, etHPB, etSSFR, etSSFB, etRateR, etRateB, etDiff, etTime, etWin, etScore;
    TextView etName;

    DatabaseHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        setContentView(R.layout.activity_match_results_single);

        dbHelper = new DatabaseHelper(getBaseContext());

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
        etScore = (TextView) findViewById(R.id.etScoreSingle);

        etName = findViewById(R.id.nameHs);

        Intent intent = getIntent();

        final String win = intent.getExtras().getString("winner");
        int time = intent.getExtras().getInt("timeLeft");
        int hp = intent.getExtras().getInt("health");
        int specials = intent.getExtras().getInt("specialFired");
        int accuracy = (int) intent.getExtras().getFloat("accuracy");

        int player2Hp = intent.getExtras().getInt("player2health");
        int player2Specials = intent.getExtras().getInt("player2specialFired");
        int player2Accuracy = (int) intent.getExtras().getFloat("player2accuracy");

        int finalScoreA = 0;

        if ((hp - 2 * specials) < 1)
            finalScoreA = 1;
        else {
            finalScoreA = hp - 2 * specials;
        }

        int finalScoreB = accuracy + time;
        int finalScoreC = (difficulty) * 15;

        final int finalScore = finalScoreA * finalScoreB + finalScoreC;

        etWin.setText(win);

        etTime.setText(time + "");

        etHPB.setText(hp + "");
        etRateB.setText(accuracy + "%");
        etSSFB.setText(specials + "");

        etRateR.setText(player2Accuracy + "" + "%");
        etHPR.setText(player2Hp + "");
        etSSFR.setText(player2Specials + "");

        etScore.setText(finalScore + "");

        if (difficulty == 0)
            etDiff.setText("Easy");
        else if (difficulty == 1)
            etDiff.setText("Medium");
        else
            etDiff.setText("Hard");

        home.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                saveScore(etName.getText().toString(), finalScore, win.equals("Blue"));

                Intent i = new Intent(v.getContext(), MainMenuActivity.class);
                startActivity(i);
                finish();
            }
        });

        playAgain.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                saveScore(etName.getText().toString(), finalScore, win.equals("Blue"));

                Intent i = new Intent(v.getContext(), ActivityCustomizeSinglePlayer.class);
                startActivity(i);
                finish();
            }
        });


    }

    private void saveScore(String name, int highScore, boolean isWin) {
        SharedPreferences dsp =
                PreferenceManager
                        .getDefaultSharedPreferences(getBaseContext());

        SharedPreferences.Editor dspEditor = dsp.edit();

//        dspEditor.clear().commit();

        // Get previous games, losses, and wins
        int losses = dsp.getInt("losses", 0);
        int wins = dsp.getInt("wins", 0);
        int games = dsp.getInt("games", 0);

        if (isWin) {
            dspEditor.putInt("wins", wins + 1);
        } else {
            dspEditor.putInt("losses", losses + 1);
        }

        dspEditor.putInt("games", games + 1);
        dspEditor.commit();

        HighScore hs = new HighScore();

        hs.setName(name);
        hs.setHighscore(highScore);

        String date;
        DateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
        Calendar calendar = Calendar.getInstance();

        date = dateFormat.format(calendar.getTime());

        hs.setDate(date);

        dbHelper.addHighScore(hs);
    }
}
