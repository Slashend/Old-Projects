package edu.dlsu.mobidev.gem;

import android.content.Context;
import android.graphics.Canvas;

import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;
import android.media.MediaPlayer;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by asus on 11/7/2017.
 */

public class GamePanel extends SurfaceView implements SurfaceHolder.Callback {
    protected static int difficulty;
    protected static boolean movement;
    private MainThread thread;
    private SceneManager manager;


    public GamePanel(Context context, int scene){
        super(context);
        Constants.CURRENT_CONTEXT = context;

        getHolder().addCallback(this);
        thread = new MainThread(getHolder(),this);
        manager = new SceneManager(scene);


        setFocusable(true);




    }


    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height){

    }

    @Override
    public void surfaceCreated(SurfaceHolder holder){
        thread = new MainThread(getHolder(),this);

        thread.setRunning(true);
        thread.start();

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder){
        boolean retry = true;
        while(retry){
            try {
                thread.setRunning(false);
                thread.join();
            }catch (Exception e ) {e.printStackTrace();}
            retry = false;
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event){
        manager.receiveTouch(event);
        return true;
        //return super.onTouchEvent(event);
    }

    public void update(){
        manager.update();
    }

    @Override
    public void draw(Canvas canvas){
        super.draw(canvas);
        manager.draw(canvas);

    }


}
