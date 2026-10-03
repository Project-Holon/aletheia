/*
 * function: func_021B9F74
 * address:  0x021B9F74
 * packet:   pkt_ov071_021B9F74
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020413B0  0x020413B0  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

void func_021B9F74(u8 *p, int i, int v)
{
    int x;
    int q;
    int m32;
    int m64;
    int d;

    if (i != 0xFFFF) {
        x = *(int *)(p + 0x2d8) >> 8;
        q = x / 32;
        m32 = x % 32;
        m64 = x % 64;
        d = i - q;
        if (d >= 0 && d < q + 7) {
            func_020413B0(6, 3, ((d * 32 + m64 - m32) % 256) / 8, 0x19, 4, v);
        }
    }
}
