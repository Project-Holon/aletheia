
/*
 * function: NVRAMi_WriteCallback
 * address:  0x020839E8
 * packet:   pkt_020839E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: the write sequence state machine, entered from the PXI
 * callback (tag 4) and from the retry alarm.  The DWARF names data and err
 * only; `seq` steps: 0 page write, 1 page written, 2 status read back,
 * 3 write disable, 4 software reset, 5 read status.  0x20B ticks is the retry
 * span.  nvramw and nvramTemp are relocated by name; the status byte at
 * nvramTemp[0] is read and written through the .bss section base
 * (0x02150EA0, NvramBss).  Closed (2026-09-28, sdk_arm9_3) by three
 * things together: `volatile` on NVRAMWork.arg (the switch head's second
 * &nvramw and the case-0 reload of arg[0]), the page-remainder MIN as an
 * inline function so arg[1] is read once, `result` preset ahead of the
 * tempSize computation with cb at function scope, and case 2's
 * `seq = 4` written after the NVRAMi_SoftwareReset call on both paths.
 *
 * symbols:
 *   nvramBss                 0x02150EA0  data
 *   nvramTemp                  0x02150EC0  data
 *   nvramw                     0x02150EE0  data
 *   NVRAMi_PageWrite           0x020844A8  arm
 *   NVRAMi_SoftwareReset       0x02084570  arm
 *   NVRAMi_WriteEnable         0x020842D8  arm
 *   NVRAMi_WriteDisable        0x02084304  arm
 *   NVRAMi_ReadStatusRegister  0x02084330  arm
 *   NVRAMi_AlarmHandler        0x02084288  arm
 *   OS_GetTick                 0x020870D0  arm
 *   OS_SetAlarm                0x0208738C  arm
 *   OS_WakeupThread            0x02085800  arm
 *   DC_InvalidateRange         0x020862B8  arm
 *   DC_StoreRange              0x020862D4  arm
 */

#include "../include/G_NvramBss.h"

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef int BOOL;
typedef u64 OSTick;
typedef void (*OSAlarmHandler)(void *);

typedef struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    struct OSiAlarm *prev;
    struct OSiAlarm *next;
    OSTick period;
    OSTick start;
} OSAlarm;

typedef struct _OSThreadQueue {
    struct _OSThread *head;
    struct _OSThread *tail;
} OSThreadQueue;

typedef enum NVRAMResult {
    NVRAM_RESULT_SUCCESS = 0,
    NVRAM_RESULT_BUSY,
    NVRAM_RESULT_ILLEGAL_PARAMETER,
    NVRAM_RESULT_SEND_ERROR,
    NVRAM_RESULT_INVALID_COMMAND,
    NVRAM_RESULT_ILLEGAL_STATUS,
    NVRAM_RESULT_FATAL_ERROR,
    NVRAM_RESULT_UNKNOWN
} NVRAMResult;

typedef enum NVRAMLock {
    NVRAM_LOCK_OFF = 0,
    NVRAM_LOCK_READ,
    NVRAM_LOCK_WRITE,
    NVRAM_LOCK_VERIFY
} NVRAMLock;

typedef void (*NVRAMCallback)(NVRAMResult result, void *arg);

typedef struct NVRAMWork {
    NVRAMLock lock;
    NVRAMCallback callback;
    void *callbackArg;
    OSAlarm alarm;
    OSTick tick;
    u32 seq;
    volatile u32 arg[3];
    OSThreadQueue queue;
} NVRAMWork;

/* nvram.o .bss from 0x02150EA0: nvramInitialized at +0, nvramTemp (32-byte
   aligned) at +0x20.  A direct read or write of nvramTemp goes through this
   section base; taking its address uses the nvramTemp symbol. */
typedef struct NvramBss NvramBss;

extern struct NvramBss nvramBss;
extern u32 nvramTemp[8];
extern NVRAMWork nvramw;

extern BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData);
extern BOOL NVRAMi_SoftwareReset(void);
extern BOOL NVRAMi_WriteEnable(void);
extern BOOL NVRAMi_WriteDisable(void);
extern BOOL NVRAMi_ReadStatusRegister(u8 *pData);
extern void NVRAMi_AlarmHandler(void *arg);
extern OSTick OS_GetTick(void);
extern void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(void *startAddr, u32 nBytes);

#define NVRAM_RETRY_SPAN 0x20B

static inline u32 MinU32(u32 a, u32 b)
{
    return (a < b) ? a : b;
}

void NVRAMi_WriteCallback(u32 data, BOOL err)
{
    NVRAMResult result;
    u16 pxiResult = (u16)(data & 0xFF);
    u16 tempSize;
    NVRAMCallback cb;

    result = NVRAM_RESULT_UNKNOWN;
    tempSize = (u16)(0x100 - (nvramw.arg[0] & 0xFF));
    tempSize = (u16)MinU32(nvramw.arg[1], tempSize);

    switch (nvramw.seq) {
    case 0:
        if (!err && pxiResult == 0) {
            if (NVRAMi_PageWrite(nvramw.arg[0], tempSize, (u8 *)nvramw.arg[2]) == 1) {
                nvramw.seq = 1;
                return;
            }
            result = NVRAM_RESULT_SEND_ERROR;
        } else if (err == 1) {
            result = NVRAM_RESULT_SEND_ERROR;
        } else if (pxiResult == 4) {
            result = NVRAM_RESULT_BUSY;
        }
        break;

    case 1:
        if (!err && pxiResult == 0) {
            nvramw.arg[0] += tempSize;
            nvramw.arg[1] -= tempSize;
            nvramw.arg[2] += tempSize;
            nvramw.tick = OS_GetTick();
            nvramw.seq = 5;
            OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, 0);
            return;
        } else if (err == 1) {
            result = NVRAM_RESULT_SEND_ERROR;
        } else {
            switch (pxiResult) {
            case 2:
                result = NVRAM_RESULT_ILLEGAL_PARAMETER;
                break;
            case 3:
                result = NVRAM_RESULT_INVALID_COMMAND;
                break;
            case 4:
                if (NVRAMi_PageWrite(nvramw.arg[0], tempSize, (u8 *)nvramw.arg[2]) == 1) {
                    return;
                }
                result = NVRAM_RESULT_SEND_ERROR;
                break;
            }
        }
        break;

    case 2:
        if (!err && pxiResult == 0) {
            if (*(u8 *)nvramBss.nvramTemp & 0x20) {
                if (NVRAMi_SoftwareReset() == 1) {
                    nvramw.seq = 4;
                    return;
                }
                nvramw.seq = 4;
                OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
                return;
            }
            if (!(*(u8 *)nvramBss.nvramTemp & 0x01)) {
                if (tempSize) {
                    if (NVRAMi_WriteEnable() == 1) {
                        nvramw.seq = 0;
                        return;
                    }
                    result = NVRAM_RESULT_SEND_ERROR;
                    break;
                }
                if (NVRAMi_WriteDisable() == 1) {
                    nvramw.seq = 3;
                    return;
                }
                nvramw.seq = 3;
                OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
                return;
            }
        } else if (!err && pxiResult != 4) {
            break;
        }
        nvramw.seq = 5;
        OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, 0);
        return;

    case 3:
        if (!err && pxiResult == 0) {
            result = NVRAM_RESULT_SUCCESS;
        } else if (err || pxiResult == 4) {
            if (NVRAMi_WriteDisable() == 1) {
                return;
            }
            nvramw.seq = 3;
            OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
            return;
        }
        break;

    case 4:
        if (!err && pxiResult == 0) {
            result = NVRAM_RESULT_ILLEGAL_STATUS;
        } else if (err || pxiResult == 4) {
            if (NVRAMi_SoftwareReset() == 1) {
                return;
            }
            nvramw.seq = 4;
            OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, (void *)4);
            return;
        }
        break;

    case 5:
        DC_InvalidateRange(nvramTemp, 32);
        if (NVRAMi_ReadStatusRegister((u8 *)nvramTemp) == 1) {
            nvramw.seq = 2;
            return;
        }
        nvramw.seq = 2;
        *(u8 *)nvramBss.nvramTemp = 1;
        DC_StoreRange(nvramTemp, 32);
        OS_SetAlarm(&nvramw.alarm, NVRAM_RETRY_SPAN, NVRAMi_AlarmHandler, 0);
        return;
    }

    nvramw.lock = NVRAM_LOCK_OFF;
    nvramw.seq = 0;
    if (nvramw.callback) {
        cb = nvramw.callback;
        nvramw.callback = 0;
        cb(result, nvramw.callbackArg);
    }
    OS_WakeupThread(&nvramw.queue);
}
