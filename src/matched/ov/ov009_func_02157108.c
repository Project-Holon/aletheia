/*
 * function: DWC_RAPCOMMON_RunDwcInit
 * address:  0x02157108
 * packet:   pkt_ov009_02157108
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A1C8C  0x021A1C8C  data  ov009  a1
 *   DWC_RAPCOMMON_CreateHeap  0x02157048  thumb  ov009
 *   DWC_InitForProduction  0x02059F6C  arm
 *   DWC_RAPCOMMON_DestroyHeap  0x021570B8  thumb  ov009
 *   DWC_RAPCOMMON_Alloc  0x02156F5C  thumb  ov009
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb  ov009
 *   _pRapHeap  0x021A8268  data
 */

#include "../include/G_Obj.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {
    u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; u32 f14; u32 f18; u32 f1C; u16 f20;
} Obj;
extern struct Obj *_pRapHeap;
extern char d_021A1C8C[];
extern void DWC_RAPCOMMON_CreateHeap(u32 a, u32 b);
extern int DWC_InitForProduction(void *a, u32 b, void *c, void *d);
extern void DWC_RAPCOMMON_DestroyHeap(void);
extern u32 DWC_RAPCOMMON_Alloc(u32 a, u32 b, u32 c);
extern void DWC_RAPCOMMON_Free(u32 a, void *p, int b);
int DWC_RAPCOMMON_RunDwcInit(u16 a)
{
    int r;
    DWC_RAPCOMMON_CreateHeap(a, 0x40000);
    r = DWC_InitForProduction(d_021A1C8C, 0x4952414A, DWC_RAPCOMMON_Alloc, DWC_RAPCOMMON_Free);
    DWC_RAPCOMMON_DestroyHeap();
    return r;
}
