/*
 * function: GRAPHTABLE_FindGroup
 * address:  0x021C2684
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Find the 0xd4-byte record whose byte +4 equals the argument; its index or zero.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 GRAPHTABLE_FindGroup(void *p, u32 v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(u8 *)((char *)p + i * 0xd4 + 4) == v)
            return (u8)i;
    }
    return 0;
}
