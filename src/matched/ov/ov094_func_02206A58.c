/*
 * function: func_02206A58
 * address:  0x02206A58
 * packet:   pkt_ov094_02206A58
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   PALANM_CopyToSlot  0x020215BC  thumb  arm9
 */
#include "../include/Obj21803.h"

typedef unsigned short u16;
extern int func_021F86E0(void);
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

void func_02206A58(char *p)
{
    if (((struct Obj21803 *)p)->f23C == 1)
        PALANM_CopyToSlot((struct PalAnmSlot *)func_021F86E0(), (u16 *)(p + 0x284), 1, 0x20, 0x20);
}
