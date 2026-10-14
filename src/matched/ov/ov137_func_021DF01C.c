/*
 * function: GURU2_MAIN_StateRoundDelay
 * address: 0x021DF01C
 * packet: pkt_ov137_021DF01C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_ClearNameWindow 0x021E0478 thumb ov137
 */
#include "../include/Obj06538.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_ClearNameWindow(u8 *p, u32 i);
int GURU2_MAIN_StateRoundDelay(u8 *p) { int i; ((struct Obj06538 *)p)->fC+=1; if(((struct Obj06538 *)p)->fC<95) return 0; for(i=0;i<((struct Obj06538 *)p)->f30;i++) GURU2_MAIN_ClearNameWindow(p,i); ((struct Obj06538 *)p)->fC=0; ((struct Obj06538 *)p)->f0=26; return 0; }
