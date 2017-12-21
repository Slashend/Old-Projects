package edu.dlsu.mobidev.gem;

import android.graphics.Canvas;
import android.view.SurfaceHolder;

/**
 * Created by asus on 11/7/2017.
 */

public class MainThread extends Thread  {
    public static final int MAX_FPS = 30;
    private double averageFPS;
    private SurfaceHolder surfaceHolder;
    private GamePanel gamepanel;
    private boolean running;
    public static Canvas canvas;

    public MainThread(SurfaceHolder surfaceHolder, GamePanel gamePanel){
        super();
        this.surfaceHolder = surfaceHolder;
        this.gamepanel = gamePanel;

    }

    public void setRunning(boolean running){
        this.running = running;
    }

    @Override
    public void run(){
        long startTime;
        long timeMillis = 1000/MAX_FPS;
        long waitTime;
        int frameCount = 0;
        long totalTime = 0;
        long targetTime = 1000/MAX_FPS;

        while(running){
            startTime = System.nanoTime();
            canvas = null;

            try {
                canvas = this.surfaceHolder.lockCanvas();
                synchronized (surfaceHolder) {
                    this.gamepanel.update();
                    this.gamepanel.draw(canvas);

                }
            } catch(Exception e) {e.printStackTrace();}

            finally {
                if(canvas != null){
                    try{
                        surfaceHolder.unlockCanvasAndPost(canvas);
                    } catch(Exception e) {e.printStackTrace();}
                }
            }

            timeMillis = (System.nanoTime() - startTime)/1000000;
            waitTime = targetTime - timeMillis;

            try {
                if(waitTime > 0){
                    this.sleep(waitTime);
                }
            }catch (Exception e) {e.printStackTrace();}

            totalTime += System.nanoTime() - startTime;
            frameCount++;
            if(frameCount == MAX_FPS){
                averageFPS = 1000/(totalTime/frameCount/1000000);
                frameCount = 0;
                System.out.println(averageFPS);
            }
        }
    }
}
