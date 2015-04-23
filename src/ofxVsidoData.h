/*
 ▖▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▘▚
 ▞ ofxVsidoData.h                                           ▚
 ▞────────────────────────────┐  project : ofxVsido         ▚
 ▞ github.com/azuremous       └───────────────────────────▶ ▚
 ▞ Created by Jung un Kim a.k.a azuremous on 4/23/15.       ▚
 ▞▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▖▘
 ----------------------------------------------------------*/

#pragma once

/*
 servo_id
 1 :腰ピッチ
 2 :首ヨー
 3 :右上腕ピッチ
 4 :右上腕ロール
 5 :右前腕ピッチ
 6 :左上腕ピッチ
 7 :左上腕ロール
 8 :左前腕ピッチ
 9 :右大腿ヨー
 10:右大腿ピッチ
 11:右大腿ロール
 12:右膝ピッチ
 13:右足ピッチ
 14:右足ロール
 15:左大腿ヨー
 16:右大腿ピッチ
 17:左大腿ロール
 18:左膝ピッチ
 19:左足ピッチ
 20:左足ロール
 */

typedef enum{
    CHEST_PITCH,            //0
    NECK_YAW,               //1
    RIGHT_SHOULDER_PITCH,   //2
    RIGHT_SHOULDER_ROLL,    //3
    RIGHT_ELBOW_PITCH,      //4
    LEFT_SHOULDER_PITCH,    //5
    LEFT_SHOULDER_ROLL,     //6
    LEFT_ELBOW_PITCH,       //7
    RIGHT_HIP_YAW,          //8
    RIGHT_HIP_ROW,          //9
    RIGHT_HIP_PITCH,        //10
    RIGHT_KNEE_PITCH        //11
    
}SERVO_NAME;

typedef enum{
    SET_ANGLE_MODE =0,
    SET_COMPLIANCE_MODE =1,
    DEFINE_ANGLE_MODE =2,
    SET_FEEDBACK_ID_MODE =3,
    GET_FEEDBACK_MODE = 4,
    REQUEST_SERVO_INFO_MODE =5,
    GET_SERVO_STATUS_MODE = 6,
    SET_IK_MODE = 7,
    WALK_MODE = 8
}VSIDO_COMMAND_MODE;

const unsigned char command_char[] = {
    'o', //0
    'c', //1
    'm', //2
    'f', //3
    'r', //4
    'd', //5
    'j', //6
    'k', //7
    't' //8
    
};