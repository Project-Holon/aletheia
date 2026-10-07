/*
 * file:     union_subdisp_p02.c
 * unit:     yes
 * function: func_021F0420, func_021F0430, func_021F0478, func_021F0490, func_021F04D4, func_021F04EC, func_021F056C, func_021F0584, func_021F0628
 * address:  0x021F0420
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 *   func_020450F0  0x020450F0  arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021F1048     0x021F1048  data  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02035D20  0x02035D20  arm
 *   func_0204B454  0x0204B454  arm
 *   func_020061E4  0x020061E4  thumb
 *   d_021F1038     0x021F1038  data  a1
 *   func_0204B6F4  0x0204B6F4  arm
 */
#include "../../matched/include/Obj20404.h"
#include "../../matched/include/Obj09791.h"
#include "../../matched/include/Obj09792.h"
#include "../../matched/include/Obj06133.h"

struct Descriptor;
struct Obj;
struct Actor;
struct PtS;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    char pad0[0x4C];
    u32 a[3];
    char pad1[0x64 - 0x58];
    struct Slot s[3];
};

typedef signed int     s32;

typedef struct { u16 a, b, c, d; } Rect;

typedef signed short   s16;

typedef struct { s16 x, y; } Pt;

extern void func_0203FB44(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_020061E4(u32 se);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021F0420(char *p);
void func_021F0430(struct Obj *p);
void func_021F0478(char *p);
void func_021F0490(char *p, u32 heap);
void func_021F04D4(char *p);
void func_021F04EC(int *p, void *h);
void func_021F056C(char *p);
int func_021F0584(int *p, u8 *flag);
void func_021F0628(char *p, int sel);
extern const Rect d_021F1048;
extern u8 d_021F1038[];

void func_021F0420(char *p)
{
    func_0203FB44(5, ((struct Obj20404 *)p)->f4, 128);
}


/*
 * Re-reading the just-stored p->a[i] as the source of the second store
 * (instead of a local or a chained assignment) is what makes the compiler
 * form &p->a[i] before the call in a callee-saved register, which in turn
 * leaves room for only the first stack constant (7) to be hoisted.
 */
void func_021F0430(struct Obj *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p->a[i] = func_020450F0(5, 1, (u8)(i * 0x38 / 8), 0x1D, 7, 0xF, 1);
        p->s[i].h = p->a[i];
        p->s[i].f = 0;
    }
}

void func_021F0478(char *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        func_020452E8(*(void **)(p + 0x4c + i * 4));
    }
}


void func_021F0490(char *p, u32 heap)
{
    ((struct Obj09791 *)p)->fC = func_0204AC18((void *)heap, 0x13, 1, 0, 0, 3, 0x15);
    ((struct Obj09791 *)p)->f8 = func_0204A6C8((void *)heap, 0xE, 0, 1, 0x15);
    ((struct Obj09791 *)p)->f10 = func_0204AF28((void *)heap, 0xC, 0xD, 0x15);
}

void func_021F04D4(char *p)
{
    func_0204ADA4(((struct Obj09792 *)p)->fC);
    func_0204A8D4(((struct Obj09792 *)p)->f8);
    func_0204AFD8(((struct Obj09792 *)p)->f10);
}


void func_021F04EC(int *p, void *h)
{
    Rect r;
    int i;

    r = d_021F1048;
    for (i = 0; i <= 4; i++) {
        r.a = i * 0x30 + 0x20;
        r.c = i;
        p[6 + i] = (int)func_0204B294((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    }
    r.c = 5;
    r.a = 0xF4;
    r.b = 0x9C;
    p[0xB] = (int)func_0204B294((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    func_0204B3DC((struct Obj *)p[0xB], 0);
}

void func_021F056C(char *p) { int i; for (i=0;i<6;i++) func_0204B3B4((struct Obj *)(*(unsigned *)(p+i*4+0x18))); }


int func_021F0584(int *p, u8 *flag)
{
    u32 w;
    u32 h;
    Pt t;
    int i;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    if (func_02035D20(&w, &h) == 0)
        return 0;
    for (i = 0; i <= 4; i++) {
        func_0204B454((struct Actor *)p[6 + i], (struct PtS *)&t, 1);
        y0 = t.y - 10;
        y1 = t.y + 10;
        x1 = t.x + 10;
        x0 = t.x - 10;
        if (x0 < w && x1 > w && y0 < h && y1 > h) {
            if (i == 0 && flag != 0) {
                flag[0x282E] = 1;
                return 0;
            }
            func_021F0628((char *)p, i);
            func_020061E4(0x54B);
            return 1;
        }
    }
    return 0;
}


/*
 * The store to +0x30 is written in both arms of an if/else (keeps the
 * empty `b` to the next instruction), and the loop condition is a
 * `? 1 : 0` ternary (keeps the entry branch to the bottom test).
 */
void func_021F0628(char *p, int sel)
{
    int i;
    int v;

    v = d_021F1038[sel];
    if (v == ((struct Obj06133 *)p)->f30)
        ((struct Obj06133 *)p)->f30 = 0;
    else
        ((struct Obj06133 *)p)->f30 = v;
    for (i = 0; (i <= 4) ? 1 : 0; i++) {
        if (i == sel && ((struct Obj06133 *)p)->f30 != 0)
            func_0204B6F4((struct Obj *)(*(u32 *)(p + 0x18 + i * 4)), 1, 1);
        else
            func_0204B6F4((struct Obj *)(*(u32 *)(p + 0x18 + i * 4)), 0, 1);
    }
}
