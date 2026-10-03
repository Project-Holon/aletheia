/*
 * function: func_020922CC
 * address:  0x020922CC
 * packet:   pkt_02092144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020922B0  0x020922B0  arm
 *   func_02094860  0x02094860  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020922B0(u32 *tmp, u32 c);
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);

u32 func_020922CC(u8 *dst, const u16 *src, u32 max)
{
    u32 n = 0;
    u32 tmp;

    if (dst == 0 || src == 0)
        return 0;

    do {
        u32 k;

        if (*src == 0) {
            dst[n] = 0;
            break;
        }
        k = func_020922B0(&tmp, *src++);
        if (n + k > max)
            break;
        func_02094860(dst + n, (const u8 *)&tmp, k);
        n += k;
    } while (n <= max);

    return n;
}
