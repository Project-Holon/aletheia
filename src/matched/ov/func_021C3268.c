/*
 * function: func_021C3268
 * address:  0x021C3268
 * packet:   pkt_021C3268
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Clears +0x10 and releases the two handles at +8 and +0xC.
 */
#include "../include/Obj09209.h"


struct Descriptor;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);

void func_021C3268(void *unused, char *p, void *a2)
{
    ((struct Obj09209 *)p)->f10 = 0;
    func_0201C6EC((struct PrintSys *)(((struct Obj09209 *)p)->f8));
    func_020452E8((struct Descriptor *)(((struct Obj09209 *)p)->fC));
}

