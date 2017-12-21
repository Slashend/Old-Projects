package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class highScoreActivity extends AppCompatActivity {

    Button buttonHome;
    TextView tvTitle, tvTitle2, tvWins, tvLosses, tvGames, tvRate;
    TextView etWins, etLosses, etGames, etRate;


    //ToDo: Initialize Recycler View and adapter
    RecyclerView recyclerView;
    DatabaseHelper dbHelper;
    HighScoreAdapter highScoreAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        setContentView(R.layout.activity_high_score);

        recyclerView = findViewById(R.id.highscore_recyclerview);
        dbHelper = new DatabaseHelper(getBaseContext());

        highScoreAdapter
                = new HighScoreAdapter(getBaseContext(),
                dbHelper.getAllHighScoresCursor());

        recyclerView.setAdapter(highScoreAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(getBaseContext()));

        buttonHome = (Button) findViewById(R.id.buttonHS);

        tvTitle = (TextView) findViewById(R.id.titleHS);
        tvTitle2 = (TextView) findViewById(R.id.title2HS);
        tvWins = (TextView) findViewById(R.id.tvWinHS);
        tvLosses = (TextView) findViewById(R.id.tvLossHS);
        tvGames = (TextView) findViewById(R.id.tvGamesHS);
        tvRate = (TextView) findViewById(R.id.tvRateHS);

        etWins = (TextView) findViewById(R.id.etWinsHS);
        etLosses = (TextView) findViewById(R.id.etLossHS);
        etGames = (TextView) findViewById(R.id.etGamesHS);
        etRate = (TextView) findViewById(R.id.etRateHS);

        SharedPreferences dsp =
                PreferenceManager
                        .getDefaultSharedPreferences(getBaseContext());

        // Get previous games, losses, and wins
        int losses = dsp.getInt("losses", 0);
        int wins = dsp.getInt("wins", 0);
        int games = dsp.getInt("games", 0);

//        Log.wtf("YO: ", (int)(((double) wins) / games * 100.0) + "%");

//        System.out.println("YO: " + (int)(((double) wins) / games * 100.0) + "%");

//        etWins.setText(wins + "");
        etWins.setText(wins + "");
        etLosses.setText(losses + "");
        etGames.setText(games + "");
        etRate.setText((int)((wins * 100.0) / games) + "%");

        buttonHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(), MainMenuActivity.class);
                startActivity(i);
                finish();
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        highScoreAdapter.changeCursor(dbHelper.getAllHighScoresCursor());
    }
}
