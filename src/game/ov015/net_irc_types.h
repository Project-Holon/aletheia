#ifndef ALETHEIA_OV015_NET_IRC_TYPES_H
#define ALETHEIA_OV015_NET_IRC_TYPES_H

#include "../types.h"

/* Packet of the game's infrared link layer, sent through IRC_Send with the
 * packet type as the libirc command byte. */
typedef struct IRCNetPacket {
    u16 checksum;      /* libirc-independent sum over everything after this field */
    u8 type;           /* command byte; 0xEE is the empty keep-alive */
    u8 seq;            /* low nibble: sequence of this packet, high nibble: last sequence received */
    u32 senderId;      /* random session id of the sender */
    u32 targetId;      /* session id the sender knows for the other side, 0 before contact */
    u8 groupId;        /* link group chosen at setup, packets of other groups are dropped */
    u8 pad0D;
    u8 payload[0xA6];
} IRCNetPacket;

typedef int (*IRCNetRecvFn)(u16 id, u8 *data, u16 len);
typedef int (*IRCNetFilterFn)(int groupId, int packetGroupId);

/* Command byte of a link packet (IRCNetPacket.type, also passed to IRC_Send and
 * IRCi_Send). The values were read from the flow in irc.c: IRC_Connect sends
 * 0x56, the answer to it is 0xFA, the confirm is 0xF8, a retry request is 0xF6,
 * a reset is 0xFC, a shutdown frame is 0xF4 and an empty keep-alive is 0xEE. */
typedef enum IRCCommand {
    IRC_CMD_CONNECT_REQUEST = 0x56,
    IRC_CMD_KEEPALIVE       = 0xEE,
    IRC_CMD_FINISH          = 0xF4,
    IRC_CMD_RESTORE         = 0xF6,
    IRC_CMD_CONNECT_CONFIRM = 0xF8,
    IRC_CMD_CONNECT_ACK     = 0xFA,
    IRC_CMD_DISCONNECT      = 0xFC
} IRCCommand;

/* State of the infrared link layer (0xE8 bytes, cleared by IRCNET_InitWork). */
typedef struct IRCNetWork {
    IRCNetRecvFn recvCallback;   /* 0x00 */
    IRCNetPacket packet;         /* 0x04 outgoing packet buffer */
    u32 peerSessionId;           /* 0xB8 senderId learned from the other side, 0 before contact */
    u32 timeoutLimit;            /* 0xBC frames the link may wait for a connection */
    u32 linkTimer;               /* 0xC0 frames spent connecting or waiting */
    void *pendingData;           /* 0xC4 payload kept for a resend */
    IRCNetFilterFn filter;       /* 0xC8 optional group filter */
    u8 isRunning;                /* 0xCC */
    u8 pad0CD;
    u8 isSendReady;              /* 0xCE */
    u8 isClosing : 1;            /* 0xCF */
    u8 hasPeer : 1;
    u8 pad0D0[12];
    u8 isSenderRole;             /* 0xDC */
    u8 isActive;                 /* 0xDD */
    u8 pendingSize;              /* 0xDE */
    u8 pendingType;              /* 0xDF */
    u8 resendSeq;                /* 0xE0 */
    u8 waitingAck;               /* 0xE1 */
    u8 sendSeq;                  /* 0xE2 */
    u8 recvSeq;                  /* 0xE3 */
    u8 needResend;               /* 0xE4 */
    u8 hasFailed;                /* 0xE5 */
    u8 randomByte;               /* 0xE6 */
    u8 unitNumber;               /* 0xE7 */
} IRCNetWork;

#endif
