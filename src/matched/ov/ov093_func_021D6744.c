/*
 * function: func_021D6744
 * address:  0x021D6744
 * packet:   pkt_ov093_021D6744
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021D6744(u8 *p, u8 a, int f, u8 b, u16 c, u16 d)
{
    u16 old = *(u16 *)(p + 0x14c);
    *(u16 *)(p + 0x14a) = d;
    *(u16 *)(p + 0x14c) = c;
    p[0x152] = a;
    p[0x144] = b;
    if (old == c) {
        if (f) *(u16 *)(p + 0x14e) += 1;
        else *(u16 *)(p + 0x14e) = 0;
    } else {
        *(u16 *)(p + 0x14e) = f ? 1 : 0;
    }
}
