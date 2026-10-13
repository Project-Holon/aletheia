/*
 * function: FIELD_G3DOBJ_SetPalTable
 * address:  0x021C6534
 * packet:   pkt_021C6534
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Setter: stores the second argument at +0x10.  Unlabelled in the listing;
 * called from FIELDMAP_SeqCreateSubsystems.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_G3DOBJ_SetPalTable(u32 *p, u32 v)
{
    p[4] = v;
}
