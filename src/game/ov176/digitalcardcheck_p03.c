/*
 * file:     digitalcardcheck_p03.c
 * unit:     yes
 * function: func_0217D410, func_0217D434, func_0217D44C, func_0217D458
 * address:  0x0217D410
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_0217DE60 0x0217DE60 thumb ov176
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021E8A80  0x021E8A80  thumb  ov177
 *   func_021E64C0  0x021E64C0  thumb  ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217D4FC 0x0217D4FC thumb ov176
 *   func_0217D730 0x0217D730 thumb ov176
 *   func_0217D964 0x0217D964 thumb ov176
 *   func_0217DA38 0x0217DA38 thumb ov176
 *   func_0217DB0C 0x0217DB0C thumb ov176
 *   func_0217DBE0 0x0217DBE0 thumb ov176
 */
#include "../../matched/include/Obj08285.h"
#include "../../matched/include/Obj14366.h"

struct Rec;
struct WordSet;
struct Big;
struct Rec160;
struct Reg2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void func_021E8A78(void *p);
extern void func_0217DE60(int *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern void func_021E8A80(int);
extern int func_021E64C0(unsigned char *, void *);
extern int func_021E8A90(int **p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *sys);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern void func_021E8AA0(int *p, int v);
extern void func_0217D4FC(int *a, int *state, int *p);
extern void func_0217D730(int *a, int *state, int *p);
extern void func_0217D964(int *a, int *state, int *p);
extern void func_0217DA38(int sys, int *state, int *p);
extern void func_0217DB0C(int sys, int *state, int *p);
extern void func_0217DBE0(int a, int *state, int *p);
void func_0217D410(int *p);
void func_0217D434(int *p);
int func_0217D44C(int *p);
void func_0217D458(int a, int unused, char *p);

void func_0217D410(int *p) {func_021E8A78((void *)p[4]);func_0217DE60(p);func_0201ED04((struct WordSet *)p[1]);func_02045C04((struct Rec *)p[0]);func_020307B0(p);}


/*
 *   func_021E64C0 (0x021E64C0) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_0217D434(int *p)
{
    func_021E8A80(((struct Obj08285 *)p)->f10);
    if (((struct Obj08285 *)p)->f8)
        func_021E64C0((unsigned char *)((struct Obj08285 *)p)->f8, (void *)((struct Obj08285 *)p)->f24);
}

int func_0217D44C(int *p) {return func_021E8A90((int **)p[4]);}

void func_0217D458(int a, int unused, char *p)
{
    void *m;
    unsigned x;
    unsigned y;
    m = func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj14366 *)p)->f30)), ((struct Obj14366 *)p)->f14);
    x = func_0200B078(m, 2);
    y = func_0200B078(m, 10);
    if (x && y == 1) {
        func_021E8AA0((int *)a, (int)func_0217D4FC);
        return;
    }
    if (x && y == 2) {
        func_021E8AA0((int *)a, (int)func_0217D730);
        return;
    }
    if (x && y == 3) {
        func_021E8AA0((int *)a, (int)func_0217D964);
        return;
    }
    if (x && y == 4) {
        func_021E8AA0((int *)a, (int)func_0217DA38);
        return;
    }
    if (x && y == 5) {
        func_021E8AA0((int *)a, (int)func_0217DB0C);
        return;
    }
    func_021E8AA0((int *)a, (int)func_0217DBE0);
}
