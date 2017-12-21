package edu.dlsu.mobidev.gem;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

/**
 * Created by user on 11/7/2017.
 */

public class DatabaseHelper extends SQLiteOpenHelper {

    public static final String SCHEMA = "highscore";
    public static final int VERSION = 1;

    public DatabaseHelper(Context context) {
        super(context, SCHEMA, null, VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        // ROLE: create the tables of this schema
        // It will only be called once at the start
        // when there is no DB, it is called by the system

        /*
        CREATE TABLE phone {
            _id INTEGER AUTOINCREMENT PRIMARY KEY,
            name TEXT,
            highscore INTEGER,
            date TEXT
         */

        String sql = "CREATE TABLE " + HighScore.TABLE_NAME + " ("
                + HighScore.COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, "
                + HighScore.COLUMN_NAME + " TEXT, "
                + HighScore.COLUMN_DATE + " INTEGER, "
                + HighScore.COLUMN_HIGHSCORE + " TEXT"
                + ");";

        db.execSQL(sql);
        // do not close connection
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int i, int i1) {
        // ROLE: will only be called if there is change in version numbers

        // you want to migrate to the new db
        // drop the current tables
        String sql = "DROP TABLE IF EXISTS " + HighScore.TABLE_NAME + ";";
        db.execSQL(sql);

        // call onCreate to get the latest db
        onCreate(db);
    }

    // CRUD
    // add high score
    public boolean addHighScore(HighScore highScore) {
        SQLiteDatabase db = getWritableDatabase();

        ContentValues contentValues = new ContentValues();
        contentValues.put(HighScore.COLUMN_NAME, highScore.getName());
        contentValues.put(HighScore.COLUMN_HIGHSCORE, highScore.getHighscore());
        contentValues.put(HighScore.COLUMN_DATE, highScore.getDate());

        long id = db.insert(HighScore.TABLE_NAME, null, contentValues);
        db.close();

        return id != -1;
    }

    // edit phone
    public boolean editHighScore(long currentId, HighScore highScore) {
        SQLiteDatabase db = getWritableDatabase();

        ContentValues contentValues = new ContentValues();
        contentValues.put(HighScore.COLUMN_NAME, highScore.getName());
        contentValues.put(HighScore.COLUMN_HIGHSCORE, highScore.getHighscore());
        contentValues.put(HighScore.COLUMN_DATE, highScore.getDate());

        int rows = db.update(HighScore.TABLE_NAME, contentValues, HighScore.COLUMN_ID + "=?", new String[]{currentId + ""});

        return rows > 0;
    }

    // remove phone
    public boolean removeHighScore(long currentId) {
        SQLiteDatabase db = getWritableDatabase();

        int rows = db.delete(HighScore.TABLE_NAME, HighScore.COLUMN_ID + " =?", new String[]{currentId + ""});
        db.close();

        return rows > 0;
    }

    // retrieve all phones
    public ArrayList<HighScore> getAllHighScores() {
        SQLiteDatabase db = getReadableDatabase();
        Cursor c = db.query(HighScore.TABLE_NAME, null, null, null, null, null, null);

        ArrayList<HighScore> highScores = null;

        if (c.moveToFirst()) {
            do {
                HighScore highScore = null;
                String name = c.getString(c.getColumnIndex(HighScore.COLUMN_NAME));
                int highScoreNum = c.getInt(c.getColumnIndex(HighScore.COLUMN_HIGHSCORE));
                String date = c.getString(c.getColumnIndex(HighScore.COLUMN_DATE));
                int id = c.getInt(c.getColumnIndex(HighScore.COLUMN_ID));

                highScore.setName(name);
                highScore.setHighscore(highScoreNum);
                highScore.setDate(date);
                highScore.setId(id);
            } while (c.moveToNext());
        }

        c.close();
        db.close();

        return highScores;
    }

    public Cursor getAllHighScoresCursor() {
        SQLiteDatabase db = getReadableDatabase();
        return db.query(HighScore.TABLE_NAME, null, null, null, null, null, HighScore.COLUMN_HIGHSCORE + " DESC");
    }
}
