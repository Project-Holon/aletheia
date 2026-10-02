/*
 * function: func_02175938
 * address: 0x02175938
 * packet: pkt_ov011_02175938
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
void func_02175938(u8 *p, const u16 *src, int index)
{
    u16 *dst = (u16 *)(p + index * 40);
    unsigned n;
    if (*((u8 *)dst + 16) != 1) {
        n = 20;
        do { *dst++ = *src++; } while (--n);
    }
}
