/*
 * file:     hand_tokusei_021dbe60.c
 * function: HAND_TOKUSEI_GetCursedBodyHandlers
 * address: 0x021DBE60
 * packet: pkt_ov093_021DBE60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gCursedBodyHandlers 0x021F0718 data a4
 */
#include "hand_tokusei_021dbaf0_types.h"

extern int gCursedBodyHandlers;

/* Cursed Body handler table (one handler). */
int *HAND_TOKUSEI_GetCursedBodyHandlers(int *handlerCount) { *handlerCount = 1; return &gCursedBodyHandlers; }
