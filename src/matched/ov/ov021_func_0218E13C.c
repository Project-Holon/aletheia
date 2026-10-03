/*
 * function: func_0218E13C
 * address:  0x0218E13C
 * packet:   pkt_ov021_0218E13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E124  0x0218E124  thumb
 *   d_021DDA00  0x021DDA00  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef void (*StateFunc)(void *a);
extern StateFunc d_021DDA00[];
extern void func_0218E124(u8 *a, u32 s);

void func_0218E13C(u8 *a, u32 s)
{
    if (*(u32 *)(a + 0x14) != s) {
        d_021DDA00[s](a);
        func_0218E124(a, s);
    }
}
