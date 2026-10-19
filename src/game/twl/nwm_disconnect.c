/*
 * file:     nwm_disconnect.c
 * unit:     yes
 * function: NWM_Disconnect
 * address:  0x02703424
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_disconnect.o
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

extern u32 NWMi_CheckState(u32 n, ...);
extern u32 NWMi_GetSystemWork(void);
extern void DC_InvalidateRange(u8 *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(unsigned short apiid, unsigned short argc, ...);

u32 NWM_Disconnect(u32 callback) {
    u32 r;
    u32 busy;
    TwlWork *w;

    r = NWMi_CheckState(1, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    w = (struct TwlWork *)NWMi_GetSystemWork();
    if (w != 0) {
        DC_InvalidateRange(w->busy + 9, 1);
        busy = (w->busy[9] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(9, callback);
    r = NWMi_SendCommand(9, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
