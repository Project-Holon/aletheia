/*
 * function: FIELD_BUILDMODEL_GetModelAnimDefs
 * address:  0x0218BCAC
 * packet:   pkt_0218BB04
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the object pointer advanced by 0x10 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p)
{
    return p + 0x10;
}

