package com.czt.ndk.helloworld;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	/**
	 * 1.定义一个native的方法。
	 * @return
	 */
	public native String helloFromC();
	public native String hello_from_c();
	//5.把要调用的c代码给加载到java虚拟机里面。
	static{
		System.loadLibrary("Hello");
	}
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	/**
	 * 调用底层c代码
	 * @param view
	 */
	public void click(View view) {
		//6. 调用c代码。
		Toast.makeText(this, helloFromC(), Toast.LENGTH_LONG).show();
	}
	/**
	 * 调用底层c代码
	 * @param view
	 */
	public void click2(View view) {
		//6. 调用c代码。
		Toast.makeText(this, hello_from_c(), Toast.LENGTH_LONG).show();
	}
}
