/*
 * function: FIELDMAP_InitCommonWork
 * address:  0x02189758
 * packet:   pkt_02189758
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets a pair: first word -1, second word 0.  Unlabelled in the listing;
 * called from FIELDMAP_SeqCreateSubsystems.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void FIELDMAP_InitCommonWork(int *p)
{
    p[0] = -1;
    p[1] = 0;
}
