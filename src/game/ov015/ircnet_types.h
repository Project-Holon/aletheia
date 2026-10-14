#ifndef ALETHEIA_OV015_IRCNET_TYPES_H
#define ALETHEIA_OV015_IRCNET_TYPES_H

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
typedef int (*IRCNetFilterFn)(u8 groupId, u8 packetGroupId);

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
