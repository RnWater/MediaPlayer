package com.henry.player;
public class GCPlayer {
    static {
        System.loadLibrary("player");
    }
    public native void normalThread();
    public native void queueThread();
}