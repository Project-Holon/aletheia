#ifndef OV009_SOCL_COMMAND_TYPES_H
#define OV009_SOCL_COMMAND_TYPES_H
/*
 * Types for the ov009 SOCL command layer (socl_command and the other socl
 * objects that share gSoclConfig). One definition per object; offsets taken
 * from the views the parts had.
 */

/* The SOCL module global at gSoclConfig. */
typedef struct SoclConfig {
    int useDhcp;                            /* 0x00 */
    unsigned long myIp;                     /* 0x04 */
    unsigned long netMask;                  /* 0x08 */
    unsigned long gatewayIp;                /* 0x0c */
    unsigned long dnsIp[2];                 /* 0x10 */
    void *(*alloc)(unsigned long size);     /* 0x18 */
    void (*free)(void *ptr);                /* 0x1c */
    long cmdPacketMax;                      /* 0x20 */
    unsigned long lanBufferSize;            /* 0x24 */
    void *lanBuffer;                        /* 0x28 */
} SoclConfig;

/* An opaque SOCL socket; the command layer only stores and reads the pointer. */
struct SOCLSocket;

/* The reply view of a command target: only the result word at 0xa8 is read. */
typedef struct SOCLCmdReply {
    char opaque[0xa8];
    long result;
} SOCLCmdReply;

/* The command queue object at gSoclCmdQueue: the packet pool pointer, then the
 * OSMessageQueue whose msgCount and usedCount sit at 0x18 and 0x20. */
typedef struct SoclCmdQueue {
    void *packets;                          /* 0x00 */
    unsigned char queueSend[8];             /* 0x04 OSThreadQueue */
    unsigned char queueReceive[8];          /* 0x0c OSThreadQueue */
    void *msgArray;                         /* 0x14 */
    int msgCount;                           /* 0x18 */
    int firstIndex;                         /* 0x1c */
    int usedCount;                          /* 0x20 */
} SoclCmdQueue;

/* One 0x2c-byte command packet, shared by the allocator and the handler
 * thread: exec 0x00, target 0x04, response queue 0x08, pipe 0x0c, flag 0x0d. */
typedef struct SOCLiCommandPacket {
    int (*exec)(void *);
    union {
        struct SOCLSocket *socket;
        SOCLCmdReply *reply;
    } target;
    void *response_queue;
    unsigned char pipeIndex;
    signed char blockFlag;
} SOCLiCommandPacket;

/* An OS message queue (0x20 bytes), matching OS_InitMessageQueue. */
typedef struct OSMessageQueue {
    char opaque[0x20];
} OSMessageQueue;

#endif
