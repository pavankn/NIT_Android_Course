package com.project.jnigallery;

import java.io.IOException;


import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import android.os.ParcelFileDescriptor;
import android.util.Log;

//import java.beans.MethodDescriptor;
import java.io.FileDescriptor;
import android.widget.ImageView ;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;


public class MainActivity extends Activity implements View.OnClickListener {

    private static final int INVALID_NUMBER = -1;
    private static final String TAG = "NativeGallery";
    private static final String Rohit = "/system/rohit.jpg";
    private static final String AnnaIvanovic = "/system/Anna.jpg";
    private static final String LionelMessi = "/system/Messi.jpg";

    private Button button;
    private EditText cInput;
    private TextView cResult;
    private NativeGallery cFibLib;
    private NativeGallery mNativeGallery;
    private ImageView imgView;
    int flag = 0;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button) findViewById(R.id.button);
        imgView = (ImageView) findViewById(R.id.imageView);
        

        button.setOnClickListener(this);
        
        mNativeGallery = new NativeGallery();
    }

    @Override
    public void onClick(View pView) {
        Log.d(TAG, "Pavankn Clicked Button ");

        if(flag == 0){           
            flag = 1;
        }else if(flag == 1){
            flag = 2;
        }else if(flag == 2){
            flag = 3;
        }else{
            Log.e(TAG, "Unknown URL, Exit");
            flag = -1;
        }
        displayImage(imgView, flag);
    }

    private void displayImage(ImageView imgView, int flag ){
        int nFD = mNativeGallery.GetJPEGData(flag);
        if(nFD < 0){
            Log.d(TAG, "Pavankn Failed to get JPEG");
            return;
        }
        ParcelFileDescriptor pfd;
        try{
            pfd = ParcelFileDescriptor.fromFd(nFD);
            final FileDescriptor fileDescriptor = pfd.getFileDescriptor();
            Log.d(TAG, "Pavankn FileDescriptor is : " + fileDescriptor);

            final Bitmap bitmap = BitmapFactory.decodeFileDescriptor(fileDescriptor);
            imgView.setImageBitmap(bitmap);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
