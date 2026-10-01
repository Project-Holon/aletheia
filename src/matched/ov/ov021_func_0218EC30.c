/*
 * function: func_0218EC30
 * address:  0x0218EC30
 * packet:   pkt_ov021_0218EC30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

void func_0218EC30(u8 *a, const Vec3 *p)
{
    *(const Vec3 **)(a + 0x1c) = p;
    *(Vec3 *)(a + 0x6c) = *p;
    *(Vec3 *)(a + 0x48) = *p;
}
