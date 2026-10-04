/*
 * function: func_021B9814
 * address: 0x021B9814
 * packet: pkt_ov110_021B9814
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 func_021B9814(u8 *p, u16 *src, u32 n, u16 *out)
{
    u32 i;
    for (i = 0; i < n; i++) {
        u32 c = *src;
        if (c == 0xFFFE) {
            u32 len;
            src++;
            len = *src++;
            while (len != 0) {
                u32 v = *src++;
                p[0x1D6E + (v >> 3)] |= (u8)(1 << (v & 7));
                len--;
            }
            *out = src[-1];
        } else {
            p[0x1D6E + (c >> 3)] |= (u8)(1 << (c & 7));
            src++;
            *out = c;
        }
        out++;
    }
    return n;
}
