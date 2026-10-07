/*
 * function: func_021B95AC
 * address: 0x021B95AC
 * packet: pkt_ov133_021B95AC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_0207CFB8 0x0207CFB8 arm
 *   func_020061E4 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../../../matched/include/Obj00004.h"
#include "../../../matched/include/Obj23321.h"
#include "../../../matched/include/Obj23322.h"
#include "../../../matched/include/Obj23323.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 func_021BA258(char *p);
extern u32 func_021BA218(u8 *p);
extern u8 *func_021BA228(u8 *p);
extern u8 *func_021F5450(u8 *,int);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern u16 func_0207CFB8(long,long);
extern void func_020061E4(u32);
static inline int fx(int x)
{
    if(x>0) return (int)(0.5f+(float)(int)((unsigned)x<<12));
    return (int)((float)(int)((unsigned)x<<12)-0.5f);
}
void func_021B95AC(u8 *p)
{
    u16 index,angle;
    u8 *rec;
    u32 *xy;
    int dx,dy,stride,absval,y;
    s16 old,adjust;
    index=func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38));
    rec=func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880,index);
    func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    xy=(u32 *)func_021BA228(*(u8 * *)&((struct Obj00004 *)p)->f38);
    y=xy[1];
    dx=fx((int)(*(u32 *)&((struct Obj00004 *)p)->f1C-xy[0]));
    dy=fx((int)(((struct Obj00004 *)p)->f20-(unsigned)y));
    angle=func_0207CFB8(dx,dy);
    if(((struct Obj00004 *)p)->f30==1) {
        stride=index*6;
        old=*(s16 *)(*(u8 * *)&((struct Obj23322 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4+stride+0x16);
        adjust=old+(s16)(((struct Obj00004 *)p)->f2C-angle);
        if(adjust< -2730) adjust= -2730;
        if(adjust>2730) adjust=2730;
        ((struct Obj00004 *)p)->f18C4+=(s16)(old-adjust);
        absval=((struct Obj00004 *)p)->f18C4;
        if(absval<0) absval= -absval;
        if(absval>1820) {
            ((struct Obj00004 *)p)->f18C4=0;
            func_020061E4(1577);
        }
        func_021F4ED4((u32)(((struct Obj00004 *)p)->f1884),func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj23321 *)rec)->f36+adjust);
        *(s16 *)(*(u8 * *)&((struct Obj23323 *)(*(u8 * *)&((struct Obj00004 *)p)->f4))->f4+stride+0x16)=adjust;
    }
    ((struct Obj00004 *)p)->f2C=angle;
    ((struct Obj00004 *)p)->f30=1;
}
