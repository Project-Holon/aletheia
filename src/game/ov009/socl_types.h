#ifndef OV009_SOCL_TYPES_H
#define OV009_SOCL_TYPES_H
/*
 * SOCL socket types shared by socl_bind, socl_create, socl_read, socl_shutdown,
 * socl_ssl and socl_write (ov009, libsoc). One definition per object; offsets
 * checked against every view the parts used.
 */

#include "../types.h"
#include "../ov009/cps_types.h"
#include "../sdk_os.h"

struct SOCLiUdpData {
    struct SOCLiUdpData *next;
    unsigned short size;
    unsigned short remote_port;
    unsigned long remote_ip;
    unsigned char data[1];
};

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xc4];
    CPSSoc *cpsoc;
    unsigned char padc8[0x18];
    unsigned char mutex[0x18];
    volatile long consumed;
    unsigned short consumed_min;
    signed char flag_noconsume;
    unsigned char padff;
    struct SOCLiUdpData *volatile tail;
    struct SOCLiUdpData *head;
    unsigned short recv_size;
    unsigned short recv_max;
    OSThreadQueue waiting;
};

struct SOCLiSocketRingBuffer {
    long size;
    unsigned char *area;
    volatile unsigned short in;
    volatile unsigned short out;
    OSThreadQueue waiting;
};

struct SOCLiSocketSendCommandPipe {
    unsigned char pad0[0xe0];
    unsigned char mutex[0x18];
    struct SOCLiSocketRingBuffer buffer;
    struct SOCLSocket *exe_socket;
};

struct SOCLSocket {
    CPSSoc cps_socket;                                    /* 0x00 */
    struct SOCLiSocketRecvCommandPipe *recv_pipe;         /* 0xa0 */
    struct SOCLiSocketSendCommandPipe *send_pipe;         /* 0xa4 */
    long result;                                          /* 0xa8 */
    short state;                                          /* 0xac */
    signed char flag_block;                               /* 0xae */
    signed char flag_mode;                                /* 0xaf */
    unsigned short local_port;                            /* 0xb0 */
    unsigned short remote_port;                           /* 0xb2 */
    unsigned long remote_ip;                              /* 0xb4 */
};

typedef struct SOCLSocket SOCLSocket;
typedef struct SOCLiSocketRecvCommandPipe SOCLiSocketRecvCommandPipe;
typedef struct SOCLiSocketSendCommandPipe SOCLiSocketSendCommandPipe;

#endif
