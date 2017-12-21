package edu.dlsu.mobidev.gem;

import android.graphics.Canvas;
import android.view.MotionEvent;

/**
 * Created by asus on 11/7/2017.
 */

public interface Scene {

    public void update();
    public void draw(Canvas canvas);
    public void terminate();
    public void receiveTouch(MotionEvent event);

}
