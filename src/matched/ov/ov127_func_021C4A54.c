/*
 * function: func_021C4A54
 * address: 0x021C4A54
 * packet: pkt_ov127_021C4A54
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C6014 0x021C6014 data a4
 */
typedef signed short s16;
struct pair { s16 a,b; };
struct delta { signed char a,b; };
extern struct delta d_021C6014;
struct pair func_021C4A54(struct pair p,int i)
{
 struct pair *v=&p;
 v->a += *(signed char *)((unsigned)&d_021C6014.a+i*2);
 v->b += *(signed char *)((unsigned)&d_021C6014.b+i*2);
 return p;
}
