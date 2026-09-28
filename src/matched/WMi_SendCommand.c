/*
 * function: WMi_SendCommand
 * address:  0x0208E3A0
 * packet:   pkt_0208E3A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libwm wm_system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Fills a command buffer with the API id and its arguments, flushes it and hands it to ARM7 through the WM FIFO.
 * bufMsgQ is the object's queue of free ARM7 command buffers; taking its
 * address uses its own symbol.
 *
 * symbols:
 *   WmGetCommandBuffer4Arm7  0x0208E340  arm
 *   DC_StoreRange            0x020862D4  arm
 *   PXI_SendWordByFifo       0x02088610  arm
 *   OS_SendMessage           0x02085DBC  arm
 *   bufMsgQ                  0x02153070  data
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

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define __va_size(t) ((sizeof(t) + 3) & ~3u)
#define va_arg(ap, t) (*(t *)((ap += __va_size(t)) - __va_size(t)))
#define va_end(v)

extern u32 *WmGetCommandBuffer4Arm7(void);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);

WMErrCode WMi_SendCommand(WMApiid id, u16 paramNum, ...)
{
    va_list vlist;
    s32 i;
    int result;
    u32 *tmpAddr;

    tmpAddr = WmGetCommandBuffer4Arm7();
    if (tmpAddr == 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    *(u16 *)tmpAddr = (u16)id;
    va_start(vlist, paramNum);
    for (i = 0; i < paramNum; i++) {
        tmpAddr[i + 1] = va_arg(vlist, u32);
    }
    va_end(vlist);

    DC_StoreRange(tmpAddr, 0x100);
    result = PXI_SendWordByFifo(10, (u32)tmpAddr, 0);
    (void)OS_SendMessage(&bufMsgQ, tmpAddr, 1);
    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }
    return WM_ERRCODE_OPERATING;
}
