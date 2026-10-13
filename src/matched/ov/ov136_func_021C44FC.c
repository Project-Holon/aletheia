/*
 * function: func_021C44FC
 * address:  0x021C44FC
 * packet:   pkt_ov136_021C44FC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C44FC 0x021C44FC thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 */
#include "../include/Obj01065.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Chan02021FD8;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
void func_021C44FC(u8 *p)
{
    PALANM_BlendChannel((struct Chan02021FD8 *)(*(u32 *)&((struct Obj01065 *)p)->f38), 0, (u16)(p[0x1b] + 0x21), 1, 0, 0x7FFF);
    p[0x19] = 0;
    p[0x18] = 0;
}
