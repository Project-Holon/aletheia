/*
 * function: SHINKA_DEMO_VIEW_ExitMcss
 * address: 0x022060BC
 * packet: pkt_ov195_022060BC
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_Exit 0x02014BA8 thumb
 */
#include "../include/Obj02911.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern void MCSS_Exit(u8 *a0);
void SHINKA_DEMO_VIEW_ExitMcss(char *p){MCSS_Exit(((struct Obj02911 *)p)->f4C);}
