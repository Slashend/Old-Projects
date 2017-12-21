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
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.Spinner;

public class ActivityCustomizeSettings extends AppCompatActivity {

    Button home, cancel;
    Spinner spinnerMovement, spinnerDiff;
    CheckBox checkboxEffects, checkboxMusic;
    int i = 0;
    int j = 0;
    boolean sfx, bgm;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        setContentView(R.layout.activity_customize_settings);

        cancel = (Button) findViewById(R.id.cancelButton);
        home = (Button) findViewById(R.id.homeButton);
        spinnerMovement = (Spinner) findViewById(R.id.spinnerMovement);
        spinnerDiff = (Spinner) findViewById(R.id.spinnerDiff);
        checkboxEffects = (CheckBox) findViewById(R.id.checkboxEffects);
        checkboxMusic = (CheckBox) findViewById(R.id.checkboxMusic);

        SharedPreferences dsp =
                PreferenceManager
                        .getDefaultSharedPreferences(getBaseContext());

        int difficulty = dsp.getInt("difficulty", 0);
        int movement = dsp.getInt("movement", 0);
        sfx = dsp.getBoolean("sfx",true);
        bgm = dsp.getBoolean("bgm",true);

        spinnerMovement.setSelection(movement);
        spinnerDiff.setSelection(difficulty);

        checkboxMusic.setChecked(bgm);
        checkboxEffects.setChecked(sfx);


        /*
        spinnerDiff.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                i = position;
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });

        spinnerMovement.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                j = position;
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        */


        cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Go to greetings activity
                Intent i = new Intent(getBaseContext(), MainMenuActivity.class);
                startActivity(i);
                finish();
            }
        });




        home.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // store name of user in sharedpreferences
                // get the name
                i = spinnerDiff.getSelectedItemPosition();
                j = spinnerMovement.getSelectedItemPosition();
                sfx = checkboxEffects.isChecked();
                bgm = checkboxMusic.isChecked();

                // store the name
                SharedPreferences dsp =
                        PreferenceManager
                                .getDefaultSharedPreferences(getBaseContext());

                SharedPreferences.Editor dspEditor = dsp.edit();

                dspEditor.putInt("difficulty",i);
                dspEditor.putInt("movement",j);
                dspEditor.putBoolean("sfx",sfx);
                dspEditor.putBoolean("bgm",bgm);
                dspEditor.commit();

                // Go to greetings activity
                Intent i = new Intent(getBaseContext(), MainMenuActivity.class);
                startActivity(i);
                // finish();
            }
        });
    }
}
