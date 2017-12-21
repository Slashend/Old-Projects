package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class ActivityCustomizeSinglePlayer extends AppCompatActivity {
    
    public ArrayList<RectPlayer> blueBotList;
    public static RectPlayer selectedBot;

    Button startGame,back;
    Button shoulderLeft, shoulderRight;
    Button headLeft, headRight;
    Button armLeft, armRight;
    ImageView imgBot;
    TextView tvHp,tvMove,tvAmmo,tvSpecial;

    private int index;


    List<Integer> sprites;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        setContentView(R.layout.activity_customize_single_player);

        tvHp = (TextView) findViewById(R.id.tv_hp);
        tvAmmo = (TextView) findViewById(R.id.tv_ammo);
        tvSpecial = (TextView) findViewById(R.id.tv_special);
        tvMove = (TextView) findViewById(R.id.tv_move);
        startGame = (Button) findViewById(R.id.buttonFinish);
        back = (Button) findViewById(R.id.buttonBack);
        shoulderLeft = (Button) findViewById(R.id.bt_shoulder_left);
        shoulderRight = (Button) findViewById(R.id.bt_shoulder_right);
        headLeft = (Button) findViewById(R.id.bt_head_left);
        headRight = (Button) findViewById(R.id.bt_head_right);
        armLeft = (Button) findViewById(R.id.bt_arm_left);
        armRight = (Button) findViewById(R.id.bt_arm_right);
        imgBot = (ImageView) findViewById(R.id.imgDisplay);

//        drpdwn = (Spinner) findViewById(R.id.sp_head);
//        SpinnerAdapter fidget;


      //  drpdwn.set
        sprites = new ArrayList<>();


        index = 0;
        blueBotList = new ArrayList<RectPlayer>();
        initData();
        setButtonClicks();
        selectedBot = blueBotList.get(0);
        updateSelected();
    }


    public void setButtonClicks(){

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),MainMenuActivity.class);
                startActivity(i);
                finish();
            }
        });

        startGame.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(),ActivityBotSettings.class);
                startActivity(i);
                finish();
            }
        });

        headRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if(index < 9){
                    index +=9;
                }
                else {
                    index+=9;
                    if (index > 17)
                        index = index - 18;
                }
                imgBot.setImageResource(blueBotList.get(index).getBotSprite());
                selectedBot = blueBotList.get(index);
                updateSelected();
            }
        });

        armRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(index < 9){
                    index +=3;
                    if (index > 8)
                        index = index - 9;
                }
                else {
                    index+=3;
                    if (index > 17)
                        index = index - 9;
                }

                imgBot.setImageResource(blueBotList.get(index).getBotSprite());
                selectedBot = blueBotList.get(index);
                updateSelected();
            }
        });

        shoulderRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                index++;
                if(index % 3 == 0)
                    index -= 3;
                imgBot.setImageResource(blueBotList.get(index).getBotSprite());
                selectedBot = blueBotList.get(index);
                updateSelected();
            }
        });

        headLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(index > 9){
                    index -=9;
                }
                else {
                    index-=9;
                    if (index < 0)
                        index = index + 18;
                }
                imgBot.setImageResource(blueBotList.get(index).getBotSprite());
                selectedBot = blueBotList.get(index);
                updateSelected();

            }
        });

        armLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(index < 9){
                    index -=3;
                    if (index < 0)
                        index = index + 9;
                }
                else {
                    index-=3;
                    if (index < 9)
                        index = index + 9;
                }

                imgBot.setImageResource(blueBotList.get(index).getBotSprite());
                selectedBot = blueBotList.get(index);
                updateSelected();
            }
        });

        shoulderLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                index--;
                if(index % 3 == 2 || index < 0 )
                    index += 3;
                imgBot.setImageResource(blueBotList.get(index).getBotSprite());
                selectedBot = blueBotList.get(index);
                updateSelected();
            }

        });

    }

    public void updateSelected(){
        tvMove.setText(selectedBot.toString(selectedBot.getMoveSpeed()));
        tvHp.setText(selectedBot.toString(selectedBot.getHealth()));
        tvAmmo.setText(selectedBot.toString(selectedBot.getAmmo()));

        if(selectedBot.getSpecial() == 1)
            tvSpecial.setText("Fires one large marble which takes four enemy hits to negate.");
        else
            tvSpecial.setText("Fires one fast marble which travels at a much faster rate.");

    }
    public void initData(){


//        RectPlayer bo/b = new RectPlayer(true,R.drawable.h1a1s1);
//        Ball ball = new Ball(1,2,true);
//        redBotList.add(bob);
        //
        //ammo s 2
//               a + 3
        blueBotList.add(new RectPlayer(true,5,1,15,8,R.drawable.h1a1s1));
        blueBotList.add(new RectPlayer(true,5,1,20,5,R.drawable.h1a1s2));
        blueBotList.add(new RectPlayer(true,8,1,15,5,R.drawable.h1a1s3));
        blueBotList.add(new RectPlayer(true,5,1,18,6,R.drawable.h1a2s1));
        blueBotList.add(new RectPlayer(true,5,1,23,3,R.drawable.h1a2s2));
        blueBotList.add(new RectPlayer(true,8,1,18,3,R.drawable.h1a2s3));
        blueBotList.add(new RectPlayer(true,10,1,15,6,R.drawable.h1a3s1));
        blueBotList.add(new RectPlayer(true,10,1,20,3,R.drawable.h1a3s2));
        blueBotList.add(new RectPlayer(true,13,1,15,3,R.drawable.h1a3s3));

        blueBotList.add(new RectPlayer(true,5,2,15,8,R.drawable.h2a1s1));
        blueBotList.add(new RectPlayer(true,5,2,20,5,R.drawable.h2a1s2));
        blueBotList.add(new RectPlayer(true,8,2,15,5,R.drawable.h2a1s3));
        blueBotList.add(new RectPlayer(true,5,2,18,6,R.drawable.h2a2s1));
        blueBotList.add(new RectPlayer(true,5,2,23,3,R.drawable.h2a2s2));
        blueBotList.add(new RectPlayer(true,8,2,18,3,R.drawable.h2a2s3));
        blueBotList.add(new RectPlayer(true,10,2,15,6,R.drawable.h2a3s1));
        blueBotList.add(new RectPlayer(true,10,2,20,3,R.drawable.h2a3s2));
        blueBotList.add(new RectPlayer(true,13,2,15,3,R.drawable.h2a3s3));

    }
}
