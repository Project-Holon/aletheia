/*
 * unit:     yes
 * function: TIMEZONE_IsNight
 * address:  0x02011410
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TIMEZONE_GetNowTimeZone     0x020113D8  thumb
 *
 * ica_anime.c: is the animation in one of the two "finished" states.  Both
 * arms return the same 1, which is why the original reaches one epilogue
 * from both compares - it is a single disjunction, not two ifs.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011410.c \
 *       --addr 0x02011410 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */

typedef unsigned int u32;

extern u32 TIMEZONE_GetNowTimeZone(u32 row);

u32 TIMEZONE_IsNight(u32 tz)
{
    switch (TIMEZONE_GetNowTimeZone(tz)) {
    case 3:
    case 4:
        return 1;
    default:
        return 0;
    }
}
