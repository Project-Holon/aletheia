/*
 * function: func_021B7F54
 * address: 0x021B7F54
 * packet: pkt_ov133_021B7F54
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA254 0x021BA254 thumb ov133
 *   func_021B8BB4 0x021B8BB4 thumb ov133
 *   func_021B8B78 0x021B8B78 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   d_021BA5A0 0x021BA5A0 data a4
 */
#include "../include/Obj00004.h"
#include "../include/Obj06497.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
typedef struct {int x,y;} Pair;
typedef struct {s16 y,x;u16 limit;} Scale;
extern const Vec d_021BA5A0;
extern u32 func_021BA218(u8 *p);
extern u8 *func_021F5450(u8 *,int);
extern int func_021B8BB4(u8 *,void *,const int *,u16 *);
extern int func_021B8B78(unsigned char *p, unsigned int id);
extern int func_021F4B24(u8 *);
extern void func_021BA21C(u8 *p, const u8 *src);
extern void func_021BA254(char *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021F4EE8(int,int,int);
extern void func_021F4E8C(int,int,Vec *);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021F4EC4(u32 unused, u32 p, s16 *a, s16 *b);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
void func_021B7F54(u8 *p,int sound)
{
    Vec v;
    Pair pos,relative;
    Scale scale;
    int old,index;
    u8 *sprite,*q;
    u16 rotation=0;
    scale.limit=12;v=d_021BA5A0;
    old=((struct Obj00004 *)p)->f34;sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    relative.x=((struct Obj00004 *)p)->f1C-128;relative.y=*(int *)&((struct Obj00004 *)p)->f20-112;
    index=func_021B8BB4(p,sprite,(const int *)&relative,&scale.limit);((struct Obj00004 *)p)->f34=index;
    if(index!=10){
        q=func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880,index);
        pos.x=(int)((float)(((struct Obj06497 *)q)->f4+((struct Obj06497 *)q)->f10)/4096.f)+128;
        pos.y=(int)((float)(((struct Obj06497 *)q)->f8+((struct Obj06497 *)q)->f14)/4096.f)+96;
        rotation=((struct Obj06497 *)q)->f36;func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,1);
        if(func_021F4B24(sprite)==1)v.z=0x1a000;
        if(func_021B8B78(p,((struct Obj00004 *)p)->f34)==0){((struct Obj00004 *)p)->f40=3;((struct Obj00004 *)p)->f44=pos.x;((struct Obj00004 *)p)->f48=pos.y;}
        func_021BA254((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),((struct Obj00004 *)p)->f34);
        if(old!=((struct Obj00004 *)p)->f34 && sound==1)GFL_USE_PlaySeDefaultVolume(0x627);
    }else{
        ((struct Obj00004 *)p)->f34=10;pos.x=((struct Obj00004 *)p)->f1C;pos.y=*(int *)&((struct Obj00004 *)p)->f20;
        func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,rotation);
    }
    if(pos.x>0)v.x=(int)(0.5f+(float)(int)((u32)pos.x<<12));else v.x=(int)((float)(int)((u32)pos.x<<12)-0.5f);
    if(pos.y>0)v.y=(int)(0.5f+(float)(int)((u32)pos.y<<12));else v.y=(int)((float)(int)((u32)pos.y<<12)-0.5f);
    func_021F4E8C(*(int *)(p+0x1884),(int)sprite,&v);
    func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&pos));
    q=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);func_021F4ED4(*(int *)(p+0x1884),(int)q,rotation);
    func_021F4EC4(*(int *)(p+0x1884),(int)sprite,&scale.x,&scale.y);
    if(scale.x<4096 || scale.y<4096){
        scale.x+=410;scale.y+=410;
        if(scale.x>4096)scale.x=4096;if(scale.y>4096)scale.y=4096;
        func_021F4EB4(*(int *)(p+0x1884),(int)sprite,scale.x,scale.y);
    }
}
