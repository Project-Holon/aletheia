/*
 * function: func_021D33F8
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
 * from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void *func_021D33F8(u32 *p)
{
    return (void *)p[2];
}
