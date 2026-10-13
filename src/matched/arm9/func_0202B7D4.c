/*
 * function: ISS_SYS_OnZoneChangeZone
 * address:  0x0202B7D4
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the node's 0x1c word goes straight to ISS_ZONE_SYS_SwitchZone.
 *
 * symbols:
 *   ISS_ZONE_SYS_SwitchZone  0x0202BECC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_SYS_OnZoneChangeZone.c \
 *       --func ISS_SYS_OnZoneChangeZone --addr 0x0202B7D4 --thumb --cc 1.1p1

 * Closed by the `matched` class: 0x0202BECC -> 0x0202BF90, both filed this wave.
 */
#include "../include/Obj15842.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_ZONE_SYS_SwitchZone(u8 *p, u32 key);

void ISS_SYS_OnZoneChangeZone(u8 *p, u32 key)
{
    ISS_ZONE_SYS_SwitchZone((u8 *)(((struct Obj15842 *)p)->f1C), key);
}
