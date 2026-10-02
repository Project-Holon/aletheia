/*
 * function: func_021D88E8
 * address: 0x021D88E8
 * packet: pkt_ov093_021D88E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int,int);

void func_021D88E8(int a, int b, int c, int *d)
{
    int k=2; if(c==func_021D775C(k) && d[3]!=0) func_021D7704(0x35,k<<10);
}
