/*
 * unit: yes
 * function: func_021D8B50, func_021D8B78
 * address: 0x021D8B50
 * packet: pkt_ov093_021D8B50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F07C0 0x021F07C0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern unsigned char d_021F07C0[];
extern int func_021D775C(int);
extern int func_021D7AD4(int);
extern void func_021D7704(int,int);

void func_021D8B50(int a, int b, int c)
{
    if(c==func_021D775C(4) && func_021D7AD4(func_021D775C(0x38))==2) func_021D7704(0x35,0xC00);
}

void *func_021D8B78(int *p)
{
    *p = 1;
    return d_021F07C0;
}
