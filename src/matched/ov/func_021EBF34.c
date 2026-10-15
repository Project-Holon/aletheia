/*
 * function: BOX2_SEQ_DeleteActorSlot
 * address:  0x021EBF34
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *
 * Release slot i of the 0x9E74 array when non-null.
 *   CLOSES the register-order residue: `struct S { char pad[0x9E74]; int arr[1]; }`
 *   with `p->arr[i]` gives the image's r4 = p+0x9E74 / r5 = i*4; a plain
 *   `char *p` plus `p + i * 4 + 0x9E74` puts the index in r1 and the constant
 *   in r5 instead.
 */


struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
struct S { char pad[0x9E74]; int arr[1]; };
void BOX2_SEQ_DeleteActorSlot(struct S *p, int i)
{
    if (p->arr[i] != 0) {
        CLACT_DeleteActor((struct Obj *)p->arr[i]);
        p->arr[i] = 0;
    }
}
