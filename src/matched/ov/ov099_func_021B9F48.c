/*
 * function: func_021B9F48
 * address: 0x021B9F48
 * packet: pkt_ov099_021B9F48
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA0F8 0x021BA0F8 thumb ov099
 *   CLACT_SetActorPos 0x0204B528 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj06349.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x,y; } Pos;
struct Obj;
extern void func_021BA0F8(void *,u16 *); extern void CLACT_SetActorPos(void *,Pos *); extern void func_0204B3DC(struct Obj *,unsigned int);
void func_021B9F48(u8 *p) { Pos b; Pos a; func_021BA0F8(p,(u16 *)&b); b.x+=8; b.y+=32; a.x=b.x; a.y=b.y; CLACT_SetActorPos(((struct Obj06349 *)p)->f28,&a); func_0204B3DC(((struct Obj06349 *)p)->f28,1); }
