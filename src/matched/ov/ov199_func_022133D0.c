/*
 * function: func_022133D0
 * address:  0x022133D0
 * packet:   pkt_022133D0
 * region:   ov199
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
extern void func_020307B0(void *p);

void func_022133D0(u8 *p)
{
    func_020307B0((void *)(*(u32 *)(p + 0x28)));
    func_020307B0((void *)(*(u32 *)(p + 0x2c)));
}

