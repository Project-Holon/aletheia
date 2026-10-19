#ifndef ALETHEIA_OV015_IRC_TYPES_H
#define ALETHEIA_OV015_IRC_TYPES_H

#include "../types.h"
#include "../sdk_os.h"

#define TRUE 1

typedef void (*IRCConnectCallback)(u8 unitId, BOOL isSender);
typedef void (*IRCRecvCallback)(u8 *data, u8 size, u8 command, u8 id);
typedef void (*IRCShutdownCallback)(BOOL isError);

typedef enum {
    IRC_ST_DISCONNECT,
    IRC_ST_WAIT_RESPONSE,
    IRC_ST_WAIT_ACK,
    IRC_ST_SENDER,
    IRC_ST_RECEIVER,
    IRC_ST_NUM
} IRCStatusType;

#endif
