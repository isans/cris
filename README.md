cris
====

RSP와 로봇과의 통신을 위한 공통 API

> 11:51 오후 일요일, 10월 13, 2013

**작업 환경** 

windows 8

android-ndk-r8e 64bit

cygwin 32bit

boost 1.53.0

**사용 방법은 다음과 같습니다.**

eclipse에서 현재 프로젝트를 import 하고.

jni/ 폴더에서 iClebo.cpp, iClebo.h를 참고 해서 작성 합니다. 

boost를 NDK로 컴파일 했으니 thread, data time, 해당 유틸리티로 

작업 하시면 됩니다. 

**boost 사용 방법** 

boost_ for_android.zip 압축 파일을 

android-ndk-r8e/sources/ 위치에 boost 이름으로 풉니다. 

**android-ndk-r8e/sources/boost/android/include/boost/**

**android-ndk-r8e/sources/boost/android/lib/**

위의 두라인이 boost의 path입니다. 

참고로 android-ndk-r9 버전에서도 boost가능 합니다. 


> 2:48 오후 토요일, 10월 05, 2013

사용 방법은 다음과 같습니다. 

먼저 modules/ 폴더에 iClebo, Ollo 예제를 보시면

모든 module은 CUnicycleRobot 클래스를 상속 받습니다. 

아래의 코드는 필수 구현 함수 입니다. 

<code>
loadConfig_sensorSpecific(), doProcess(), ControlVelocity()


CGenericRobot 클래스는 RSP와 통신하기 위한 interface 클래스입니다. 