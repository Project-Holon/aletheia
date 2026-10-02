/*
 * unit: yes
 * function: func_021DAAEC, func_021DAB0C, func_021DAB18
 * address: 0x021DAAEC
 * packet: pkt_ov093_021DAAEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0798 0x021F0798 data a4
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA8DC 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAB0C, 021DAB18.
 */
extern unsigned char d_021F0798[];
extern int func_021DA8A8(int, int, int);
extern void func_021DA8DC(int, int, int);

void func_021DAAEC(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 12))
        func_021DA8DC(b, c, 4);
}

void *func_021DAB0C(int *p)
{
    *p = 1;
    return d_021F0798 + 8;
}

void *func_021DAB18(int *p)
{
    *p = 1;
    return d_021F0798;
}
