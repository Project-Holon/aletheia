/*
 * function: func_021BF77C
 * address:  0x021BF77C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed u32 read: table at +0x2c4, index from the u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 *func_021BF77C(void *p)
{
    u32 i = *(u32 *)((char *)p + 0x2cc);
    return *(u8 **)((char *)p + i * 4 + 0x2c4);

}
