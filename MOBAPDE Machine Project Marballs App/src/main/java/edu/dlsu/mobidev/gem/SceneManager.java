package edu.dlsu.mobidev.gem;



import android.graphics.Canvas;
import android.view.MotionEvent;

import java.util.ArrayList;

/**
 * Created by asus on 11/7/2017.
 */

public class SceneManager {
    private ArrayList<Scene> scenes = new ArrayList<Scene>();
    public static int ACTIVE_SCENE;

    public SceneManager(int scene){
        ACTIVE_SCENE = 0;
        if(scene == 0)
            scenes.add(new GameplaySceneSingle());
        else
            scenes.add(new GameplaySceneMulti());
    }

    public void receiveTouch(MotionEvent event) {
        scenes.get(ACTIVE_SCENE).receiveTouch(event);
    }

    public void update(){
        scenes.get(ACTIVE_SCENE).update();
    }

    public void draw(Canvas canvas){
        scenes.get(ACTIVE_SCENE).draw(canvas);

    }

}
