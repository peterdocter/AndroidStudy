package com.czt.ndkpassdata;

/**
 * 提供native的方法的声明.
 *
 */
public class DataProvider {
	static{
		System.loadLibrary("Hello");
	}
	/**
	 * 传递两个int类型的数据给c语言,c代码处理完毕这两个数据后返回给上层的java
	 * native代码的计算器
	 * @param x
	 * @param y
	 * @return
	 */
	public native int add(int x ,int y); // String[] zhangsan:lisi:wangwu
                                         // kiss : keep it simple and stupid
	
	
	/**
	 * 传递一个java中的string给c语言,c语言处理完毕这个string之后返回一个新的字符串.
	 * @param s  在c代码里面对字符串加密
	 * 传递string给c语言,c语言在string后面 拼装一个nihao 返回给java
	 * @return
	 */
	public native String sayHelloInC(String s); //传递java char数组
	
	/**
	 * 传递一个int类型的数组给 c语言 ,c语言处理这个int类型的数组,
	 * 把处理后的数组再返回给java
	 * 场景：音视频
	 * @param iNum
	 * @return
	 */
	public native int[] intMethod(int[] iNum); 

}
