/*
 * file:     unit_021DBE60.c
 * function: func_021DBE60
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
#include "unit_021DBAF0_types.h"

extern int gCursedBodyHandlers;

/* Cursed Body handler table (one handler). */
int *func_021DBE60(int *handlerCount) { *handlerCount = 1; return &gCursedBodyHandlers; }
