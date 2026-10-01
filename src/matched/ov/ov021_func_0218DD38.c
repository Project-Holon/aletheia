/*
 * function: func_0218DD38
 * address:  0x0218DD38
 * packet:   pkt_ov021_0218DD38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A7418  0x021A7418  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021A7418(void *p);

void func_0218DD38(void **a)
{
    if (*a != 0) {
        func_021A7418(*a);
        *a = 0;
    }
}
