package com.czt.ndkcallback;

public class DataProvider {
	static{
		System.loadLibrary("Hello");
	}
	public void helloFromJava(){
		System.out.println("我是Java的空方法");
	}
	public int add(int x, int y){
		return x+y;
	}
	public void printString(String s){
		System.out.println("s=" + s);
	}
	public native void callMethod1();
	public native void callMethod2();
	public native void callMethod3();
}
