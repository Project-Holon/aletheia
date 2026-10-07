/*
 * file:     dup_fitting_item_p05.c
 * unit:     yes
 * function: func_021B8140, func_021B8254
 * address:  0x021B8140
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA19C 0x021BA19C thumb ov133
 *   func_021BA100 0x021BA100 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021B7A18 0x021B7A18 thumb ov133
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_020061E4 0x020061E4 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_021BA5B8 0x021BA5B8 data a4
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA124 0x021BA124 thumb ov133
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 */
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj23312.h"

struct Object;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x,y,z; } Vec;

typedef struct { u32 x,y; } Pair;

typedef struct { short y,x; } Scale;

typedef signed short   s16;

extern u32 func_021BA20C(u8 *p);
extern u32 func_021BA218(u8 *p);
extern u8 *func_021BA19C(u16 heap, struct Object *q, u8 *r, int *v);
extern void func_021BA100(u8 *p, u8 *q);
extern void func_021BA21C(u8 *p, const u8 *src);
extern u8 *func_021BA228(u8 *p);
extern void func_021F4EC4(u32 unused, u32 p, s16 *a, s16 *b);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021F4EE8(int,int,int),func_021B7A18(u8 *),func_020061E4(u32);
extern void func_021BA148(u8 *p, u8 *q);
extern void func_021BA124(u8 *p, u8 *q);
extern void *func_021BA184(char *p);
extern u32 func_021BA208(u8 *p);
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
extern void func_021F4E8C(int, int, Vec *);
void func_021B8140(u8 *p);
void func_021B8254(u8 *p);
extern const Vec d_021BA5B8;

void func_021B8140(u8 *p)
{
    Vec scale=d_021BA5B8;
    Pair pos;
    Scale old;
    u8 *q,*data,*s,*t;
    u32 *v;
    data=(u8 *)func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38);
    pos.x=*(u32 *)&((struct Obj00004 *)p)->f1C;pos.y=((struct Obj00004 *)p)->f20;
    if(pos.x!=0) scale.x=(int)(0.5f+(float)(pos.x<<12));
    else scale.x=(int)((float)(pos.x<<12)-0.5f);
    if(((struct Obj00004 *)p)->f20!=0) scale.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f20<<12));
    else scale.y=(int)((float)(((struct Obj00004 *)p)->f20<<12)-0.5f);
    q=func_021BA19C(((struct Obj00004 *)p)->f0,((struct Obj00004 *)p)->f1884,data,(int *)(&scale));
    func_021BA100(((struct Obj00004 *)p)->f1820,q);
    func_021BA21C(q,(const u8 *)(&pos));
    s=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);t=(u8 *)func_021BA218(q);
    func_021F4EC4(*(int *)&((struct Obj00004 *)p)->f1884,(int)s,&old.x,&old.y);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884,(int)t,old.x,old.y);
    func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884,(int)t,0);
    v=(u32 *)func_021BA228(*(u8 * *)&((struct Obj00004 *)p)->f38);
    *(u32 *)&((struct Obj00004 *)p)->f40=1;
    *(u32 *)&((struct Obj00004 *)p)->f44=v[0];*(u32 *)&((struct Obj00004 *)p)->f48=v[1];
    *(u32 *)&((struct Obj00004 *)p)->f3C=2;*(u8 * *)&((struct Obj00004 *)p)->f38=q;*(u32 *)&((struct Obj00004 *)p)->f40=1;
    ((struct Obj23312 *)data)->fC=1;
    func_021B7A18(p);func_020061E4(0x625);
}

void func_021B8254(u8 *p)
{
    Vec v;
    u8 *e, *s;
    int z = 0xa000;
    s = (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA148(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA124(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021F4EB4(*(int *)&((struct Obj00004 *)p)->f1884, (int)s, 4096, 4096);
    e = func_021BA184(((struct Obj00004 *)p)->f1820);
    while (e) {
        s = (u8 *)func_021BA218(e);
        func_021F4EA4(*(int *)(p + 0x1884), (int)s, (u32)(&v));
        v.z = z;
        func_021F4E8C(*(int *)(p + 0x1884), (int)s, &v);
        z -= 1024;
        e = (u8 *)func_021BA208(e);
    }
}
