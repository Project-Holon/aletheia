/*
 * file:     nwm_connect.c
 * unit:     yes
 * function: NWM_Connect
 * address:  0x027032E0
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_connect.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommandDirect  0x02703B24  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 *   DAT_027341cc                 0x027341CC  data
 */
#include "../types.h"

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *busy;
} TwlWork;

typedef struct TwlMsg {
    u16 len;
    u8 idx;
    u8 pad;
    u32 buf;
} TwlMsg;

extern u32 NWMi_CheckState(unsigned int n, ...);
extern unsigned int NWMi_GetSystemWork(void);
extern void DC_InvalidateRange(u8 *, u32);
extern void DC_StoreRange(const void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(unsigned int command, unsigned int length);
extern u32 DAT_027341cc[];

u32 NWM_Connect(u32 callback, u32 authMode, const u16 *bssDesc) {
    u32 r;
    u32 busy;
    u32 len;
    TwlWork *w;
    TwlMsg msg;

    r = NWMi_CheckState(1, 3);
    if (r != 0 && r != 2) {
        return r;
    }
    w = (struct TwlWork *)NWMi_GetSystemWork();
    if (w != 0) {
        DC_InvalidateRange(w->busy + 8, 1);
        busy = (w->busy[8] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    if (bssDesc == 0) {
        return 5;
    }
    len = bssDesc[0];
    if (len > 0x200) {
        return 5;
    }
    if (authMode >= 3) {
        return 5;
    }
    if (bssDesc[5] == 0) {
        return 5;
    }
    DC_StoreRange(bssDesc, len * 2);
    NWMi_SetCallbackTable(8, callback);
    msg.buf = (u32)DAT_027341cc;
    msg.len = 8;
    msg.idx = authMode;
    MI_CpuCopy8(bssDesc, DAT_027341cc, bssDesc[0]);
    DC_StoreRange((void *)msg.buf, 0x200);
    DC_StoreRange(&msg, 8);
    r = NWMi_SendCommandDirect((unsigned int)(&msg), 8);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
