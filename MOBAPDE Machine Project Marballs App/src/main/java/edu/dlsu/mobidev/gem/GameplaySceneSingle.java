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
 */

public class GameplaySceneSingle implements Scene {

    private String winner;

    private int playerShotsFired;
    private int playerSpecialsFired;
    private int enemyShotsFired;
    private int enemySpecialsFired;

    private int timeLeft;

    private Rect r = new Rect();

    private RectPlayer player;
    private Point playerPoint;
    private long playerFireTime;
    private BallManager ballManager;
    private Rect playerHp;

    private boolean gameOver;
    private long gameOverTime;

    private RectPlayer enemy;
    private Point enemyPoint;
    private long enemyFireTime;
    private Rect enemyHp;

    private BitmapFactory bf;
    private Bitmap playerSpecialTimer;


    private MediaPlayer mpSound;
    private MediaPlayer mpMusic;
    private int right;
    private int enemyRight;

    private int playerHpChange;
    private int enemyHpChange;
    private int specialFireTime;
    private int enemySpecialFireTime;
    private long timePassed;

    private long playerReloadCdLeft,playerReloadCdRight;
    private long enemyReloadCdLeft, enemyReloadCdRight;


    private OrientationData orientationData;
    private long frameTime;

    private Bitmap background;
    private Activity activity;
    private ImageButton btLeft;
    private ImageButton btRight;
    private float playerHpRemove;
    private float enemyHpRemove;

    private Ball playerReloadLeft,playerReloadRight;
    private Ball enemyReloadLeft,enemyReloadRight;



    public GameplaySceneSingle(){
        orientationData = new OrientationData();
        orientationData.register();
        activity = (Activity) Constants.CURRENT_CONTEXT;
        btLeft = (ImageButton) activity.findViewById(R.id.bt_left);
        btRight = (ImageButton) activity.findViewById(R.id.bt_right);
        gameOver = false;
        right = 0;
        playerHpChange = 15;
        enemyHpChange = 85;
        enemyRight = 15;
        enemyShotsFired
                = enemySpecialsFired
                = playerShotsFired
                = playerSpecialsFired = 0;


        player = ActivityCustomizeSinglePlayer.selectedBot;
        playerPoint = new Point(Constants.SCREEN_WIDTH/2,85*Constants.SCREEN_HEIGHT/100);
        player.update(playerPoint);
        initEnemy();

        ballManager = new BallManager();
        ballManager.reloadEnemy(player.getAmmo());
        ballManager.reloadPlayer(player.getAmmo());

        mpMusic = MediaPlayer.create(Constants.CURRENT_CONTEXT,R.raw.jetsetrun);

        if (bgm == true)
        {
            mpMusic.start();
            mpMusic.setLooping(true);
        }


        mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT,R.raw.megamandeath);



        bf = new BitmapFactory();
        playerSpecialTimer = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(),R.drawable.timer);
        background = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(),R.drawable.battlebgtwo);






        playerHp = new Rect(Constants.SCREEN_WIDTH*15/100,
                Constants.SCREEN_HEIGHT*93/100 -5,
                Constants.SCREEN_WIDTH*45/100,
                Constants.SCREEN_HEIGHT*96/100-5);

        enemyHp = new Rect(Constants.SCREEN_WIDTH*55/100,
                Constants.SCREEN_HEIGHT*93/100-5,
                Constants.SCREEN_WIDTH*85/100,
                Constants.SCREEN_HEIGHT*96/100-5);


        timeLeft = 60;
        specialFireTime = 15;

        playerReloadCdLeft
                = frameTime
                = timePassed
                = playerReloadCdRight
                = enemyReloadCdRight
                = enemyReloadCdLeft
                = enemyFireTime
                = playerFireTime = System.currentTimeMillis();




        playerHpRemove = 30 / player.getHealth()*1f;
        enemyHpRemove = 30 / enemy.getHealth()*1f;




//        ballManager = new BallManager();



            btRight.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    if (event.getAction() == MotionEvent.ACTION_DOWN){
    //                    right = player.getMoveSpeed();
                        right = 15;
                        return true;
                    }
                    else  if (event.getAction() == MotionEvent.ACTION_UP){
                        right = 0;
                        return true;
                    }

                    return false;
                }
            });
            btLeft.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    if (event.getAction() == MotionEvent.ACTION_DOWN){
    //                    right = -1*player.getMoveSpeed();
                        right = -15;
                        return true;
                    }
                    else  if (event.getAction() == MotionEvent.ACTION_UP){
                        right = 0;
                        return true;
                    }

                    return false;
                }
            });





        playerReloadLeft = new Ball(50,playerPoint.y + 55,true);
        playerReloadRight = new Ball(Constants.SCREEN_WIDTH - 50, playerPoint.y + 55, true);
        enemyReloadLeft = new Ball(50, enemyPoint.y-10,false);
        enemyReloadRight = new Ball(Constants.SCREEN_WIDTH - 50, enemyPoint.y-10,false);



    }

    public void reset(){



    }

    public void initEnemy(){
        if(GamePanel.difficulty == 0)
            enemy = new RectPlayer(false,7,1,18,4, R.drawable.pr);
        else if(GamePanel.difficulty == 1){
            enemySpecialFireTime = 15;
            enemy = new RectPlayer(false,10,2,25,8, R.drawable.pr);
        }

        else {
            enemySpecialFireTime = 10;
            enemy = new RectPlayer(false, 15, 1, 30, 10, R.drawable.pr);
        }
        enemyPoint = new Point(Constants.SCREEN_WIDTH / 2, (int) 5* Constants.SCREEN_HEIGHT / 100);
        enemy.update(enemyPoint);


    }


    public void enemyFire(){

        if(ballManager.getEnemyAmmo() > 0) {
            ballManager.fire(enemyPoint.x, enemyPoint.y, false);
            enemyFireTime = System.currentTimeMillis();
            mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.fire);
            if (sfx == true) {
                mpSound.start();
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
            }
        }
            else{
            mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.empty);
            if (sfx == true) {
                mpSound.start();
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
            }


    }
    }

    public void updateEnemy(){



        if((enemyPoint.x >= Constants.SCREEN_WIDTH - 50 || new Random().nextInt(20) <= (GamePanel.difficulty + 1)|| (ballManager.getEnemyAmmo() <= 0 && enemyPoint.x < Constants.SCREEN_WIDTH)) ){

            enemyRight = -enemy.getMoveSpeed();
        }

        else if ((enemyPoint.x <= 50 || new Random().nextInt(20) <= (GamePanel.difficulty + 1)) || (ballManager.getEnemyAmmo() <= 0 && enemyPoint.x > Constants.SCREEN_WIDTH)){
            enemyRight = enemy.getMoveSpeed();

        }
        if(enemyPoint.x >= Constants.SCREEN_WIDTH)
            enemyPoint.set(Constants.SCREEN_WIDTH - 50 ,enemyPoint.y);
        if(enemyPoint.x <= 0 )
            enemyPoint.set(50 ,enemyPoint.y);

        enemyPoint.set(enemyRight + enemyPoint.x,enemyPoint.y);


        if((enemyReloadLeft.playercollide(enemy)) && System.currentTimeMillis() - enemyReloadCdLeft >= 3000){
            ballManager.reloadEnemy(enemy.getAmmo());
            mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.reload);
            if (sfx == true) {
                mpSound.start();
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
            }
            enemyReloadCdLeft = System.currentTimeMillis();
        }
        if((enemyReloadRight.playercollide(enemy)) && System.currentTimeMillis() - enemyReloadCdRight >= 3000){
            ballManager.reloadEnemy(enemy.getAmmo());
            mpSound = MediaPlayer.create(Constants.CURRENT_CONTEXT, R.raw.reload);
            if (sfx == true) {
                mpSound.start();
                mpSound.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.reset();
                    }
                });
            }
            enemyReloadCdRight = System.currentTimeMillis();
        }


        if((enemyPoint.x >= playerPoint.x - 50 && enemyPoint.x <= playerPoint.x + 50)&& System.currentTimeMillis() - enemyFireTime >= 500) {
            if (enemySpecialFireTime <= 0 && GamePanel.difficulty != 0) {

                enemySpecialsFired++;

                ballManager.player2FireSpecial(enemyPoint.x, enemyPoint.y, false, enemy.getSpecial());
                if(GamePanel.difficulty == 2)
                    enemySpecialFireTime = 10;
                else
                    enemySpecialFireTime = 15;


            }
            else {
                enemyFire();
                enemyShotsFired++;
            }
        }



    }

    public boolean isGameOver(){
        if(ballManager.playerCollide(enemy,true)){


            enemyHpChange -= enemyHpRemove;
            enemyHp.right = Constants.SCREEN_WIDTH*enemyHpChange/100;
            if (enemy.loseHealth()){
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
        if(ballManager.playerCollide(player,false)){
            playerHpChange += playerHpRemove;
            playerHp.left = Constants.SCREEN_WIDTH * playerHpChange /100;
            if(player.loseHealth()){
                playerHp.left = Constants.SCREEN_WIDTH * 45/100;
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

            updateEnemy();


            if(GamePanel.movement) {
                int elapsedTime = (int) (System.currentTimeMillis() - frameTime);
                frameTime = System.currentTimeMillis();
                if (orientationData.getOrientation() != null && orientationData.getStartOrientation() != null) {
                    float roll = orientationData.getOrientation()[2] - orientationData.getStartOrientation()[2];
                    float xSpeed = 2 * roll * Constants.SCREEN_WIDTH / 1000f;
                    playerPoint.x += Math.abs(xSpeed * elapsedTime) > 5 ? xSpeed * elapsedTime : 0;

                }
                if (playerPoint.x < 0)
                    playerPoint.x = 15;
                else if (playerPoint.x > Constants.SCREEN_WIDTH)
                    playerPoint.x = Constants.SCREEN_WIDTH - 15;
            }

            if(playerPoint.x >= Constants.SCREEN_WIDTH - 50)
                playerPoint.set(playerPoint.x - 50, playerPoint.y);
            else if(playerPoint.x <= 50)
                playerPoint.set(playerPoint.x + 50, playerPoint.y);

            if(playerPoint.x < Constants.SCREEN_WIDTH && playerPoint.x > 0)
                playerPoint.set(playerPoint.x + right, playerPoint.y);

            player.update(playerPoint);
            enemy.update(enemyPoint);
            ballManager.update();

            if(System.currentTimeMillis() - timePassed >= 1000 && specialFireTime > 0){
                specialFireTime--;
            }

            if(System.currentTimeMillis() - timePassed >= 1000 && enemySpecialFireTime > 0){
                enemySpecialFireTime--;
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


            gameOverTime = System.currentTimeMillis();
        }

    }

    @Override
    public void draw(Canvas canvas) {

        if(GamePanel.movement) {
            btLeft.setVisibility(View.INVISIBLE);
            btRight.setVisibility(View.INVISIBLE);
        }

        canvas.drawBitmap(background,null,new Rect(0,0,Constants.SCREEN_WIDTH,Constants.SCREEN_HEIGHT),new Paint());
        if(System.currentTimeMillis() - playerReloadCdLeft >= 3000) {
            playerReloadLeft.draw(canvas);
        }
        if(System.currentTimeMillis() - playerReloadCdRight >= 3000) {
            playerReloadRight.draw(canvas);
        }
        if(System.currentTimeMillis() - enemyReloadCdLeft >= 3000) {
            enemyReloadLeft.draw(canvas);
        }
        if(System.currentTimeMillis() - enemyReloadCdRight >= 3000) {
            enemyReloadRight.draw(canvas);
        }

        Paint border, hpPlayer,hpEnemy;
        border =  new Paint();
        hpPlayer = new Paint();
        hpEnemy = new Paint();
        Paint ammo = new Paint();
        Paint timeRemaining = new Paint();

        ammo.setColor(Color.BLACK);
        ammo.setTextSize(50);
        timeRemaining.setColor(Color.BLACK);
        timeRemaining.setTextSize(50);

        player.draw(canvas);
        enemy.draw(canvas);
        ballManager.draw(canvas);

        canvas.drawBitmap(playerSpecialTimer,null,new Rect(Constants.SCREEN_WIDTH*46/100,
                Constants.SCREEN_HEIGHT*91/100-5,
                Constants.SCREEN_WIDTH*54/100,
                Constants.SCREEN_HEIGHT*98/100-5),new Paint());


        hpPlayer.setShader(new LinearGradient(playerHp.left,0,playerHp.right,0,Color.rgb(0,0,200),Color.rgb(0,0,170),Shader.TileMode.CLAMP));
        hpEnemy.setShader(new LinearGradient(enemyHp.left,0,enemyHp.right,0,Color.rgb(170,0,0),Color.rgb(200,0,0),Shader.TileMode.CLAMP));
        border.setStyle(Paint.Style.STROKE);
        border.setStrokeWidth(5);
        border.setColor(Color.BLACK);


        canvas.drawRect(playerHp,hpPlayer);
        canvas.drawRect(enemyHp,hpEnemy);
        canvas.drawRect(playerHp,border);
        canvas.drawRect(enemyHp,border);

        String text = "Ammo: " + ballManager.getPlayerAmmo();
        String text2 = "Time: " + timeLeft;

        canvas.drawText(text, Constants.SCREEN_WIDTH*8/100,Constants.SCREEN_HEIGHT*90/100, ammo);
        canvas.drawText(text2, Constants.SCREEN_WIDTH*72/100,Constants.SCREEN_HEIGHT*90/100, timeRemaining);

        drawTimer(canvas);
        if(gameOver){
            Paint paint = new Paint();
            paint.setTextSize(100);
            paint.setColor(Color.BLACK);

            if((player.getHealth() <= 0 && enemy.getHealth() <= 0) || player.getHealth() == enemy.getHealth()) {
                drawCenterText(canvas, paint, "DRAW");
                winner = "Draw";
            }
            else if(player.getHealth() < enemy.getHealth() ) {
                drawCenterText(canvas, paint, "ENEMY WINS");
                winner = "Red";
            }
            else if(enemy.getHealth() < player.getHealth() ) {
                drawCenterText(canvas, paint, "PLAYER WINS");
                winner = "Blue";
            }
        }
        if(timeLeft <= 5 && timeLeft > 0){
            Paint paint = new Paint();
            paint.setTextSize(100);
            paint.setColor(Color.BLACK);
            String text3 = timeLeft+"";
            drawCenterText(canvas,paint,text3);
        }



    }

    @Override
    public void terminate() {
        SceneManager.ACTIVE_SCENE = 0;
    }

    @Override
    public void receiveTouch(MotionEvent event) {
        switch (event.getActionMasked()) {

            case MotionEvent.ACTION_DOWN:
                System.out.println(event.getX());
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
                else if(!gameOver && System.currentTimeMillis() - playerFireTime >= 500){
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

                if(gameOver && System.currentTimeMillis() - gameOverTime >= 1000){
                    Intent intent = new Intent(Constants.CURRENT_CONTEXT,matchResultsSingle.class);
                    if(mpMusic.isPlaying()) {
                        mpMusic.stop();
                        mpMusic.release();
                    }
                    intent.putExtra("accuracy",((enemy.getTotalHealth()-enemy.getHealth())*1f/ (playerShotsFired+playerSpecialsFired))*100f);

                    intent.putExtra("health",player.getHealth());
                    intent.putExtra("specialFired",playerSpecialsFired);
                    intent.putExtra("timeLeft",timeLeft);
                    intent.putExtra("player2accuracy",((player.getTotalHealth()-player.getHealth())*1f/ (enemyShotsFired+enemySpecialsFired))*100f);
                    intent.putExtra("player2health",enemy.getHealth());
                    intent.putExtra("player2specialFired",enemySpecialsFired);
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
