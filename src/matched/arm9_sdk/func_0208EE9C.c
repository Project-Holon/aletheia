/*
 * function: func_0208EE9C
 * address:  0x0208EE9C
 * packet:   pkt_0208EE9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_GetLinkLevel (libwm.TWL.HYB.a(wm_sync.o))
 *           .comment Metrowerks C/C++ for ARM 4.0.0.1024
 *
 * symbols:
 *   WMi_GetSystemWork                0x0208e4bc arm
 *   WMi_CheckInitialized             0x0208e4cc arm
 *   DC_InvalidateRange               0x020862b8 arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef short s16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_ILLEGAL_STATE = 3,
    WM_ERRCODE_WM_DISABLE = 4,
    WM_ERRCODE_NO_DATASET = 5,
    WM_ERRCODE_INVALID_PARAM = 6,
    WM_ERRCODE_NO_ENTRY = 7,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef void (*WMCallbackFunc)(void *arg);

typedef struct WMArm9Buf {
    struct WMArm7Buf *WM7;
    struct WMStatus *status;
    u32 *indbuf;
    u32 *fifo9to7;
    u32 *fifo7to9;
    u16 dmaNo;
    u16 scanOnlyFlag;
    WMCallbackFunc CallbackTable[44];
    WMCallbackFunc indCallback;
    WMCallbackFunc portCallbackTable[16];
    void *portCallbackArgument[16];
    u32 connectedAidBitmap;
    u16 myAid;
    u8 reserved1[174];
} WMArm9Buf;

typedef struct WMStatus {
    u16 state;
    u8 pad02[0xBA];
    u16 linkLevel;
    u8 padBE[0xC4];
    u16 child_bitmap;
} WMStatus;

typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1,
    WM_LINK_LEVEL_2,
    WM_LINK_LEVEL_3,
    WM_LINK_LEVEL_MAX
} WMLinkLevel;

extern WMArm9Buf *WMi_GetSystemWork(void);
extern WMErrCode WMi_CheckInitialized(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);

WMLinkLevel func_0208EE9C(void)
{
    WMErrCode result;
    WMArm9Buf *p = WMi_GetSystemWork();

    result = WMi_CheckInitialized();
    if (result != WM_ERRCODE_SUCCESS) {
        return WM_LINK_LEVEL_0;
    }

    DC_InvalidateRange(&p->status->state, 2);
    switch (p->status->state) {
    case 9:
        DC_InvalidateRange(&p->status->child_bitmap, 2);
        if (p->status->child_bitmap == 0) {
            return WM_LINK_LEVEL_0;
        }
    case 10:
    case 11:
        DC_InvalidateRange(&p->status->linkLevel, 2);
        return (WMLinkLevel)p->status->linkLevel;
    }
    return WM_LINK_LEVEL_0;
}
