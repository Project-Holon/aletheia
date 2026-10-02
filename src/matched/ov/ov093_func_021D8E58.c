/*
 * function: func_021D8E58
 * address: 0x021D8E58
 * packet: pkt_ov093_021D8E58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D8E1C 0x021D8E1C thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D8E1C(int, void *, int, int *);
void func_021D8E58(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021D8E1C(a, b, c, d);
}
