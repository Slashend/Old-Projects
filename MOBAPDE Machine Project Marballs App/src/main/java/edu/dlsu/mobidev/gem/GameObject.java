package edu.dlsu.mobidev.gem;

import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Point;

/**
 * Created by asus on 11/7/2017.
 */

public interface GameObject {
    public void draw(Canvas canvas);
    public void update();
}
