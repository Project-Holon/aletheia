/*
 * function: func_0219CD68
 * address:  0x0219CD68
 * packet:   pkt_ov021_0219CD68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills the first free 0xC-byte entry (tag 0xFFFF... see pool) of the table.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e)
{
    u8 *ctx = *(u8 **)(o + 0x1c);
    u32 i;
    u32 n = *(u16 *)(ctx + 4);
    o = *(u8 **)(ctx + 0xc);
    for (i = 0; i < n; i++, o += 0xc) {
        if (*(u16 *)o == 0xFFFF) {
            *(u16 *)o = a;
            *(u8 *)(o + 4) = b;
            *(u8 *)(o + 5) = c;
            *(u16 *)(o + 2) = d;
            *(u32 *)(o + 8) = e;
            return;
        }
    }
}
