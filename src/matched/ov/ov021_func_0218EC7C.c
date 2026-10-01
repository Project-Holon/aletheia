/*
 * function: func_0218EC7C
 * address:  0x0218EC7C
 * packet:   pkt_ov021_0218EC7C
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

extern void func_02048B6C(u32 a, u32 *args);

void func_0218EC7C(u8 *a, u32 first, ...)
{
    func_02048B6C(*(u32 *)(a + 0xc), &first);
}
