/*
 * function: IRC_COMPATIBLE_MENU_ExitFloaters
 * address: 0x021B89B8
 * packet: pkt_ov102_021B89B8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_MENU_ExitFloater 0x021B8868 thumb ov102
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj22169.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_MENU_ExitFloater(void *);
extern void MI_CpuFill8(void *,int,u32);
void IRC_COMPATIBLE_MENU_ExitFloaters(u8 *p) { int i; for(i=0;i<((struct Obj22169 *)p)->f34E;i++)IRC_COMPATIBLE_MENU_ExitFloater(p+i*28); MI_CpuFill8(p,0,848); }
