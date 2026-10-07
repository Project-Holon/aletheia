/*
 * file:     unit_021BB954_p18.c
 * unit:     yes
 * function: func_021BCD58, func_021BCDB0, func_021BCE30, func_021BCE80, func_021BCEAC, func_021BCECC, func_021BCF4C, func_021BCF6C
 * address:  0x021BCD58
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
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BCB70  0x021BCB70  thumb  ov099
 *   func_021BBEB4  0x021BBEB4  thumb  ov099
 *   func_021BC06C  0x021BC06C  thumb  ov099
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   func_021BCBD8  0x021BCBD8  thumb  ov099
 *   func_0203D378  0x0203D378  arm
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BA978  0x021BA978  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 */
#include "../../matched/include/Obj07945.h"
#include "../../matched/include/Obj22033.h"
#include "../../matched/include/Obj12113.h"
#include "../../matched/include/Obj18202.h"
#include "../../matched/include/Obj04412.h"
#include "../../matched/include/Obj05262.h"
#include "../../matched/include/Obj22034.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj22035.h"

struct BigObj;
struct O;
struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BCD58;

typedef unsigned int u32_021BCDB0;

typedef unsigned int u32_021BCE30;

typedef unsigned long  u32_021BCE80;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef unsigned int u32_021BCEAC;

typedef unsigned long  u32_021BCECC;

typedef unsigned long  u32_021BCF4C;

typedef int BOOL;

typedef unsigned int u32_021BCF6C;

extern int func_021BA928(char *p, int v);
extern u32_021BCD58 func_020362DC(void);
extern void func_021BA8EC(char *p);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BCD58 *mask);
extern void func_021BBEB4(struct O *p, int mask, u32_021BCD58 a, int mode);
extern void func_021BC06C(char *p);
extern int func_021BCBBC(int a, int b, int *out);
extern u32_021BCE80 func_021BCBD8(char *p, int m);
extern u32_021BCECC func_0203D378(void);
extern void func_021BCC4C(void *a);
extern void func_021BA874(char *p, int id);
extern void func_021BA978(char *p, int a, int b, int c);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);
int func_021BCD58(char *p, int v);
int func_021BCDB0(char *p, int v);
int func_021BCE30(char *p, int v);
int func_021BCE80(char *p, int v);
int func_021BCEAC(char *p, int ret);
int func_021BCECC(char *p, int v);
int func_021BCF4C(char *p, int v);
int func_021BCF6C(char *p, int ret);
int func_021BCF8C(char *p, int ret);
int func_021BCF98(char *p, int ret);


int func_021BCD58(char *p, int v)
{
    int out;

    if (func_021BA928(p, v) == 0) {
        return v;
    }
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCB70((void *)(((struct Obj07945 *)p)->f1348), (const struct BigObj *)(((struct Obj07945 *)p)->fC4), (u32_021BCD58 *)(&out));
        func_021BBEB4((struct O *)p, out, ((struct Obj22033 *)(*(u8 * *)&((struct Obj07945 *)p)->f248))->f48, 2);
        ((struct Obj07945 *)p)->f1CC = 0x77;
    }
    return v;
}


int func_021BCDB0(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        if (*(int *)(p + 0xCC) != 0) {
            int out;
            func_021BCBBC(*(int *)(p + 0x1348), *(int *)(p + 0xCC), &out);
            func_021BBEB4((struct O *)p, out, *(u8 *)(*(char **)(p + 0x248) + 0x48), 3);
            *(int *)(p + 0x1CC) = 0x78;
        } else {
            switch (*(int *)(p + 0x135C)) {
            case 3:
                *(int *)(p + 0x1CC) = 0x4E;
                break;
            case 2:
                *(u8 *)(p + 0x1353) = 0x97;
                *(int *)(p + 0x1CC) = 0x8A;
                break;
            case 4:
                *(u8 *)(p + 0x1353) = 0x90;
                *(int *)(p + 0x1CC) = 0x8A;
                break;
            default:
                *(int *)(p + 0x1CC) = 0x72;
                break;
            }
        }
    }
    return v;
}


int func_021BCE30(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        func_021BA8EC(p);
        switch (*(int *)(p + 0x135C)) {
        case 3:
            *(int *)(p + 0x1CC) = 0x4E;
            break;
        case 2:
            *(u8 *)(p + 0x1353) = 0x97;
            *(int *)(p + 0x1CC) = 0x8A;
            break;
        case 4:
            *(u8 *)(p + 0x1353) = 0x90;
            *(int *)(p + 0x1CC) = 0x8A;
            break;
        default:
            *(int *)(p + 0x1CC) = 0x72;
            break;
        }
    }
    return v;
}


int func_021BCE80(char *p, int v)
{
    func_021BCBD8(p, 1);
    func_021BBEB4((struct O *)p, 0, ((struct Obj18202 *)(*(char * *)&((struct Obj12113 *)p)->f248))->f20, 0);
    ((struct Obj12113 *)p)->f1CC = 0x5D;
    return v;
}

int func_021BCEAC(char *p, int ret)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        ((struct Obj04412 *)p)->f1CC = 0x4E;
    }
    return ret;
}


int func_021BCECC(char *p, int v)
{
    if (func_0203D378() == 0) {
        func_021BCC4C(p);
        func_021BBEB4((struct O *)p, 0, ((struct Obj22034 *)(*(u8 * *)&((struct Obj05262 *)p)->f248))->f48, 1);
        func_021BA874(p, ((struct Obj05262 *)p)->f242 - 1);
        func_021BA978(p, ((struct Obj05262 *)p)->f134C + 0x69 + (((struct Obj05262 *)p)->f134E << 2), 0, 1);
        ((struct Obj05262 *)p)->f1CC = 0x7A;
    } else {
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        ((struct Obj05262 *)p)->f1CC = 0x49;
    }
    return v;
}


int func_021BCF4C(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    *(u32_021BCF4C *)&((struct Obj00008 *)p)->f1CC = 0x7B;
    return v;
}

int func_021BCF6C(char *p, int ret)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        ((struct Obj04412 *)p)->f1CC = 0x7C;
    }
    return ret;
}

int func_021BCF8C(char *p, int ret)
{
    ((struct Obj22035 *)p)->f1CC = 0x60;
    return ret;
}

int func_021BCF98(char *p, int ret)
{
    return ret;
}
