/*
 * function: MB_SEQ_SetActorAnim
 * address:  0x021C66A0
 * packet:   pkt_ov136_021C66A0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq        0x0204B878  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void MB_SEQ_SetActorAnim(u8 *p, int i, u32 v)
{
    CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x1F0), (u16)v);
}
