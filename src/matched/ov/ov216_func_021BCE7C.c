/*
 * function: func_021BCE7C
 * address:  0x021BCE7C
 * packet:   pkt_021BCE7C
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);

void func_021BCE7C(void *p, unsigned short value)
{
    CLACT_SetActorAnimSeq(p, value);
    CLACT_RestartActorAnim(p);
}
