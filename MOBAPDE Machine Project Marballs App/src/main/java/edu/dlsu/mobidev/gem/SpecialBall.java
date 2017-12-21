package edu.dlsu.mobidev.gem;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

/**
 * Created by asus on 12/13/2017.
 */

public class SpecialBall extends Ball {
    private int type;
    private int hp;
    private int totalHp;


    public SpecialBall(int x, int y, boolean isPlayer,int type){
        super(x,y,isPlayer);
        this.type = type;
        ballSprite = bf.decodeResource(Constants.CURRENT_CONTEXT.getResources(),R.drawable.specialball);
        if(type == 1)
            hp = totalHp = 3;
        else
            hp = totalHp = 2;

    }
    public int getTotalHp(){return totalHp;}

    public int getHp(){
        return hp;
    }

    public void loseHp(int dmg){
        hp -= dmg;
    }

    public void loseHp(){
        hp--;
    }

    public int getType(){
        return type;
    }


}
