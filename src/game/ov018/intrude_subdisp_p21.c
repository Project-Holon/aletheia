/*
 * file:     intrude_subdisp_p21.c
 * unit:     yes
 * function: func_021808E8, func_02180978, func_02180980
 * address:  0x021808E8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_021808C4  0x021808C4  thumb ov018
 *   func_0201232C 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021809A4 0x021809A4 thumb ov018
 */
#include "../../matched/include/Obj09400.h"

struct Ctx;
struct Obj;
struct Rec44;
struct Sub24;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void *func_020124E4(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
unsigned int func_02012138(const struct Ctx *p);
int func_02158344(int a0);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(u8 *p, int a);
int func_0217F40C(u8 *p);
int func_0217F420(void);
void func_0217FE38(void *m, u8 *obj);
void func_021808C4(void *task, const void *src);
extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
extern int func_021809A4(void *, int *, void *);
int func_021808E8(int x, int *st, u8 *obj);
void func_02180978(int id, void *dst);
void func_02180980(void *task, const void *src);
extern u16 d_0218383C[];


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


void func_02180978(int id, void *dst)
{
    func_021808C4((void *)id, dst);
}

void func_02180980(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_021809A4, 0xA4);
    work = func_020124E8(task);
    func_02082D44(src, work, 0x98);
}
