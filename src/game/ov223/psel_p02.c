/*
 * file:     psel_p02.c
 * unit:     yes
 * function: func_021B97F8, func_021B9830, func_021B9848, func_021B9854, func_021B98F4, func_021B9914, func_021B99A0
 * address:  0x021B97F8
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E54 0x02047E54 arm
 *   func_02047E88 0x02047E88 arm
 *   func_021B95B0 0x021B95B0 thumb ov223
 *   func_020489F4 0x020489F4 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   func_02011510 0x02011510 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 *   d_021BC7AC 0x021BC7AC data a4
 *   func_020480E4 0x020480E4 arm
 *   func_021B9600 0x021B9600 thumb ov223
 *   func_02011558 0x02011558 thumb
 *   func_02047910 0x02047910 arm
 *   func_02011590 0x02011590 thumb
 *   setup 0x021BC7BC data a4
 *   positions 0x021BC7CC data a4
 */
#include "../../matched/include/Obj03962.h"
#include "../../matched/include/Obj14786.h"
#include "../../matched/include/Obj00739.h"
#include "../../matched/include/Obj02266.h"
#include "../../matched/include/Obj05570.h"
#include "../../matched/include/Obj01594.h"
#include "../../matched/include/Obj00211.h"

struct Arg;
struct Rec;
struct G3dSys;
struct Record;
struct Ctx;
struct IcaAnime;
struct Util;
struct Setup;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct {int x,y,z;} Vec;

struct Record{u16 id,pad;Vec translation,scale;u32 matrix[9],flag;};

extern void *func_02048A18(u8 *,int);
extern void func_02047A60(void *,struct Arg *);
extern int func_02047CFC(int, int, u16);
extern void func_02047E54(struct Rec *);
extern u16 func_02047E88(void *, const void *);
extern struct Record *func_021B95B0(u32 heap, u32 count);
extern u32 func_020489F4(u8 *a0, int i);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void *func_02011510(u32 heap, u32 b, u32 c, u32 d);
extern unsigned func_021BC52C(u8 *p);
extern void func_02011B8C(void *, void *);
extern void func_020480E4(struct Ctx *,u32),func_021B9600(void *),func_02011558(struct IcaAnime *);
extern int func_02047910(void *,int,int);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
void func_021B97F8(char *p);
void func_021B9830(char *p);
void func_021B9848(int *p);
void func_021B9854(u8 *p);
void func_021B98F4(char *p);
void func_021B9914(char *p);
void func_021B99A0(char *p);
extern const u8 d_021BC7AC[];
extern const struct Setup setup;
extern const Vec positions[];

void func_021B97F8(char *p) { u16 i;for(i=0;i<((struct Obj03962 *)p)->f3A;i++){char *q=(char *)(((struct Obj03962 *)p)->f3C+(u32)i*68);if(((struct Obj14786 *)q)->f40)func_02047A60(func_02048A18(*(u8 * *)&((struct Obj03962 *)p)->f28,((struct Obj14786 *)q)->f0),(struct Arg *)(q+4));} }


void func_021B9830(char *p)
{
    ((struct Obj00739 *)p)->f28 = func_02047CFC(5, 4, ((struct Obj00739 *)p)->f0);
    ((struct Obj00739 *)p)->f3A = 0;
}

void func_021B9848(int *p) { func_02047E54(*(struct Rec * *)&((struct Obj02266 *)p)->f28); }

void func_021B9854(u8 *p)
{
    u16 i;
    u32 n;
    u16 j;
    u8 *rec;
    u32 r;
    void *h;
    *(u16 *)(p + 0x2C) = func_02047E88(*(void **)(p + 0x28), d_021BC7AC);
    *(u16 *)(p + 0x3A) = 1;
    *(void **)(p + 0x3C) = func_021B95B0(*(u16 *)p, *(u16 *)(p + 0x3A));
    r = func_020489F4(*(void **)(p + 0x28), *(u16 *)(p + 0x2C));
    *(u16 *)(p + 0x30) = 0;
    rec = *(u8 **)(p + 0x3C);
    *(u16 *)rec = r;
    *(u32 *)(rec + 0x40) = 1;
    for (i = 0; i < *(u16 *)(p + 0x3A); i++) {
        h = (void *)func_02048A18(*(void **)(p + 0x28), *(u16 *)(*(u8 **)(p + 0x3C) + i * 0x44));
        n = func_0204779C(h);
        for (j = 0; j < n; j++) {
            func_020477A4(h, j);
        }
    }
    *(void **)(p + 0x40) = func_02011510(*(u16 *)p, 0xCD, 0x21, 0xA);
    func_02011B8C((void *)func_021BC52C(*(u8 **)(p + 0x14)), *(void **)(p + 0x40));
    *(u32 *)(p + 0x50) = 0;
}

void func_021B98F4(char *p) { func_020480E4(*(struct Ctx * *)&((struct Obj05570 *)p)->f28,((struct Obj05570 *)p)->f2C);func_021B9600(((struct Obj05570 *)p)->f3C);((struct Obj05570 *)p)->f3A=0;func_02011558(*(struct IcaAnime * *)&((struct Obj05570 *)p)->f40); }

void func_021B9914(char *p)
{
    int *obj;
    u32 n;
    u16 i,j;
    for(i=0;i<((struct Obj01594 *)p)->f3A;i++) {
        obj=(int *)func_02048A18(*(unsigned char * *)&((struct Obj01594 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj01594 *)p)->f3C+i*68));
        n=func_0204779C(obj);
        for(j=0;j<n;j++) func_02047910(obj,j,2048);
    }
    func_02011590(((struct Obj01594 *)p)->f40,2048);
    func_02011B8C((void *)func_021BC52C(((struct Obj01594 *)p)->f14),((struct Obj01594 *)p)->f40);
    (*(u32 *)&((struct Obj01594 *)p)->f50)++;
}

void func_021B99A0(char *p)
{
    u16 i,n,j;
    u32 base,count;
    int *obj;
    struct Record *r;
    ((struct Obj00211 *)p)->f2E=func_02047E88(*(struct Util * *)&((struct Obj00211 *)p)->f28,&setup);
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
    count=func_0204779C(obj);
    for(j=0;j<count;j++)func_020477A4((struct G3dSys *)obj,j);
    ((struct Obj00211 *)p)->f40=func_02011510(((struct Obj00211 *)p)->f0,205,36,10);
    func_02011B8C((void *)func_021BC52C(((struct Obj00211 *)p)->f14),((struct Obj00211 *)p)->f40);
    ((struct Obj00211 *)p)->f50=0;
}
