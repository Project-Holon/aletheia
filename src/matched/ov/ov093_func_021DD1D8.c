/*
 * function: func_021DD1D8
 * address:  0x021DD1D8
 * packet:   pkt_ov093_021DD1D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *func_021C7CF4(void *a, int b);
extern int func_021D62A8(u8 *p);
extern int func_021D62C4(u8 *p, int i);
extern int func_021D7E10(u8 *p);

int func_021DD1D8(u8 *a, int b, int c)
{
    u8 *m = func_021C7CF4(a, b);
    switch (c) {
    case 0x25:
        if (func_021D62A8(m) == 0 && func_021D62C4(m, 6) == 0)
            break;
        return 1;
    case 0x24:
        if (func_021D62A8(m) != 0)
            return 1;
        return 0;
    case 0x26:
        if (func_021D7E10(m) != 0)
            return 1;
        return 0;
    default:
        return func_021D62C4(m, c);
    }
    return 0;
}
