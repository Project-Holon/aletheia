/*
 * function: WIFICLUBACTOR_SpawnEntity
 * address: 0x021BA1C4
 * packet: pkt_ov099_021BA1C4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_Create 0x021C4918 thumb ov127
 */
#include "../include/Obj06347.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x,y; u16 a,b,c,d; } Params;
extern void *WF2DMAP_OBJ_Create(void *,Params *);
void WIFICLUBACTOR_SpawnEntity(u8 *p,void **out,short *xy,int a,u16 d,u8 c,int b) { Params q; q.x=xy[0]; q.y=xy[1]; q.a=a; q.b=b; q.c=c; q.d=d; *out=WF2DMAP_OBJ_Create(((struct Obj06347 *)p)->f58C,&q); }
