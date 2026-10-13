/*
 * function: func_021E67C4
 * address: 0x021E67C4
 * packet: pkt_ov119_021E67C4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
typedef unsigned short u16;

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void func_021E67C4(void *p, int i)
{
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)((char *)p + i * 4 + 0x10bc)), (u16)(i + 15));
}
