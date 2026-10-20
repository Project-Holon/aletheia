/*
 * file:     timezone.c
 * unit:     yes
 * function: TIMEZONE_GetNowTimeZone, TIMEZONE_GetTimeZoneOfHour, TIMEZONE_GetLight, TIMEZONE_IsNight
 * address:  0x020113D8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from vm.c by tools/splitfile.py.
 *
 * symbols:
 *   GF_STANDARD_GetCachedTime  0x0203F4CC  arm
 *   _TimeZoneTable  0x0209DF24  data  a1
 *   _TimeZoneLightTable  0x0209DF10  data  a1
 */
#include "script_vm_types.h"

/* RTC time as GF_STANDARD_GetCachedTime fills it. */
#include "gf_standard_types.h"

extern void GF_STANDARD_GetCachedTime(struct RtcTime *time);

u32 TIMEZONE_GetNowTimeZone(u32 season);

int TIMEZONE_GetTimeZoneOfHour(int season, int hour);

u8 TIMEZONE_GetLight(int season, int timeZone);

u32 TIMEZONE_IsNight(u32 season);

extern const u8 _TimeZoneTable[][0x18];

extern const u8 _TimeZoneLightTable[][5];

/*
 * VM_SetWait's bytes after its first `movs r2, #2` (where the caller's r2 is
 * stored at +0x0d) were once filed as a separate function by an early
 * matching wave; they are part of VM_SetWait, not an entry of their own.
 */



/*
 * Fills a 12-byte buffer through GF_STANDARD_GetCachedTime and tail-hands its own
 * argument and the buffer's first word to TIMEZONE_GetTimeZoneOfHour, a table lookup
 * that is a documented near miss (src/matched/TIMEZONE_IsNight.c's header has
 * the details) and so is declared here only, not defined.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TIMEZONE_GetNowTimeZone.c \
 *       --func TIMEZONE_GetNowTimeZone --addr 0x020113D8 --cc 1.1p1 --lang c99 --thumb
 */
u32 TIMEZONE_GetNowTimeZone(u32 season)
{
    struct RtcTime time;

    GF_STANDARD_GetCachedTime(&time);
    return TIMEZONE_GetTimeZoneOfHour(season, time.hour);
}

/*
 * vm.c, 0x020113F0..0x02011410: two byte lookups in constant 2D tables,
 * rows of 0x18 and 5 bytes.  Plain subscripts `tbl[row][col]` give the
 * image's `base + row * stride` then `ldrb [col, base]`; the old pending
 * park (byte-offset arithmetic, docs/notes/pkt_020113F0.c.txt) was capped on
 * the two single-pool rodata tables, which sole-ref/self now carries.
 */
int TIMEZONE_GetTimeZoneOfHour(int season, int hour)
{
    return _TimeZoneTable[season][hour];
}

u8 TIMEZONE_GetLight(int season, int timeZone)
{
    return _TimeZoneLightTable[season][timeZone];
}

/*
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
u32 TIMEZONE_IsNight(u32 season)
{
    switch (TIMEZONE_GetNowTimeZone(season)) {
    case 3:
    case 4:
        return 1;
    default:
        return 0;
    }
}
