package edu.dlsu.mobidev.gem;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;
import android.graphics.drawable.*;

/**
 * Created by asus on 11/7/2017.
 */

public class Ball implements GameObject {


    protected Bitmap ballSprite;
    protected Rect rectangle;
    protected BitmapFactory bf;


    public int getPosY() {
        return rectangle.top;
    }

    public Rect getRect(){
        return rectangle;
    }

    public void setRect(Rect rect){
        rectangle = rect;
    }



    public void decrementY(float y){
        rectangle.top -= y;
        rectangle.bottom -= y;
    }
    public void incrementY(float y){
        rectangle.top += y;
        rectangle.bottom += y;
    }

    public Ball(int x, int y,boolean isPlayer){

        bf = new BitmapFactory();
        if(isPlayer) {
            ballSprite = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(), R.drawable.blueball);
            rectangle = new Rect(x - 15, y - 85, x + 35, y - 35);
        }
        else {
            ballSprite = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(), R.drawable.redball);
            rectangle = new Rect(x - 15, y, x + 35, y + 50);

        }

    }

    public void setSpriteSize(int x, int y){
//        ballSprite;
        ballSprite.setWidth(x);
    }


    public boolean playercollide(RectPlayer player) {
        return Rect.intersects(rectangle,player.getRectangle());
    }

    public boolean ballCollide(Rect ball){
        return Rect.intersects(rectangle,ball);
    }


    @Override
    public void draw(Canvas canvas) {
        canvas.drawBitmap(ballSprite,null,rectangle,new Paint());
    }

    @Override
    public void update() {


    }
}