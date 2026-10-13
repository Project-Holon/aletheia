/*
 * function: func_021FF914
 * address:  0x021FF914
 * packet:   pkt_021FF914
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *

 *
 * Tail call into CLACT_SetActorAnimSeq with the object at +0xd0c and a u16 value.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void func_021FF914(u32 *p, u32 v)
{
    CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p[2] + 0xd0c)), (u16)v);
}
