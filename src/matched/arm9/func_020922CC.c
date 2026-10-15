/*
 * function: MSL_C_LIB_WideToNarrow
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
 *   MSL_C_LIB_CallFormatHook  0x020922B0  arm
 *   strncpy  0x02094860  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 MSL_C_LIB_CallFormatHook(u32 *tmp, u32 c);
extern u8 *strncpy(u8 *dest, const u8 *src, u32 n);

u32 MSL_C_LIB_WideToNarrow(u8 *dst, const u16 *src, u32 max)
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
        k = MSL_C_LIB_CallFormatHook(&tmp, *src++);
        if (n + k > max)
            break;
        strncpy(dst + n, (const u8 *)&tmp, k);
        n += k;
    } while (n <= max);

    return n;
}
