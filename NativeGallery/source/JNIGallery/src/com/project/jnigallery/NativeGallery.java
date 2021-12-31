package com.project.jnigallery;


public class NativeGallery{
    public native int get(int n);
	public native int GetJPEGData(int flag);
	static {
		System.loadLibrary("nativegallery");
	}
}
