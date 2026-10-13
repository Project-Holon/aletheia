/*
 * function: UNION_SUBDISP_SelectAppeal
 * address:  0x021F0628
 * packet:   pkt_ov031_021F0628
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The store to +0x30 is written in both arms of an if/else (keeps the
 * empty `b` to the next instruction), and the loop condition is a
 * `? 1 : 0` ternary (keeps the entry branch to the bottom test).
 *
 * symbols:
 *   sUnionSubdispAppealNo     0x021F1038  data  a1
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 */
#include "../include/Obj06133.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 sUnionSubdispAppealNo[];
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

void UNION_SUBDISP_SelectAppeal(char *p, int sel)
{
    int i;
    int v;

    v = sUnionSubdispAppealNo[sel];
    if (v == ((struct Obj06133 *)p)->f30)
        ((struct Obj06133 *)p)->f30 = 0;
    else
        ((struct Obj06133 *)p)->f30 = v;
    for (i = 0; (i <= 4) ? 1 : 0; i++) {
        if (i == sel && ((struct Obj06133 *)p)->f30 != 0)
            CLACT_SetActorPaletteOffset((struct Obj *)(*(u32 *)(p + 0x18 + i * 4)), 1, 1);
        else
            CLACT_SetActorPaletteOffset((struct Obj *)(*(u32 *)(p + 0x18 + i * 4)), 0, 1);
    }
}
