/*
 * function: func_0218F0A8
 * address:  0x0218F0A8
 * packet:   pkt_ov021_0218F0A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218F050  0x0218F050  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0218F050(void *p);

void func_0218F0A8(u8 *a)
{
    u8 *p = *(u8 **)(a + 0xec);
    if (p != 0) {
        if (*(u32 *)(p + 0x10) == 0 && *(u32 *)(p + 8) == *(u32 *)(p + 0xc) && *(u32 *)(p + 4) == 0)
            func_0218F050(p);
        else
            *(u32 *)(p + 0x2c) = 1;
    }
}
