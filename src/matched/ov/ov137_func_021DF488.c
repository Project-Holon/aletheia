/*
 * function: GURU2_MAIN_StateWaitSe
 * address: 0x021DF488
 * packet: pkt_ov137_021DF488
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_PopBgmWhenDone 0x021E19A4 thumb ov137
 */
#include "../include/Obj08217.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GURU2_MAIN_PopBgmWhenDone(void);
int GURU2_MAIN_StateWaitSe(u8 *p) { if(((struct Obj08217 *)p)->fC<120) ((struct Obj08217 *)p)->fC+=1; else if(!GURU2_MAIN_PopBgmWhenDone()) { ((struct Obj08217 *)p)->fC=0; ((struct Obj08217 *)p)->f0=38; } return 0; }
