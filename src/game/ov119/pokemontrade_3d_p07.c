/*
 * file:     pokemontrade_3d_p07.c
 * unit:     yes
 * function: func_021E2C3C, func_021E2D70, func_021E2EA0, func_021E2EFC, func_021E2F2C, func_021E2F34, func_021E2FB0
 * address:  0x021E2C3C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02011CF0 0x02011CF0 thumb
 *   func_02011D0C 0x02011D0C thumb
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02011610 0x02011610 thumb
 *   func_02051838 0x02051838 arm
 *   d_021E79C8 0x021E79C8 data a4
 *   func_02011510 0x02011510 thumb
 *   func_020115EC 0x020115EC thumb
 *   func_02011558 0x02011558 thumb
 *   func_02050B80 0x02050B80 arm
 *   func_02030734 0x02030734 arm
 *   func_02050C04 0x02050C04 arm
 *   d_021E81C0 0x021E81C0 data a4
 *   func_0205121C 0x0205121C arm
 *   func_02087A3C 0x02087A3C arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051360 0x02051360 arm
 */
#include "../../matched/include/Obj00673.h"
#include "../../matched/include/Obj02173.h"
#include "../../matched/include/Obj08067.h"
#include "../../matched/include/Obj04480.h"
#include "../../matched/include/Obj08068.h"

struct Light;
struct IcaAnime;
struct Rec12;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct { VecFx32 trans; VecFx32 scale; MtxFx33 rot; } Transform;

typedef struct {
    char pad0[0x90];
    u32 anim90;
    u32 anim94;
    u32 anim98;
    u32 anim9c;
    void *objA0;
    void *objA4;
    void *objA8;
    void *objAC;
} Sub;

typedef struct {
    char pad0[0xc];
    Sub *sub;
    char pad10[0x83c - 0x10];
    void *x83c;
} Work;

typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } Shading;

typedef signed int     s32_021E2D70;

typedef short s16;

typedef signed char s8;

typedef int s32_021E2F2C;

extern void func_0207ADC4(MtxFx33 *m);
extern void func_02011CF0(void *a0, void *a1);
extern void func_02011D0C(void *a0, void *a1);
extern void func_02048AD0(struct Light *l);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_02046A94(u32 idx, const u16 *src);
extern u32 func_02011610(struct IcaAnime *t, struct Rec12 *out);
extern void func_02051838(void *obj, VecFx32 *v);
extern void *func_02011510(u32,u32,u32,u32);
extern void func_020115EC(struct IcaAnime *p, s32_021E2D70 v);
extern void func_02011558(struct IcaAnime *p);
extern void func_02050B80(u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void *func_02087A3C(int,int);
extern int func_020056BC(void *);
extern void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3);
void func_021E2C3C(Work *w, Transform *t);
void func_021E2D70(char *p,unsigned mode);
void func_021E2EA0(char *p);
void func_021E2EFC(char *p);
void func_021E2F2C(void *a0);
void func_021E2F34(char *p);
void func_021E2FB0(char *p);
extern char d_021E79C8[];
extern char d_021E81C0[];

static inline void shading(Shading s) { *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3002) | (s << 1)); }

static inline void antialias(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10); else *(volatile u16 *)0x04000060 &= (u16)~0x3010; }

static inline void alphatest(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 4); else *(volatile u16 *)0x04000060 &= (u16)~0x3004; }

static inline void blend(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8); else *(volatile u16 *)0x04000060 &= (u16)~0x3008; }

static inline void edge(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x20); else *(volatile u16 *)0x04000060 &= (u16)~0x3020; }

/*
 * volatile: 0x04000060 reread at 021E2C9C, 021E2CAA, 021E2CB6, 021E2CC0, 021E2CC8; 0x04000580 hardware store at 021E2CEC.
 */
void func_021E2C3C(Work *w, Transform *t)
{
    unsigned i;
    VecFx32 v1;
    VecFx32 v2;
    t->trans.x = 0;
    t->trans.y = 0;
    t->trans.z = 0;
    t->scale.x = 0x1000;
    t->scale.y = 0x1000;
    t->scale.z = 0x1000;
    func_0207ADC4(&t->rot);
    if (w->sub != 0) {
        if (w->sub->objA8 == 0) func_02011CF0(w->x83c, (void *)w->sub->anim90);
        if (w->sub->objAC == 0) func_02011D0C(w->x83c, (void *)w->sub->anim94);
    }
    func_02048AD0(w->x83c);
    shading(SHADING_HIGHLIGHT); antialias(1); alphatest(0); blend(0); edge(0);
    func_0207DC44(1, 0, 0, 0);
    func_0207DD24(0, 0, 0x7fff, 0x3f, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++) func_02046A94((u8)i, (const u16 *)(d_021E79C8 + i * 8));
    if (w->sub != 0) {
        if (w->sub->objA0 != 0) {
            func_02011610((struct IcaAnime *)w->sub->anim98, (struct Rec12 *)&v1);
            func_02051838(w->sub->objA0, &v1);
        }
        if (w->sub->objA4 != 0) {
            func_02011610((struct IcaAnime *)w->sub->anim9c, (struct Rec12 *)&v2);
            func_02051838(w->sub->objA4, &v2);
        }
    }
}

void func_021E2D70(char *p,unsigned mode)
{
    switch(mode) {
    case 0:
        ((struct Obj00673 *)p)->f90=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x38,10);
        ((struct Obj00673 *)p)->f94=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x39,10);
        ((struct Obj00673 *)p)->f98=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        ((struct Obj00673 *)p)->f9C=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        break;
    case 1:
        ((struct Obj00673 *)p)->f90=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x3f,10);
        ((struct Obj00673 *)p)->f94=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x3e,10);
        ((struct Obj00673 *)p)->f98=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        break;
    case 2:
        ((struct Obj00673 *)p)->f90=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x3d,10);
        ((struct Obj00673 *)p)->f94=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x3c,10);
        break;
    case 3:
        ((struct Obj00673 *)p)->f90=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x3b,10);
        ((struct Obj00673 *)p)->f94=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x3a,10);
        ((struct Obj00673 *)p)->f9C=func_02011510(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        func_020115EC(((struct Obj00673 *)p)->f9C,0x2b5000);
        break;
    }
}

/*
 * follower: two-byte zero alignment padding at 0x021E2EFA.
 */
void func_021E2EA0(char *p) {
    if (((struct Obj02173 *)p)->f90) {func_02011558(((struct Obj02173 *)p)->f90); ((struct Obj02173 *)p)->f90=0;}
    if (((struct Obj02173 *)p)->f94) {func_02011558(((struct Obj02173 *)p)->f94); ((struct Obj02173 *)p)->f94=0;}
    if (((struct Obj02173 *)p)->f98) {func_02011558(((struct Obj02173 *)p)->f98); ((struct Obj02173 *)p)->f98=0;}
    if (((struct Obj02173 *)p)->f9C) {func_02011558(((struct Obj02173 *)p)->f9C); ((struct Obj02173 *)p)->f9C=0;}
}

/*
 * extent: 46-byte body followed by 2-byte alignment padding.
 */
void func_021E2EFC(char *p)
{
    ((struct Obj08067 *)p)->f90=func_02011510(((struct Obj08067 *)p)->fBA,0x68,0xb,10);
    ((struct Obj08067 *)p)->f94=func_02011510(((struct Obj08067 *)p)->fBA,0x68,0xc,10);
}

void func_021E2F2C(void *a0) { func_021E2EA0(a0); }

void func_021E2F34(char *p) {
    int i,flag;
    func_02050B80(((struct Obj04480 *)p)->fBA);
    ((struct Obj04480 *)p)->fB4=0;
    for(i=0;i<9;i++) {
        ((void **)p)[9+i]=func_02030734(((struct Obj04480 *)p)->fBA,0x4800,1,d_021E81C0,0x201);
        switch(i) {
        case 0: case 1: case 2: case 5: case 6: case 8: flag=0; break;
        case 3: case 4: case 7: default: flag=1; break;
        }
        ((void **)p)[i]=(void *)func_02050C04((int)(((void **)p)[9+i]),0x4800,flag,((struct Obj04480 *)p)->fBA);
    }
}

void func_021E2FB0(char *p) {
    int i;
    ((struct Obj08068 *)p)->fB4=(void *)func_0205121C((int)0x67,(int)0x35,(u16)((((struct Obj08068 *)p)->fBA&0x7fff)|0x8000));
    for(i=0;i<4;i++) {
        int x=func_020056BC(func_02087A3C(1,1));
        func_02051360(((void **)p)[i],(unsigned int)(((struct Obj08068 *)p)->fB4),1,x);
    }
}
