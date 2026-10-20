/*
 * file:     nwm_setpowersave.c
 * unit:     yes
 * function: NWM_SetPowerSaveMode
 * address:  0x027035F4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_setpowersave.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 */
#include "../types.h"

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *busy;
} TwlWork;

#include "nwm_system.h"
#include "../arm9/os_cache.h"
#include "nwm_cmd.h"

u32 NWM_SetPowerSaveMode(void *callback, u32 powerSave) {
    u32 r;
    u32 busy;
    TwlWork *w;

    r = NWMi_CheckState(2, 3, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    w = (struct TwlWork *)NWMi_GetSystemWork();
    if (w != 0) {
        DC_InvalidateRange(w->busy + 14, 1);
        busy = (w->busy[14] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(14, (u32)callback);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(14, 1, powerSave);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
