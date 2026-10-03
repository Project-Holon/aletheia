/*
 * unit: yes
 * function: func_0689B098, func_0689B0CC
 * address: 0x0689B098
 * packet: pkt_ov095_0689B098
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: unlabelled byte accessor at 0x0689B0CC, followed by alignment padding.
 * symbols:
 *   func_0689AE34 0x0689AE34 thumb ov095
 */
typedef unsigned char u8;
extern void func_0689AE34(u8 *list, u8 n, int unused, u8 *s);

void func_0689B098(u8 *p, u8 *s)
{
    if (p[0] != 0) {
        func_0689AE34(p + 3, p[0], 0, s);
    } else if (p[2] == 1) {
        func_0689AE34(p + 3, p[1], 1, s);
    } else {
        func_0689AE34(p + 3, p[1], 2, s);
    }
}

u8 func_0689B0CC(u8 *p)
{
    return p[0x89];
}
