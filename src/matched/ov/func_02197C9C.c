/*
 * function: func_02197C9C
 * address:  0x02197C9C
 * packet:   pkt_02197C9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D55C(int a0, int a1);
extern u32 func_0216DB10(u32, u32, u32, u32);
extern int func_0216DC4C(void *a0);

int func_02197C9C(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216DB10(a, b, c, d) != 0) {
    if (func_0216DC4C((void *)a) == 0) {
        return 1;
    }
}
if (func_0216D55C(a, 16) != 0) {
    return 1;
}
return 0;
}

