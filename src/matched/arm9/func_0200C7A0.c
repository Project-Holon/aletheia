/*
 * function: ZUKAN_SAVE_IsCountedForRegionalCompletion
 * address:  0x0200C7A0
 * packet:   pkt_0200C738
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209DE20 - same as ZUKAN_SAVE_IsCountedForNationalCompletion: table named only by this function's own pool word.  All 32 bytes right.
 * symbols:
 *   sZukanRegionalExcludedSpecies      0x0209DE20  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 sZukanRegionalExcludedSpecies[];

int ZUKAN_SAVE_IsCountedForRegionalCompletion(u32 v)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (v == sZukanRegionalExcludedSpecies[i])
            return 0;
    }
    return 1;
}
