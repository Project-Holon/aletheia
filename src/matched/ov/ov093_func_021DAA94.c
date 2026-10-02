/*
 * unit: yes
 * function: func_021DAA94, func_021DAAB4
 * address: 0x021DAA94
 * packet: pkt_ov093_021DAA94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0B30 0x021F0B30 data a4
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA8DC 0x021DA8DC thumb ov093
 * extent: includes store-and-return followers 021DAAB4.
 */
extern unsigned char d_021F0B30[];
extern int func_021DA8A8(int, int, int);
extern void func_021DA8DC(int, int, int);

void func_021DAA94(int a, int b, int c)
{
    if (func_021DA8A8(b, c, 10))
        func_021DA8DC(b, c, 4);
}

void *func_021DAAB4(int *p)
{
    *p = 3;
    return d_021F0B30;
}
