/*
 * function: DWC_RAPCOMMON_DestroySubHeap
 * address:  0x02156ED0
 * packet:   pkt_ov009_02156ED0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapHeap  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   DWC_RAPCOMMON_ReleaseSubHeap  0x02156F14  thumb  ov009
 */

#include "../include/G_Obj.h"

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

extern struct Obj *_pRapHeap;
extern char d_021A1C78[];
extern char d_021A1C7C[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern void DWC_RAPCOMMON_ReleaseSubHeap(void);

void DWC_RAPCOMMON_DestroySubHeap(void)
{
    if (_pRapHeap == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (_pRapHeap->f14 != 0) {
        GFL_NET_STATE_SetError(0, 0, 0, 0x3EE);
        _pRapHeap->f1C = 1;
        return;
    }
    DWC_RAPCOMMON_ReleaseSubHeap();
}
