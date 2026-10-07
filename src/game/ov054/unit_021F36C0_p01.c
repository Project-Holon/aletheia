/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F3704
 * address:  0x021F36C0
 * region:   ov054
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021F37B4  0x021F37B4  thumb  ov054
 *   func_021F38E4  0x021F38E4  thumb  ov054
 *   func_0202B914  0x0202B914  thumb
 *   d_021F39A0     0x021F39A0  data  a4
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021F38B0 0x021F38B0 thumb ov054
 *   func_021C4DA8 0x021C4DA8 thumb ov021
 */
#include "../../matched/include/Obj20572.h"

struct Obj;
struct O;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void func_021BE310(unsigned a, void *b, int c);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021F37B4(struct O *o, u32 q);
extern void func_021F38E4(char *p, int a);
extern void func_0202B914(struct Obj *o, u32 v);
extern int *func_021897BC(char *,int);
extern void func_021897A0(unsigned char *,int);
extern void func_021F38B0(char *,int);
extern int func_021C4DA8(void *a);
void func_021F36C0(unsigned a);
void func_021F3704(char *a);
extern char d_021F39A0[];


void func_021F36C0(unsigned a)
{
    unsigned r5;
    int *p;

    r5 = func_02188C84((u8 *)a);
    func_021BE310(func_02188D2C((int *)a), d_021F39A0, 0);
    p = func_02189764((unsigned char *)a, 0, r5, 0x28);
    func_021F37B4((struct O *)p, a);
    func_021F38E4((char *)p, a);
    func_0202B914((struct Obj *)p[1], 0x7f);
}

void func_021F3704(char *a) { int i=0; char *p=(char *)func_021897BC(a,0); func_0202B914((struct Obj *)(((struct Obj20572 *)p)->f4),0); func_021F38B0(p,(int)a); for(;i<2;i++) func_021C4DA8((void *)(*(void **)(p+8+4*i))); func_021897A0((unsigned char *)a,0); }
