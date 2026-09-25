/*
 * function: func_02204DC4
 * address:  0x02204DC4
 * packet:   pkt_02204DC4
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02005E30(u32);

void func_02204DC4(u8 *p, u8 *q)
{
    if (*(u32 *)(p + 0xc) != 0) {
        func_02005E30(0x1e);
    }
    *(u32 *)(q + 0x30) = 1;
}

