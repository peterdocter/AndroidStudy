package com.czt.ndkpassdata;

import android.app.Activity;
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
    public void click1(View view){
    	int z = mDataProvider.add(3, 5);
    	Toast.makeText(this, z + "", Toast.LENGTH_LONG).show();
    }
    public void click2(View view){
    	String str = mDataProvider.sayHelloInC("zhangsan");
    	Toast.makeText(this, str, Toast.LENGTH_LONG).show();
    }
    public void click3(View view){
    	int[] arr = {1,2,3,4,5};
    	mDataProvider.intMethod(arr);
    	for(int i : arr){
    		System.out.println(i);
    	}
    }
}
