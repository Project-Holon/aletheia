/*
 * file:     unit_021BCF9C_p06.c
 * unit:     yes
 * function: func_021BD444, func_021BD4A8, func_021BD500, func_021BD558
 * address:  0x021BD444
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C282C  0x021C282C  thumb  ov099
 *   d_021C38EC     0x021C38EC  data  ov099  a4
 *   func_021BC104  0x021BC104  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BBEB4 0x021BBEB4 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BC06C 0x021BC06C thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../../matched/include/Obj06357.h"
#include "../../matched/include/Obj07948.h"
#include "../../matched/include/Obj22036.h"
#include "../../matched/include/Obj07949.h"
#include "../../matched/include/Obj22037.h"
#include "../../matched/include/Obj04412.h"

struct BigObj;
struct O;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BD444;

typedef struct { u32_021BD444 v[8]; } Tbl8;

typedef unsigned int u32_021BD4A8;

typedef unsigned int u32_021BD500;

typedef unsigned int u32_021BD558;

extern int func_021C282C(u8 *p);
extern void func_021BC104(char *p);
extern void func_021BA8EC(char *p);
extern void func_021C18C8(char *p, int kind, int value);
extern int func_021BA928(char *, int);
extern u32_021BD4A8 func_020362DC(void);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BD4A8 *mask);
extern void func_021BBEB4(struct O *p, int mask, u32_021BD4A8 a, int mode);
extern int func_021BCBBC(int a, int b, int *out);
extern void func_021BC06C(char *);
extern void func_021BAAB8(char *, int, int);
int func_021BD444(char *p);
int func_021BD4A8(char *p, int ret);
int func_021BD500(char *p, int result);
int func_021BD558(char *p, int v);
extern const Tbl8 d_021C38EC;


int func_021BD444(char *p)
{
    Tbl8 t;
    u32_021BD444 s;

    func_021C282C(*(u8 * *)&((struct Obj06357 *)p)->f8);
    ((struct Obj06357 *)p)->f1351 = 0;
    t = d_021C38EC;
    s = t.v[((struct Obj06357 *)p)->f134E + ((struct Obj06357 *)p)->f134C * 2];
    ((struct Obj06357 *)p)->f1D0 = s;
    func_021BC104(p);
    func_021BA8EC(p);
    func_021C18C8(p, 4, s);
    return 2;
}

int func_021BD4A8(char *p, int ret)
{
    int out;
    if (func_021BA928(p, ret) == 0) return ret;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCB70((void *)(((struct Obj07948 *)p)->f1348), (const struct BigObj *)(((struct Obj07948 *)p)->fC4), (u32_021BD4A8 *)(&out));
        func_021BBEB4((struct O *)p, out, ((struct Obj22036 *)(*(u8 * *)&((struct Obj07948 *)p)->f248))->f48, 2);
        ((struct Obj07948 *)p)->f1CC = 0x6d;
    }
    return ret;
}

int func_021BD500(char *p, int result)
{
    int out;
    if (func_021BA928(p, result) == 0) return result;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCBBC(((struct Obj07949 *)p)->f1348, ((struct Obj07949 *)p)->fCC, &out);
        func_021BBEB4((struct O *)p, out, ((struct Obj22037 *)(*(u8 * *)&((struct Obj07949 *)p)->f248))->f48, 3);
        ((struct Obj07949 *)p)->f1CC = 0x6d;
    }
    return result;
}

int func_021BD558(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        func_021BAAB8(p, 0x71, 0);
        ((struct Obj04412 *)p)->f1CC = 0x65;
    }
    return v;
}
