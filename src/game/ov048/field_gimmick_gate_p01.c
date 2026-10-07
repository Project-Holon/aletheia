/*
 * file:     field_gimmick_gate_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F374C, func_021F376C, func_021F3790, func_021F37A4, func_021F37C4
 * address:  0x021F36C0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_021F3880  0x021F3880  thumb  ov048
 *   func_021F392C  0x021F392C  thumb  ov048
 *   func_021F3BC0  0x021F3BC0  thumb  ov048
 *   func_021F37FC  0x021F37FC  thumb  ov048
 *   func_021F3908  0x021F3908  thumb  ov048
 *   func_021F3818  0x021F3818  thumb  ov048
 *   func_021F3830  0x021F3830  thumb  ov048
 *   func_021F3D78  0x021F3D78  thumb  ov048
 *   func_021F3870  0x021F3870  thumb  ov048
 *   func_021F39E4  0x021F39E4  thumb  ov048
 *   func_021F39BC  0x021F39BC  thumb  ov048
 *   d_021F4E94     0x021F4E94  data  a4
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F474C 0x021F474C thumb ov048
 *   func_021F38EC 0x021F38EC thumb ov048
 *   func_021F4784 0x021F4784 thumb ov048
 *   func_021BE580 0x021BE580 thumb ov021
 *   d_021F50C0 0x021F50C0 data a4
 *   func_021F47B0 0x021F47B0 thumb ov048
 */
#include "../../matched/include/Obj05133.h"
#include "../../matched/include/G_T.h"
#include "../../matched/include/Obj09833.h"

struct Big;
struct Ctx;
struct Sub02008700Obj;
struct Obj;
struct Rec94;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct { u32 w[15]; } Copy60;

extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void func_021BE760(int a, void *b, int c);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern struct Obj *func_021F3880(int a);
extern void func_021F392C(struct Obj *o);
extern void func_021F3BC0(u8 *p);
extern void func_021F37FC(int *p);
extern void func_021F3908(int *p);
extern void func_021F3818(int *p);
extern void func_021F3830(int *p);
extern void func_021F3D78(void *p);
extern void func_021F3870(int *p);
extern void func_021F39E4(int *p);
extern void func_021F39BC(int *p);
extern int *func_021897BC(char *,int);
extern void func_021F474C(unsigned char *p);
extern void func_021F38EC(int *p);
extern void func_021F4784(unsigned char *p, int c);
extern void func_021BE580(void *);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021F47B0(void *);
void func_021F36C0(int a);
void func_021F374C(char *a);
void func_021F376C(char *a);
u8 func_021F3790(char *p);
u8 *func_021F37A4(u32 a);
void func_021F37C4(u8 *p);
extern u8 d_021F4E94[];
extern struct T d_021F50C0;


void func_021F36C0(int a)
{
    int r6;
    int r4;
    int *p;
    int v;

    r6 = func_02188D2C((int *)a);
    v = func_020083E4((short unsigned int *)func_0200873C(func_02012EBC(func_020120F4(func_02188C80((void *)a)))));
    if (v != 0) {
        if (v == 1) {
            r4 = 0;
        }
    } else {
        r4 = 1;
    }
    func_021BE760(r6, d_021F4E94 + r4 * 16, 1);
    p = (int *)func_021F3880(a);
    func_021F392C((struct Obj *)p);
    func_021F3BC0((u8 *)p);
    func_021F37FC(p);
    if (p[4] == 0) {
        func_021F3908(p);
    } else {
        func_021F3818(p);
        func_021F3830(p);
    }
    func_021F3D78(p);
    func_021F3870(p);
    func_021F39E4(p);
    func_021F39BC(p);
}

void func_021F374C(char *a) { u8 *p; p=(u8 *)func_021897BC(a,0); func_021F37C4(p); if(((struct Obj05133 *)p)->f14)func_021F474C(((struct Obj05133 *)p)->f14); func_021F38EC((int *)p); }

void func_021F376C(char *a) { int *p; p=func_021897BC(a,0); func_021F4784((void *)p[5],(*(int *)&d_021F50C0)); func_021BE580((void *)func_02188D2C((int *)((u32)a))); }

u8 func_021F3790(char *p) { return (u8)(*(int **)((char *)func_021897BC(p,0)+0x1c))[5]; }

u8 *func_021F37A4(u32 a) { u32 p; p=(u32)func_02012EC4(func_020120F4(func_02188C80((void *)a))); return (u8 *)func_0200B3A4((struct Rec94 *)p,func_0200B3AC((struct Rec94 *)p)); }

void func_021F37C4(u8 *p) { u8 *q; q=func_021F37A4(((struct Obj05133 *)p)->f4); ((struct Obj09833 *)q)->f0=((struct Obj05133 *)p)->f10; ((struct Obj09833 *)q)->f4=func_021F47B0(((struct Obj05133 *)p)->f14)>>12; ((struct Obj09833 *)q)->f8=((struct Obj05133 *)p)->f64; *(Copy60 *)(q+0xc)=*(Copy60 *)(p+0x28); }
