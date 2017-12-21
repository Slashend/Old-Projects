package edu.dlsu.mobidev.gem;

import android.graphics.Canvas;
import android.graphics.Rect;
import android.media.MediaPlayer;

import java.util.ArrayList;

/**
 * Created by asus on 11/7/2017.
 */

public class BallManager {
    //Higher index = lower on screen = higher y value
    private ArrayList<Ball> playerBalls;
    private ArrayList<Ball> player2Balls;

    private int playerAmmo;
    private int player2Ammo;
    private SpecialBall playerSpecial;
    private SpecialBall player2Special;



    public int getPlayerAmmo() {
        return playerAmmo;
    }


    public int getEnemyAmmo() {
        return player2Ammo;
    }




    private long startTime;
    private long initTime;

    private MediaPlayer mpClash;




    public BallManager(){



        playerBalls = new ArrayList<Ball>();
        player2Balls = new ArrayList<Ball>();

        startTime = initTime = System.currentTimeMillis();

    }

    public void reloadPlayer(int ammo){
        playerAmmo = ammo;
    }


    public void reloadEnemy(int ammo){
        player2Ammo = ammo;
    }

    public void playerFireSpecial(int x, int y, boolean isPlayer1,int type){
        playerSpecial = new SpecialBall(x,y,isPlayer1,type);
        if(type == 1){
            Rect r = playerSpecial.getRect();
            playerSpecial.setRect(new Rect(r.left - 75,r.top - 75,r.right + 75,r.bottom + 75));
        }
    }

    public void player2FireSpecial(int x, int y, boolean isPlayer1,int type){
        player2Special = new SpecialBall(x,y,isPlayer1,type);
        if(type == 1){
            Rect r = player2Special.getRect();
            player2Special.setRect(new Rect(r.left - 75,r.top - 75,r.right + 75,r.bottom + 75));
        }
    }



    public boolean playerCollide(RectPlayer player, boolean isPlayer1){
        if(isPlayer1) {
            for (Ball ob : playerBalls) {
                if (ob.playercollide(player)) {
                    playerBalls.remove(ob);
                    return true;
                }
            }
            if(playerSpecial != null)
                if(playerSpecial.playercollide(player)) {
                    playerSpecial = null;
                    return true;
                }


        }
        else {
            for (Ball ob : player2Balls) {
                if (ob.playercollide(player)) {
                    player2Balls.remove(ob);
                    return true;
                }
            }

            if (player2Special != null)
                if (player2Special.playercollide(player)) {
                    player2Special = null;
                    return true;
                }
        }
        return false;
    }
    public void fire(int x, int y, boolean isPlayer) {
        if(isPlayer) {
            playerBalls.add(new Ball(x, y, isPlayer));
            playerAmmo--;
        }
        else {
            player2Balls.add(new Ball(x, y, isPlayer));
            player2Ammo--;
        }

    }

    public ArrayList<Ball> getBalls(){
        return playerBalls;
    }

    public boolean ballCollide(){
        if(!player2Balls.isEmpty() && !playerBalls.isEmpty()){
            for(int i = 0; i < playerBalls.size();i++){
                for(int j = 0; j < player2Balls.size(); j++){
                    if(playerBalls.get(i).ballCollide(player2Balls.get(j).getRect())){
                        playerBalls.remove(i);
                        player2Balls.remove(j);
                        mpClash = MediaPlayer.create(Constants.CURRENT_CONTEXT,R.raw.ballclash);
                        mpClash.start();
                        mpClash.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                            @Override
                            public void onCompletion(MediaPlayer mp) {
                                mpClash.reset();
                            }
                        });
                        break;
                    }
                }
            }
        }
        if(!player2Balls.isEmpty() && playerSpecial != null){
            for(int j = 0; j < player2Balls.size(); j++){
                if(playerSpecial.ballCollide(player2Balls.get(j).getRect())) {
                    playerSpecial.loseHp();
                    player2Balls.remove(j);
                    if(playerSpecial.getHp() <= 0)
                        playerSpecial = null;
                }
            }
        }

        if(!playerBalls.isEmpty() && player2Special != null){
            for(int j = 0; j < playerBalls.size(); j++){
                if(player2Special.ballCollide(playerBalls.get(j).getRect())) {
                    player2Special.loseHp();
                    playerBalls.remove(j);
                    if(player2Special.getHp() <= 0)
                        player2Special = null;
                }
            }
        }

        if(playerSpecial != null && player2Special != null){
            if(player2Special.ballCollide(playerSpecial.getRect())){
                player2Special.loseHp(playerSpecial.getTotalHp());
                playerSpecial.loseHp(player2Special.getTotalHp());
                if(player2Special.getHp() <= 0)
                    player2Special = null;
                if(playerSpecial.getHp() <= 0)
                    playerSpecial = null;
            }
        }
        return true;

    }

    public void draw(Canvas canvas){
        for(Ball ob : playerBalls)
            ob.draw(canvas);
        for(Ball eb: player2Balls)
            eb.draw(canvas);
        if(playerSpecial != null)
            playerSpecial.draw(canvas);
        if(player2Special != null)
            player2Special.draw(canvas);

    }






    public void update(){


        int elapsedTime = (int)(System.currentTimeMillis() - startTime);
        startTime = System.currentTimeMillis();
        float speed = (float)(Math.sqrt(1 + (startTime - initTime)/1000.0))*  Constants.SCREEN_HEIGHT/(10000.0f);

        if(playerSpecial != null) {
            if(playerSpecial.getType() == 1)
                playerSpecial.decrementY(20);
            else
                playerSpecial.decrementY(speed*3 * elapsedTime);
            if(playerSpecial.getPosY() <= 0)
                playerSpecial = null;
        }

        if(player2Special != null) {
            if(player2Special.getType() == 1)
                player2Special.incrementY(20);
            else
                player2Special.incrementY(speed*3 * elapsedTime);
            if(player2Special.getPosY() >= Constants.SCREEN_HEIGHT)
                player2Special = null;
        }

        for (Ball ob : playerBalls){

            ob.decrementY(speed * elapsedTime);

        }
        if(!playerBalls.isEmpty()){
            if(playerBalls.get(0).getPosY() <= 0 ){
                playerBalls.remove(0);
            }
        }
        else if(!playerBalls.isEmpty()){
            if(playerBalls.get(0).getPosY() >= Constants.SCREEN_HEIGHT ){
                playerBalls.remove(0);
            }
        }
        for (Ball ob : player2Balls){

            ob.incrementY(speed * elapsedTime);
        }
        if(!player2Balls.isEmpty()){
            if(player2Balls.get(0).getPosY() <= 0 ){
                player2Balls.remove(0);
            }
        }
        else if(!player2Balls.isEmpty()){
            if(player2Balls.get(0).getPosY() >= Constants.SCREEN_HEIGHT ){
                player2Balls.remove(0);
            }
        }
        ballCollide();

        


    }

}
