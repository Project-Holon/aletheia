/*
 * function: func_021B6FD8
 * address:  0x021B6FD8
 * packet:   pkt_ov071_021B6FD8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to CLACT_DeleteActor.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */

struct Obj;
void func_021B6FD8(void *p)
{
    void CLACT_DeleteActor(struct Obj *p);
    CLACT_DeleteActor(p);
}
