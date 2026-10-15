/*
 * function: BR_UTIL_StepFollow
 * address: 0x021FE54C
 * packet: pkt_ov186_021FE54C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 370 instruction bytes; trailing 2 zero bytes at 0x021FE6BE are alignment.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   VEC_Mag 0x0207CBD0 arm
 *   func_0207C768 0x0207C768 arm
 */
#include "../include/Obj02904.h"
typedef unsigned int u32;
typedef struct {long x,y,z;} VecFx32;
extern long VEC_Mag(const VecFx32 *);
extern u32 func_0207C768(u32,u32);
static inline int roundFixed(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}
int BR_UTIL_StepFollow(char *p,int *out)
{
    VecFx32 delta;
    int length,x,y;
    delta.x=roundFixed((*(int **)p)[0])-((struct Obj02904 *)p)->f4;
    delta.y=roundFixed((*(int **)p)[1])-((struct Obj02904 *)p)->f8;
    delta.z=0;
    length=VEC_Mag(&delta);
    if(length) {
        x=func_0207C768((int)(((long long)delta.x* ((struct Obj02904 *)p)->f10+2048)>>12),length);
        y=func_0207C768((int)(((long long)delta.y* ((struct Obj02904 *)p)->f10+2048)>>12),length);
        if((delta.x<0?-delta.x:delta.x)>(x<0?-x:x))((struct Obj02904 *)p)->f4+=x;
        else ((struct Obj02904 *)p)->f4=roundFixed((*(int **)p)[0]);
        if((delta.y<0?-delta.y:delta.y)>(y<0?-y:y))((struct Obj02904 *)p)->f8+=y;
        else ((struct Obj02904 *)p)->f8=roundFixed((*(int **)p)[1]);
    }
    if(out){out[0]=((struct Obj02904 *)p)->f4>>12;out[1]=((struct Obj02904 *)p)->f8>>12;}
    return length==0;
}
