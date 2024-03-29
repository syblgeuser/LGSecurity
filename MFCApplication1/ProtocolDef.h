#pragma once
#define MESSAGE_USER WM_USER+10
enum SecureMode
{
	MODE_SECURE,
	MODE_NON_SECURE,
};

enum OperMode
{
	MODE_RUN,
	MODE_LEARNING,
	MODE_TEST_RUN,
};

enum Authority
{
	MODE_FAIL = -1,
	MODE_ADMIN = 0,
	MODE_NORMAL,
};

enum  MsgReq
{
	MSG_LOGIN = 1000,
	MSG_IMAGE = 1002,
	MSG_CONTROL_MODE=1003,
	MSG_SERVER_SETTING = 1004,
	MSG_VIDEO_FILE_LIST = 1005,
	MSG_VIDEO_SELECT = 1006,
	MSG_START_LEARNING_MODE = 1007,
	MSG_ACK = 9999,
} ;

enum MsgRecv
{
	ACK_OK = 0,
	ACK_NOK = 1,
};

enum MsgUserDefine
{
	MSG_NO_VIDEO = 2000,
	MSG_PRINT_LOG,
	MSG_LOGIN_SUCCESS,
	MSG_LOGIN_FAIL,
	MSG_MODE_CHANGE_SUCCESS,
	MSG_MODE_CHANGE_FAIL,
	MSG_LEARNING_SUCCESS,
	MSG_LEARNING_FAIL,
	MSG_VIDEO_SELECTED_SUCCESS,
	MSG_VIDEO_SELECTED_FAIL,
	MSG_RECONNECT,
};


#pragma pack(push, 1)    // 1바이트 크기로 정렬
typedef  struct {
    unsigned char head[4];
    uint32_t size;
	uint32_t timestamp;
	uint32_t msgtype;
} MyPacketHeader;

typedef  struct {
	MyPacketHeader hdr;
	unsigned char payload[1];
} MyPacket;
#pragma pack(pop)
