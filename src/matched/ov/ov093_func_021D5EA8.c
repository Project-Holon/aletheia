/*
 * function: func_021D5EA8
 * address:  0x021D5EA8
 * packet:   pkt_ov093_021D5EA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef signed char s8; typedef unsigned char u8; typedef unsigned short u16;
void func_021D5EA8(s8 *p, int i, u8 n)
{
    s8 *q;
    switch (i) {
    case 1: q = p + 0xfc; break;
    case 2: q = p + 0xfd; break;
    case 3: q = p + 0xfe; break;
    case 4: q = p + 0xff; break;
    case 5: q = p + 0x100; break;
    case 6: q = p + 0x101; break;
    case 7: q = p + 0x102; break;
    default: return;
    }
    if (n <= 12) q[0] = n;
}
