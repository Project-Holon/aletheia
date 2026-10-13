/*
 * unit:     yes
 * function: GFL_NET_STATE_ConnectMacDone, GFL_NET_STATE_ExtendConnectTimer
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
 *   _pNetState  0x021469DC  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203B018.c \
 *       --addr 0x0203B018 --arm
 *
 * net_state.c.  GFL_NET_STATE_ConnectMacDone is the 4-byte `bx lr` no-op that
 * GFL_NET_STATE_ConnectMac hands to GFL_NET_SYSTEM_ConnectToParent as its completion callback (the
 * pool word at 0x0203B080 is its only referrer).  GFL_NET_STATE_ExtendConnectTimer is the
 * unlabelled leaf that bumps the state record's +0x46 countdown by 0x3C;
 * GFL_NET_STATE_ChangeoverConnect names it through a pool word.  Filing both here gives the
 * `matched` class a witness for each (docs/families/net_state.h, THE REPORT
 * TAG RULE, "the two genuine exceptions").
 *
 * Integrator: seed 0x0203B01C arm (member of this unit, no label).
 */

#include "../include/G_Sys.h"

typedef unsigned short u16;

extern struct Sys *_pNetState;

void GFL_NET_STATE_ConnectMacDone(void)
{
}

void GFL_NET_STATE_ExtendConnectTimer(void)
{
    _pNetState->f46 += 0x3c;
}
