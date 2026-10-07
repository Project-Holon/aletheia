/*
 * file:     itemmenu_p08.c
 * unit:     yes
 * function: func_021B80C4, func_021B811C, func_021B8134, func_021B81B0, func_021B81B8, func_021B81F4, func_021B822C
 * address:  0x021B80C4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020355D8  0x020355D8  arm
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0202EB04  0x0202EB04  thumb
 *   func_021B97E8  0x021B97E8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_0202E448  0x0202E448  thumb
 *   func_021B83A0  0x021B83A0  thumb  ov070
 *   func_02012BE0  0x02012BE0  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB368  0x021BB368  thumb  ov070
 *   func_02012BF8 0x02012BF8 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_02021014  0x02021014  thumb
 *   func_0202136C  0x0202136C  thumb
 */
#include "../../matched/include/Obj20667.h"
#include "../../matched/include/Obj04328.h"

struct CodeIn;
struct Obj;
struct Rec;
typedef unsigned char u8;

typedef struct Obj_021B80C4 {
    unsigned char pad000[0x81C];
    int f81C;
    unsigned char pad820[0x850 - 0x820];
    void *f850;
} Obj_021B80C4;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Obj_021B8134 {
    void *f000;
    unsigned char pad004[0x80C - 0x4];
    int f80C;
    unsigned char pad810[0x814 - 0x810];
    int f814;
    int f818;
} Obj_021B8134;

typedef struct Obj_021B822C {
    unsigned char pad00[0x1C];
    int f1C;
} Obj_021B822C;

extern void func_020355D8(u8 v);
extern int func_021B61C8(u8 *p);
extern void func_021BB398(int p, u32 val);
extern void func_0202EB04(struct CodeIn *p);
extern void func_021B97E8(char *p, int mode);
extern void *func_021B616C(u8 *p, int i);
extern u32 func_0202E448(u32 id);
extern int func_021B83A0(char *p, int value);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_020061E4(unsigned int id);
extern int func_02012BF8(int p, int a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_0202136C(u16 v);
void func_021B80C4(Obj_021B80C4 *o, int flag);
int func_021B811C(u8 *p);
int func_021B8134(Obj_021B8134 *o, int k);
int func_021B81B0(int x);
void func_021B81B8(u8 *p);
void func_021B81F4(u8 *p);
void func_021B822C(Obj_021B822C *o, void *rec, u16 *p, u8 *out);


void func_021B80C4(Obj_021B80C4 *o, int flag)
{
    if (o->f81C == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (func_021B61C8((u8 *)o) == 0)
        flag = 0;
    if (flag == 0) {
        func_021BB398((int)o, 0);
    } else {
        func_021BB398((int)o, 1);
        func_0202EB04(o->f850);
    }
    func_021B97E8((char *)o, flag);
}

int func_021B811C(u8 *p) { int v = ((struct Obj20667 *)p)->f10; if (v==0 || v==1 || v==3) return 1; return 0; }


int func_021B8134(Obj_021B8134 *o, int k)
{
    u16 *p;
    int v;

    k += o->f814 + 1;
    if (o->f80C == 4) {
        if (func_021B61C8((u8 *)o) <= k)
            return 0;
        p = func_021B616C((u8 *)o, k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (func_021B83A0((char *)o, *p) == 1)
            func_02012BE0(o->f000, v, 0);
        else
            func_02012BE0(o->f000, v, 1);
        func_020061E4(0x646);
        o->f818 = 0xFFFF;
        return 1;
    }
    return 0;
}

int func_021B81B0(int x)
{
    int func_021BB368(int);
    return func_021BB368(x);
}

void func_021B81B8(u8 *p) { int a; int v; a=func_021B81B0(((struct Obj04328 *)p)->f80C); v=func_02012BF8(*(int *)&((struct Obj04328 *)p)->f0,a); func_02012BE0(((struct Obj04328 *)p)->f0,a,v^1); func_020061E4(0x646); func_021B81F4(p); }

void func_021B81F4(u8 *p) { if (((struct Obj04328 *)p)->f81C!=1) func_0204B878(((struct Obj04328 *)p)->f718,(unsigned int)func_02012BF8(*(int *)&((struct Obj04328 *)p)->f0,func_021B81B0(((struct Obj04328 *)p)->f80C))+6u); }


void func_021B822C(Obj_021B822C *o, void *rec, u16 *p, u8 *out)
{
    if (func_02021014(rec, 6) != 0) {
        if (func_0202136C(*p) == 1)
            *out = 2;
        else if (*p == 0x1C2 && o->f1C == 1)
            *out = 1;
        else
            *out = 0;
    }
    if ((u16)(*p + 0xFD98) <= 1)
        *out = 0;
}
