/*
 * unit:     yes
 * function: func_0203B018, func_0203B01C
 * address:  0x0203B018
 * packet:   pkt_0203B018
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC  0x021469DC  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203B018.c \
 *       --addr 0x0203B018 --arm
 *
 * net_state.c.  func_0203B018 is the 4-byte `bx lr` no-op that
 * func_0203B038 hands to func_02037A6C as its completion callback (the
 * pool word at 0x0203B080 is its only referrer).  func_0203B01C is the
 * unlabelled leaf that bumps the state record's +0x46 countdown by 0x3C;
 * func_0203B390 names it through a pool word.  Filing both here gives the
 * `matched` class a witness for each (docs/families/net_state.h, THE REPORT
 * TAG RULE, "the two genuine exceptions").
 *
 * Integrator: seed 0x0203B01C arm (member of this unit, no label).
 */

#include "../include/G_Sys.h"

typedef unsigned short u16;

extern struct Sys *g_021469DC;

void func_0203B018(void)
{
}

void func_0203B01C(void)
{
    g_021469DC->f46 += 0x3c;
}
