/*
 * function: IRC_RANKING_DisplayExit
 * address: 0x021B807C
 * packet: pkt_ov106_021B807C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   IRC_RANKING_ClactExit 0x021B7FC8 thumb ov106
 *   IRC_RANKING_GfxExit 0x021B7F00 thumb ov106
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj22261.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void IRC_RANKING_ClactExit(void **);
extern void IRC_RANKING_GfxExit(u32 *);
extern void MI_CpuFill8(void *,int,int);
void IRC_RANKING_DisplayExit(u8 *p) { func_02030EAC(((struct Obj22261 *)p)->f24); IRC_RANKING_ClactExit((void **)(p+16)); IRC_RANKING_GfxExit((u32 *)p); MI_CpuFill8(p,0,40); }
