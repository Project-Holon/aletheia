/*
 * function: WIFICLUBACTOR_ResumeActorSprite
 * address:  0x021B98E4
 * packet:   pkt_ov099_021B98E4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted by the recursive unblocker lane.  The +0008 ABS32 WF2DMAP_OBJDRAW_SetSubActorDrawEnable
 * call now resolves as `matched` against layout/matched/ov127/
 * pkt_ov127_021C584C.json (an unlabelled ov127 accessor veneer matched
 * after its own callee WIFI_2DCHAR_SetSubActorDrawEnable).  The region hint on the symbols line
 * breaks the 9-overlay overlap.
 *
 * symbols:
 *   WF2DMAP_OBJDRAW_SetSubActorDrawEnable  0x021C584C  thumb  ov127
 */
#include "../include/Obj22009.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void WF2DMAP_OBJDRAW_SetSubActorDrawEnable(u8 *p, int a);
void WIFICLUBACTOR_ResumeActorSprite(int a, u8 *b) { WF2DMAP_OBJDRAW_SetSubActorDrawEnable((u8 *)(((struct Obj22009 *)b)->f4), 1); }
