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

public class AddEvent extends AppCompatActivity {

    EditText eventName;
    EditText eventDate;
    EditText eventTime;
    EditText eventDescription;
    Button bReturn;
    Button bSave;
    String userName;
    TextView err;






    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_add_event);

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
                createEvent();
            }
        });

        Bundle ex = getIntent().getExtras();

        if(ex != null) {
            userName = ex.getString("user");
        }

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }

    public void returnToList(){
        finish();
    }

    public void createEvent(){
        EventsDatabase db = new EventsDatabase(getApplicationContext(), userName);

        if (eventName.getText().toString().trim().isEmpty() || eventDate.getText().toString().trim().isEmpty() || eventTime.getText().toString().trim().isEmpty()){
            err.setText("Event Name, Date, and Time must be filled in!");
            return;
        }




        db.addEvent(eventName.getText().toString(), eventDate.getText().toString(), eventTime.getText().toString(), eventDescription.getText().toString());
        finish();
    }

}