package com.example.eventtracking;

import android.content.Context;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.EventLogTags;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;

public class EventList extends AppCompatActivity {

    String userName;
    EventsDatabase db;

    HashMap<Integer, View> eventViewArray;
    HashMap<Integer, String[]> events;

    LinearLayout eventLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_event_list);

        Bundle ex = getIntent().getExtras();

        if(ex != null) {
            userName = ex.getString("user");
        }

        db = new EventsDatabase(getApplicationContext(), userName);

        eventViewArray = new HashMap<Integer, View>();

        eventLayout = findViewById(R.id.eventList);

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });


    }

    @Override
    public void onResume(){
        super.onResume();



        clearEvents();
        fillEvents();
    }

    public void addEvent(View v){
        Intent i = new Intent(EventList.this, AddEvent.class);

        i.putExtra("user", userName);



        startActivity(i);
    }

    public void clearEvents(){
        //clear linear view before refilling
        eventLayout.removeAllViews();
    }

    public void fillEvents(){

        String[] stuff = new String[4];

        LayoutInflater inf = (LayoutInflater) getApplicationContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        ViewGroup parent = (ViewGroup) eventLayout;

        events = db.readEvents();


        for(int i = 1; i <= events.size(); i++){
            stuff = events.get(i);

            final int index = i;

            View v = inf.inflate(R.layout.eventlayout, null);
            TextView name = (TextView)v.findViewById(R.id.tvEventName);
            name.setText(stuff[0]);
            TextView date = (TextView)v.findViewById(R.id.tvDate);
            date.setText("Date: " + stuff[1]);
            TextView time = (TextView)v.findViewById(R.id.tvTime);
            time.setText("Time: " + stuff[2]);
            TextView desc = (TextView)v.findViewById(R.id.tvDescription);
            desc.setText(stuff[3]);
            ImageButton bEdit = (ImageButton)v.findViewById(R.id.bEdit);
            bEdit.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    handleEditButton(index);
                }
            });

            ImageButton bDelete = (ImageButton)v.findViewById(R.id.bDelete);
            bDelete.setOnClickListener(new View.OnClickListener(){
                @Override
                public void onClick(View v) {
                    handleDeleteButton(index);
                }
            });

            parent.addView(v);

            eventViewArray.put(eventViewArray.size() + 1, v);

        }

    }

    public void handleEditButton(int index){
        Log.d("editButtonHandle", "Index = " + index);

        Intent I = new Intent(EventList.this, editEvent.class);

        HashMap<Integer, String[]> events = db.readEvents();

        String[] values = events.get(index);

        I.putExtra("user", userName);
        I.putExtra("values", values);

        startActivity(I);

    }

    public void handleDeleteButton(int index){

        String[] values = events.get(index);

        db.deleteEvent(values[0], values[1], values[2]);

        clearEvents();
        fillEvents();
    }
}