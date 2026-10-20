#ifndef GAME_SDK_SOC_H
#define GAME_SDK_SOC_H

#include "types.h"

/* Socket address types of the SDK network socket layer (SOC). */

typedef struct SOCInAddr {
    u32 addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct SOCHostEnt {
    char *name;
    char **aliases;
    s16 addrType;
    s16 length;
    u8 **addrList;
} SOCHostEnt;

typedef void *(*SOCAlloc)(unsigned long name, long size);
typedef void (*SOCFree)(unsigned long name, void *ptr, long size);

typedef long long SOCTime;

/* Start-up parameters of the socket layer. */
typedef struct SOCConfig {
    u16 vendor;
    u16 version;
    SOCAlloc alloc;
    SOCFree free;
    unsigned long flag;
    SOCInAddr addr;
    SOCInAddr netmask;
    SOCInAddr router;
    SOCInAddr dns1;
    SOCInAddr dns2;
    long timeWaitBuffer;
    long reassemblyBuffer;
    long mtu;
    long rwin;
    SOCTime r2;
    const char *peerid;
    const char *passwd;
    const char *serviceName;
    const char *hostName;
    long rdhcp;
    long udpSendBuff;
    long udpRecvBuff;
} SOCConfig;

#endif
