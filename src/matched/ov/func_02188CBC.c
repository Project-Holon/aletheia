/*
 * function: FIELDMAP_IsFieldPlayerCreated
 * address:  0x02188CBC
 * packet:   pkt_02188CBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELDMAP_IsFieldPlayerCreated(u32 a)
{
if (*(u32 *)((u8 *)((a + 140))) != 0) {
    return 1;
}
return 0;
}

