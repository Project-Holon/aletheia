/*
 * function: func_021C52CC
 * address: 0x021C52CC
 * packet: pkt_ov127_021C52CC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4A54 0x021C4A54 thumb ov127
 */
typedef unsigned short u16;
struct pair { u16 a,b; };
extern struct pair func_021C4A54(struct pair,int);
struct pair func_021C52CC(struct pair p,int i)
{
 return func_021C4A54(p,i);
}
