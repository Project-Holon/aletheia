/*
 * function: func_021D890C
 * address: 0x021D890C
 * packet: pkt_ov093_021D890C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
extern int func_0201C1E8(int a);
extern void func_021D7704(int,int);

void func_021D890C(int a, int b, int c, int *d)
{
    if(c==func_021D775C(3) && d[3]!=0 && func_0201C1E8((unsigned short)func_021D775C(0x12))==1) func_021D7704(0x35,0x800);
}
