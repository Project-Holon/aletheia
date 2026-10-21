/*
 * file:     nwm_sendframe.c
 * unit:     yes
 * function: NWM_SendFrame, NWMi_AddMACHeader
 * address:  0x027036A0
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_sendframe.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
#include "../types.h"

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *buf;
} TwlWork;

#include "nwm_system.h"
#include "../arm9/os_system.h"
#include "../arm9/os_cache.h"
#include "nwm_cmd.h"
extern void MI_CpuCopy8(u32, u32, u32);
void NWMi_AddMACHeader(u32 destMac, u32 srcMac, u8 *frame, u32 length);

u32 NWM_SendFrame(void *callback, u32 destMac, u8 *frame, u32 length) {
    TwlWork *w;
    u32 r;
    u32 saved;

    w = (struct TwlWork *)NWMi_GetSystemWork();
    r = NWMi_CheckState(1, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    saved = OS_DisableInterrupts();
    if (length > 0x5F2) {
        OS_RestoreInterrupts(saved);
        return 5;
    }
    DC_StoreRange(frame, length);
    NWMi_AddMACHeader(destMac, (uptr)(w->buf + 0x40), frame, length);
    DC_StoreRange(frame, 0xE);
    r = NWMi_SendCommand(0xB, 3, (uptr)callback, frame, length);
    if (r == 0) {
        return 2;
    }
    OS_RestoreInterrupts(saved);
    return r;
}

void NWMi_AddMACHeader(u32 destMac, u32 srcMac, u8 *frame, u32 length) {
    if (length < 0xE) {
        return;
    }
    MI_CpuCopy8(destMac, (uptr)frame, 6);
    MI_CpuCopy8(srcMac, (uptr)(frame + 6), 6);
}
