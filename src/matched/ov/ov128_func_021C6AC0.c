/*
 * function: func_021C6AC0
 * address:  0x021C6AC0
 * packet:   pkt_021C6AC0
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_020307B0(void *p);

void func_021C6AC0(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_020307B0(*(void **)(p + 0x16c + i * 4));
}
