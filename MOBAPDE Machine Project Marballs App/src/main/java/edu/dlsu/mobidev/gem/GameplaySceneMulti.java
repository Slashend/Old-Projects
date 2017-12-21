package edu.dlsu.mobidev.gem;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.LinearGradient;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;
import android.graphics.Shader;
import android.media.MediaPlayer;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageButton;

import java.util.Random;

import static edu.dlsu.mobidev.gem.SinglePlayerGame.bgm;
import static edu.dlsu.mobidev.gem.SinglePlayerGame.sfx;

/**
 * Created by asus on 11/7/2017.
 *
 *
 * NOTE: Rect Parameters are (left, top, right, bottom) if ever you will adjust the positioning
 */

public class GameplaySceneMulti implements Scene {

    private String winner;

    private int playerShotsFired;
    private int playerSpecialsFired;
    private int player2ShotsFired;
    private int player2SpecialsFired;

    private int timeLeft;

    private Rect r = new Rect();

    private RectPlayer player;
    private Point playerPoint;
    private long playerFireTime;
    private BallManager ballManager;
    private Rect playerHp;
    private Rect playerHp2;

    private boolean gameOver;
    private long gameOverTime;

    private RectPlayer player2;
    private Point player2Point;
    private long player2FireTime;
    private Rect player2Hp;
    private Rect player2Hp2;

    private BitmapFactory bf;
    private Bitmap playerSpecialTimer;


    private MediaPlayer mpSound;
    private MediaPlayer mpMusic;
    private int right;
    private int player2Right;

    private int playerHpChange;
    private int player2HpChange;
    private int specialFireTime;
    private int player2SpecialFireTime;
    private long timePassed;

    private long playerReloadCdLeft,playerReloadCdRight;
    private long player2ReloadCdLeft, player2ReloadCdRight;



    private Bitmap background;
    private Activity activity;
    private ImageButton p1btLeft;
    private ImageButton p1btRight;
    private ImageButton p2btLeft;
    private ImageButton p2btRight;
    private float playerHpRemove;
    private float player2HpRemove;

    private Ball playerReloadLeft,playerReloadRight;
    private Ball player2ReloadLeft, player2ReloadRight;



    public GameplaySceneMulti(){

        activity = (Activity) Constants.CURRENT_CONTEXT;
        p1btLeft = (ImageButton) activity.findViewById(R.id.bt_p1left);
        p1btRight = (ImageButton) activity.findViewById(R.id.bt_p1right);
        p2btLeft = (ImageButton) activity.findViewById(R.id.bt_p2left);
        p2btRight = (ImageButton) activity.findViewById(R.id.bt_p2right);
        gameOver = false;
        right = 0;
        playerHpChange = 15;
        player2HpChange = 85;
        player2Right = 0;
        player2ShotsFired
                = player2SpecialsFired
                = playerShotsFired
                = playerSpecialsFired = 0;


        player = ActivityCustomizeBlue.selectedBot;
        playerPoint = new Point(Constants.SCREEN_WIDTH/2,85*Constants.SCREEN_HEIGHT/100);
        player.update(playerPoint);

        player2SpecialFireTime = 15;

        //Change THIS to selected bot from prev activity

        // player2 = new RectPlayer(false, 15, 1, 30, 10, R.drawable.pr);
        //Sets initial position
        player2 = ActivityCustomizeRed.selectedBot;
        player2Point = new Point(Constants.SCREEN_WIDTH / 2, (int) 13* Constants.SCREEN_HEIGHT / 100);
        player2.update(player2Point);

        //Manages Balls
        ballManager = new BallManager();
        ballManager.reloadEnemy(player.getAmmo());
        ballManager.reloadPlayer(player.getAmmo());

        mpMusic = MediaPlayer.create(Constants.CURRENT_CONTEXT,R.raw.battlepressure);

        if (bgm == true)
        {
            mpMusic.start();
            mpMusic.setLooping(true);
        }

        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT,R.raw.megamandeath);



        bf = new BitmapFactory();
        playerSpecialTimer = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(),R.drawable.timer);
        background = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(),R.drawable.battlebgtwo);






        //HP Bars
        playerHp = new Rect(Constants.SCREEN_WIDTH*15/100,
                Constants.SCREEN_HEIGHT*93/100 -5,
                Constants.SCREEN_WIDTH*45/100,
                Constants.SCREEN_HEIGHT*96/100-5);

        player2Hp = new Rect(Constants.SCREEN_WIDTH*55/100,
                Constants.SCREEN_HEIGHT*93/100-5,
                Constants.SCREEN_WIDTH*85/100,
                Constants.SCREEN_HEIGHT*96/100-5);

        playerHp2 = new Rect(Constants.SCREEN_WIDTH*15/100,
                Constants.SCREEN_HEIGHT*7/100 +5,
                Constants.SCREEN_WIDTH*45/100,
                Constants.SCREEN_HEIGHT*4/100+5);

        player2Hp2 = new Rect(Constants.SCREEN_WIDTH*55/100,
                Constants.SCREEN_HEIGHT*7/100+5,
                Constants.SCREEN_WIDTH*85/100,
                Constants.SCREEN_HEIGHT*4/100+5);


        //Game Time
        timeLeft = 60;

        //Player 1 special cd
        specialFireTime = 15;

        playerReloadCdLeft
                = timePassed
                = playerReloadCdRight
                = player2ReloadCdRight
                = player2ReloadCdLeft
                = player2FireTime
                = playerFireTime = System.currentTimeMillis();




        //How much of the hp will be depleted
        playerHpRemove = 30 / player.getHealth()*1f;
        player2HpRemove = 30 / player2.getHealth()*1f;



        //Button left of P2
        p2btLeft.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN){
                    player2Right = -1*player2.getMoveSpeed();
                    return true;
                }
                else  if (event.getAction() == MotionEvent.ACTION_UP){
                    player2Right = 0;
                    return true;
                }
                return false;
            }
        });

        //Button right of P2
        p2btRight.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN){
                    player2Right = player2.getMoveSpeed();
                    return true;
                }
                else  if (event.getAction() == MotionEvent.ACTION_UP){
                    player2Right = 0;
                    return true;
                }
                return false;
            }
        });

        //Button right of P1
        p1btRight.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN){
                    right = player.getMoveSpeed();
                    return true;
                }
                else  if (event.getAction() == MotionEvent.ACTION_UP){
                    right = 0;
                    return true;
                }

                return false;
            }
        });

        //Button left of P1
        p1btLeft.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN){
                    right = -1*player.getMoveSpeed();
                    return true;
                }
                else  if (event.getAction() == MotionEvent.ACTION_UP){
                    right = 0;
                    return true;
                }

                return false;
            }
        });





        //Reload balls on the side
        playerReloadLeft = new Ball(50,playerPoint.y + 55,true);
        playerReloadRight = new Ball(Constants.SCREEN_WIDTH - 50, playerPoint.y + 55, true);
        player2ReloadLeft = new Ball(50, player2Point.y-10,false);
        player2ReloadRight = new Ball(Constants.SCREEN_WIDTH - 50, player2Point.y-10,false);



    }

    //Does Nothing
    public void reset(){



    }




    //Returns true when anyone's hp becomes 0
    public boolean isGameOver() {
        if (ballManager.playerCollide(player2, true)){
            player2HpChange -= player2HpRemove;
            player2Hp.right = Constants.SCREEN_WIDTH * player2HpChange / 100;
            player2Hp2.right = Constants.SCREEN_WIDTH * player2HpChange / 100;
            //loseHealth() returns true if health is 0
            if (player2.loseHealth()) {
                player2Hp.right = Constants.SCREEN_WIDTH * 55 / 100;
                player2Hp2.right = Constants.SCREEN_WIDTH * 55 / 100;
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.megamandeath);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
                return true;
            } else {
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.hit);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
            }

        }
        if(ballManager.playerCollide(player,false)){
            playerHpChange += playerHpRemove;
            playerHp.left = Constants.SCREEN_WIDTH * playerHpChange /100;
            playerHp2.left = Constants.SCREEN_WIDTH * playerHpChange /100;
            if(player.loseHealth()){
                playerHp.left = Constants.SCREEN_WIDTH * 45/100;
                playerHp2.left = Constants.SCREEN_WIDTH * 45/100;
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.megamandeath);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
                return true;
            }
            else {
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.hit);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
            }

        }
        return false;
    }

    @Override
    public void update() {
        if(!gameOver) {



            if(player2Point.x >= Constants.SCREEN_WIDTH - 50)
                player2Point.set(player2Point.x - 50, player2Point.y);
            else if(player2Point.x <= 50)
                player2Point.set(player2Point.x + 50, player2Point.y);

            if(player2Point.x < Constants.SCREEN_WIDTH && player2Point.x > 0)
                player2Point.set(player2Point.x + player2Right, player2Point.y);

            if(playerPoint.x >= Constants.SCREEN_WIDTH - 50)
                playerPoint.set(playerPoint.x - 50, playerPoint.y);
            else if(playerPoint.x <= 50)
                playerPoint.set(playerPoint.x + 50, playerPoint.y);

            if(playerPoint.x < Constants.SCREEN_WIDTH && playerPoint.x > 0)
                playerPoint.set(playerPoint.x + right, playerPoint.y);

            player.update(playerPoint);
            player2.update(player2Point);
            ballManager.update();

            if(System.currentTimeMillis() - timePassed >= 1000 && specialFireTime > 0){
                specialFireTime--;
            }

            if(System.currentTimeMillis() - timePassed >= 1000 && player2SpecialFireTime > 0){
                player2SpecialFireTime--;
            }

            if(System.currentTimeMillis() - timePassed >= 1000){
                timeLeft--;
                if(timeLeft <= 0)
                    gameOver = true;
                timePassed = System.currentTimeMillis();
            }


            if(isGameOver())
                gameOver = true;



            if((playerReloadLeft.playercollide(player)) && System.currentTimeMillis() - playerReloadCdLeft >= 3000){
                ballManager.reloadPlayer(player.getAmmo());
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.reload);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
                playerReloadCdLeft = System.currentTimeMillis();

            }
            if((playerReloadRight.playercollide(player)) && System.currentTimeMillis() - playerReloadCdRight >= 3000){
                ballManager.reloadPlayer(player.getAmmo());
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.reload);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
                playerReloadCdRight = System.currentTimeMillis();
            }

            if((player2ReloadLeft.playercollide(player2)) && System.currentTimeMillis() - player2ReloadCdLeft >= 3000){
                ballManager.reloadEnemy(player2.getAmmo());
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.reload);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
                player2ReloadCdLeft = System.currentTimeMillis();

            }
            if((player2ReloadRight.playercollide(player2)) && System.currentTimeMillis() - player2ReloadCdRight >= 3000){
                ballManager.reloadEnemy(player2.getAmmo());
                mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.reload);
                if (sfx == true)
                {
                    mpSound.start();
                }
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
                player2ReloadCdRight = System.currentTimeMillis();
            }


            gameOverTime = System.currentTimeMillis();
        }

    }

    @Override
    public void draw(Canvas canvas) {


//        canvas.drawColor(Color.BLACK);

        canvas.drawBitmap(background,null,new Rect(0,0,Constants.SCREEN_WIDTH,Constants.SCREEN_HEIGHT),new Paint());
        if(System.currentTimeMillis() - playerReloadCdLeft >= 3000) {
            playerReloadLeft.draw(canvas);
        }
        if(System.currentTimeMillis() - playerReloadCdRight >= 3000) {
            playerReloadRight.draw(canvas);
        }
        if(System.currentTimeMillis() - player2ReloadCdLeft >= 3000) {
            player2ReloadLeft.draw(canvas);
        }
        if(System.currentTimeMillis() - player2ReloadCdRight >= 3000) {
            player2ReloadRight.draw(canvas);
        }

        Paint border, hpPlayer,hpEnemy;
        border =  new Paint();
        hpPlayer = new Paint();
        hpEnemy = new Paint();
        player.draw(canvas);
        player2.draw(canvas);
        ballManager.draw(canvas);


        //Draws timer
        canvas.drawBitmap(playerSpecialTimer,null,new Rect(Constants.SCREEN_WIDTH*46/100,
                Constants.SCREEN_HEIGHT*91/100-5,
                Constants.SCREEN_WIDTH*54/100,
                Constants.SCREEN_HEIGHT*98/100-5),new Paint());

        canvas.drawBitmap(playerSpecialTimer,null,new Rect(Constants.SCREEN_WIDTH*46/100,
                Constants.SCREEN_HEIGHT*2/100+5,
                Constants.SCREEN_WIDTH*54/100,
                Constants.SCREEN_HEIGHT*9/100+5),new Paint());


        hpPlayer.setShader(new LinearGradient(playerHp.left,0,playerHp.right,0,Color.rgb(0,0,200),Color.rgb(0,0,170),Shader.TileMode.CLAMP));
        hpEnemy.setShader(new LinearGradient(player2Hp.left,0, player2Hp.right,0,Color.rgb(170,0,0),Color.rgb(200,0,0),Shader.TileMode.CLAMP));
        border.setStyle(Paint.Style.STROKE);
        border.setStrokeWidth(5);
        border.setColor(Color.BLACK);


        canvas.drawRect(playerHp,hpPlayer);
        canvas.drawRect(player2Hp,hpEnemy);
        canvas.drawRect(playerHp,border);
        canvas.drawRect(player2Hp,border);

        hpPlayer.setShader(new LinearGradient(playerHp2.left,0,playerHp2.right,0,Color.rgb(0,0,200),Color.rgb(0,0,170),Shader.TileMode.CLAMP));
        hpEnemy.setShader(new LinearGradient(player2Hp2.left,0, player2Hp2.right,0,Color.rgb(170,0,0),Color.rgb(200,0,0),Shader.TileMode.CLAMP));

        canvas.drawRect(playerHp2,hpPlayer);
        canvas.drawRect(player2Hp2,hpEnemy);
        canvas.drawRect(playerHp2,border);
        canvas.drawRect(player2Hp2,border);

        drawTimer(canvas);
        if(gameOver){
            Paint paint = new Paint();
            paint.setTextSize(100);
            paint.setColor(Color.BLACK);

            if((player.getHealth() <= 0 && player2.getHealth() <= 0) || player.getHealth() == player2.getHealth()) {
                drawCenterText(canvas, paint, "DRAW");
                winner = "Draw";
            }
            else if(player.getHealth() < player2.getHealth() ) {
                drawCenterText(canvas, paint, "PLAYER 2 WINS");
                winner = "Red";
            }
            else if(player2.getHealth() < player.getHealth() ) {
                drawCenterText(canvas, paint, "PLAYER 1 WINS");
                winner = "Blue";
            }
        }
        if(timeLeft <=5 && timeLeft > 0){
            Paint paint = new Paint();
            paint.setTextSize(100);
            paint.setColor(Color.BLACK);
            String text = timeLeft+"";
            drawCenterText(canvas,paint,text);
        }

        Paint p = new Paint();
        p.setColor(Color.BLACK);
        p.setTextSize(50);
        String text = "Ammo: " + ballManager.getPlayerAmmo();
        String text2 = "Time: " + timeLeft;

        canvas.drawText(text, Constants.SCREEN_WIDTH*8/100,Constants.SCREEN_HEIGHT*90/100, p);
        canvas.drawText(text2, Constants.SCREEN_WIDTH*72/100,Constants.SCREEN_HEIGHT*90/100, p);

        //Player 2 Side
        text = "Ammo: " + ballManager.getEnemyAmmo();

        //To flip, write before drawText()
        //canvas.rotate(degress,x,y)
        //x = x ng text, y = y ng text
        //Then flip again
        //canvas.rotate(-degress,x,y)
        //Do this PER drawText (Unless di pala madidisplace yung text)

        canvas.rotate(180,Constants.SCREEN_WIDTH*92/100,Constants.SCREEN_HEIGHT*11/100);
        canvas.drawText(text, Constants.SCREEN_WIDTH*92/100,Constants.SCREEN_HEIGHT*11/100, p);
        canvas.rotate(-180,Constants.SCREEN_WIDTH*92/100,Constants.SCREEN_HEIGHT*11/100);


        canvas.rotate(180,Constants.SCREEN_WIDTH*28/100,Constants.SCREEN_HEIGHT*11/100);
        canvas.drawText(text2, Constants.SCREEN_WIDTH*28/100,Constants.SCREEN_HEIGHT*11/100, p);
        canvas.rotate(-180,Constants.SCREEN_WIDTH*28/100,Constants.SCREEN_HEIGHT*11/100);




    }

    @Override
    public void terminate() {
        SceneManager.ACTIVE_SCENE = 0;
    }

    @Override
    public void receiveTouch(MotionEvent event) {
        switch (event.getActionMasked()) {

            case MotionEvent.ACTION_DOWN:
                if(!gameOver
                        && event.getX() >= Constants.SCREEN_WIDTH * 0.46
                        && event.getX() <= Constants.SCREEN_WIDTH * 0.54
                        && event.getY() >= Constants.SCREEN_HEIGHT * 0.91){
                    if(specialFireTime <= 0){
                        ballManager.playerFireSpecial(playerPoint.x,playerPoint.y,true,player.getSpecial());
                        specialFireTime = 15;
                        playerSpecialsFired++;

                    }
                }
                else if(!gameOver && System.currentTimeMillis() - playerFireTime >= 500 && event.getY() > Constants.SCREEN_HEIGHT/2){
                    if(ballManager.getPlayerAmmo() > 0 ) {
                        ballManager.fire(playerPoint.x, playerPoint.y, true);
                        playerShotsFired++;
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.fire);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                        playerFireTime = System.currentTimeMillis();
                    }
                    else{
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.empty);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                    }

                }
                if(!gameOver
                        && event.getX() >= Constants.SCREEN_WIDTH * 0.46
                        && event.getX() <= Constants.SCREEN_WIDTH * 0.54
                        && event.getY() <= Constants.SCREEN_HEIGHT * 0.09){
                    if(player2SpecialFireTime <= 0){
                        ballManager.player2FireSpecial(player2Point.x,player2Point.y,false,player2.getSpecial());
                        player2SpecialFireTime = 15;
                        playerSpecialsFired++;

                    }
                }
                else if(!gameOver && System.currentTimeMillis() - player2FireTime >= 500 && event.getY() <= Constants.SCREEN_HEIGHT/2){
                    if(ballManager.getEnemyAmmo() > 0 ) {
                        ballManager.fire(player2Point.x, player2Point.y, false);
                        player2ShotsFired++;
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.fire);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                        player2FireTime = System.currentTimeMillis();
                    }
                    else{
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.empty);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                    }

                }

                if(gameOver && System.currentTimeMillis() - gameOverTime >= 1000){
                    Intent intent = new Intent(Constants.CURRENT_CONTEXT,matchResultsMulti.class);
                    if(mpMusic.isPlaying()) {
                        mpMusic.stop();
                        mpMusic.release();
                    }
                    intent.putExtra("accuracy",((player2.getTotalHealth()- player2.getHealth())*1f/ (playerShotsFired+playerSpecialsFired))*100);
                    intent.putExtra("health",player.getHealth());
                    intent.putExtra("specialFired",playerSpecialsFired);
                    intent.putExtra("timeLeft",timeLeft);
                    intent.putExtra("player2accuracy",((player.getTotalHealth()-player.getHealth())*1f/ (player2ShotsFired + player2SpecialsFired))*100);
                    intent.putExtra("player2health", player2.getHealth());
                    intent.putExtra("player2specialFired", player2SpecialsFired);
                    intent.putExtra("winner",winner);
                    Constants.CURRENT_CONTEXT.startActivity(intent);
                    ((Activity) Constants.CURRENT_CONTEXT).finish();

                }


                break;
            case MotionEvent.ACTION_POINTER_DOWN:
                if(!gameOver
                        && event.getX() >= Constants.SCREEN_WIDTH * 0.46
                        && event.getX() <= Constants.SCREEN_WIDTH * 0.54
                        && event.getY() >= Constants.SCREEN_HEIGHT * 0.91){
                    if(specialFireTime <= 0){
                        ballManager.playerFireSpecial(playerPoint.x,playerPoint.y,true,player.getSpecial());
                        specialFireTime = 15;
                        playerSpecialsFired++;

                    }
                }
                else if(!gameOver && System.currentTimeMillis() - playerFireTime >= 500 && event.getY() > Constants.SCREEN_HEIGHT/2){
                    if(ballManager.getPlayerAmmo() > 0 ) {
                        ballManager.fire(playerPoint.x, playerPoint.y, true);
                        playerShotsFired++;
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.fire);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                        playerFireTime = System.currentTimeMillis();
                    }
                    else{
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.empty);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                    }

                }
                if(!gameOver
                        && event.getX() >= Constants.SCREEN_WIDTH * 0.46
                        && event.getX() <= Constants.SCREEN_WIDTH * 0.54
                        && event.getY() <= Constants.SCREEN_HEIGHT * 0.09){
                    if(player2SpecialFireTime <= 0){
                        ballManager.player2FireSpecial(player2Point.x,player2Point.y,false,player2.getSpecial());
                        player2SpecialFireTime = 15;
                        playerSpecialsFired++;

                    }
                }
                else if(!gameOver && System.currentTimeMillis() - player2FireTime >= 500 && event.getY() <= Constants.SCREEN_HEIGHT/2){
                    if(ballManager.getEnemyAmmo() > 0 ) {
                        ballManager.fire(player2Point.x, player2Point.y, false);
                        player2ShotsFired++;
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.fire);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                        player2FireTime = System.currentTimeMillis();
                    }
                    else{
                        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.empty);
                        if (sfx == true)
                        {
                            mpSound.start();
                        }
                        mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mp.reset();
                            }
                        });
                    }

                }

                if(gameOver && System.currentTimeMillis() - gameOverTime >= 1000){
                    Intent intent = new Intent(Constants.CURRENT_CONTEXT,matchResultsMulti.class);
                    if(mpMusic.isPlaying()) {
                        mpMusic.stop();
                        mpMusic.release();
                    }
                    intent.putExtra("accuracy",((player2.getTotalHealth()- player2.getHealth())*1f/ (playerShotsFired+playerSpecialsFired))*100);
                    intent.putExtra("health",player.getHealth());
                    intent.putExtra("specialFired",playerSpecialsFired);
                    intent.putExtra("timeLeft",timeLeft);
                    intent.putExtra("player2accuracy",((player.getTotalHealth()-player.getHealth())*1f/ (player2ShotsFired + player2SpecialsFired))*100);
                    intent.putExtra("player2health", player2.getHealth());
                    intent.putExtra("player2specialFired", player2SpecialsFired);
                    intent.putExtra("winner",winner);
                    Constants.CURRENT_CONTEXT.startActivity(intent);
                    ((Activity) Constants.CURRENT_CONTEXT).finish();

                }


                break;


        }
    }


    private void drawTimer(Canvas canvas) {
        Paint paint = new Paint();
        String text = specialFireTime+"";
        if(specialFireTime <= 0)
            text = "S";
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setColor(Color.BLACK);
        paint.setTextSize(45);
        canvas.getClipBounds(r);
        paint.getTextBounds(text, 0, text.length(), r);
        canvas.drawText(text, Constants.SCREEN_WIDTH/2,Constants.SCREEN_HEIGHT*96/100-5, paint);
        text = player2SpecialFireTime+"";
        if(player2SpecialFireTime <= 0)
            text = "S";
        canvas.rotate(180,Constants.SCREEN_WIDTH/2,Constants.SCREEN_HEIGHT*4/100+5);
        canvas.drawText(text, Constants.SCREEN_WIDTH/2,Constants.SCREEN_HEIGHT*4/100+5, paint);
        canvas.rotate(180,Constants.SCREEN_WIDTH/2,Constants.SCREEN_HEIGHT*4/100+5);


    }

    private void drawCenterText(Canvas canvas, Paint paint, String text) {
        paint.setTextAlign(Paint.Align.LEFT);
        canvas.getClipBounds(r);
        int cHeight = r.height();
        int cWidth = r.width();
        paint.getTextBounds(text, 0, text.length(), r);
        float x = cWidth / 2f - r.width() / 2f - r.left;
        float y = cHeight / 2f + r.height() / 2f - r.bottom;
        canvas.drawText(text, x, y, paint);
        if(gameOver && System.currentTimeMillis() - gameOverTime >= 1000){
            text = "Touch anywhere to continue";
            paint.setTextSize(50);
            y += 100;
            canvas.drawText(text,x,y,paint);
        }



    }
}
