/*
 * function: func_021B70B8
 * address:  0x021B70B8
 * packet:   pkt_ov071_021B70B8
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * CLACT_DeleteActor with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */

struct Obj;
void func_021B70B8(void **p)
{
    void CLACT_DeleteActor(struct Obj *p);
    CLACT_DeleteActor(*p);
}
