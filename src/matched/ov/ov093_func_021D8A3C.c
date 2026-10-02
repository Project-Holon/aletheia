/*
 * unit: yes
 * function: func_021D8A3C, func_021D8A58
 * address: 0x021D8A3C
 * packet: pkt_ov093_021D8A3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0650 0x021F0650 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern unsigned char d_021F0650[];
extern int func_021D775C(int);
extern void func_021D7704(int,int);

void func_021D8A3C(int a, int b, int c)
{
    if(c==func_021D775C(3)) func_021D7704(0x35,0x14CD);
}

void *func_021D8A58(int *p)
{
    *p = 1;
    return d_021F0650;
}
