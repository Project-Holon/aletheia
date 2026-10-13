/*
 * function: ISS_CITY_SYS_NotifyZoneChange
 * address:  0x0202AB5C
 * packet:   pkt_0202AB5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ISS_CITY_SYS_HandleZoneChange  0x0202AC60  thumb
 *
 * iss_city_sys.c: an unlabelled forwarding leaf, a pool-word tail call to
 * ISS_CITY_SYS_HandleZoneChange with the caller's arguments passed through untouched.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_CITY_SYS_HandleZoneChange(u8 *p, u32 a1);

void ISS_CITY_SYS_NotifyZoneChange(u8 *p, u32 a1)
{
    ISS_CITY_SYS_HandleZoneChange(p, a1);
}
