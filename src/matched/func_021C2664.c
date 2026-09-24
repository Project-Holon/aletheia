/*
 * function: func_021C2664
 * address:  0x021C2664
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Element field: u8 at +0xf of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C2664(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0xf + j * 0xc);
}
