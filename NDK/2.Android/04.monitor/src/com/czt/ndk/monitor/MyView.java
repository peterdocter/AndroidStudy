package com.czt.ndk.monitor;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;
import android.view.WindowManager;

public class MyView extends View {
	private int pressure;
	private int bottom;
	private Paint paint;
	public MyView(Context context,int pressure) {
		super(context);
		/**
		 * int height = context.getResources().getDisplayMetrics().heightPixels;
		 * 高度还可以这样获取。
		 * 状态栏高度也可以换一种方式来获取。不必要非得盲目的直接减60
		 */
		WindowManager wm = (WindowManager) context.getSystemService(Context.WINDOW_SERVICE);
		bottom = wm.getDefaultDisplay().getHeight()-60;
		this.pressure = pressure;
		paint = new Paint();
		paint.setStrokeWidth(5);
		if(pressure<100){
			paint.setColor(Color.GREEN);
		}else if(pressure<200){
			paint.setColor(Color.YELLOW);
		}else {
			paint.setColor(Color.RED);
		}
		
		
	}

	
	@Override
	protected void onDraw(Canvas canvas) {

		canvas.drawRect(30, bottom-pressure, 60, bottom, paint);
		super.onDraw(canvas);
	}
}
