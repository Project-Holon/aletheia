/*
 * function: BOX2_UI_ShowWindowB
 * address:  0x021EF68C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb  arm9
 *
 * Forward the word at +0x74 plus constants to BGWINFRM_PutFrame.
 */
#include "../include/Obj18536.h"

typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void BOX2_UI_ShowWindowB(char *p)
{
    BGWINFRM_PutFrame(*(struct WinMgr * *)&((struct Obj18536 *)p)->f74, 0xb, 0, 0x15);
}

