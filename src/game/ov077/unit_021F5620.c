/*
 * file:     unit_021F5620.c
 * unit:     yes
 * function: func_021F5620, func_021F5744, func_021F5798, func_021F57F8
 * address:  0x021F5620
 * region:   ov077
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021CF51C 0x021CF51C thumb ov021
 *   func_0207DD24 0x0207DD24 arm
 *   func_021F52D8 0x021F52D8 thumb ov075
 */
#include "../../matched/include/Obj20795.h"
#include "../../matched/include/Obj07712.h"
#include "../../matched/include/Obj13217.h"

struct Ctx;
struct Desc;
struct Obj;
typedef unsigned char  u8;

typedef short          s16;

typedef unsigned int   u32;

typedef int            s32_021F5620;

typedef struct Cell {
    s32_021F5620 x;
    s32_021F5620 y;
    s32_021F5620 f8;
    u8 padC[0xC];
    s32_021F5620 f18;
    s32_021F5620 f1C;
    s32_021F5620 f20;
    u8 pad24[0x10];
    s32_021F5620 f34;
    s32_021F5620 f38;
    u32 f3C;
} Cell;

typedef struct Work {
    Cell cell[0xC0];
    u8 pad3000[8];
    s16 cols;
    s16 rows;
    u8 pad300C[0x64];
    u32 f3070;
    u32 f3074;
    u32 f3078;
} Work;

typedef struct Param {
    int w;
    int h;
    void (*cb)(Work *w);
    u32 fC;
    u32 f10;
} Param;

typedef signed int     s32_021F5744;

typedef unsigned short u16;

extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 *func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern u32 func_021CF560(u32 *p);
extern void func_0204E720(u32 a, s32_021F5744 b, s32_021F5744 c, s32_021F5744 d);
extern int func_0204E804(void);
extern u32 func_021CF51C(u32 *p);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_021F52D8(u32 *);
void *func_021F5620(void *task, const Param *p, int flag);
int func_021F5744(void *task, int *st);
int func_021F5798(u8 *p);
void func_021F57F8(u32 *p);


void *func_021F5620(void *task, const Param *p, int flag)
{
    Work *w;
    void *h;
    int i;
    int a;
    int b;
    int cols;
    int rows;
    int a8;
    int b8;
    int ox;
    int oy;
    int n;
    int col;
    int row;

    w =(Work *)func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(task))), sizeof(Work), 0x50);
    h = func_020122C0(task, 0, func_021F5744, 0);
    a = p->w;
    b = p->h;
    a8 = a * 8;
    b8 = b * 8;
    cols = 0x20 / a;
    rows = 0x18 / b;
    w->cols = cols;
    w->rows = rows;
    ox = (cols / 2) * a8 - a8 / 2;
    oy = (rows / 2) * b8 - b8 / 2;
    n = cols * rows;
    for (i = 0; i < n; i++) {
        col = i % cols;
        w->cell[i].x = (col * a8 - ox) << 12;
        row = i / cols;
        w->cell[i].y = (oy - row * b8) << 12;
        w->cell[i].f8 = 0;
        w->cell[i].f18 = 0;
        w->cell[i].f1C = 0;
        w->cell[i].f20 = 0;
        w->cell[i].f34 = 0;
        w->cell[i].f38 = 0;
        w->cell[i].f3C = p->f10;
    }
    w->f3070 = p->fC;
    if (p->cb != 0) {
        p->cb(w);
    }
    if (flag != 0) {
        w->f3074 = 0xC;
        w->f3078 = 0x7FFF;
    } else {
        w->f3074 = 3;
        w->f3078 = 0;
    }
    return h;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021F5744(void *task, int *st)
{
    u8 *w;

    w = (u8 *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(func_020124E4(task)))));
    switch (*st) {
    case 0:
        if (func_021F5798(w) == 0)
            break;
        func_0204E720(((struct Obj20795 *)w)->f3074, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}


int func_021F5798(u8 *p)
{
    int i;
    int n;
    int cnt;

    (*(void (**)(u8 *))(p + 0x3070))(p);
    n = ((struct Obj13217 *)p)->f3008 * ((struct Obj13217 *)p)->f300A;
    cnt = 0;
    for (i = 0; i < n; i++) {
        u8 *e = p + i * 64;
        int ok = 0;

        if (((struct Obj07712 *)e)->f38 == 0) {
            if (((struct Obj07712 *)e)->f34 != 0) {
                int (*fn)(u8 *) = *(int (**)(u8 *))(e + 0x3c);

                if (fn == 0)
                    ((struct Obj07712 *)e)->f38 = 1;
                else
                    ok = fn(e);
            }
        } else {
            ok = 1;
        }
        if (ok)
            cnt++;
    }
    return cnt >= n;
}

/*
 * 2026-10-05: EXACT now that ov021 func_021CF51C is filed; no source change.
 */
void func_021F57F8(u32 *p) {
    u32 h = func_021CF51C(p);
    u32 w = func_021CF560(p);
    func_0207DD24(*(u32 *)(w+0x3078),31,0x7FFF,0,0);
    func_021F52D8((u32 *)h);
}
