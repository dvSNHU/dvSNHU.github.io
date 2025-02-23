package com.example.eventtracking;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class editEvent extends AppCompatActivity {

    EditText eventName;
    EditText eventDate;
    EditText eventTime;
    EditText eventDescription;
    Button bReturn;
    Button bSave;
    String userName;
    String[] values = new String[4];
    TextView err;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_edit_event);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });


        eventName = findViewById(R.id.etEventNameEdit);
        eventDate = findViewById(R.id.etDateEdit);
        eventTime = findViewById(R.id.etTimeEdit);
        eventDescription = findViewById(R.id.etDescriptionEdit);
        err = findViewById(R.id.tvErrorEditEvent);

        bReturn = findViewById(R.id.bReturnEdit);
        bSave = findViewById(R.id.bSaveEdit);

        bReturn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                returnToList();
            }
        });

        bSave.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                editEvent();
            }
        });

        Bundle ex = getIntent().getExtras();

        if(ex != null) {
            userName = ex.getString("user");
            values = ex.getStringArray("values");

            eventName.setText(values[0]);
            eventDate.setText(values[1]);
            eventTime.setText(values[2]);
            eventDescription.setText(values[3]);
        }



    }

    public void returnToList(){
        finish();
    }

    public void editEvent(){
        EventsDatabase db = new EventsDatabase(getApplicationContext(), userName);

        if (eventName.getText().toString().trim().isEmpty() || eventDate.getText().toString().trim().isEmpty() || eventTime.getText().toString().trim().isEmpty()){
            err.setText("Event Name, Date, and Time must be filled in!");
            return;
        }

        db.updateEvent(values[0],values[1],values[2],eventName.getText().toString(),eventDate.getText().toString(),eventTime.getText().toString(),eventDescription.getText().toString());
        finish();
    }


}