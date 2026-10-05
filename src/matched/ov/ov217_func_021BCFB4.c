/*
 * function: func_021BCFB4
 * address:  0x021BCFB4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear three u32 slots at +0x120.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BCFB4(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x120) = 0;
}
