/*
 * function: func_021BA098
 * address: 0x021BA098
 * packet: pkt_ov133_021BA098
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
typedef struct {short x,y;} Pos;
extern void func_0204B9A0(struct Actor*);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(void*,const Pos*,unsigned);
void func_021BA098(u8*p){Pos pos;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;func_0204B9A0(*(struct Actor* *)&((struct Obj00004 *)p)->f18B4);func_0204B3DC(*(void* *)&((struct Obj00004 *)p)->f18B4,1);func_0204B404(*(void* *)&((struct Obj00004 *)p)->f18B4,&pos,0);}
