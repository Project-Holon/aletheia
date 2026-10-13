/*
 * function: ISS_CITY_SYS_Update
 * address:  0x0202AB38
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker ISS_CITY_SYS_InitUnits.c is now a manifest entry (matched class)
 *
 * When ISS_CITY_SYS_IsEnabled reports non-zero, runs ISS_CITY_SYS_UpdateByMode.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_Update.c \
 *       --func ISS_CITY_SYS_Update --addr 0x0202AB38 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_CITY_SYS_IsEnabled  0x0202ACC8  thumb
 *   ISS_CITY_SYS_UpdateByMode  0x0202ACCC  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 ISS_CITY_SYS_IsEnabled(void *obj);
extern void ISS_CITY_SYS_UpdateByMode(u8 *p);

void ISS_CITY_SYS_Update(u8 *p)
{
    if (ISS_CITY_SYS_IsEnabled(p) != 0) {
        ISS_CITY_SYS_UpdateByMode(p);
    }
}
