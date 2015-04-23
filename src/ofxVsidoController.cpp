/*
 ▖▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▚
 ▞ ofxVsidoController.cpp                                   ▚
 ▞────────────────────────────┐  project : ofxVsido         ▚
 ▞ github.com/azuremous       └───────────────────────────▶ ▚
 ▞ Created by Jung un Kim a.k.a azuremous on 4/23/15.       ▚
 ▞▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▘
 ----------------------------------------------------------*/

#include "ofxVsidoController.h"

//--------------------------------------------------------------
ofxVsidoController::ofxVsidoController()

{}

//--------------------------------------------------------------
bool ofxVsidoController::init(){
    return vsido_connect.connect();
}

//--------------------------------------------------------------
void ofxVsidoController::setMode(VSIDO_COMMAND_MODE _mode){
    _data.clear();
    _data.resize(3);
    _data[0] = 0xFF;
    _data[1] = command_char[(int)_mode];
}

//--------------------------------------------------------------
void ofxVsidoController::moveServo(int id, int angle, int spd){
    setMode(SET_ANGLE_MODE);
    unsigned char speed = spd;
    _data.push_back(speed);
    setAngle(id, angle);
    send();
}

//--------------------------------------------------------------
void ofxVsidoController::moveServo(servoData servo, int spd){
    setMode(SET_ANGLE_MODE);
    unsigned char speed = spd;
    _data.push_back(speed);
    setAngle(servo.id, servo.angle);
    send();
}

//--------------------------------------------------------------
void ofxVsidoController::moveServos(vector<servoData> servo, int spd){
    setMode(SET_ANGLE_MODE);
    unsigned char speed = spd;
    _data.push_back(speed);
    for (int i = 0; i < servo.size(); i++) {
        setAngle(servo[i].id, servo[i].angle);
    }
    send();
}

//--------------------------------------------------------------
void ofxVsidoController::walk(int spd, int rotate){
    setMode(WALK_MODE);
    
    _data.push_back(0x00);
    _data.push_back(0x02);
    _data.push_back(spd + 100);//spd
    _data.push_back(rotate + 100);//rotate
    
    send();
}

//--------------------------------------------------------------
void ofxVsidoController::move(int id, int x, int y, int z){
    setMode(SET_IK_MODE);
    _data.push_back(0x01);
    setIK(id, x, y, z);
    send();
}

//--------------------------------------------------------------
void ofxVsidoController::move(vector<IKData> ik){
    setMode(SET_IK_MODE);
    _data.push_back(0x01);//IKF
    for (int i = 0; i< ik.size(); i++) {
        setIK(ik[i].id, ik[i].pos.x, ik[i].pos.y, ik[i].pos.z);
    }
    send();
}

//--------------------------------------------------------------
void ofxVsidoController::setAngle(int id, int angle){
    unsigned char _id = id;
    unsigned char _a1 = (angle << 1) & 0xff;
    unsigned char _a2 = ((angle << 1) >> 8) << 1;
    
    _data.push_back(_id);
    _data.push_back(_a1);
    _data.push_back(_a2);
}

//--------------------------------------------------------------
void ofxVsidoController::setIK(int id, int x, int y, int z){
    _data.push_back(id);//KID
    _data.push_back(x);
    _data.push_back(y);
    _data.push_back(z);
}

//--------------------------------------------------------------
void ofxVsidoController::send(){
    _data.push_back(0x00);
    _data[2] = _data.size();
    for (int i = 0; i < _data.size()-1; i++) { _data[_data.size()-1] ^=_data[i]; } //SUM
    
    unsigned char _d[_data.size()];
    for (int i = 0; i < _data.size(); i++) {
        _d[i] = _data[i];
    }
    vsido_connect.sendCommands(_d, _data.size());
}
//--------------------------------------------------------------