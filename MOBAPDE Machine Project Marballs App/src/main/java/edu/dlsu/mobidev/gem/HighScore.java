package edu.dlsu.mobidev.gem;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by user on 12/15/2017.
 */

public class HighScore {
    public static final String TABLE_NAME = "highscoremodel";
    public static final String COLUMN_ID = "_id";
    public static final String COLUMN_NAME = "name";
    public static final String COLUMN_HIGHSCORE = "highscore";
    public static final String COLUMN_DATE = "date";

    private long id;
    private String name;
    private int highscore;
    private String date;

    public HighScore() {
    }

    public HighScore(String name, int highscore) {
        this.setName(name);
        this.setHighscore(highscore);

//        SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");
//
//        Date d = new Date();
//
//        try {
//            d = dateFormat.parse(s);
//        } catch (ParseException ex) {
//            ex.printStackTrace();
//        }

        this.setDate("SAMPLE DATE");
    }


    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHighscore() {
        return highscore;
    }

    public void setHighscore(int highscore) {
        this.highscore = highscore;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }
}
