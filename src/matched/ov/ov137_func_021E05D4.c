/*
 * function: func_021E05D4
 * address: 0x021E05D4
 * packet: pkt_ov137_021E05D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 */
#include "../include/Obj02872.h"
#include "../include/Obj23776.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { int x,y,z; } Vec;
typedef struct { int m[9]; } Mtx;
typedef struct { Vec pos,scale; Mtx rot; } Transform;
typedef unsigned int   u32;
struct Arg;
extern u32 func_02048A18(u8 *a0, int i);
struct Mtx33;
extern void func_020520FC(int,int,int,struct Mtx33 *);
extern void func_02047A60(void *a0, struct Arg *a1);
static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x; v->y=y; v->z=z;
}
void func_021E05D4(u8 *p)
{
    Transform t;
    u8 *s;
    void *object;
    s=p+224;
    object=(void *)func_02048A18(((struct Obj23776 *)p)->fAF4,(u16)(((struct Obj02872 *)s)->fBC));
    VecSet(&t.pos,((struct Obj02872 *)s)->fC,((struct Obj02872 *)s)->f10,((struct Obj02872 *)s)->f14);
    VecSet(&t.scale,((struct Obj02872 *)s)->f18,((struct Obj02872 *)s)->f1C,((struct Obj02872 *)s)->f20);
    func_020520FC(((struct Obj02872 *)s)->f4C,(u16)(((struct Obj02872 *)s)->f4E*182),((struct Obj02872 *)s)->f50,(struct Mtx33 *)&t.rot);
    func_02047A60(object,(struct Arg *)(&t));
}
