/*
 * function: func_021BCD6C
 * address:  0x021BCD6C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear seven u32 slots at +0xdc, then ten at +0xb4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BCD6C(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xdc) = 0;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0xb4) = 0;
}
