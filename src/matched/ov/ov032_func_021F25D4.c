/*
 * function: func_021F25D4
 * address: 0x021F25D4
 * packet: pkt_ov032_021F25D4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_021F0668 0x021F0668 thumb ov032
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F05E8(u8 *, int, u32);
extern int func_021F0668(char *p, int i);
int func_021F25D4(u8 *p, int *st)
{
    switch (st[0]) {
    case 0:
        func_021F05E8(p, st[6], 1);
        st[0]++;
        return 0;
    case 1:
        if (func_021F0668((char *)p, st[6]) != 0)
            return 0;
        break;
    }
    return 1;
}
