cris
====

RSP와 로봇과의 통신을 위한 공통 API

> 2:48 오후 토요일, 10월 05, 2013

사용 방법은 다음과 같습니다. 

먼저 modules/ 폴더에 iClebo, Ollo 예제를 보시면

모든 module은 CUnicycleRobot 클래스를 상속 받습니다. 

아래의 코드는 필수 구현 함수 입니다. 

<code>
loadConfig_sensorSpecific(), doProcess(), ControlVelocity()


CGenericRobot 클래스는 RSP와 통신하기 위한 interface 클래스입니다. 