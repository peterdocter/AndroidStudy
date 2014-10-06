package com.czt.ndkcallback;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {
	private DataProvider mDataProvider = new DataProvider();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	public void click1(View view){
		mDataProvider.callMethod1();
	}
	public void click2(View view){
		mDataProvider.callMethod2();
	}
	public void click3(View view){
		mDataProvider.callMethod3();
	}
}
