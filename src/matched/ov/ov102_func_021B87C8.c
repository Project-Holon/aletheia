/*
 * function: IRC_COMPATIBLE_MENU_UpdateScrollEffect
 * address: 0x021B87C8
 * packet: pkt_ov102_021B87C8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   IRC_COMPATIBLE_MENU_StepLinear 0x021B8A90 thumb ov102
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 */
#include "../include/Obj07980.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Struct021B8A90;
extern int IRC_COMPATIBLE_MENU_StepLinear(struct Struct021B8A90 *p);
extern void BG_SYS_ResetSlot(u32,u32,u32);
void IRC_COMPATIBLE_MENU_UpdateScrollEffect(u8 *p) { if(((struct Obj07980 *)p)->f18) { if(IRC_COMPATIBLE_MENU_StepLinear((struct Struct021B8A90 *)p))((struct Obj07980 *)p)->f18=0; BG_SYS_ResetSlot(4,3,88-((struct Obj07980 *)p)->f0); BG_SYS_ResetSlot(7,3,88-((struct Obj07980 *)p)->f0); } }
