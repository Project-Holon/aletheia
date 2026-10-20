/*
 * file:     nwm_close.c
 * unit:     yes
 * function: NWM_Close
 * address:  0x02702FE8
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_close.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 */
#include "../types.h"

#include "nwm_system.h"
extern void DC_InvalidateRange(u32, u32);
#include "nwm_cmd.h"

u32 NWM_Close(void *callback) {
    u32 r = NWMi_CheckState(1, 3);
    uptr base;
    u32 busy;
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        DC_InvalidateRange(ptr + 6, 1);
        if (*(unsigned char *)(*(u32 *)(base + 0x2278) + 6) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(6, (uptr)callback);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(6, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
