#ifndef OV009_WCM_TYPES_H
#define OV009_WCM_TYPES_H
/*
 * Shared WCM (wireless connection manager) types for ov009 units
 * wcm_aplist and wcm_wmif. One definition per object, offsets
 * checked against every view the parts had.
 */

typedef struct WCMPrivacy {
    unsigned char key[80];
    unsigned char mode;
    union {
        unsigned char keyId;
        unsigned char keyLen;
    } u;
    unsigned char reserved[2];
} WCMPrivacy;

#include "../sdk_wm.h"

typedef struct WCMApList {
    unsigned char state;
    unsigned char reserved;
    unsigned short linkLevel;
    unsigned long index;
    struct WCMApList *previous;
    struct WCMApList *next;
    WMBssDesc bssDesc;
} WCMApList;

typedef struct WCMApListHeader {
    unsigned long count;
    WCMApList *head;
    WCMApList *tail;
} WCMApListHeader;

typedef struct WCMWork {
    unsigned char sendBuf[0x600];
    unsigned char recvBuf[0xC40];
    WCMPrivacy privacyDesc;         /* +0x1240 */
    unsigned char alarm[0x2C];      /* +0x1294 keep-alive alarm */
    WCMConfig config;               /* +0x12C0 */
    void (*notify)(void *);         /* +0x12D0 */
    unsigned long option;           /* +0x12D4 */
    unsigned short maxScanTime;     /* +0x12D8 */
    short notifyId;                 /* +0x12DA */
    unsigned char apListLock;       /* +0x12DC */
    unsigned char resetting;        /* +0x12DD */
    unsigned char phase;            /* +0x12DE */
    unsigned char deviceId;         /* +0x12DF */
    union {
        unsigned char bssDesc[0xC0];    /* +0x12E0 */
        WMBssDesc apBss;                /* +0x12E0, the same bytes as a parsed AP */
    };
    unsigned char wmSysBuf[0xF00];  /* +0x13A0, WM_Init work buffer */
    WMScanExParam scanParam;        /* +0x22A0 */
    unsigned long notifyCount;      /* +0x22E4 */
    unsigned short aid;             /* +0x22E8 */
    unsigned short wlStatus;        /* +0x22EA */
} WCMWork;

#endif
