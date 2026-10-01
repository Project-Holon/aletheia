/*
 * function: func_0218E58C
 * address:  0x0218E58C
 * packet:   pkt_ov021_0218E58C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3E44  0x021D3E44  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef void (*StateFunc)(void *a, u32 b);
extern StateFunc d_021D3E44[];

void func_0218E58C(u8 *a, u32 b)
{
    d_021D3E44[*(u32 *)(a + 0x14)](a, b);
}
