/*
 * function: EVENT_APPEAR_OnScoreboardEnd
 * address:  0x021BF8DC
 * packet:   pkt_021BF8DC
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
 *   EVENT_APPEAR_StartPlayerSpin  0x021BF874  thumb  ov021
 *   EVENT_APPEAR_StartZoomOut  0x021BF7F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern int EVENT_APPEAR_StartPlayerSpin(void **a);
extern void EVENT_APPEAR_StartZoomOut(void *p);

void EVENT_APPEAR_OnScoreboardEnd(u8 *p)
{
    EVENT_APPEAR_StartPlayerSpin((void **)p);
    EVENT_APPEAR_StartZoomOut(p);
}
