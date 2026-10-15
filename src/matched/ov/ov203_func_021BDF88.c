/*
 * function: DEMO3D_GRAPHIC_SetLightVector
 * address:  0x021BDF88
 * packet:   pkt_021BDF88
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VEC_Fx16Normalize 0x0207CDB8 arm
 *   G3D_LIGHT_SetSlotColor 0x02048CA4 arm
 */
#include "../include/Obj25310.h"

extern void VEC_Fx16Normalize(int, void *);
typedef unsigned int   u32;
struct LightSlot;
struct Rgb555;
extern void G3D_LIGHT_SetSlotColor(struct LightSlot *slots, u32 i, struct Rgb555 *in);

void DEMO3D_GRAPHIC_SetLightVector(char *p, int a, int b)
{
    int buf[2];
    VEC_Fx16Normalize(b, buf);
    G3D_LIGHT_SetSlotColor(((struct Obj25310 *)p)->fC, a, (struct Rgb555 *)buf);
}
