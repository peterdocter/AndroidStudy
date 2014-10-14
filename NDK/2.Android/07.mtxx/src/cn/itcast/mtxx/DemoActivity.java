package cn.itcast.mtxx;

import com.mt.mtxx.image.JNI;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class DemoActivity extends Activity {
	static {
		System.loadLibrary("mtimage-jni");
	}
	private JNI jni;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		jni = new JNI();
	
	}
	
	public void convert(View view){
		Bitmap bitmap = BitmapFactory.decodeResource(getResources(),
				R.drawable.a);
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		int[] paramArrayOfInt = new int[width * height];

		bitmap.getPixels(paramArrayOfInt, 0, width, 0, 0, width, height);

		jni.StyleLomoB(paramArrayOfInt, width, height);
		Bitmap newbitmap = Bitmap.createBitmap(paramArrayOfInt, width, height,
				bitmap.getConfig());
		ImageView iv = (ImageView) findViewById(R.id.iv);
		iv.setImageBitmap(newbitmap);
	}
}