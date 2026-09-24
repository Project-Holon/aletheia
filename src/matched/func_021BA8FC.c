/*
 * function: func_021BA8FC
 * address:  0x021BA8FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BA8FC(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x5c) = 0;
}
