/*
 * function: func_021DB2F8
 * address: 0x021DB2F8
 * packet: pkt_ov093_021DB2F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DB318 0x021DB318 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021DB318(int,void *,int);

void func_021DB2F8(int a, void *b, int c)
{
    if (c == func_021D775C(2)) func_021DB318(a, b, c);
}
