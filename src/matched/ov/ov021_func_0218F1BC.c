/*
 * function: func_0218F1BC
 * address:  0x0218F1BC
 * packet:   pkt_ov021_0218F1BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DDA18  0x021DDA18  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef void (*Handler)(void *a, u32 b, u32 c);
extern Handler d_021DDA18[];

void func_0218F1BC(u32 *a, u32 b)
{
    if (a[1] == 0) {
        Handler fp = d_021DDA18[a[0]];
        if (fp != 0)
            fp(a, b, b);
    }
}
