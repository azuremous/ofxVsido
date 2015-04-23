/*
 ▖▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▚
 ▞ ofxVsidoNetwork.cpp                                      ▚
 ▞────────────────────────────┐  project : ofxVsido         ▚
 ▞ github.com/azuremous       └───────────────────────────▶ ▚
 ▞ Created by Jung un Kim a.k.a azuremous on 4/23/15.       ▚
 ▞▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▘
 ----------------------------------------------------------*/

#include "ofxVsidoNetwork.h"


//--------------------------------------------------------------
ofxVsidoNetwork::ofxVsidoNetwork():
portNum(-1),
baudrate(115200),
isConnect(false)
{}

//--------------------------------------------------------------
void ofxVsidoNetwork::getSerialList(){
    v_sido.listDevices();
}

//--------------------------------------------------------------
bool ofxVsidoNetwork::setup(string portName, int baud){
    return isConnect = v_sido.setup(portName, baud);
}

//--------------------------------------------------------------
bool ofxVsidoNetwork::setup(int portNum, int baud){
    return isConnect = v_sido.setup(portNum, baud);
}

//--------------------------------------------------------------
bool ofxVsidoNetwork::connect(){
    vector<ofSerialDeviceInfo>_info = v_sido.getDeviceList();
    
    for (int i = 0; i < _info.size(); i++) {
        if(_info[i].getDeviceName().find("SBDBT") != -1){
            portNum = i;
        }
    }
    if (portNum != -1) {
        ofLog(OF_LOG_VERBOSE, "find v-sido : " + _info[portNum].getDeviceName());
       return isConnect = v_sido.setup(portNum, baudrate);
    }
    ofLog(OF_LOG_ERROR, "couldn't find v-sido");
    return false;
}

//--------------------------------------------------------------
int ofxVsidoNetwork::sendCommand(unsigned char buffer){
    return v_sido.writeByte(buffer);
}

//--------------------------------------------------------------
int ofxVsidoNetwork::sendCommands(unsigned char * buffer, int length){
    return v_sido.writeBytes(buffer, length);
}

//--------------------------------------------------------------
void ofxVsidoNetwork::update(){
    
}
