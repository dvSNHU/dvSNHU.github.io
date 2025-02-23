package com.example.eventtracking;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.content.Context;
import android.util.Log;

public class UserDatabase extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "users.db";
    private static final int VERSION = 1;

    private static final String TABLE = "logins";
    private static final String ID = "_id";
    private static final String USER = "username";
    private static final String PASS = "password";

    public UserDatabase (Context con){
        super(con, DATABASE_NAME, null, VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db){
        db.execSQL("create table " + TABLE + " (" +
                ID + " integer primary key autoincrement, " +
                USER + " text, " +
                PASS + " text)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVer, int newVer){

    }

    public boolean validateCredentials(String Username, String Password){
        SQLiteDatabase rDB = getReadableDatabase();

        String command = "select " + PASS + " from " + TABLE + " where " + USER + "=" + "'" + Username + "'";
        Cursor c = rDB.rawQuery(command, null);

        if(c.getCount() == 0) {
            Log.d("credentails", "User Not in Database");
            return false;
        }

        c.moveToFirst();

        if(c.getString(0).equals(Password)) {
          return true;
        }

        c.close();
        Log.d("credentails", "User/Pass mismatch");
        return false;
    }

    public long addCredentials(String Username, String Password){
        SQLiteDatabase rDB = getReadableDatabase();

        String command = "select " + USER + " from " + TABLE;
        Cursor c = rDB.rawQuery(command, null);

        c.moveToFirst();

        if(c.getCount() != 0) {

            do {
                String rUser = c.getString(0);
                if (rUser.equals(Username)) {
                    c.close();
                    return (long) -2;
                }


            }
            while (c.moveToNext());
        }
        c.close();

        SQLiteDatabase db = getWritableDatabase();

        ContentValues values = new ContentValues();

        values.put(USER, Username);
        values.put(PASS, Password);

        long result = db.insert(TABLE, null, values);

        db.close();

        return result;
    }

}