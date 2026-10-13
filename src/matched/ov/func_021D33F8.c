/*
 * function: FIELD_PALACE_SYS_GetPalTable
 * address:  0x021D33F8
 * packet:   pkt_021D33F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter: returns the word at +0x08.  Unlabelled in the listing; called
 * from FIELDMAP_SeqCreateSubsystems.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void *FIELD_PALACE_SYS_GetPalTable(u32 *p)
{
    return (void *)p[2];
}
