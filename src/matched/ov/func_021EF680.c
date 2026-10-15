/*
 * function: BOX2_UI_HideWindowA
 * address:  0x021EF680
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_HideFrame  0x0202CC70  thumb  ov170
 *
 * Forward the word at +0x74 with index 10.
 */
#include "../include/Obj18535.h"

typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);

void BOX2_UI_HideWindowA(char *p)
{
    BGWINFRM_HideFrame(*(struct WinMgr * *)&((struct Obj18535 *)p)->f74, 0xa);
}

