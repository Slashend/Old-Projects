package edu.dlsu.mobidev.gem;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;

/**
 * Created by asus on 11/7/2017.
 */

public class RectPlayer implements GameObject {

    private Rect rectangle;


    private int health;
    private int totalHealth;
    private int special;

    public int getSpecial() {
        return special;
    }

    public int getMoveSpeed() {
        return moveSpeed;
    }

    public int getAmmo() {
        return ammo;
    }

    private int moveSpeed;
    private int ammo;

    int botSprite;

    private Bitmap idleImg;

    public Rect getRectangle() {
        return rectangle;
    }

    public int getBotSprite(){
        return botSprite;
    }

    public RectPlayer(boolean isPlayer,int health, int special, int moveSpeed,int ammo,int img) {


        botSprite = img;
        BitmapFactory bf = new BitmapFactory();
        if(isPlayer)
            idleImg = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(),img);
        else
            idleImg = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(), R.drawable.pr);

        rectangle = new Rect(0,0,idleImg.getWidth(),idleImg.getHeight());

        this.health = this.totalHealth = health;
        this.ammo = ammo;
        this.special = special;
        this.moveSpeed = moveSpeed;

    }

    public int getTotalHealth(){
        return  totalHealth;
    }

    public int getHealth(){
        return  health;
    }

    public boolean loseHealth(){
        health--;
        if(health <= 0)
            return true;
        return false;
    }




    public String toString(int i){
        return i + "";
    }

    @Override
    public void draw(Canvas canvas) {
//        Paint paint = new Paint();
//        paint.setColor(Color.RED);
        //canvas.drawRect(rectangle, paint);
        //animManager.draw(canvas, rectangle);
//        canvas.drawRect(rectangle,paint);
        canvas.drawBitmap(idleImg,null,rectangle,new Paint());


    }

    @Override
    public void update() {

    }

    public void update(Point point) {
        float oldLeft = rectangle.left;

        rectangle.set(point.x - rectangle.width()/2, point.y - rectangle.height()/2, point.x + rectangle.width()/2, point.y + rectangle.height()/2);

        int state = 0;
        if(rectangle.left - oldLeft > 5)
            state = 1;
        else if(rectangle.left - oldLeft < -5)
            state = 2;


    }
}