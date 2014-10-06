package com.czt.ndk.monitor;

import java.util.Timer;
import java.util.TimerTask;

import com.czt.ndk.monitor.R;

import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;

public class DemoActivity extends Activity {
	static {
		System.loadLibrary("Hello");
	}

	public native int getCurrentPressure();

	private Timer timer; // 创建一个定时器
	private TimerTask task; // 创建定时器执行的任务
	
	private Handler handler = new Handler(){
		public void handleMessage(android.os.Message msg) {
			int pressure = (Integer) msg.obj;
			
			if(pressure>275){
				//发短信, 发邮件, 播放报警音乐.
				MediaPlayer player = MediaPlayer.create(getApplicationContext(), R.raw.ylzs);
				player.setLooping(false);
				player.setVolume(1.0f, 1.0f);
				player.start();
				if (task != null && timer != null) {
					task.cancel();
					timer.cancel();
					task = null;
					timer = null;
				}
				TextView tv  = new TextView(getApplicationContext());
				tv.setTextSize(30);
				tv.setText("锅炉快要爆炸了,赶紧跑把");
				setContentView(tv);
				return;
			}
			
			
			setContentView(new MyView(getApplicationContext(), pressure));
		};
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		timer = new Timer();
		task = new TimerTask() {

			@Override
			public void run() {
				int pressure = getCurrentPressure();
				//System.out.println("pressure:" + pressure);
				Message msg = Message.obtain();
				msg.obj = pressure;
				handler.sendMessage(msg);
			}
		};
		// 定期的获取锅炉的压力.
		timer.schedule(task, 1000, 1000);
	}
	/**
	 * 在onDestory里面不好，在小米手机上界面关闭一会儿之后才能响应。
	 * 最好改成在finish或者监控back响应。
	 */
	@Override
	protected void onDestroy() {
		if (task != null && timer != null) {
			task.cancel();
			timer.cancel();
			task = null;
			timer = null;
		}
		super.onDestroy();
	}
}