#ifndef CLIENT_H_
#define CLIENT_H_

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Xinput.h>
#elif linux
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#endif


#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <curses.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

//defined values for the socket connection
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define DEFAULT_ADDRESS "192.168.1.2"

#ifdef linux
typedef unsigned int SOCKET; // Linux just defines SOCKET as an int, same number of bits
typedef unsigned short WORD; // See above comment

#define INVALID_SOCKET (SOCKET)(~0)
#endif

SOCKET setup(int, SOCKET);
int sendData(int, SOCKET);
int recieveDistance(int, SOCKET);

extern int isConnected;
extern float lXstick, lYstick, rXstick, rYstick;
extern float rTrigger, lTrigger;
extern float LFspd, LRspd, RRspd, RFspd;
extern float dist;
extern std::string lShoulder, rShoulder;
extern std::string a, b, x, y;
extern std::string startButton, selectButton;

class Gamepad {
private:
	int cId;
#ifdef _WIN32
        XINPUT_STATE state;
#endif
	float deadzoneX;
	float deadzoneY;

public:
	Gamepad() : deadzoneX(0.05f), deadzoneY(0.02f) {}
	Gamepad(float dzX, float dzY) : deadzoneX(dzX), deadzoneY(dzY) {}

#ifdef _WIN32
	XINPUT_GAMEPAD* GetState();
#endif
	int GetPort();
	float leftStickX;
	float leftStickY;
	float rightStickX;
	float rightStickY;
	float leftTrigger;
	float rightTrigger;
	bool CheckConnection();
	bool Refresh();
	bool IsPressed(WORD);
};

#endif // !CLIENT_H_
