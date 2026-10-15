/*
 * function: GF_STANDARD_GetTime
 * address:  0x0203F4FC
 * packet:   pkt_0203F4FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Seconds since midnight out of the three-word global at 0x02146A1C: the
 * minutes and hours are the first two members of the source's struct and
 * come out of one `ldm`.  The sum is spelled minutes-before-hours -
 * `m * 60 + h * 3600` - and that order is what makes the hours term the
 * `mul` and the minutes term the `mla`, with the seconds member added last.
 * Subtracting only the ordering from the swapped spelling costs the `ldm`
 * and the paired multiply and adds a pool word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_GetTime.c \
 *       --func GF_STANDARD_GetTime --addr 0x0203F4FC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 GF_STANDARD_GetTime(void)
{
    u32 *p = (u32 *)(0x2146A1C);

    return p[1] * 60 + p[0] * 3600 + p[2];
}
