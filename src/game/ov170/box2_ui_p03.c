/*
 * file:     box2_ui_p03.c
 * unit:     yes
 * function: func_021EE200, func_021EE224, func_021EE234, func_021EE244, func_021EE26C, func_021EE2C4, func_021EE364, func_021EE3CC
 * address:  0x021EE200
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02025774  0x02025774  thumb  ov170
 *   func_020257C4  0x020257C4  thumb
 *   func_0202590C 0x0202590C thumb
 *   func_020258E8 0x020258E8 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_021EE408 0x021EE408 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   d_021F02F0 0x021F02F0 data a4
 *   func_020260F0 0x020260F0 thumb
 *   func_02025D14  0x02025D14  thumb
 */
#include "../../matched/include/Obj18525.h"
#include "../../matched/include/Obj14282.h"
#include "../../matched/include/Obj24027.h"
#include "../../matched/include/Obj24028.h"
#include "../../matched/include/Obj24029.h"
#include "../../matched/include/Obj24030.h"
#include "../../matched/include/Obj24031.h"
#include "../../matched/include/Obj24032.h"
#include "../../matched/include/Obj24033.h"
#include "../../matched/include/Obj24034.h"
#include "../../matched/include/Obj00000.h"

struct Grid;
struct Obj020437AC;
struct Obj02025774;
struct Struct_02025D1C;
struct Struct_02025CD0;
struct Sound;
typedef signed short   s16;

typedef struct { unsigned a, b; } Pair_021EE2C4;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { unsigned a; unsigned b; } Pair_021EE364;

extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02025588(void *p);
extern void func_02025774(int, int);
extern int func_020257C4(const int *p);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern void func_020258E8(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern u8 func_020355C4(void);
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_02025D1C(struct Struct_02025D1C *obj);
extern void func_021EE408(char *p, int v);
extern void func_021ED55C(char **, int);
extern u32 func_020260F0(struct Sound *obj);
extern void func_02025D14(void);
void func_021EE200(char *p);
void func_021EE224(char *p, int i, int v);
int func_021EE234(int *a, int i);
void func_021EE244(char *p, int i, int flag);
void func_021EE26C(char *p, int d);
void func_021EE2C4(char **p);
void func_021EE364(char **p, int idx, int v);
void func_021EE3CC(int *p);
extern const Pair_021EE2C4 d_021F02F0[];

void func_021EE200(char *p)
{
    unsigned i;
    for (i = 0; i < 9; i++) {
        func_0202570C((struct Grid *)(*(int *)(p + i * 8 + 4)));
        func_020437AC((struct Obj020437AC *)(*(int *)(p + i * 8 + 8)));
    }
    func_02025588((void *)(((struct Obj18525 *)p)->f0));
}


void func_021EE224(char *p, int i, int v)
{
    func_02025774(*(int *)(p + i * 8 + 4), v);
}


/*
 *   func_020257C4 (0x020257C4) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int func_021EE234(int *a, int i)
{
    return func_020257C4((const int *)(*(int *)((char *)a + i * 8 + 4)));
}


void func_021EE244(char *p, int i, int flag)
{
    if (flag == 0)
        func_0202590C(*(void **)(p + i * 8 + 4), -0x94, 0x14);
    else
        func_0202590C(*(void **)(p + i * 8 + 4), 0xDC, 0x14);
}


void func_021EE26C(char *p, int d)
{
    unsigned i;
    short x;
    short y;
    for (i = 7; i <= 8; i++) {
        char *e = p + i * 8;
        func_020258E8(((struct Obj14282 *)e)->f4, &x, &y);
        func_0202590C(((struct Obj14282 *)e)->f4, x + d, y);
        if (x + d == -0x94 || x + d == 0xDC)
            func_021EE224(p, i, 0);
    }
}

void func_021EE2C4(char **p)
{
    int f;
    int i;
    f = func_020355C4() == 1 ? 0 : 1;
    switch (((struct Obj24027 *)(p[0]))->f24) {
    case 0: i = 0; break;
    case 1: i = 2; break;
    case 2: i = 3; break;
    case 3: i = 7; break;
    case 4: i = 13; break;
    case 5: i = 15; break;
    }
    func_021EE3CC((int *)p);
    ((struct Obj24028 *)(p[11]))->f70 = func_02025CD0(d_021F02F0[i].a, d_021F02F0[i].b, (u32)p, f, ((unsigned *)p)[9], 0x4c);
    func_02025D1C(((struct Obj24029 *)(p[11]))->f70);
    func_021EE408((char *)p, ((int *)p)[9]);
    func_021ED55C(p, f);
    ((struct Obj24030 *)(p[11]))->fA168 = ((int *)p)[9];
}


void func_021EE364(char **p, int idx, int v)
{
    int r = func_020260F0(((struct Obj24031 *)(p[11]))->f70);
    func_021EE3CC((int *)p);
    ((struct Obj24032 *)(p[11]))->f70 = func_02025CD0(d_021F02F0[idx].a, d_021F02F0[idx].b, (u32)p, r, v, 0x4C);
    func_02025D1C(((struct Obj24033 *)(p[11]))->f70);
    func_021EE408((char *)p, v);
    func_021ED55C(p, r);
    ((struct Obj24034 *)(p[11]))->fA168 = v;
}


/*
 *   func_02025D14 (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_021EE3CC(int *p)
{
    if (*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70)) {
        func_02025D14();
        *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70) = 0;
    }
}
