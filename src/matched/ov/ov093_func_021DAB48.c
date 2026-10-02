/*
 * unit: yes
 * function: func_021DAB48, func_021DAB6C
 * address: 0x021DAB48
 * packet: pkt_ov093_021DAB48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0790 0x021F0790 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 * extent: includes store-and-return followers 021DAB6C.
 */
extern unsigned char d_021F0790[];
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);

void func_021DAB48(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x15) == 7)
        func_021D76BC(0x4b, 1);
}

void *func_021DAB6C(int *p)
{
    *p = 1;
    return d_021F0790;
}
