/*
 * function: TOUCHBAR_SetButtonToggle
 * address:  0x021B69D8
 * packet:   pkt_ov067_021B69D8
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores +0x2A (flag set) or +0x26 (flag clear) into the word at +8, then
 * passes the object at +0 and the low halfword of +8 to CLACT_SetActorAnimSeq.
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   (none)
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct S {
    struct Obj *f0;
    u32 f4;
    u32 f8;
    char pad[0x26 - 0xC];
    u16 f26;
    u16 f28;
    u16 f2a;
};
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void TOUCHBAR_SetButtonToggle(struct S *p, u32 v)
{
    if (v != 0)
        p->f8 = p->f2a;
    else
        p->f8 = p->f26;
    CLACT_SetActorAnimSeq(p->f0, (u16)p->f8);
}
