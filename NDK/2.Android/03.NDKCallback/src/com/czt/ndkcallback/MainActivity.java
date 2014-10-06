package com.czt.ndkcallback;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	private DataProvider mDataProvider = new DataProvider();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	public native void callMethod5();
	public native void callMethod6();
	public void methodInDemoActivity(){
		System.out.println("methodInDemoActivity");
	}
	public static void showToast(Context context, String message){
		Toast.makeText(context, message, Toast.LENGTH_LONG).show();
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
	public void click4(View view){
		mDataProvider.callMethod4();
	}
	public void click5(View view){
		callMethod5();
	}
	public void click6(View view){
		callMethod6();
	}
}
