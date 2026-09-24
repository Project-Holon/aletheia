/*
 * function: func_021BF878
 * address:  0x021BF878
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Element field: u16 at +0x4a of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BF878(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x4a + i * 0xd4 + j * 0xc);
}
