#include "com_isans_cris_CRISAndroid.h"
#include <android/log.h>

#include "iClebo.h"

//==============================
// Declarations
//==============================
#define LOG_TAG "cris.cpp"
#define DPRINTF(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define IPRINTF(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define EPRINTF(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

static CGenericRobot* robot = NULL;

extern "C"{
	jint JNI_OnLoad(JavaVM* vm, void* reserved)
	{
		robot = reinterpret_cast<CUnicycleRobot*>(new iClebo);
		return JNI_VERSION_1_4;
	}
} // extern "C"


/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SendData
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_com_isans_cris_CRISAndroid_SendData
  (JNIEnv *, jclass, jbyteArray)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetData
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_isans_cris_CRISAndroid_GetData
  (JNIEnv *, jclass)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    Initialize
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_Initialize
  (JNIEnv *, jobject)
{
	if(robot)
		robot->initialize();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveForward
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveForward
  (JNIEnv *, jobject)
{
	if(robot)
		robot->MoveForward();
}
/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveBackward
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveBackward
  (JNIEnv *, jobject)
{
	if(robot)
		robot->MoveBackward();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnLeft
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnLeft
  (JNIEnv *, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnRight
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnRight
  (JNIEnv *, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveDelta
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveDelta
  (JNIEnv *, jobject, jdouble)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnDelta
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnDelta
  (JNIEnv *, jobject, jdouble)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GoToPose
 * Signature: (Ljava/util/Vector;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_GoToPose
  (JNIEnv *, jobject, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    Stop
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_Stop
  (JNIEnv *, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetLed
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_SetLed
  (JNIEnv *, jobject, jint)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    Command
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_Command
  (JNIEnv *, jobject, jint)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveDeltaB
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveDeltaB
  (JNIEnv *, jobject, jdouble)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnDeltaB
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnDeltaB
  (JNIEnv *, jobject, jdouble)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GoToPoseB
 * Signature: (Ljava/util/Vector;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_GoToPoseB
  (JNIEnv *, jobject, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetMaxVelocity
 * Signature: (Ljava/util/Vector;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_SetMaxVelocity
  (JNIEnv *, jobject, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetMaxVelocity
 * Signature: ()Ljava/util/Vector;
 */
JNIEXPORT jobject JNICALL Java_com_isans_cris_CRISAndroid_GetMaxVelocity
  (JNIEnv *, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetMaxAcceleration
 * Signature: (Ljava/util/Vector;)V
 */
JNIEXPORT void JNICALL Java_com_isans_cris_CRISAndroid_SetMaxAcceleration
  (JNIEnv *, jobject, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetMaxAcceleration
 * Signature: ()Ljava/util/Vector;
 */
JNIEXPORT jobject JNICALL Java_com_isans_cris_CRISAndroid_GetMaxAcceleration
  (JNIEnv *, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetVelocity
 * Signature: (Ljava/util/Vector;)V
 */
JNIEXPORT void JNICALL Java_com_isans_cris_CRISAndroid_SetVelocity
  (JNIEnv *, jobject, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetVelocity
 * Signature: ()Ljava/util/Vector;
 */
JNIEXPORT jobject JNICALL Java_com_isans_cris_CRISAndroid_GetVelocity
  (JNIEnv *, jobject)
{

}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetMap
 * Signature: ()Ljava/util/Vector;
 */
JNIEXPORT jobject JNICALL Java_com_isans_cris_CRISAndroid_GetMap
  (JNIEnv *, jobject)
{

}
