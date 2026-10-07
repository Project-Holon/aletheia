/*
 * function: func_021D5E38
 * address:  0x021D5E38
 * packet:   pkt_ov093_021D5E38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef signed char s8; typedef unsigned char u8; typedef unsigned short u16;
u8 func_021D5E38(s8 *p, int i, u8 n)
{
    s8 *q;
    int t;
    switch (i) {
    case 1: q = p + 0xfc; break;
    case 2: q = p + 0xfd; break;
    case 3: q = p + 0xfe; break;
    case 4: q = p + 0xff; break;
    case 5: q = p + 0x100; break;
    case 6: q = p + 0x101; break;
    case 7: q = p + 0x102; break;
    default: return 0;
    }
    t = q[0];
    if (t > 0) {
        if (t - n < 0) n = t;
        q[0] -= n;
        return n;
    }
    return 0;
}
