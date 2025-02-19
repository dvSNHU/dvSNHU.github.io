package com.example.eventtracking;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class EventsDatabase extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "Events.db";
    private static final int VERSION = 1;

    private static final String TABLE = "Events";
    private static final String ID = "_id";
    private static final String EVENTNAME = "EventName";
    private static final String EVENTDATE = "EventDate";
    private static final String EVENTTIME = "EventTime";
    private static final String EVENTDESCRIPTION = "EventDescription";

    private String TrueTable;

    public EventsDatabase (Context con, String Username){
        super(con, DATABASE_NAME, null, VERSION);
        TrueTable = TABLE + Username;

        //create table if it doesnt exist
        SQLiteDatabase rDB = getReadableDatabase();
        SQLiteDatabase wDB = getWritableDatabase();

        String eCommand = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + TrueTable + "'";
        Cursor cur = rDB.rawQuery(eCommand, null);

        if(cur.getCount() == 0) {
            wDB.execSQL("create table " + TrueTable + " (" +
                    ID + " integer primary key autoincrement, " +
                    EVENTNAME + " text, " +
                    EVENTDATE + " text, " +
                    EVENTTIME + " text, " +
                    EVENTDESCRIPTION + " text)");
        }

        cur.close();
    }

    @Override
    public void onCreate(SQLiteDatabase db){
        db.execSQL("create table " + TrueTable + " (" +
                ID + " integer primary key autoincrement, " +
                EVENTNAME + " text, " +
                EVENTDATE + " text, " +
                EVENTTIME + " text, " +
                EVENTDESCRIPTION + " text)"

        );

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVer, int newVer){

    }

    public HashMap<Integer, String[]> readEvents(){
        SQLiteDatabase rDB = getReadableDatabase();
        HashMap<Integer, String[]> events = new HashMap<Integer, String[]>();



        String command = "select * from " + TrueTable;
        Cursor c = rDB.rawQuery(command, null);



        //return empty list if events database is empty
        if(c.getCount() == 0) { return events; }
        String TAG = "Return";
        String TAG2 = "map Value";

        c.moveToFirst();
        int i = 1;

        do
        {
            String[] stringArray = new String[4];

            stringArray[0] = c.getString(1);
            stringArray[1] = c.getString(2);
            stringArray[2] = c.getString(3);
            stringArray[3] = c.getString(4);

            events.put(i, stringArray);

            i++;
        }
        while (c.moveToNext());

        c.close();

        return events;
    }

    public void addEvent(String eventName, String eventDate, String eventTime, String eventDesc){

        SQLiteDatabase db = getWritableDatabase();

        ContentValues values = new ContentValues();

        values.put(EVENTNAME, eventName);
        values.put(EVENTDATE, eventDate);
        values.put(EVENTTIME, eventTime);
        values.put(EVENTDESCRIPTION, eventDesc);

        long result = db.insert(TrueTable, null, values);

        //db.close();


    }

    //
    public void deleteEvent(String eventName, String eventDate, String eventTime){
        String command = "DELETE FROM " + TrueTable + " WHERE " +
                EVENTNAME + "='" + eventName + "' AND " +
                EVENTDATE + "='" + eventDate + "' AND " +
                EVENTTIME + "='" + eventTime +"'";
        Log.d("DB DELETE", command);

        SQLiteDatabase db = getWritableDatabase();

        db.execSQL(command);
    }

    public void updateEvent(String oldName, String oldDate, String oldTime, String newName, String newDate, String newTime, String newDesc ){
        String command = "UPDATE " + TrueTable +
                " SET " +
                EVENTNAME + "='" + newName + "'," +
                EVENTDATE + "='" + newDate + "'," +
                EVENTTIME + "='" + newTime + "'," +
                EVENTDESCRIPTION + "='" + newDesc +
                "' WHERE " +
                EVENTNAME + "='" + oldName + "' AND " +
                EVENTDATE + "='" + oldDate + "' AND " +
                EVENTTIME + "='" + oldTime +"'";

        SQLiteDatabase db = getWritableDatabase();

        db.execSQL(command);

    }

}
