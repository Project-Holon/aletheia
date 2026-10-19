/*
 * function: WIFILOGIN_DISP_VBlank
 * address: 0x021D5900
 * packet: pkt_ov115_021D5900
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj10333.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void CLACT_VBlankSystem(void);
void WIFILOGIN_DISP_VBlank(void *task,u8 *p) { if(((struct Obj10333 *)p)->fB4A>0) { BG_SYS_ChangeScrollImmediate(7,0,((struct Obj10333 *)p)->fB4A-1); BG_SYS_ChangeScrollImmediate(2,0,((struct Obj10333 *)p)->fB4A-1); } CLACT_VBlankSystem(); }
