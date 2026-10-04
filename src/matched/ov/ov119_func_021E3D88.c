/*
 * function: func_021E3D88
 * address:  0x021E3D88
 * packet:   pkt_ov119_021E3D88
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02007A18  0x02007A18  thumb
 *   func_021E3D04  0x021E3D04  thumb  ov119
 */
#include "../include/Obj13914.h"

typedef unsigned int   u32;
struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern unsigned char func_021E3D04(void *mon, unsigned int heap);

void func_021E3D88(char *p, int box, unsigned char *out)
{
    unsigned char i;

    for (i = 0; i < 30; i++)
        out[i] = func_021E3D04(func_02007A18(((struct Obj13914 *)p)->f828, box, i), ((struct Obj13914 *)p)->f5F4);
}
