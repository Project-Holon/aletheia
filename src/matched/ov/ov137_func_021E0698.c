/*
 * function: func_021E0698
 * address: 0x021E0698
 * packet: pkt_ov137_021E0698
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   BUTTON_MAN_MakeRotMtxXYZ 0x020520FC arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 */
#include "../include/Obj14235.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { int m[9]; } Mtx;
typedef struct { Vec pos,scale; Mtx rot; } Transform;
typedef unsigned int   u32;
struct Arg;
extern u32 func_02048A18(u8 *a0, int i);
struct Mtx33;
extern void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, struct Mtx33 *dst);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x;
    v->y=y;
    v->z=z;
}
void func_021E0698(u8 *p)
{
    Transform t;
    void *object;
    object = (void *)func_02048A18(((struct Obj14235 *)p)->fAF4,(u16)(((struct Obj14235 *)p)->fDA4));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    BUTTON_MAN_MakeRotMtxXYZ(0,0,0,(struct Mtx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
}
