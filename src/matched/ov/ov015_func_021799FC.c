/*
 * function: IRCNET_IsSendReady
 * address: 0x021799FC
 * packet: pkt_ov015_021799FC
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov015/unit_02179824_p03.c and filed here.
 *
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015 a1
 */

#include "../include/G_State.h"

typedef unsigned char u8;
u8 IRCNET_IsSendReady(void);
extern struct State d_0217AB80;

u8 IRCNET_IsSendReady(void) { return d_0217AB80.f14; }
