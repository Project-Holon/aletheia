/*
 * function: func_021EAF00
 * address:  0x021EAF00
 * packet:   pkt_ov093_021EAF00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj21579.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BTL_CLIENT_IsMainStepActive(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021EAF00(u8 *p, int a)
{
    if (BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj21579 *)p)->f4) == 0)
        GFL_USE_PlaySeDefaultVolume(a);
}
