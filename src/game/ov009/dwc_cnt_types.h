#ifndef OV009_DWC_CNT_TYPES_H
#define OV009_DWC_CNT_TYPES_H
/*
 * DWC main control block (ov009, dwc_main.o): the 0x1250-byte block that
 * gDwcGlobalState.st points to, allocated by DWC_InitFriendsMatch. It embeds the
 * login control (dwc_login_types.h), the friend control (opaque here), the
 * match control (dwc_match_ctl_types.h) and the transport info
 * (TransInfo, dwc_transport.c, 0x728 bytes).
 */

#include "../ov009/dwc_login_types.h"
#include "../ov009/dwc_match_ctl_types.h"

/* gDwcGlobalState: the DWC global, one per process. */
struct DWCstDwcCnt;

typedef struct DwcGlobal {
    int lastSocketError;            /* +0x00 */
    struct DWCstDwcCnt *st;         /* +0x04 */
} DwcGlobal;

typedef struct DWCstGt2Callbacks {
    void (*connected)(void *connection, int result);        /* +0x00 */
    void (*received)(void *connection, unsigned char *message, int size, int reliable); /* +0x04 */
    void (*closed)(void *connection, int reason);           /* +0x08 */
    void (*ping)(void *connection, int latency);            /* +0x0C */
} DWCstGt2Callbacks;

typedef struct DWCstDwcCnt {
    void *gt2Socket;                /* +0x000 */
    DWCstGt2Callbacks gt2Callbacks; /* +0x004 */
    unsigned long sendBufSize;      /* +0x014 */
    unsigned long recvBufSize;      /* +0x018 */
    void *gp;                       /* +0x01C */
    DWCstAccUserData *userdata;     /* +0x020 */
    int state;                      /* +0x024 */
    int prevState;                  /* +0x028 */
    u8 pad02C;
    u8 closeAllHard;                /* +0x02D */
    u8 pad02E[2];
    u16 playerName[0x1a];           /* +0x030 */
    int profileID;                  /* +0x064 */
    char *gameName;                 /* +0x068 */
    char *secretKey;                /* +0x06C */
    void (*loginCallback)(int, int, void *); /* +0x070 */
    void *loginParam;               /* +0x074 */
    void (*updateCallback)(int, int, void *); /* +0x078 */
    void *updateParam;              /* +0x07C */
    MatchedCallback matchedCallback; /* +0x080 */
    void *matchedParam;             /* +0x084 */
    MatchedCallback closedCallback; /* +0x088 */
    void *closedParam;              /* +0x08C */
    DWCstLoginControl login;        /* +0x090 */
    u8 friendCnt[0x60];             /* +0x2F0 */
    DWCstMatchControl match;        /* +0x350 */
    u8 transInfo[0x728];            /* +0xB28 */
} DWCstDwcCnt;

#endif
