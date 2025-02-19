package com.example.eventtracking;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.io.IOException;


public class MainActivity extends AppCompatActivity {

    private static final int REQUEST_SMS_PERMISSION = 123456;
    private TextView tv;
    private TextView err;
    private EditText etUser;
    private EditText etPass;
    private Button bLogin;
    private Button bNewUser;
    private Button bPermissions;

    private UserDatabase db;

    private ExtUserDB EUD;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        tv = findViewById(R.id.header);
        err = findViewById(R.id.tvError);
        etUser = findViewById(R.id.editTextUsername);
        etPass = findViewById(R.id.editTextPassword);
        bLogin = findViewById(R.id.bLogin);
        bNewUser = findViewById(R.id.bNewUser);
        bPermissions = findViewById(R.id.bPermisions);

        db = new UserDatabase(getApplicationContext());

        EUD = new ExtUserDB(getApplicationContext());

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });



    }

    public void onClickLogin(View v){
        String userName = etUser.getText().toString();
        String passWord = etPass.getText().toString();

        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    EUD.isUserValid(userName, passWord);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        });

        thread.start();


        if(userName.isEmpty() || passWord.isEmpty()){
            err.setText("Username or Password can't be empty");
            return;
        }

        if(db.validateCredentials(userName, passWord)){

            Intent i = new Intent(MainActivity.this, EventList.class);

            i.putExtra("user", userName);

            startActivity(i);

        }
        else {
            err.setText("Username or Password does not match!");
        }
    }

    public void onClickNewUser(View V){



        String userName = etUser.getText().toString();
        String passWord = etPass.getText().toString();



        if(userName.isEmpty() || passWord.isEmpty()){
            err.setText("Username or Password can't be empty");
            return;
        }

        long result = db.addCredentials(userName, passWord);

        if(result == -1){
            err.setText("Error adding credentials to Database");
            return;
        }
        if(result == -2){
            err.setText("Username already in Database");
            return;
        }

        onClickLogin(V);

    }

    public void onClickPermissions(View v){

        if(ActivityCompat.checkSelfPermission(this, android.Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED){
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.SEND_SMS}, REQUEST_SMS_PERMISSION);
        }


    }

}

