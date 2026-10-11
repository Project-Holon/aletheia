#ifndef OV009_WCM_TYPES_H
#define OV009_WCM_TYPES_H
/*
 * Shared WCM (wireless connection manager) types for ov009 units
 * unit_02165B80 and unit_02166880. One definition per object, offsets
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

typedef struct WCMConfig {
    unsigned long dmano;
    void *pbdbuffer;
    unsigned long nbdbuffer;
    unsigned long nbdmode;
} WCMConfig;

typedef struct WMGameInfo {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
    unsigned char attribute;
    unsigned short parentMaxSize;
    unsigned short childMaxSize;
    unsigned short userGameInfo[56];
} WMGameInfo;

typedef struct WMBssDesc {
    unsigned short length;          /* +0x00 */
    unsigned short rssi;            /* +0x02 */
    unsigned char bssid[6];         /* +0x04 */
    unsigned short ssidLength;      /* +0x0a */
    unsigned char ssid[32];         /* +0x0c */
    unsigned short capaInfo;        /* +0x2c */
    unsigned short rateSet[2];      /* +0x2e */
    unsigned short beaconPeriod;    /* +0x32 */
    unsigned short dtimPeriod;      /* +0x34 */
    unsigned short channel;         /* +0x36 */
    unsigned short cfpPeriod;       /* +0x38 */
    unsigned short cfpMaxDuration;  /* +0x3a */
    unsigned short gameInfoLength;  /* +0x3c */
    unsigned short elementCount;    /* +0x3e */
    unsigned short elements[64];    /* +0x40, holds a WMGameInfo on DS */
} WMBssDesc;

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

typedef struct WMScanExParam {
    unsigned char *scanBuf;
    unsigned short scanBufSize;
    unsigned short channelList;
    unsigned short maxChannelTime;
    unsigned char bssid[6];
    unsigned short scanType;
    unsigned short ssidLength;
    unsigned char ssid[32];
} WMScanExParam;

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
    unsigned char bssDesc[0xC0];    /* +0x12E0 */
    unsigned char wmSysBuf[0xF00];  /* +0x13A0, WM_Init work buffer */
    WMScanExParam scanParam;        /* +0x22A0 */
    unsigned char pad22D4[0x10];
    unsigned long notifyCount;      /* +0x22E4 */
    unsigned short aid;             /* +0x22E8 */
    unsigned short wlStatus;        /* +0x22EA */
} WCMWork;

#endif
