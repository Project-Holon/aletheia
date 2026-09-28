/*
 * function: func_02061C30
 * address:  0x02061C30
 * packet:   pkt_02061C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      dacktimer_alarmhandler (libcps.a(network.o))
 *           .comment Metrowerks C/C++ for ARM 3.0.0.139
 *           DIFF: network.o is stamped 3.0.0.139 (prebuilt TwlWiFi_base), no tools/mwccarm build
 *           writes it; every available build loads the argument before the tail-call target (two
 *           swapped ldr and pool words). Blocked on the compiler, not the C.
 *           static in the object; g_02146B80 is network.o's static dacktimer_thread (OSThread)
 *
 * symbols:
 *   OS_WakeupThreadDirect            0x02061b5c data
 *   dacktimer_thread                 0x02146b80 data
 *   g_02146B80                       0x02146b80 data
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

struct _OSThread;
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern struct _OSThread g_02146B80;
#define dacktimer_thread g_02146B80

void func_02061C30(void)
{
    OS_WakeupThreadDirect(&dacktimer_thread);
}
