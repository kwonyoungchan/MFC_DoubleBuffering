# MFC_DoubleBuffering

### 이 프로젝트는 무엇? 
- MFC Double Buffering 기법 활용을 위한 예제 프로젝트
- 본인이 MFC 응용프로그램 개발할 때 사용하려고 만듦
- 만약 본인의 MFC 응용프로그램 윈도우가 엄청 심하게 **<ins>깜빡거린다면</ins> ** 해당 프로젝트를 참조하는 것을 추천
- 이 프로젝트는 MFC 프로젝트이며 MFC에 대한 기초적인 이해가 요구됨.

## 어떻게 사용하면 될까요?

### 1. CHAN_DoubleBufferingView.cpp 소스코드 확인 
위 소스코드의 아래와 같은 이벤트 함수를 참조할 것 
- OnPaint()
- OnEraseBkgand()

### 2. BufferDC 클래스 활용 
- 다른 프로젝트에 더블 버퍼링 기법을 사용하고자 한다면 해당 클래스의 소스코드를 복사해가면 됨
- 이 클래스는 Win32 API 기반으로 작동되므로 MFC 용도 아니면 사용하지 않는 것을 권장함
