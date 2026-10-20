#ifndef OV009_SOCL_COMMAND_TYPES_H
#define OV009_SOCL_COMMAND_TYPES_H

#include "../types.h"
/*
 * Types for the ov009 SOCL command layer (socl_command and the other socl
 * objects that share gSoclConfig). One definition per object; offsets taken
 * from the views the parts had.
 */

/* The SOCL module global at gSoclConfig. */
typedef struct SOCLHostIp {
    unsigned long addr;                     /* 0x00 */
    unsigned long mask;                     /* 0x04 */
    unsigned long gateway;                  /* 0x08 */
    unsigned long dns;                      /* 0x0c */
    unsigned long dns2;                     /* 0x10 */
} SOCLHostIp;

typedef struct SOCLConfig {
    int use_dhcp;                           /* 0x00 */
    SOCLHostIp host_ip;                     /* 0x04 */
    void *(*alloc)(u32 size);     /* 0x18 */
    void (*free)(void *ptr);                /* 0x1c */
    unsigned long cmd_packet_max;           /* 0x20 */
    unsigned long lan_buffer_size;          /* 0x24 */
    void *lan_buffer;                       /* 0x28 */
    long cps_thread_prio;                   /* 0x2c */
    long mtu;                               /* 0x30 */
    long rwin;                              /* 0x34 */
} SOCLConfig;

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
#include "../sdk_os.h"

#endif
