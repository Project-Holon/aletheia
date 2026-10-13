/*
 * function: BTLV_CORE_SetCounterDisplay
 * address:  0x021EAE74
 * packet:   pkt_ov093_021EAE74
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAE98  0x021EAE98  thumb  ov093
 */
#include "../include/Obj07847.h"
typedef unsigned int u32;

extern void func_021EAE98(void *a, void *b);

void BTLV_CORE_SetCounterDisplay(char *p, u32 a, u32 b)
{
    ((struct Obj07847 *)p)->f160 = a;
    ((struct Obj07847 *)p)->f164 = b;
    ((struct Obj07847 *)p)->f16C = 0;
    func_021EAE98(((struct Obj07847 *)p)->f180, p + 0x160);
}
