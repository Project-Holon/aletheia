/*
 * file:     itemmenu_p16.c
 * unit:     yes
 * function: func_021BA41C, func_021BA4A4, func_021BA654, func_021BA6A4
 * address:  0x021BA41C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0202EB04  0x0202EB04  thumb
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B908  0x0204B908  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_0204B878  0x0204B878  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0202EE0C  0x0202EE0C  thumb
 */
#include "../../matched/include/Obj01365.h"
#include "../../matched/include/Obj09880.h"
#include "../../matched/include/Obj13158.h"
#include "../../matched/include/Obj00002.h"

struct CodeIn;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Bmp;
typedef struct {
    unsigned short a, b;
} Pt;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void func_021BB398(int p, u32 val);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_020355C4(void);
extern void func_0202EB04(struct CodeIn *p);
extern int func_021B61C8(u8 *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B908(int, int);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *, u32);
extern void func_0207E780(void *, void *, u32);
extern int func_021B811C(u8 *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021BA41C(char *p);
void func_021BA4A4(char *p);
void func_021BA654(char *p);
void func_021BA6A4(char *p);


void func_021BA41C(char *p)
{
    Pt pt;
    func_021BB398((int)p, 0);
    func_0204B454((struct Actor *)((struct Obj01365 *)p)->f6A4, (struct PtS *)&pt, 0xFFFF);
    pt.b = (((struct Obj01365 *)p)->f810 + 1) * 0x18;
    func_0204B404((struct Obj *)(((struct Obj01365 *)p)->f6A4), (const struct Vec2 *)(&pt), 0xFFFF);
    if (func_020355C4() == 0) {
        func_021BB398((int)p, 1);
    }
    func_0202EB04((struct CodeIn *)(((struct Obj01365 *)p)->f850));
    func_0204B3DC((struct Obj *)((struct Obj01365 *)p)->f6A8, func_021B61C8((u8 *)p) >= 7);
    func_0204B908(((struct Obj01365 *)p)->f6A4, 0);
    func_0204B908(((struct Obj01365 *)p)->f6A8, 0);
}


void func_021BA4A4(char *p)
{
    int i;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 8; i++) {
        src = (u8 *)func_0204ABBC(*(u32 *)(p + i * 4 + 0x5F4), 0);
        dst = func_020437D4(*(void **)(p + i * 4 + 0x614));
        func_020862F0(dst, func_020437EC(*(void **)(p + i * 4 + 0x614)));
        func_0207E780(dst + 0x100, src + 0x80, 0x80);
        func_0207E780(dst + 0x280, src + 0x100, 0x80);
        func_0207E780(dst, src + 0x300, 0x100);
        func_0207E780(dst + 0x180, src + 0x400, 0x100);
        if (*(u32 *)(p + i * 4 + 0x654) != 0) {
            if (((struct Obj09880 *)p)->f80C == 4) {
                if (func_021B811C((u8 *)p) == 1 && *(u32 *)(p + i * 4 + 0x654) != 3) {
                    func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
                } else {
                    func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
                }
            } else if (((struct Obj09880 *)p)->f80C == 0 && *(u32 *)(p + i * 4 + 0x654) >= 4) {
                func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
            } else if (((struct Obj09880 *)p)->f80C == 2 && *(u32 *)(p + i * 4 + 0x654) >= 7) {
                func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
            } else {
                func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
            }
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x634), 1);
        } else {
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
            func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x634), 0);
        }
    }
}


void func_021BA654(char *p)
{
    unsigned w;
    unsigned v;
    Pt pt;
    if (func_02035CB8(&w, &v) == 1) {
        if (v < 0x1A) {
            v = 0x1A;
        } else if (v > 0x8E) {
            v = 0x8E;
        }
        func_0204B454((struct Actor *)((struct Obj13158 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = v;
        func_0204B404((struct Obj *)(((struct Obj13158 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}


void func_021BA6A4(char *p)
{
    Pt pt;
    int n = func_021B61C8((u8 *)p);
    if (n >= 7) {
        func_0204B454((struct Actor *)*(int *)&((struct Obj00002 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = func_0202EE0C(n - 6, ((struct Obj00002 *)p)->f814 + 1, 0x1A, 0x8E, 0);
        func_0204B404((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}
