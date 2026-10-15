/*
 * function: WF2DMAP_OBJ_OffsetPos
 * address: 0x021C4A54
 * packet: pkt_ov127_021C4A54
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sWf2dmapStepDelta 0x021C6014 data a4
 */
typedef signed short s16;
struct pair { s16 a,b; };
struct delta { signed char a,b; };
extern struct delta sWf2dmapStepDelta;
struct pair WF2DMAP_OBJ_OffsetPos(struct pair p,int i)
{
 struct pair *v=&p;
 v->a += *(signed char *)((unsigned)&sWf2dmapStepDelta.a+i*2);
 v->b += *(signed char *)((unsigned)&sWf2dmapStepDelta.b+i*2);
 return p;
}
