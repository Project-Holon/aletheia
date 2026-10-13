/*
 * function: func_021BC43C
 * address:  0x021BC43C
 * packet:   pkt_ov216_021BC43C
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021BC43C in ov099; the ov216 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10945.h"

typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);

void func_021BC43C(void *unused, char *p)
{
    CLACT_ReleaseCellAnim(((struct Obj10945 *)p)->f8);
    CLACT_ReleaseCharacter(((struct Obj10945 *)p)->f4);
    CLACT_ReleasePalette(((struct Obj10945 *)p)->f0);
}
