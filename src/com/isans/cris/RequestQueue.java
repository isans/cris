package com.isans.cris;

import java.util.Vector;

public class RequestQueue {
	private Vector<byte[]> queue;
	public RequestQueue(){
		queue = new Vector<byte[]>();
	}
	public synchronized byte[] dequeue() throws InterruptedException{
		int retry = 0;
		while( queue.isEmpty() && (retry < 5) ){
			wait(200,0);
			retry++;
		}
		if( queue.isEmpty() )
			throw new InterruptedException("dequeue() : Queue is empty");
		byte[] retValue = queue.firstElement();
		queue.removeElementAt(0);
		return retValue;		
	}
	public synchronized void enqueue(byte[] data){
		queue.addElement(data);
	}
	public synchronized void clearQueue(){
		queue.removeAllElements();
	}
	public synchronized boolean isEmtpy(){
		return queue.isEmpty();
	}
}
