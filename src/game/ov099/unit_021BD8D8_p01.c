/*
 * file:     unit_021BD8D8_p01.c
 * unit:     yes
 * function: func_021BD8D8, func_021BD924, func_021BD994, func_021BD9B4, func_021BD9F4, func_021BDA3C, func_021BDAA4, func_021BDAC8
 * address:  0x021BD8D8
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
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   sub_020399A8  0x020399A8  arm
 *   sub_02039C68  0x02039C68  arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D378 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_02039C68 0x02039C68 arm
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
#include "../../matched/include/Obj07951.h"
#include "../../matched/include/Obj22042.h"
#include "../../matched/include/Obj05264.h"
#include "../../matched/include/Obj13695.h"
#include "../../matched/include/Obj18245.h"
#include "../../matched/include/Obj22043.h"
#include "../../matched/include/Obj13696.h"
#include "../../matched/include/Obj07952.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj10206.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u16 a, b; } Request;

typedef unsigned int   u32_021BD8D8;

typedef unsigned int   u32_021BD924;

typedef unsigned long  u32_021BD994;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BD9B4;

typedef unsigned int u32_021BD9F4;

typedef unsigned long  u32_021BDAA4;

typedef unsigned int   u32_021BDAC8;

extern u8 func_021BDD54(int, void *);
extern void func_021C2864(void *, u8);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32_021BD8D8 b, u32_021BD8D8 c, u32_021BD8D8 d);
extern unsigned int func_021BCBD8(char *p, int m);
extern struct Entry *sub_020399A8(void);
extern void sub_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern u32_021BD9B4 func_02039CB4(struct Link *, u32_021BD9B4, u32_021BD9B4);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_0203D7B0(u8 a0);
extern int func_0203D7BC(int);
extern int func_0203D378(int);
extern void func_021BAAB8(char *, int, int);
extern int func_0203D1E8(int, int);
extern void func_021BA874(void *, int);
extern void func_021BC090(char *);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern int func_021BA928(void *p);
extern void func_021BA828(char *p);
extern void func_0201DD68(void);
extern u32_021BDAC8 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
int func_021BD8D8(char *p, int ret);
int func_021BD924(char *p, int v);
int func_021BD97C(char *p, int v);
int func_021BD994(void *v, int b);
int func_021BD9B4(char *p, int v);
int func_021BD9F4(char *p, int v);
int func_021BDA3C(char *p, int v);
int func_021BDAA4(char *p, int v);
int func_021BDAC8(char *p, int result);

int func_021BD8D8(char *p, int ret)
{
    Request request;
    request.a = func_021BDD54((int)p, ((struct Obj07951 *)p)->f8);
    request.b = 1 - ((struct Obj22042 *)(*(char * *)&((struct Obj07951 *)p)->f248))->f46;
    if (func_0203D3A8(func_020399A8(), 0xa03, 4, (unsigned)&request) != 0) {
        ((struct Obj07951 *)p)->f1CC = 0x81;
        func_021C2864(((struct Obj07951 *)p)->f8, request.b);
    }
    return ret;
}

int func_021BD924(char *p, int v)
{
    int t;
    if (((struct Obj05264 *)p)->f1352 == 6) {
        ((struct Obj05264 *)p)->f1353 = 0x4d;
        ((struct Obj05264 *)p)->f1CC = 0x8a;
    } else {
        if (((struct Obj05264 *)p)->f135C == 3 || ((struct Obj05264 *)p)->f135C == 1) {
            t = func_021BCBD8(p, 1);
        } else {
            t = func_021BCBD8(p, 0);
        }
        if (func_0203D3A8(func_020399A8(), 0xa06, 4, (u32_021BD924)(&t)) != 0) {
            ((struct Obj05264 *)p)->f1CC = 0x82;
        }
    }
    return v;
}

int func_021BD97C(char *p, int v)
{
    ((struct Obj13695 *)p)->f1353 = 0x5e;
    ((struct Obj13695 *)p)->f1CC = 0x8a;
    return v;
}


/*
 * The result of the first arm9 call is the first argument of the second.
 * Returns the second argument.
 */
int func_021BD994(void *v, int b)
{
    sub_02039C68((struct Link *)sub_020399A8(), 0x1B, 0x0A);
    ((struct Obj18245 *)v)->f1CC = 0x8B;

    return b;
}

int func_021BD9B4(char *p, int v)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x1b, 10) != 0) {
        if (func_0203D3A8(func_020399A8(), 0xa05, 1, (u32_021BD9B4)(p + 0x1353)) != 0) {
            ((struct Obj22043 *)p)->f1CC = 0x48;
        }
    }
    return v;
}

int func_021BD9F4(char *p, int v)
{
    int zero;
    func_021C18C8(p, 1, 2);
    zero = 0;
    ((struct Obj13696 *)p)->f135C = zero;
    func_0203D7B0(0);
    if (func_0203D378(func_0203D7BC(0)) != 0) {
        func_021BAAB8(p, 0x73, zero);
    } else {
        func_021BAAB8(p, 0x7c, zero);
    }
    ((struct Obj13696 *)p)->f1CC = 0x8e;
    return v;
}

int func_021BDA3C(char *p, int v)
{
    int zero;
    zero = 0;
    if (func_0203D378(func_0203D1E8((int)func_020399A8(), 0)) == 0) {
        func_021BA874(p, ((struct Obj07952 *)p)->f242 - 1);
        func_021BAAB8(p, 0x77, zero);
        ((struct Obj07952 *)p)->f1CC = 0xaa;
    } else {
        func_021BA874(p, ((struct Obj07952 *)p)->f242 - 1);
        func_021BAAB8(p, 0x4c, zero);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 10);
        ((struct Obj07952 *)p)->f1CC = 0x49;
    }
    return v;
}


int func_021BDAA4(char *p, int v)
{
    if (func_021BA928(p) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32_021BDAA4 *)&((struct Obj00008 *)p)->f1CC = 0xAB;
    return v;
}

/*
 * lever: unsigned byte stores materialize 0xa8 as movs, rather than a signed subtraction.
 */
int func_021BDAC8(char *p, int result)
{
    int v;
    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1) return result;
    if (v == 0) ((struct Obj10206 *)p)->f1353 = 0x44;
    else ((struct Obj10206 *)p)->f1353 = 0xa8;
    func_021BA8EC(p);
    ((struct Obj10206 *)p)->f1CC = 0x8a;
    return result;
}
