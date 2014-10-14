package com.czt.lame;

import java.io.File;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.DialogInterface.OnCancelListener;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {
	static {
		System.loadLibrary("mp3lame");
	}
	
	public native String getVersion();
	public native void convert(String wavPath, String mp3Path);
	public native void stopConvert();
	
	private EditText mWavPathView;
	private EditText mMp3PathView;
	private ProgressDialog mProgressDialog;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		mWavPathView = (EditText) findViewById(R.id.wav_path);
		mMp3PathView = (EditText) findViewById(R.id.mp3_path);
		mProgressDialog = new ProgressDialog(this);
		mProgressDialog.setMessage("转化中....");
		mProgressDialog.setOnCancelListener(new OnCancelListener() {
			
			@Override
			public void onCancel(DialogInterface dialog) {
				//停止掉 子线程 不让他继续转化了
				stopConvert();
			}
		});
	}

	public void getVersion(View view) {
		Toast.makeText(this, getVersion(), Toast.LENGTH_LONG).show();
	}
    /**
     * 设置当前转化的进度的.
     * @param process
     */
	public void setCurrentProcess(int process){
		mProgressDialog.setProgress(process);
	}
	public void convert(View view) {
		final String mp3 = mMp3PathView.getText().toString().trim();
		final String wav = mWavPathView.getText().toString().trim();

		if (TextUtils.isEmpty(mp3) || TextUtils.isEmpty(wav)) {
			Toast.makeText(this, "文件名不能为空", Toast.LENGTH_LONG).show();
			return;
		}
		File file = new File(wav);
		if (!file.exists()) {
			Toast.makeText(this, "文件名不存在", Toast.LENGTH_LONG).show();
			return;
		}
    	int max = (int) file.length();
    	//设置为显示进度的对话框
    	mProgressDialog.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
    	mProgressDialog.setMax(max);
    	mProgressDialog.show();
    	
		new Thread() {
			public void run() {
				convert(wav, mp3);
				mProgressDialog.dismiss();
			};
		}.start();
	}
}
