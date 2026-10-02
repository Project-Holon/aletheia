/*
 * function: func_021D8940
 * address: 0x021D8940
 * packet: pkt_ov093_021D8940
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D8974 0x021D8974 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D8974(void *, int, int, int *);

void func_021D8940(void *a, int b, int c, int *d)
{
    if(c==func_021D775C(2)) func_021D8974(a,b,c,d);
}
