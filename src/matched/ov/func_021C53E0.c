/*
 * function: ZUKAN_DETAIL_FORM_DeleteIconActor
 * address:  0x021C53E0
 * packet:   pkt_021C53E0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *
 * Forwards its second argument to CLACT_DeleteActor and then the first to
 * CLACT_ReleaseCharacter.
 */

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);

void ZUKAN_DETAIL_FORM_DeleteIconActor(int a, int b)
{
    CLACT_DeleteActor((struct Obj *)b);
    CLACT_ReleaseCharacter(a);
}
