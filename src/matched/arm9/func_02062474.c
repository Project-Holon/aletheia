/*
 * function: NNSi_GfdInitPlttVramManager
 * address:  0x02062474
 * packet:   pkt_02062474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146BB0       0x02146BB0  data
 *   NNS_GfdDefaultFuncAllocPlttVram       0x020A8148  data
 *   NNS_GfdDefaultFuncFreePlttVram       0x020A814C  data
 *   NNSi_GfdInitPlttVramHeap    0x020625D8  arm
 *   NNS_GfdAllocPlttVram    0x020624C8  arm
 *   NNS_GfdFreePlttVram    0x02062594  arm

 * Blocking class: evidence (`literal`/`label`).  Every concrete byte is right; the
 * one unresolved site is the ABS32 for the data object at 0x020624C8 at 0x020624B8
 * (the pool word that installs the descriptor's function pointer).  0x020624C8 is
 * named by this pool word only -- nothing branches to it and no other pool
 * repeats it -- so `literal` discards its only witness and `label` does not
 * apply.  Every other site of this file resolves: 0x02146BB0 `literal x20`,
 * 0x020A8148 `literal x15`, 0x02062594 `label x5` and 0x020A814C `literal x15`.
 */

#include "../include/G_Hdr02062474.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern struct Hdr02062474 g_02146BB0;
extern u32 NNS_GfdDefaultFuncAllocPlttVram;
extern u32 NNS_GfdDefaultFuncFreePlttVram;
extern void NNSi_GfdInitPlttVramHeap(void);
extern u32 NNS_GfdAllocPlttVram(u32 size, u32 flag);
extern int NNS_GfdFreePlttVram(u32 id);

void NNSi_GfdInitPlttVramManager(u32 a, u32 b, u32 c, u32 d)
{
    g_02146BB0.f08 = a;
    g_02146BB0.f0c = b;
    g_02146BB0.f10 = c;
    NNSi_GfdInitPlttVramHeap();
    if (d == 0) {
        return;
    }
    NNS_GfdDefaultFuncAllocPlttVram = (u32)NNS_GfdAllocPlttVram;
    NNS_GfdDefaultFuncFreePlttVram = (u32)NNS_GfdFreePlttVram;
}
