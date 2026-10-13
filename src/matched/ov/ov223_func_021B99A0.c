/*
 * function: func_021B99A0
 * address: 0x021B99A0
 * packet: pkt_ov223_021B99A0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: record index initialized before the accessor and stored into each slot.
 * symbols:
 *   setup 0x021BC7BC data a4
 *   positions 0x021BC7CC data a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_021B95B0 0x021B95B0 thumb ov223
 *   func_020489F4 0x020489F4 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 */
#include "../include/Obj00211.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {int x,y,z;} Vec;
struct Record{u16 id,pad;Vec translation,scale;u32 matrix[9],flag;};
struct Util;struct Setup;struct G3dSys;
extern const struct Setup setup;
extern const Vec positions[];
extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);
extern struct Record *func_021B95B0(u32,u32);
extern u32 func_020489F4(u8 *,int);
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *,u32);
extern void *ICA_ANIME_CreateStream(u32,u32,u32,u32);
extern unsigned func_021BC52C(unsigned char *p);
extern void ICA_ANIME_SetCameraStatus(void *,void *);
void func_021B99A0(char *p)
{
    u16 i,n,j;
    u32 base,count;
    int *obj;
    struct Record *r;
    ((struct Obj00211 *)p)->f2E=G3D_UTIL_AddUnit(*(struct Util * *)&((struct Obj00211 *)p)->f28,&setup);
    ((struct Obj00211 *)p)->f3A=4;
    *(struct Record * *)&((struct Obj00211 *)p)->f3C=func_021B95B0(((struct Obj00211 *)p)->f0,((struct Obj00211 *)p)->f3A);
    n=0;
    base=func_020489F4(*(u8 * *)&((struct Obj00211 *)p)->f28,((struct Obj00211 *)p)->f2E);
    for(i=0;i<4;i++) {
        *(u16 *)(p+i*2+50)=n;
        r=*(struct Record * *)&((struct Obj00211 *)p)->f3C+n;
        r->id=base+i;
        r->flag=1;
        if(i+1>=2&&i+1<=4)r->translation=*(positions+i-1);
        n++;
    }
    obj=(int *)func_02048A18(*(u8 * *)&((struct Obj00211 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00211 *)p)->f3C+((struct Obj00211 *)p)->f32*68));
    count=G3D_SYSTEM_GetObjectAnimeCount(obj);
    for(j=0;j<count;j++)G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)obj,j);
    ((struct Obj00211 *)p)->f40=ICA_ANIME_CreateStream(((struct Obj00211 *)p)->f0,205,36,10);
    ICA_ANIME_SetCameraStatus((void *)func_021BC52C(((struct Obj00211 *)p)->f14),((struct Obj00211 *)p)->f40);
    ((struct Obj00211 *)p)->f50=0;
}
