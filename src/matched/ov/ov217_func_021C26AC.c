/*
 * function: func_021C26AC
 * address:  0x021C26AC
 * packet:   pkt_ov217_021C26AC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Const base pointer, i declared before e, e assigned in its own statement.
 *
 * symbols:
 *   func_021C2684  0x021C2684  thumb  ov217
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C2684(const void *p, u32 v);

u32 func_021C26AC(const u8 *p, u32 unused, u32 key)
{
    s32 i;
    const u8 *e;
    e = p + 4 + func_021C2684(p, unused) * 0xd4;
    for (i = 0; i < e[1]; i++) {
        if (key == *(u16 *)(e + 8 + i * 0xc))
            return (u8)i;
    }
    return 0;
}
