/*
 * unit: yes
 * function: func_021DAAC0, func_021DAAE0
 * address: 0x021DAAC0
 * packet: pkt_ov093_021DAAC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0730 0x021F0730 data a4
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA8DC 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAAE0.
 */
extern unsigned char d_021F0730[];
extern int func_021DA8A8(int, int, int);
extern void func_021DA8DC(int, int, int);

void func_021DAAC0(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 10))
        func_021DA8DC(b, c, 4);
}

void *func_021DAAE0(int *p)
{
    *p = 1;
    return d_021F0730;
}
