/*
 * file:     guru2_main_p12.c
 * unit:     yes
 * function: func_021E04B4, func_021E04C4, func_021E04E0, func_021E0554, func_021E0570, func_021E05D4, func_021E0634
 * address:  0x021E04B4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02035C08 0x02035C08 arm
 *   d_021E1CB0 0x021E1CB0 data a4
 *   func_02047E88 0x02047E88 arm
 *   d_021E20EC 0x021E20EC data a4
 *   d_021E1DE8 0x021E1DE8 data a4
 *   func_020480E4 0x020480E4 arm
 *   func_021E15DC 0x021E15DC thumb ov137
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 */
#include "../../matched/include/Obj03842.h"
#include "../../matched/include/Obj02499.h"
#include "../../matched/include/Obj10625.h"
#include "../../matched/include/Obj23775.h"
#include "../../matched/include/Obj14232.h"
#include "../../matched/include/Obj01754.h"
#include "../../matched/include/Obj14233.h"
#include "../../matched/include/Obj02872.h"
#include "../../matched/include/Obj23776.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
struct Bank;
struct Util;
struct Setup;
struct Ctx;
struct Arg;
struct Mtx33;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x,y,z; } Vec;

typedef struct { int a[4]; } Descriptor;

typedef short s16;

typedef struct { int m[9]; } Mtx;

typedef struct { Vec pos,scale; Mtx rot; } Transform;

extern u32 func_02048AC4(void *ptr);
extern int func_02035C08(const void *);
extern int func_02047E88(void *,const void *);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_021E15DC(int *,int);
extern u32 func_02048A18(u8 *a0, int i);
extern void func_020520FC(int,int,int,struct Mtx33 *);
extern void func_02047A60(void *a0, struct Arg *a1);
void func_021E04B4(u8 *p);
int func_021E04C4(char *a0);
void func_021E04E0(u8 *p);
void func_021E0554(u8 *p);
void func_021E0570(u8 *p);
void func_021E05D4(u8 *p);
void func_021E0634(u8 *p,int a);
extern const u8 d_021E1CB0[];
extern const Descriptor d_021E20EC[];
extern const int d_021E1DE8[];

void func_021E04B4(u8 *p){func_02048AC4(((struct Obj03842 *)p)->fD54);}

int func_021E04C4(char *a0){if(func_02035C08(d_021E1CB0)!=-1)return 1;return 0;}

/*
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 */
void func_021E04E0(u8 *p)
{
    int index;
    enum { ZERO } zero;
    u8 *s;
    index=((struct Obj23775 *)(*(u8 * *)&((struct Obj10625 *)p)->fD8))->f8;
    s=p+224;
    ((struct Obj02499 *)s)->fBC=func_02047E88(((struct Obj10625 *)p)->fAF4,&d_021E20EC[index-2]);
    zero=0;
    ((struct Obj02499 *)s)->f44=d_021E1DE8[index];
    ((struct Obj02499 *)s)->f18=4096;
    ((struct Obj02499 *)s)->f1C=4096;
    ((struct Obj02499 *)s)->f20=4096;
    ((struct Obj02499 *)s)->f4C=0;
    ((struct Obj02499 *)s)->f4E=0;
    ((struct Obj02499 *)s)->f50=0;
    ((struct Obj02499 *)s)->f3C=zero;
    ((struct Obj10625 *)p)->fE0=zero;
    ((struct Obj02499 *)s)->f4=-147456;
    ((struct Obj02499 *)s)->f8=zero;
    *(Vec *)(s+12)=*(Vec *)s;
}

void func_021E0554(u8 *p){func_020480E4(*(struct Ctx * *)&((struct Obj14232 *)p)->fAF4,(u16)(((struct Obj14232 *)p)->f19C));}

void func_021E0570(u8 *p)
{
    u8 *s;
    int angle;
    s=p+224;
    angle=((struct Obj14233 *)p)->f58;
    func_021E15DC(&angle,((struct Obj01754 *)s)->f40);
    func_021E15DC(&angle,((struct Obj01754 *)s)->f44);
    ((struct Obj01754 *)s)->f4E=(360-angle/4096)%360;
    ((struct Obj01754 *)s)->fC=((struct Obj14233 *)p)->fE0+((struct Obj01754 *)s)->f30+((struct Obj01754 *)s)->f24;
    ((struct Obj01754 *)s)->f10=((struct Obj01754 *)s)->f4+((struct Obj01754 *)s)->f34+((struct Obj01754 *)s)->f28;
    ((struct Obj01754 *)s)->f14=((struct Obj01754 *)s)->f8+((struct Obj01754 *)s)->f38+((struct Obj01754 *)s)->f2C;
}

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

void func_021E0634(u8 *p,int a){func_021E15DC((int *)(p+0x3c),a);}
