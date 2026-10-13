/*
 * function: func_021E68F4
 * address: 0x021E68F4
 * packet: pkt_ov119_021E68F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021E7DEC 0x021E7DEC data a2
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct { short x,y; } Pt;
typedef struct { Pt pos[6]; } Table;
extern const Table d_021E7DEC;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p,unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
typedef unsigned int   u32;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021E68F4(int p, int i) {
    Table t=d_021E7DEC;
    Create c;
    if(i==-1) {
        if(((struct Obj00001 *)p)->fFD4) CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00001 *)p)->fFD4,0);
    } else {
        if(!((struct Obj00001 *)p)->fFD4) {
            c.x=64;c.y=48;c.z=23;c.a=0;c.b=1;
            ((struct Obj00001 *)p)->fFD4=(int)CLACT_CreateActor((void *)((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f894,((struct Obj00001 *)p)->f880,((struct Obj00001 *)p)->f8B0,&c,1,((struct Obj00001 *)p)->f5F4);
        }
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00001 *)p)->fFD4,1);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00001 *)p)->fFD4,1);
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00001 *)p)->fFD4),(const struct Vec2 *)(&t.pos[i]),1);
    }
}
