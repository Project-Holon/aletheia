/*
 * file:     nwm_cmd.c
 * unit:     yes
 * function: NWMi_SetCallbackTable, NWMi_SetReceiveCallbackTable, NWMi_SendCommand, NWMi_SendCommandDirect, NwmGetCommandBuffer4Arm7
 * address:  0x02703A34
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_cmd.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
#include "../types.h"

#include "nwm_system.h"
#include "../arm9/os_cache.h"
#include "../arm9/pxi_fifo.h"
#include "../sdk_os.h"

#include "../arm9/os_message.h"
extern void MI_CpuCopy8(const void *, void *, u32);
void NWMi_SetCallbackTable(u32 index, NWMCallbackFunc callback);
void NWMi_SetReceiveCallbackTable(u32 index, NWMCallbackFunc callback);
u32 NWMi_SendCommand(u16 apiid, u16 argc, ...);
u32 NWMi_SendCommandDirect(void *command, u32 length);
u16 *NwmGetCommandBuffer4Arm7(void);

void NWMi_SetCallbackTable(u32 index, NWMCallbackFunc callback) {
    struct NwmSystemWork *base = NWMi_GetSystemWork();
    base->callback[index] = callback;
}

void NWMi_SetReceiveCallbackTable(u32 index, NWMCallbackFunc callback) {
    struct NwmSystemWork *base = NWMi_GetSystemWork();
    base->recvCallback[index] = callback;
}

u32 NWMi_SendCommand(u16 apiid, u16 argc, ...) {
    u32 ret;
    s32 res;
    char *ap;
    s32 i;
    s32 n;
    u16 *msg;
    struct NwmSystemWork *base;

    base = NWMi_GetSystemWork();
    msg = NwmGetCommandBuffer4Arm7();
    if (msg == 0) {
        return 6;
    }
    msg[0] = apiid;
    ap = (char *)(((uptr)&argc & ~3) + 4);
    n = argc;
    for (i = 0; i < n; i++) {
        ((u32 *)msg)[1 + i] = *(u32 *)((ap += 4) - 4);
    }
    DC_StoreRange(msg, 0x100);
    res = PXI_SendWordByFifo(0x16, (uptr)msg, 0);
    OS_SendMessage((struct OSMessageQueue *)base->cmdQueue, msg, 1);
    ret = 6;
    if (res >= 0) {
        ret = 2;
    }
    return ret;
}

u32 NWMi_SendCommandDirect(void *command, u32 length) {
    struct NwmSystemWork *base = NWMi_GetSystemWork();
    u16 *msg = NwmGetCommandBuffer4Arm7();
    s32 res;
    u32 ret;

    if (msg == 0) {
        return 6;
    }
    MI_CpuCopy8(command, msg, length);
    DC_StoreRange(msg, length);
    res = PXI_SendWordByFifo(0x16, (uptr)msg, 0);
    OS_SendMessage((struct OSMessageQueue *)base->cmdQueue, msg, 1);
    ret = 6;
    if (res >= 0) {
        ret = 2;
    }
    return ret;
}

u16 *NwmGetCommandBuffer4Arm7(void) {
    u16 *msg = 0;
    struct NwmSystemWork *base = NWMi_GetSystemWork();

    do {
        if (OS_ReceiveMessage((struct OSMessageQueue *)base->cmdQueue, (void **)(&msg), 0) == 0) {
            return 0;
        }
        DC_InvalidateRange(base, 0x2000);
        DC_InvalidateRange(msg, 2);
        if (!(*msg & 0x8000)) {
            OS_SendMessage((struct OSMessageQueue *)base->cmdQueue, msg, 1);
            msg = 0;
        }
    } while (msg == 0);
    return msg;
}
