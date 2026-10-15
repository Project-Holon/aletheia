/*
 * function: BOX2_SEQ_SetActorAnimSeq
 * address:  0x021EBFA8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *
 * Stop and re-issue slot i of the 0x9E74 array; the word is
 *   re-read for the second call.  Writing the array offset before the index
 *   term is what puts the pool constant in r2 and the index in r6.
 */


typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v)
{
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned short)v);
}
