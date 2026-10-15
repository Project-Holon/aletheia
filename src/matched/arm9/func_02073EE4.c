/*
 * function: NNS_SndStartTimer
 * address:  0x02073EE4
 * packet:   pkt_02073BF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gNNSSndSystem  0x0214E9FC  data
 *   SND_StopTimer  0x020894DC  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 */

#include "../include/G_St.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct G { u32 f0; u8 p4[0x24 - 4]; u32 f24; u32 f28; u32 f2c; };
extern struct St gNNSSndSystem;
extern void SND_StopTimer(u32, u32, u32, u32);
extern u32 SND_GetCurrentCommandTag(void);
extern void func_02089B38(u32);
extern void SND_WaitForCommandProc(u32);
void NNS_SndStartTimer(void) {
    struct G *g = ((struct G *)&gNNSSndSystem);
    u32 m;
    u32 r;
    if (g->f0 == 0) return;
    if ((int)g->f2c >= 0) m = 1u << g->f2c;
    else m = 0;
    SND_StopTimer(g->f24, g->f28, m, 0);
    r = SND_GetCurrentCommandTag();
    func_02089B38(1);
    SND_WaitForCommandProc(r);
}
