/*
 * file:     guru2_p02.c
 * unit:     yes
 * function: func_021DC9F4, func_021DCAB4, func_021DCAF0, func_021DCAFC
 * address:  0x021DC9F4
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
 *   func_020307B0 0x020307B0 arm
 *   func_021DC950 0x021DC950 thumb ov137
 *   func_02031348 0x02031348 arm
 *   d_0000005B 0x0000005B data a1
 *   d_021BED00 0x021BED00 data ov091 a4
 *   func_021DC90C 0x021DC90C thumb ov137
 */
#include "../../matched/include/Obj08209.h"
#include "../../matched/include/Obj23669.h"
#include "../../matched/include/Obj23670.h"
#include "../../matched/include/Obj23671.h"

struct BigObj;
struct Blk37;
struct DC950Obj;
struct DC950Src;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_02031348(void *,int,const void *,void *);
extern struct DC950Obj *func_021DC950(struct DC950Src *p, int a, int b);
extern void func_021DC90C(u8 *p);
int func_021DC9F4(u32 *p);
int func_021DCAB4(u8 *p);
int func_021DCAE8(u32 *p);
int func_021DCAF0(u8 *p);
void *func_021DCAFC(u8 *p);
extern const u8 d_021E2260[],d_021DC800[],d_021E1A44[],d_00000083[];
extern const u8 d_0000005B[],d_021BED00[];

/*
 * func_020307B0 0x020307B0 arm
 * func_02030734 0x02030734 arm
 * func_02082BCC 0x02082BCC arm
 * func_02031348 0x02031348 arm
 * d_021E2260 0x021E2260 data a4
 * d_021DC800 0x021DC800 data a4 ov131
 * d_021E1A44 0x021E1A44 data a4
 * d_00000083 0x00000083 data a1
 */
int func_021DC9F4(u32 *p)
{
    u32 *v=(u32 *)p[6];
    int mode=v[16],sel=v[15];
    void *q;
    void *r;
    func_020307B0(v);
    if(mode==1) {
        func_02012944((void *)p[4]);
        q=func_0200CA1C((void *)p[4]);
        p[7]=(u32)func_02030734(4,40,0,(const char *)d_021E2260,328);
        func_02082BCC((void *)p[7],0,40);
        r=(void *)func_02012934((void *)p[4]);
        *(void **)p[7]=r;
        *(u32 *)(p[7]+8)=p[4];
        *(u8 *)(p[7]+12)=1;
        *(u8 *)(p[7]+14)=func_0201AA18(r);
        *(u8 *)(p[7]+15)=0;
        *(u8 *)(p[7]+13)=1;
        *(u16 *)(p[7]+20)=0;
        *(u8 *)(p[7]+16)=0;
        *(u32 *)(p[7]+24)=func_0200CA38(q);
        p[1]=sel;
        *(u8 *)(p[7]+15)=sel;
        func_02031348((void *)p[8],(int)d_00000083,d_021DC800,(void *)p[7]);
        p[0]=3;
    } else {
        *(u32 *)(p[3]+4)=sel;
        func_02031348((void *)p[8],-1,d_021E1A44,(void *)p[3]);
        *(u32 *)p[3]=3;
        p[0]=4;
    }
    return 0;
}

int func_021DCAB4(u8 *p) {u8 a;void *v;a=(*(u8 **)(p+28))[15];func_020307B0(((struct Obj08209 *)p)->f1C);v=func_021DC950((struct DC950Src *)p,21,a);((struct Obj08209 *)p)->f18=v;func_02031348(((struct Obj08209 *)p)->f20,(int)d_0000005B,d_021BED00,v);((struct Obj08209 *)p)->f0=2;return 0;}

int func_021DCAE8(u32 *p) {*p=5;return 0;}

int func_021DCAF0(u8 *p) {func_021DC90C(((struct Obj23669 *)p)->fC);return 1;}

void *func_021DCAFC(u8 *p) { return **(void ** *)&((struct Obj23671 *)(*(u8 * *)&((struct Obj23670 *)p)->f0))->f14; }
