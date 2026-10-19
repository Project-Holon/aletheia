/*
 * function: BOX2_MAIN_RefreshCurrentBoxMonInfo
 * address:  0x021DEFEC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_RefreshMonInfo  0x021DEF98  thumb  ov170
 *
 * Forward with the byte field at +0x14.
 */
#include "../include/Obj18458.h"

extern int BOX2_MAIN_RefreshMonInfo(char *p, int a, unsigned b);

void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b)
{
    BOX2_MAIN_RefreshMonInfo(p, ((struct Obj18458 *)p)->f14, b);
}

