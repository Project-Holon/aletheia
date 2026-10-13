/*
 * function: func_021B7068
 * address:  0x021B7068
 * packet:   pkt_ov071_021B7068
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to CLACT_DeleteActor.  Address also resident in ov021;
 * region-qualified packet id.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */

struct Obj;
void func_021B7068(void *p)
{
    void CLACT_DeleteActor(struct Obj *p);
    CLACT_DeleteActor(p);
}
