/*
 * function: func_021DD314
 * address:  0x021DD314
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Two ranges: below 30 forward all, at or above rebase.
 * The tested field is unsigned: a signed `b` compiles the inverted
 * branch as blo where the image has bhs.
 */
#include "../include/Obj18443.h"
#include "../include/Obj18444.h"

typedef signed int     s32;
typedef unsigned int   u32;
struct Party;
extern void func_02007664(void *save, u32 box, u32 slot);
extern u32 func_0201A9C8(struct Party *p, s32 idx);

void func_021DD314(char **p, int a, unsigned b)
{
    if (b < 0x1eU)
        func_02007664((void *)(((struct Obj18443 *)(*p))->f4), a, b);
    else
        func_0201A9C8((struct Party *)(((struct Obj18444 *)(*p))->f8), b - 0x1eU);
}
