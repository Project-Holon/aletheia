/*
 * file:     field_gimmick_bsubway_p03.c
 * unit:     yes
 * function: func_021F388C, func_021F38C0, func_021F38F0
 * address:  0x021F388C
 * region:   ov052
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F3AC0 0x021F3AC0 data ov052 a4
 *   func_020307B0 0x020307B0 arm
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC4C  0x0218DC4C  thumb  ov021
 *   d_021F39CC     0x021F39CC  data  a4
 */
#include "../../matched/include/Obj20565.h"
#include "../../matched/include/Obj13112.h"
#include "../../matched/include/Obj20567.h"
#include "../../matched/include/Obj01038.h"
#include "../../matched/include/Obj20568.h"

struct Big;
struct Ctx;
struct Rec94;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

typedef struct { int v[4]; } T4;

typedef struct { int x, y, z; } V3;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u16 func_02188C9C(u8 *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02188C98(u8 *p);
extern void func_0218DC4C(int, V3 *);
void func_021F388C(int a);
void func_021F38C0(char *a);
void func_021F38E4(char *a);
void func_021F38F0(char *a, int b);
extern char d_021F3AC0[];
extern T4 d_021F39CC;


void func_021F388C(int a)
{
    unsigned h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    if (func_02188C9C((u8 *)a) == 0x4b) {
        char *p = (char *)func_0200B3A4((struct Rec94 *)h, 0x27);
        if (p != 0) {
            unsigned char *q = *(unsigned char * *)&((struct Obj20565 *)p)->f24;
            if (q != 0)
                *q = 1;
        }
    }
}


void func_021F38C0(char *a)
{
    ((struct Obj13112 *)a)->f24 = func_02030734(((struct Obj13112 *)a)->fC, 12, 1, d_021F3AC0, 0x164);
}


void func_021F38E4(char *a)
{
    func_020307B0(((struct Obj20567 *)a)->f24);
}


void func_021F38F0(char *a, int b)
{
    V3 v = {0, 0, 0};
    T4 t = d_021F39CC;
    unsigned char *p = *(unsigned char * *)&((struct Obj20568 *)a)->f24;
    int r = func_02188C98((u8 *)b);

    switch (p[1]) {
    case 0:
        if (p[0] == 1)
            return;
        ((struct Obj01038 *)p)->f4 = t.v[p[2]];
        p[2]++;
        p[2] &= 3;
        p[1]++;
    case 1:
        if (--((struct Obj01038 *)p)->f4 <= 0) {
            ((struct Obj01038 *)p)->f8 = 1;
            p[1]++;
        }
        break;
    case 2:
        v.y = ((struct Obj01038 *)p)->f8 << 12;
        func_0218DC4C(r, &v);
        if (((struct Obj01038 *)p)->f8 == 0)
            p[1] = 0;
        if (((struct Obj01038 *)p)->f8 < 0) {
            ((struct Obj01038 *)p)->f8 += 2;
            if (((struct Obj01038 *)p)->f8 > 0)
                ((struct Obj01038 *)p)->f8 = 0;
        }
        ((struct Obj01038 *)p)->f8 = -((struct Obj01038 *)p)->f8;
        break;
    }
}
