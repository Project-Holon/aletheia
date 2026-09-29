/*
 * function: func_021D5CB4
 * address:  0x021D5CB4
 * packet:   pkt_ov093_021D5CB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef signed char s8; typedef unsigned char u8;
s8 *func_021D5CB4(s8 *p, int i, u8 *a, u8 *b)
{
    *a = 0;
    *b = 12;
    switch (i) {
    case 1: return p + 0xfc;
    case 2: return p + 0xfd;
    case 3: return p + 0xfe;
    case 4: return p + 0xff;
    case 5: return p + 0x100;
    case 6: return p + 0x101;
    case 7: return p + 0x102;
    default: return 0;
    }
}
