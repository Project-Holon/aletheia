/*
 * function: func_021808E8
 * address:  0x021808E8
 * packet:   pkt_ov018_021808E8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb ov010
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb ov018
 *   func_0217F40C  0x0217F40C  thumb ov018
 *   func_0217F420  0x0217F420  thumb ov018
 *   func_0217FE38  0x0217FE38  thumb ov018
 *   d_0218383C     0x0218383C  data ov018 a2
 */
#include "../include/Obj09400.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 d_0218383C[];

typedef unsigned int   u32;
struct Ctx;
struct Obj;
struct Rec44;
struct Sub24;
struct WordSet;
void *func_020124E4(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
struct Ctx;
unsigned int func_02012138(const struct Ctx *p);
int func_02158344(int a0);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(u8 *p, int a);
int func_0217F40C(u8 *p);
int func_0217F420(void);
void func_0217FE38(void *m, u8 *obj);

int func_021808E8(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    int w = (int)func_020120F4((const struct Ctx *)v);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj09400 *)obj)->f10), 0, func_02012950((struct Sub24 *)w, obj[0x40]));
        func_0217F3C4(obj + 0x10, d_0218383C[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C(obj + 0x10) == 1) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = *st + 1;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}
