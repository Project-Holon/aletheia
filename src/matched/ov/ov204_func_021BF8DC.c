/*
 * function: func_021BF8DC
 * address: 0x021BF8DC
 * packet: pkt_ov204_021BF8DC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original forwards heap without narrowing at 021BF900 and 021BF950;
 * u32 heap externs remove the truncations inserted by the legacy u16 prototypes.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_DisableObjectAnime 0x020477D4 arm
 *   site 0x021C0B00 data a1
 *   va 0x021C0914 data a4
 *   vb 0x021C0920 data a4
 *   vc 0x021C0908 data a4
 *   setup 0x021C093C data a4
 */
#include "../include/Obj02921.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec3;
extern const Vec3 va,vb,vc;
extern const char site[];
extern const char setup[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *G3D_UTIL_Create(u16,u16,u32);
extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec3 *,Vec3 *,Vec3 *,u32);
extern u16 G3D_UTIL_AddUnit(void *,const void *);
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
struct G3dSys;
struct Owner;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);
char *func_021BF8DC(void *owner,int kind,u32 heap)
{
    Vec3 a,b,c;
    char *p;
    void *obj;
    p=func_02030734(heap,48,1,site,162);
    ((struct Obj02921 *)p)->f4=heap;
    ((struct Obj02921 *)p)->f0=owner;
    ((struct Obj02921 *)p)->f8=G3D_UTIL_Create(10,16,heap);
    a=va;b=vb;c=vc;
    ((struct Obj02921 *)p)->fC=G3D_CAMERA_Create(2,24576,(u32)-24576,(u32)-32768,32768,4096,4194304,4096,&a,&b,&c,heap);
    if(kind!=7){
        ((struct Obj02921 *)p)->f10=G3D_UTIL_AddUnit(((struct Obj02921 *)p)->f8,setup);
        obj=(void *)func_02048A18(((struct Obj02921 *)p)->f8,((struct Obj02921 *)p)->f10);
        G3D_SYSTEM_EnableObjectAnime(obj,3);G3D_SYSTEM_EnableObjectAnime(obj,4);
        G3D_SYSTEM_DisableObjectAnime(obj,0);G3D_SYSTEM_DisableObjectAnime(obj,1);G3D_SYSTEM_DisableObjectAnime(obj,2);
    }else ((struct Obj02921 *)p)->f10=0xffff;
    ((struct Obj02921 *)p)->f18=1;
    return p;
}
