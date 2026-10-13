/*
 * function: FIELD_PLAYER_CheckAnimePaused
 * address:  0x021A3244
 * packet:   pkt_021A3244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_CheckAnimePaused  0x021A3A3C  thumb  ov021
 *
 * Tail-call thunk: ldr r0,[r0,#4]; ldr r3,[pc]; bx r3; .word FIELD_PLAYER_CORE_CheckAnimePaused.
 * Unlabelled in the ARM9 listings (the .word run at 0x021A3244 in ov021);
 * blocker target of ov010's REPORT_EVENT_IsAvatarReady (pkt_0216A244).
 */
#include "../include/Obj18020.h"

typedef unsigned int   u32;
extern int FIELD_PLAYER_CORE_CheckAnimePaused(u32 *p);

int FIELD_PLAYER_CheckAnimePaused(void *p)
{
    return FIELD_PLAYER_CORE_CheckAnimePaused(((struct Obj18020 *)p)->f4);
}
