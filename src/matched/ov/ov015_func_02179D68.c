/*
 * function: IRCNET_HasPeer
 * address: 0x02179D68
 * packet: pkt_ov015_02179D68
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov015/unit_02179CAC_p01.c and filed here.
 *
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015
 */

#include "../include/G_State.h"

typedef unsigned char u8;

struct flags_ab80 {
    u8 pad[0xE];
    u8 fE;
    u8 b0 : 1;
    u8 b1 : 1;
};

u8 IRCNET_HasPeer(void);
extern struct State d_0217AB80;

u8 IRCNET_HasPeer(void) { return ((struct flags_ab80 *)&d_0217AB80)->b1; }
