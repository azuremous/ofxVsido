/*
 ▖▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▚
 ▞ ofxVsidoController.h                                     ▚
 ▞────────────────────────────┐  project : ofxVsido         ▚
 ▞ github.com/azuremous       └───────────────────────────▶ ▚
 ▞ Created by Jung un Kim a.k.a azuremous on 4/23/15.       ▚
 ▞▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▘
 ----------------------------------------------------------*/

#pragma once

#include "ofxVsidoData.h"
#include "ofxVsidoNetwork.h"
#include "ofMain.h"

struct servoData{
    int id;
    int angle;
};

struct IKData{
    int id;
    ofVec3f pos;
};

class ofxVsidoController {
private:
    vector<unsigned char>_data;
    ofxVsidoNetwork vsido_connect;
    
protected:
    void setAngle(int id, int angle);
    void setIK(int id, int x, int y, int z);
    void send();
public:
    explicit ofxVsidoController();
    bool init();
    void setMode(VSIDO_COMMAND_MODE _mode);
    void moveServo(int id, int angle, int spd = 2);
    void moveServo(servoData servo, int spd = 2);
    void moveServos(vector<servoData> servo, int spd = 2);
    void move(int id, int x, int y, int z);
    void move(vector<IKData> ik);
    void walk(int spd = 100, int rotate = 0);
};
