/*
 * function: MONOLITH_TOOL_STATS_LoadGraphics
 * address: 0x021B8ADC
 * packet: pkt_ov071_021B8ADC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj20741.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_PushTile(unsigned int);
void MONOLITH_TOOL_STATS_LoadGraphics(char *p) { func_020498F4((void *)(((struct Obj20741 *)p)->f30),5,6,0,0,1,0x61); BG_SYS_PushTile(6); BG_SYS_PushTile(4); }
