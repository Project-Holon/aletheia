/*
 * function: func_021EAAC4
 * address:  0x021EAAC4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *
 * Walk 0x1c 8-byte records at p+0x2c+0x94, release each, then
 *   release the pool.  Unsigned counter for the image's blo.
 */
#include "../include/Obj18507.h"


struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021EAAC4(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1c; i++)
        func_020452E8((struct Descriptor *)(*(int *)(((struct Obj18507 *)p)->f2C + i * 8 + 0x94)));
    BMP_WIN_Exit();
}
