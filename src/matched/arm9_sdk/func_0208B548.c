/*
 * function: func_0208B548
 * address:  0x0208B548
 * packet:   pkt_0208B548
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MicCommonCallback (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   g_02152FE0                     0x02152FE0  data
 *
 * The DWARF lists (data, err); the body reads r1 and r2, so this is the
 * 3-argument PXI FIFO callback. The error path does not return. The
 * switch operand needs the (u16) cast; the plain mask swaps r5 and r6.
 */

#include "../include/G_DWCHttp.h"

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef enum MICResult {
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY,
    MIC_RESULT_ILLEGAL_PARAMETER,
    MIC_RESULT_SEND_ERROR,
    MIC_RESULT_INVALID_COMMAND,
    MIC_RESULT_ILLEGAL_STATUS,
    MIC_RESULT_FATAL_ERROR
} MICResult;

typedef void (*MICCallback)(MICResult result, void *arg);

/* mic.o .bss: micInitialized at +0, micWork (28 bytes) at +4 */
typedef struct MicBss {
    u16 micInitialized;
    u32 lock;
    MICCallback callback;
    void *callbackArg;
    MICResult commonResult;
    MICCallback full;
    void *fullArg;
    u16 *dst_buf;
} MicBss;

extern struct DWCHttp g_02152FE0;
#define micWork (*(MicBss *)&g_02152FE0)

void func_0208B548(int tag, u32 data, BOOL err)
{
    MICResult result;
    u16 command;

    if (err) {
        if (micWork.lock) {
            micWork.lock = 0;
        }
        if (micWork.callback) {
            MICCallback cb = micWork.callback;
            micWork.callback = 0;
            cb(MIC_RESULT_FATAL_ERROR, micWork.callbackArg);
        }
    }

    command = (u16)((data & 0x7f00) >> 8);
    switch ((u16)(data & 0xff)) {
    case 0:
        result = MIC_RESULT_SUCCESS;
        break;
    case 1:
        result = MIC_RESULT_INVALID_COMMAND;
        break;
    case 2:
        result = MIC_RESULT_ILLEGAL_PARAMETER;
        break;
    case 3:
        result = MIC_RESULT_ILLEGAL_STATUS;
        break;
    case 4:
        result = MIC_RESULT_BUSY;
        break;
    default:
        result = MIC_RESULT_FATAL_ERROR;
        break;
    }

    if (command == 0x51) {
        if (micWork.full) {
            micWork.full(result, micWork.fullArg);
        }
        return;
    }
    if (command == 0x40) {
        if (micWork.dst_buf) {
            *micWork.dst_buf = *(volatile u16 *)0x02FFFF94;
        }
    }
    if (micWork.lock) {
        micWork.lock = 0;
    }
    if (micWork.callback) {
        MICCallback cb = micWork.callback;
        micWork.callback = 0;
        cb(result, micWork.callbackArg);
    }
}
