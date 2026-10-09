#ifndef OV107_MB_WM_H
#define OV107_MB_WM_H
/*
 * WM (wireless manager) callback types and the multiboot WM-side work block
 * (NitroSDK MB library), shared by the ov107 translation unit unit_021F4560.
 * d_021F6F90 (struct WmBase) holds the DMA number, the WM system buffer, the
 * MBiParam block (work) and the MB_CommCommonWork block (ext).
 */
#include "mb_parent.h"

typedef struct WMCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
} WMCallback;

typedef struct WMIndCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 reason;
} WMIndCallback;

typedef struct WMGameInfo {
    u16 magicNumber;
    u8 ver;
    u8 platform;
    u32 ggid;
    u16 tgid;
    u8 userGameInfoLength;
    u8 gameNameCount_attribute;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 userGameInfo[56];
} WMGameInfo;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    struct {
        u16 basic;
        u16 support;
    } rateSet;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc;

typedef struct WMStartScanCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 channel;
    u16 linkLevel;
    u16 ssidLength;
    u16 ssid[16];
    u16 gameInfoLength;
    WMGameInfo gameInfo;
} WMStartScanCallback;

typedef struct WMStartScanExCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u8 reserved[2];
    u16 bssDescCount;
    WMBssDesc *bssDesc[16];
    u16 linkLevel[16];
} WMStartScanExCallback;

typedef struct WMStartConnectCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 aid;
    u16 reason;
    u16 wlStatus;
    u8 macAddress[6];
    u16 parentSize;
    u16 childSize;
} WMStartConnectCallback;

typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[2];
    void *recvBuf;
    u16 timeStamp;
    u16 rate_rssi;
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 seqNum;
    u16 tmptt;
    u16 pollbmp;
    u16 reserved2;
} WMStartMPCallback;

typedef struct WMScanExParam {
    WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 channelList;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];
    u16 ssidMatchLength;
    u16 rsv2[7];
} WMScanExParam;

typedef struct ParentInfo {
    union {
        WMBssDesc parentInfo[1];
        u8 parentInfo_area[192];
    };
    WMStartScanCallback scan_data;
    u8 reserved1[8];
} ParentInfo;

/* WMParentParam as embedded in MBiParam: 0x14 bytes after 4-byte alignment */
typedef struct WMParentParam {
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 KS_Flag;
    u16 CS_Flag;
    u16 beaconPeriod;
} WMParentParam;

typedef struct MBiParam {
    u8 pad0[8];
    WMParentParam parentParam;                  /* 0x008 */
    u8 pad1C[0x40 - 0x1C];
    u16 sendBuf[512];                           /* 0x040 */
    u8 parentInfoBuf_area[192];                 /* 0x440 */
    u16 p_sendlen;                              /* 0x500 */
    u16 p_recvlen;                              /* 0x502 */
    void *recvBuf;                              /* 0x504 */
    void (*callback_ptr)(void *);               /* 0x508 */
    u8 mpBusy;                                  /* 0x50C */
    u8 mbIsStarted;                             /* 0x50D */
    u8 reserved0[10];
    u16 sendBufSize;                            /* 0x518 */
    u16 recvBufSize;                            /* 0x51A */
    void (*callback)(u16, void *);              /* 0x51C */
    WMBssDesc *pInfo;                           /* 0x520 */
    u16 mode;                                   /* 0x524 */
    u16 endReq;                                 /* 0x526 */
    u16 mpStarted;                              /* 0x528 */
    u16 child_bitmap;                           /* 0x52A */
    u16 contSend;                               /* 0x52C */
    u8 reserved1[2];
    u16 uname[4];                               /* 0x530 */
    u16 gname[16];                              /* 0x538 */
    u8 reserved2[0x560 - 0x558];                /* 0x548: u16 cleared by func_021F5BE0 */
    u16 userGameInfo[64];                       /* 0x560 */
    u16 found_parent_count;                     /* 0x5E0 */
    u16 my_aid;                                 /* 0x5E2 */
    BOOL scanning_flag;                         /* 0x5E4 */
    BOOL scan_channel_flag;                     /* 0x5E8 */
    int last_found_parent_no;                   /* 0x5EC */
    u8 reserved8[16];
    ParentInfo parent_info[16];                 /* 0x600 */
} MBiParam;

typedef struct WmBase {
    u16 WM_DMA_NO;                              /* 0x00 */
    u16 pad;
    void *wmSysBuf;                             /* 0x04 */
    BOOL isEnableReject;                        /* 0x08 */
    MBiParam *work;                             /* 0x0C */
    MB_CommCommonWork *ext;                     /* 0x10 */
} WmBase;

extern char d_021F6F90[];
#define mbWm (*(WmBase *)d_021F6F90)

/*
 * Initialised data at 0x021F6E58 .. 0x021F6E70 (defined in unit_021F4560).
 * The compiler lays statics out in an order set by the definition order and
 * the types, so each part that needs a different subset of them (p03 needs
 * the reject words before MB_Init, p04 defines them after MB_Init's `game`)
 * defines its own block with MB_WM_OWN_STATICS set before this header is
 * included.  The block below is the one for the remaining parts.
 */
#ifndef MB_WM_OWN_STATICS
static u32 mbi_reject_ggid_mask;
static u32 mbi_reject_ggid;
static u16 mbi_life_frame = 5;
static u16 mbi_life_table_no = 0xffff;
static u16 mbi_life_cam = 0x28;
static u16 mbi_life_mp = 0x28;
static int mbi_power_save_mode = 1;
#endif
extern WMScanExParam mbiScanParam __attribute__((aligned(32)));

#endif
