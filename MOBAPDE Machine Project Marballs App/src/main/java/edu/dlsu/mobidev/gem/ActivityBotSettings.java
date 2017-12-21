package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;

public class ActivityBotSettings extends AppCompatActivity {

    Spinner spDifficulty, spMovement;
    TextView tvDescription;
    Button btBack,btStart;
    boolean sfx, bgm;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bot_settings);

        spDifficulty = (Spinner) findViewById(R.id.sp_difficulty);
        spMovement = (Spinner) findViewById(R.id.sp_move);
        tvDescription = (TextView) findViewById(R.id.tv_description);
        btBack = (Button) findViewById(R.id.buttonBack);
        btStart = (Button) findViewById(R.id.buttonFinish);

        SharedPreferences dsp =
                PreferenceManager
                        .getDefaultSharedPreferences(getBaseContext());

        int difficulty = dsp.getInt("difficulty", 0);
        int movement = dsp.getInt("movement", 0);
        sfx = dsp.getBoolean("sfx",true);
        bgm = dsp.getBoolean("bgm",true);

        spMovement.setSelection(movement);
        spDifficulty.setSelection(difficulty);

        if(difficulty == 0)
            tvDescription.setText("This is the easiest version. The opponent can not fire special shots and its stats are diminished.");
        else if (difficulty == 1)
            tvDescription.setText("This is the normal version. The opponent can fire special shots and its stats are comparatively average.");
        else if (difficulty == 2)
            tvDescription.setText("This is the hard version. The opponent can fire more special shots and its stats are increased.");
        else
            tvDescription.setText(" ");


        spDifficulty.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if(position == 0)
                    tvDescription.setText("This is the easiest version. The opponent can not fire special shots and its stats are diminished.");
                else if (position == 1)
                    tvDescription.setText("This is the normal version. The opponent can fire fast special shots and its stats are comparatively average.");
                else if (position == 2)
                    tvDescription.setText("This is the hard version. The opponent can fire gigantic special shots and its stats are increased.");
                else
                    tvDescription.setText(" ");
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });


        btStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int diff = spDifficulty.getSelectedItemPosition();
                boolean move;

                if(spMovement.getSelectedItemPosition() == 1)
                    move = true;
                else
                    move = false;
//                if(diff==1)
//                    move = true;

                Intent i = new Intent(getBaseContext(),SinglePlayerGame.class);
                i.putExtra("difficulty",diff);
                i.putExtra("movement",move);
                i.putExtra("sfx",sfx);
                i.putExtra("bgm",bgm);
                startActivity(i);
                finish();
            }
        });


    }
}
