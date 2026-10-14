/*
 * function: GURU2_EntryProcMain
 * address: 0x021DC888
 * packet: pkt_ov137_021DC888
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   gGuru2EntryStateTable 0x021E1A50 data a4
 */
#include "../include/Obj23665.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PROCSYS_Main(void *);
extern int (* const gGuru2EntryStateTable[])(u8 *);
int GURU2_EntryProcMain(void *obj,int a,int b,u8 *p) { switch(PROCSYS_Main(((struct Obj23665 *)p)->f20)) { case 0: if(gGuru2EntryStateTable[*(u32 *)p](p)==1) return 1; break; case 1: break; case 2: break; } return 0; }
