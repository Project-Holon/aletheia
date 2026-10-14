/*
 * function: GURU2_EntryStateStartReceipt
 * address: 0x021DC928
 * packet: pkt_ov137_021DC928
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_SessionCreate 0x021DC8D0 thumb ov137
 *   PROCSYS_Push 0x02031348 arm
 *   gGuru2LobbyProcData 0x021E1A38 data a4
 */
#include "../include/Obj08208.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GURU2_SessionCreate(void *,int);
extern void PROCSYS_Push(void *,int,const void *,void *);
extern const u8 gGuru2LobbyProcData[];
int GURU2_EntryStateStartReceipt(u8 *p) {void *v;v=GURU2_SessionCreate(((struct Obj08208 *)p)->f8,4);((struct Obj08208 *)p)->f0=1;((struct Obj08208 *)p)->fC=v;PROCSYS_Push(((struct Obj08208 *)p)->f20,-1,gGuru2LobbyProcData,v);return 0;}
