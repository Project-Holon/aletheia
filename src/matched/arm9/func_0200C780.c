/*
 * function: ZUKAN_SAVE_IsCountedForNationalCompletion
 * address:  0x0200C780
 * packet:   pkt_0200C738
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209DE2C - data table named by one pool word in the whole image, this function's own; the `literal` class discards its only witness and no cut helps.  All 32 bytes right.
 * symbols:
 *   sZukanNationalExcludedSpecies      0x0209DE2C  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 sZukanNationalExcludedSpecies[];

int ZUKAN_SAVE_IsCountedForNationalCompletion(u32 v)
{
    u32 i;

    for (i = 0; i < 0xf; i++) {
        if (v == sZukanNationalExcludedSpecies[i])
            return 0;
    }
    return 1;
}
