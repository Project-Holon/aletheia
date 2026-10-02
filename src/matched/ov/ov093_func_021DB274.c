/*
 * function: func_021DB274
 * address: 0x021DB274
 * packet: pkt_ov093_021DB274
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DB254 0x021DB254 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021DB254(int,void *,int,int *);

void func_021DB274(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021DB254(a, b, c, d);
}
