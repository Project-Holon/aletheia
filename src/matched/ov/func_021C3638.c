/*
 * function: func_021C3638
 * address:  0x021C3638
 * packet:   pkt_021C3638
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *   (none)

 * Releases the three handles at +0x2C, +0x20 and +0x14.
 */
#include "../include/Obj09210.h"


struct Descriptor;
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021C3638(void *unused, char *p, void *a2)
{
    BMP_Delete((struct Obj020437AC *)(((struct Obj09210 *)p)->f2C));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj09210 *)p)->f20));
    func_020307B0((void *)(((struct Obj09210 *)p)->f14));
}

