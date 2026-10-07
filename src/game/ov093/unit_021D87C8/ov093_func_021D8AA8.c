/*
 * function: func_021D8AA8
 * address: 0x021D8AA8
 * packet: pkt_ov093_021D8AA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
typedef unsigned char  u8;
extern int func_021C8288(u8 *p);
extern void func_021D7704(int,int);

void func_021D8AA8(int a, int b, int c)
{
    if(c==func_021D775C(4) && func_021C8288((u8 *)b)==3) func_021D7704(0x35,0xCCD);
}
