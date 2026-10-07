/*
 * file:     sta_act_light_p03.c
 * unit:     yes
 * function: func_021F6F64, func_021F6F8C, func_021F6FB0
 * address:  0x021F6F64
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047910 0x02047910 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02047A60 0x02047A60 arm
 *   d_021F8430 0x021F8430 data a4
 *   d_021F8418 0x021F8418 data a4
 *   func_021F7048 0x021F7048 thumb ov112
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 */
#include "../../matched/include/Obj13837.h"
#include "../../matched/include/Obj13838.h"

struct Arg;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;

extern int func_02047910(void *,int,int);
extern void func_0207ADC4(void *);
extern void func_02047A60(void *,struct Arg *);
extern void func_021F7048(Cleanup *);
extern void *func_02046DB8(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
void func_021F6F64(u8 *p);
void func_021F6F8C(u8 *p);
void func_021F6FB0(Cleanup *p, char *q);
extern u32 d_021F8430[];
extern struct Arg d_021F8418;

void func_021F6F64(u8 *p) { u8 i; if(((struct Obj13837 *)p)->f1C) { for(i=0;i<3;i++) func_02047910(((struct Obj13837 *)p)->f3C,i,4096); } }

void func_021F6F8C(u8 *p) { if(((struct Obj13838 *)p)->f1C) { func_0207ADC4(d_021F8430); func_02047A60(((struct Obj13838 *)p)->f3C,&d_021F8418); } }

/*
 * extent: two-byte zero padding before 021F7048.
 */
void func_021F6FB0(Cleanup *p, char *q) {
    u8 i, j;
    if (p->single != 0) func_021F7048(p);
    p->single = (int)func_02046DB8(0x2f, (u32)(q + 0x1e));
    p->a[0] = (int)func_02046DB8(0x2f, (u32)(q + 0x24));
    p->a[1] = (int)func_02046DB8(0x2f, (u32)(q + 0x2e));
    p->a[2] = (int)func_02046DB8(0x2f, (u32)(q + 0x29));
    if (func_02046FF8((int *)p->single) != 0) {
        p->b = (int)func_02047400((void *)p->single, 0, (void *)p->single);
        for (i = 0; i < 3; i++) p->c[i] = (int)func_02047564((struct G3dOwner *)p->b, (const struct G3dOwner *)p->a[i], 0);
        p->d = (int)func_0204767C(p->b, (u32 *)p->c, 3);
        for (j = 0; j < 3; j++) func_020477A4((struct G3dSys *)p->d, j);
    }
}
