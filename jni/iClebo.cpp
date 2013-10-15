#include "com_isans_cris_CRISAndroid.h"

#include "iClebo.h"

static CGenericRobot* robot = NULL;

extern "C"{
	jint JNI_OnLoad(JavaVM* vm, void* reserved)
	{
		DPRINTF("__FUNCTION__ test ==> %s", __FUNCTION__);
		robot = reinterpret_cast<CUnicycleRobot*>(new iClebo);
		DPRINTF("%s", __FUNCTION__);
		return JNI_VERSION_1_4;
	}
} // extern "C"
/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetState
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_isans_cris_CRISAndroid_GetState
  (JNIEnv *, jobject)
{
	return robot->getState();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetProcessRate
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_isans_cris_CRISAndroid_GetProcessRate
  (JNIEnv *, jobject)
{
	return robot->getProcessRate();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetVendorID
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_isans_cris_CRISAndroid_GetVendorID
  (JNIEnv* env, jobject)
{
	std::string id = robot->getVendorID();
	return env->NewStringUTF(id.c_str());
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    Initialize
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_Initialize
  (JNIEnv *, jobject)
{
	return robot->initialize();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveForward
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveForward
  (JNIEnv *, jobject)
{
	return robot->MoveForward();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveBackward
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveBackward
  (JNIEnv *, jobject)
{
	return robot->MoveBackward();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnLeft
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnLeft
  (JNIEnv *, jobject)
{
	return robot->TurnLeft();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnRight
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnRight
  (JNIEnv *, jobject)
{
	return robot->TurnRight();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveDelta
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveDelta
  (JNIEnv *, jobject, jdouble delta)
{
	return robot->MoveDelta(delta);
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnDelta
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnDelta
  (JNIEnv *, jobject, jdouble delta)
{
	return robot->TurnDelta(delta);
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GoToPose
 * Signature: (DDD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_GoToPose
  (JNIEnv *, jobject, jdouble x, jdouble y, jdouble theta)
{
	return robot->GoToPose( Pose(x,y,theta) );
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    Stop
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_Stop
  (JNIEnv *, jobject)
{
	return robot->Stop();
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetLed
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_SetLed
  (JNIEnv *, jobject, jint which)
{
	return robot->SetLed(which);
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    Command
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_Command
  (JNIEnv *, jobject, jint cmd)
{
	return robot->Command(cmd);
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    MoveDeltaB
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_MoveDeltaB
  (JNIEnv *, jobject, jdouble delta)
{
	return robot->MoveDeltaB(delta);
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    TurnDeltaB
 * Signature: (D)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_TurnDeltaB
  (JNIEnv *, jobject, jdouble delta)
{
	return robot->TurnDeltaB(delta);
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GoToPoseB
 * Signature: (DDD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_isans_cris_CRISAndroid_GoToPoseB
  (JNIEnv *, jobject, jdouble x, jdouble y, jdouble theta)
{
	return robot->GoToPoseB( Pose(x,y,theta) );
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetMaxVelocity
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_isans_cris_CRISAndroid_SetMaxVelocity
  (JNIEnv *, jobject, jdouble linear, jdouble angular)
{
	robot->SetMaxVelocity( Polar(linear, angular) );
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetMaxVelocity
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_isans_cris_CRISAndroid_GetMaxVelocity
  (JNIEnv* env, jobject)
{
	Polar polar = robot->GetMaxVelocity();
	jdoubleArray result_arr;
	jdouble* arr_elems;

	jboolean isCopy;
	result_arr = env->NewDoubleArray(2);
	arr_elems = env->GetDoubleArrayElements(result_arr, &isCopy);

	arr_elems[0] = polar.linear;
	arr_elems[1] = polar.angular;

	if (isCopy == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(result_arr, arr_elems, 0);
	}
	return result_arr;
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetMaxAcceleration
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_isans_cris_CRISAndroid_SetMaxAcceleration
  (JNIEnv *, jobject, jdouble linear, jdouble angular)
{
	robot->SetMaxAcceleration( Polar(linear, angular) );
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetMaxAcceleration
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_isans_cris_CRISAndroid_GetMaxAcceleration
  (JNIEnv* env, jobject)
{
	Polar polar = robot->GetMaxAcceleration();
	jdoubleArray result_arr;
	jdouble* arr_elems;

	jboolean isCopy;
	result_arr = env->NewDoubleArray(2);
	arr_elems = env->GetDoubleArrayElements(result_arr, &isCopy);

	arr_elems[0] = polar.linear;
	arr_elems[1] = polar.angular;

	if (isCopy == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(result_arr, arr_elems, 0);
	}
	return result_arr;
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    SetVelocity
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_isans_cris_CRISAndroid_SetVelocity
  (JNIEnv *, jobject, jdouble linear, jdouble angular)
{
	robot->SetVelocity( Polar(linear,angular) );
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetVelocity
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_isans_cris_CRISAndroid_GetVelocity
  (JNIEnv* env, jobject)
{
	Polar polar = robot->GetVelocity();

	jdoubleArray result_arr;
	jdouble* arr_elems;

	jboolean isCopy;
	result_arr = env->NewDoubleArray(2);
	arr_elems = env->GetDoubleArrayElements(result_arr, &isCopy);

	arr_elems[0] = polar.linear;
	arr_elems[1] = polar.angular;

	if (isCopy == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(result_arr, arr_elems, 0);
	}
	return result_arr;
}

/*
 * Class:     com_isans_cris_CRISAndroid
 * Method:    GetMap
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_isans_cris_CRISAndroid_GetMap
  (JNIEnv* env, jobject)
{
	std::vector<PointInfo> info = robot->GetMap();
	jdoubleArray result_arr;
	jdouble* arr_elems;

	jboolean isCopy;
	result_arr = env->NewDoubleArray(info.size()*3);
	arr_elems = env->GetDoubleArrayElements(result_arr, &isCopy);

	for(int i = 0; i < info.size(); i++){
		arr_elems[i*3+0] = info[i].x;
		arr_elems[i*3+1] = info[i].y;
		arr_elems[i*3+2] = info[i].flag;
		arr_elems[i*3+3] = info[i].wall;
	}

	if (isCopy == JNI_TRUE) {
		env->ReleaseDoubleArrayElements(result_arr, arr_elems, 0);
	}
	return result_arr;
}


