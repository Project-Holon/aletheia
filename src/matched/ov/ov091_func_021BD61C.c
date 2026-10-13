/*
 * function: PLIST_BATTLE_DeleteTimerWindows
 * address: 0x021BD61C
 * packet: pkt_ov091_021BD61C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj13262.h"
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void PLIST_BATTLE_DeleteTimerWindows(char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj13262 *)p)->f1FC); func_020452E8(*(struct Descriptor * *)&((struct Obj13262 *)p)->f200); }
