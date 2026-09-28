/*
 * function: WmGetCommandBuffer4Arm7
 * address:  0x0208E340
 * packet:   pkt_0208E340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static in the vendor object: takes a free command buffer from the queue, or puts it back and returns NULL while ARM7 still owns it.
 * bufMsgQ is the object's queue of free ARM7 command buffers; taking its
 * address uses its own symbol.
 *
 * symbols:
 *   bufMsgQ             0x02153070  data
 *   OS_ReceiveMessage   0x02085E50  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   OS_JamMessage       0x02085EF0  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef long s32;
typedef int BOOL;
typedef void *OSMessage;

typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_OPERATING = 2,
    WM_ERRCODE_FIFO_ERROR = 8,
    WM_ERRCODE_MAX = 0x7FFFFFFF
} WMErrCode;

typedef enum WMApiid {
    WM_APIID_MAX = 0x7FFFFFFF
} WMApiid;

typedef struct _OSThreadQueue {
    struct _OSThread *head;
    struct _OSThread *tail;
} OSThreadQueue;

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    s32 msgCount;
    s32 firstIndex;
    s32 usedCount;
} OSMessageQueue;

extern OSMessageQueue bufMsgQ;

extern BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);

u32 *WmGetCommandBuffer4Arm7(void)
{
    u32 *tmpAddr;

    if (OS_ReceiveMessage(&bufMsgQ, (OSMessage *)&tmpAddr, 0) == 0) {
        return 0;
    }
    DC_InvalidateRange(tmpAddr, 2);
    if (*(u16 *)tmpAddr & 0x8000) {
        return tmpAddr;
    }
    (void)OS_JamMessage(&bufMsgQ, tmpAddr, 1);
    return 0;
}
