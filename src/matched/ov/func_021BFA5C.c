/*
 * function: EVENT_APPEAR_OnScoreboardEndAlt
 * address:  0x021BFA5C
 * packet:   pkt_021BFA5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   EVENT_APPEAR_StartPlayerSpinAlt  0x021BF9F4  thumb  ov021
 *   EVENT_APPEAR_StartZoomOutAlt  0x021BF978  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern int EVENT_APPEAR_StartPlayerSpinAlt(void **a);
extern void EVENT_APPEAR_StartZoomOutAlt(void *p);

void EVENT_APPEAR_OnScoreboardEndAlt(u8 *p)
{
    EVENT_APPEAR_StartPlayerSpinAlt((void **)p);
    EVENT_APPEAR_StartZoomOutAlt(p);
}
