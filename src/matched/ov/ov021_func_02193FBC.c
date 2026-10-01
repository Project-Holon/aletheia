/*
 * function: func_02193FBC
 * address:  0x02193FBC
 * packet:   pkt_ov021_02193FBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02082D44(void *src, void *dst, int n);

void func_02193FBC(u16 *a, void *b)
{
    if (*a == 1) {
        func_02082D44(b, (u8 *)a + 0x34, 0x18);
    }
}
