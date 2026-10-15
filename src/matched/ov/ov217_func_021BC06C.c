/*
 * function: RESEARCH_LIST_PrintCurrentEntry
 * address:  0x021BC06C
 * packet:   pkt_021BC06C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call forwarding p and the byte field at +0x32.
 *
 * symbols:
 *   RESEARCH_LIST_PrintEntryLabels  0x021BC07C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05558.h"

typedef unsigned char u8;

extern int RESEARCH_LIST_PrintEntryLabels(u8 *p, u8 index);

int RESEARCH_LIST_PrintCurrentEntry(char *p)
{
    return RESEARCH_LIST_PrintEntryLabels((u8 *)p, ((struct Obj05558 *)p)->f32);
}
