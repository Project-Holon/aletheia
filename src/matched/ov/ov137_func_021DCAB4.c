/*
 * unit: yes
 * function: GURU2_EntryStateReopenPartyList, GURU2_EntryStateFinish
 * address: 0x021DCAB4
 * packet: pkt_ov137_021DCAB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   GURU2_PartyListArgsCreate 0x021DC950 thumb ov137
 *   PROCSYS_Push 0x02031348 arm
 *   d_0000005B 0x0000005B data a1
 *   gPartyListProcData 0x021BED00 data ov091 a4
 */
#include "../include/Obj08209.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
struct DC950Obj;
struct DC950Src;
extern struct DC950Obj *GURU2_PartyListArgsCreate(struct DC950Src *p, int a, int b);
extern void PROCSYS_Push(void *,int,const void *,void *);
extern const u8 d_0000005B[],gPartyListProcData[];
int GURU2_EntryStateReopenPartyList(u8 *p) {u8 a;void *v;a=(*(u8 **)(p+28))[15];func_020307B0(((struct Obj08209 *)p)->f1C);v=GURU2_PartyListArgsCreate((struct DC950Src *)p,21,a);((struct Obj08209 *)p)->f18=v;PROCSYS_Push(((struct Obj08209 *)p)->f20,(int)d_0000005B,gPartyListProcData,v);((struct Obj08209 *)p)->f0=2;return 0;}
int GURU2_EntryStateFinish(u32 *p) {*p=5;return 0;}
