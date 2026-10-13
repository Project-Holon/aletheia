/*
 * function: func_021C0C00
 * address:  0x021C0C00
 * packet:   pkt_021C0C00
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   (none)
 *
 * Calls 0x0204B3B4 on the second argument, then 0x0204A8D4 on the first.
 */

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);

void func_021C0C00(void *a, void *b)
{
    CLACT_DeleteActor(b);
    CLACT_ReleaseCharacter((u32)a);
}
