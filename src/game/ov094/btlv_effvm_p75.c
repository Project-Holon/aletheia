/*
 * file:     btlv_effvm_p75.c
 * unit:     yes
 * function: func_02200DE4, func_02200E1C
 * address:  0x02200DE4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_02015C78 0x02015C78 thumb
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data
 */
#include "../../matched/include/Obj00264.h"

#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))
struct S02030EE8;
typedef unsigned char u8;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x52c - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x52c */
    char pad530[0x596 - 0x530];
    u8 tag[1];              /* 0x596 */
} Work;

typedef struct {
    char body[0x3c];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short s16;

typedef long long s64;

typedef struct Vec { int x, y, z; } Vec;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F935C(int x);
extern int func_022019F4(char *, int);
extern void func_021F89BC(void *);
extern void func_02015C78(void *, u32 *);
void func_02200DE4(void *h);
void func_02200E1C(void *task, char *q);
extern const s16 d_020A1B38[];


void func_02200DE4(void *h)
{
    Ctx *c = (Ctx *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

void func_02200E1C(void *task, char *q)
{
    char *p = *(char * *)&((struct Obj00264 *)q)->f0;
    Vec v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj00264 *)q)->f4);
    char *e;
    int off;
    int x, y;
    int j;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj00264 *)q)->f38 != *(u8 *)(p + ((struct Obj00264 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj00264 *)q)->f34 == 0) {
        if (((struct Obj00264 *)q)->f30 == ((struct Obj00264 *)q)->f1C) {
        ((struct Obj00264 *)q)->f30 = 0;
        if (((struct Obj00264 *)q)->f8 & 1)
            ((struct Obj00264 *)q)->f28 -= ((struct Obj00264 *)q)->f2C;
        else
            ((struct Obj00264 *)q)->f28 += ((struct Obj00264 *)q)->f2C;
        if (((struct Obj00264 *)q)->f28 & 0xffff0000) {
            ((struct Obj00264 *)q)->f28 = (u16)((struct Obj00264 *)q)->f28;
            ((struct Obj00264 *)q)->f20 -= 1;
            ((struct Obj00264 *)q)->f34 = ((struct Obj00264 *)q)->f24;
        }
        if (((struct Obj00264 *)q)->f20 != 0) {
            switch (((struct Obj00264 *)q)->fC) {
            case 0:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = d_020A1B38[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = d_020A1B38[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                x += ((struct Obj00264 *)q)->f10;
                break;
            case 1:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = d_020A1B38[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10) - ((struct Obj00264 *)q)->f10;
                y = d_020A1B38[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14);
                break;
            case 2:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = d_020A1B38[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = d_020A1B38[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                y += ((struct Obj00264 *)q)->f14;
                break;
            case 3:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = d_020A1B38[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10);
                y = d_020A1B38[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14) - ((struct Obj00264 *)q)->f14;
                break;
            }
            switch ((((struct Obj00264 *)q)->f8 & 7) >> 1) {
            default:
            case 0:
                v.z = x;
                v.y = y;
                break;
            case 1:
                v.x = x;
                v.z = y;
                break;
            case 2:
                v.x = x;
                v.y = y;
                break;
            }
        }
        func_02015C78(*(void **)(e + off), (u32 *)&v);
        } else {
            ((struct Obj00264 *)q)->f30 += 1;
        }
    } else {
        ((struct Obj00264 *)q)->f34 -= 1;
    }
    if (((struct Obj00264 *)q)->f20 == 0)
        func_021F89BC(task);
}
