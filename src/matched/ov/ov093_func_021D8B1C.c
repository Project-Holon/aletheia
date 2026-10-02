/*
 * unit: yes
 * function: func_021D8B1C, func_021D8B44
 * address: 0x021D8B1C
 * packet: pkt_ov093_021D8B1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0738 0x021F0738 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern unsigned char d_021F0738[];
extern int func_021D775C(int);
extern int func_021D7AD4(int);
extern void func_021D7704(int,int);

void func_021D8B1C(int a, int b, int c)
{
    if(c==func_021D775C(3) && func_021D7AD4(func_021D775C(0x38))==3) func_021D7704(0x35,0x2000);
}

void *func_021D8B44(int *p)
{
    *p = 1;
    return d_021F0738;
}
