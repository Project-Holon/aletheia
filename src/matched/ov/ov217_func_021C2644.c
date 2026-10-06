/*
 * function: func_021C2644
 * address:  0x021C2644
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Element field: u16 at +0xc of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C2644(void *p, u32 i, u8 j)
{
    return *(u16 *)((char *)p + i * 0xd4 + 0xc + j * 0xc);
}
