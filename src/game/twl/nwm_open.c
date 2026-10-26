/*
 * file:     nwm_open.c
 * unit:     yes
 * function: NWM_Open
 * address:  0x02702F38
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_open.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 */
#include "../types.h"

#include "nwm_init.h"
#include "nwm_system.h"
extern void DC_InvalidateRange(void *, u32);
#include "nwm_cmd.h"

u32 NWM_Open(NWMCallbackFunc callback) {
    u32 r;
    struct NwmSystemWork *base;
    u32 busy;
    if (NWMi_CheckEnableFlag() == 0) {
        return 7;
    }
    r = NWMi_CheckState(1, 2);
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        struct NwmStatus *ptr = base->status;
        busy = 1;
        DC_InvalidateRange(&ptr->busy[5], 1);
        if (base->status->busy[5] != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(5, callback);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(5, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
