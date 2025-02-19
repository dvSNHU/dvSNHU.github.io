package com.example.eventtracking;

import android.content.Context;
import android.util.Log;

import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.net.MalformedURLException;
import java.net.URLEncoder;
import java.net.URLConnection;
import java.net.URL;
import java.util.Scanner;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONObject;

public class ExtUserDB {

    Context cont;










    ExtUserDB(Context con) {
        cont = con;
    }


    boolean isUserValid(String user, String pass) throws IOException {

        String url = "http://192.168.1.4:80/EventTrackerAPI/userapi.php";
        /*
        String charset = "UTF-8";
        String username = user;

        String q = String.format("username=%s",
                URLEncoder.encode(username, charset));

        URLConnection connection = new URL(url + '?' + q).openConnection();
        connection.setRequestProperty("Accept-Charset", charset);
        InputStream response = connection.getInputStream();
        Scanner scanner = new Scanner(response);
        Log.d("HTTPRESPONSE", scanner.useDelimiter("\\A").next());
        */

        RequestQueue reqQueue = Volley.newRequestQueue(cont);

        JsonArrayRequest req = new JsonArrayRequest(Request.Method.GET, url, null, new Response.Listener<JSONArray>() {
            @Override
            public void onResponse(JSONArray arr) {
                System.out.println(arr);

            }
        }, new Response.ErrorListener(){
            @Override
            public void onErrorResponse(VolleyError err) {
                System.out.println(err.toString());
            }
        });
        reqQueue.add(req);
        System.out.println("obj");

        return false;
    }













}
