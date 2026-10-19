#ifndef OV107_MB_WM_H
#define OV107_MB_WM_H
/*
 * WM (wireless manager) callback types and the multiboot WM-side work block
 * (NitroSDK MB library), shared by the ov107 translation unit mb_wm_base.
 * gMbWm (struct WmBase) holds the DMA number, the WM system buffer, the
 * MBiParam block (work) and the MB_CommCommonWork block (ext).
 */
#include "mb_parent.h"

#include "../sdk_wm.h"

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

typedef struct ParentInfo {
    union {
        WMBssDesc parentInfo[1];
        u8 parentInfo_area[192];
    };
    WMStartScanCallback scan_data;
    u8 reserved1[8];
} ParentInfo;

typedef struct MBiParam {
    WMParentParam parentParam;                  /* 0x000 */
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
    u8 reserved2[0x560 - 0x558];                /* 0x548: u16 cleared by MBi_StartCommon */
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

extern char gMbWm[];
#define mbWm (*(WmBase *)gMbWm)

/*
 * Initialised data at 0x021F6E58 .. 0x021F6E70 (defined in mb_wm_base).
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
