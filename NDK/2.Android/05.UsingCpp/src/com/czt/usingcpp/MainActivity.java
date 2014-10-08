package com.czt.usingcpp;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends Activity {
	static{
		System.loadLibrary("Hello");
	}
	public native String helloFromCpp();
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Toast.makeText(this, helloFromCpp(), Toast.LENGTH_LONG).show();
	}
}
