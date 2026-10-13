/*
 * function: func_02185824
 * address:  0x02185824
 * packet:   pkt_02185824
 * region:   ov219
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   d_02185DD4    0x02185DD4 data ov219
 */
#include "../include/Obj10976.h"

typedef unsigned int   u32;
struct LightSet;
struct LightSlot;
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
struct LightSlot;
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern char d_02185DD4[];

void func_02185824(char *p)
{
    ((struct Obj10976 *)p)->fC370 = G3D_LIGHT_CreateSlots((const struct LightSet *)d_02185DD4, (unsigned short)((struct Obj10976 *)p)->f0);
    G3D_LIGHT_ApplySlots(((struct Obj10976 *)p)->fC370);
}
