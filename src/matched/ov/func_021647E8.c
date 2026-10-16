/*
 * function: CALENDER_GetWeatherThunk
 * address:  0x021647E8
 * packet:   pkt_021647E8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CALENDER_GetWeather  0x0216481C  thumb
 *
 * Tail call to CALENDER_GetWeather through a pool word and `bx r3`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the
 * listing: no prologue, and its only caller is ISS_SWITCH_GetSubscreenMode in arm9.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 CALENDER_GetWeather(u8 *p, u32 b);

u32 CALENDER_GetWeatherThunk(void *arg, unsigned int b)
{
    return CALENDER_GetWeather(arg, b);
}
