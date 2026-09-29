/*
 * function: func_021D29A8
 * address:  0x021D29A8
 * packet:   pkt_ov021_021D29A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_021A0FA8  0x021A0FA8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_021A0F30(u32 link, u32 on);
extern int func_021A0F94(u32 link);
extern void func_021A0FA8(u32 link);

u32 func_021D29A8(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        func_021A0F30(p[1], 9);
        st[0]++;
        break;
    case 1:
        if (func_021A0F94(p[1]) == 14) {
            func_021A0FA8(p[1]);
            st[0]++;
        }
        break;
    case 2:
        func_021A0F30(p[1], 0);
        return 1;
    }
    return 0;
}
