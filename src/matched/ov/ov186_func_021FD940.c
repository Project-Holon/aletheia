/*
 * function: BR_UTIL_SetHandlesAnimSeq
 * address: 0x021FD940
 * packet: pkt_ov186_021FD940
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Set the counter before narrowing value; its initialization splits the two shifts.
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
void BR_UTIL_SetHandlesAnimSeq(u8 *p,u32 value)
{
    int i;
    u16 narrow;
    i=0;
    narrow=value;
    for(;i<12;i++)CLACT_SetActorAnimSeq(*(struct Obj **)((u32)p+(u32)i*4+0x1f8),narrow);
}
