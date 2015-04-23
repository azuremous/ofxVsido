/*
 ▖▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▚
 ▞ ofxVsidoNetwork.h                                        ▚
 ▞────────────────────────────┐  project : ofxVsido         ▚
 ▞ github.com/azuremous       └───────────────────────────▶ ▚
 ▞ Created by Jung un Kim a.k.a azuremous on 4/23/15.       ▚
 ▞▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▘
 ----------------------------------------------------------*/

#pragma once

#include "ofSerial.h"
#include "ofLog.h"

class ofxVsidoNetwork {
private:
    ofSerial v_sido;
    int portNum;
    int baudrate;
    
    bool isConnect;
protected:
    void update();
    
public:
    explicit ofxVsidoNetwork();
    void getSerialList();
    void setBaud(int baud) { baudrate = baud; }
    bool setup(string portName, int baud = 115200);
    bool setup(int portNum, int baud = 115200);
    bool connect();
    
    int sendCommand(unsigned char buffer);
    int sendCommands(unsigned char * buffer, int length);
    
};
