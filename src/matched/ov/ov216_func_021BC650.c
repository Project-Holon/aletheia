/*
 * function: func_021BC650
 * address: 0x021BC650
 * packet: pkt_ov216_021BC650
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_021BC614 0x021BC614 thumb ov216
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj00366.h"
typedef unsigned int   u32;
struct Obj;
extern void *func_021BCA38(char *p);
extern unsigned func_021BC614(unsigned short *p, unsigned manager, unsigned *r, short x, short y, unsigned char z, unsigned char a, unsigned char b, unsigned short flag);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void func_021BC650(char *p)
{
    void *q=func_021BCA38(((struct Obj00366 *)p)->f50);
    void *a=(void *)func_021BC614((short unsigned int *)p,(unsigned int)q,(unsigned int *)(p+0x80),128,120,0,0,2,0);
    ((struct Obj00366 *)p)->f264=a;
    CLACT_SetActorPaletteOffset(a,0,1);
    ((struct Obj00366 *)p)->f268=(void *)func_021BC614((short unsigned int *)p,(unsigned int)q,(unsigned int *)(p+0x5c),96,120,0,1,2,0);
}
