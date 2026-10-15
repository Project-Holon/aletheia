/*
 * function: SHINKA_DEMO_VIEW_OtherSlot
 * address:  0x02206264
 * packet:   pkt_02206264
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (saves no lr), seeded by address: flips a 0/1
 * slot index.
 */

typedef unsigned char u8;

u8 SHINKA_DEMO_VIEW_OtherSlot(u8 i)
{
    u8 r;

    if (i == 0)
        r = 1;
    else
        r = 0;
    return r;
}
