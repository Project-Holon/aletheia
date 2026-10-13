/*
 * file:     unit_021E9728.c
 * unit:     yes
 * function: func_021E9728, func_021E9730, func_021E9738, func_021E9760, func_021E979C, func_021E97A4, func_021E97BC, func_021E9808, func_021E9858, func_021E9884
 * address:  0x021E9728
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06899F40  0x06899F40  thumb
 *   func_06899F64  0x06899F64  thumb
 *   func_06899FD4  0x06899FD4  thumb
 *   func_06899FDC  0x06899FDC  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021E964C  0x021E964C  thumb  ov093
 *   func_021E9928 0x021E9928 thumb ov093
 */
#include "../../matched/include/Obj06279.h"
#include "../../matched/include/Obj21552.h"
#include "../../matched/include/Obj06280.h"
#include "../../matched/include/Obj06281.h"
#include "../../matched/include/Obj21554.h"

struct QU;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021E9728  str r1,[r0,#0x14]; movs r1,#0; str r1,[r0,#0x18] */
struct QU { u8 pad[0x14]; u32 a; u32 b; };

typedef int (*Step)(void *self, void *a, void *b);

struct S {
    char pad[0x14];
    Step fn;
    char a[0x14];
    char b[4];
};

typedef struct { u32 f0; u8 pad[60]; } E64;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021E964C(char *p, int *st);
extern void func_021E9928(char *p);
extern void func_06899F40(void *a, u8 *b, int c);
extern void func_06899F64(void *a, u32 *b, int c);
extern void func_06899FDC(void *p);
void func_021E9728(struct QU *p, u32 v);
void func_021E9730(struct QU *p);
int func_021E9738(struct S *s);
void func_021E9760(char *p, u8 *a, int b, int c);
void func_021E979C(char *p);
int func_021E97A4(char *p);
void func_021E97BC(char *p, u8 *a, int b);
void func_021E9808(char *p, u32 *q, int c);
void func_021E9858(char *p);
int func_021E9884(E64 *p);


/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: str r1, [r0, #0x14]; movs r1, #0; str r1, [r0, #0x18]; bx lr.
 */
void func_021E9728(struct QU *p, u32 v)
{
    p->a = v;
    p->b = 0;
}


/* 021E9730  movs r1,#0; str r1,[r0,#0x14]; str r1,[r0,#0x18] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0; str r1, [r0, #0x14]; str r1, [r0, #0x18]; bx lr.
 */
void func_021E9730(struct QU *p)
{
    p->a = 0;
    p->b = 0;
}


int func_021E9738(struct S *s)
{
    if (s->fn != 0) {
        if (s->fn(s, s->a, s->b) != 0) {
            s->fn = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void func_021E9760(char *p, u8 *a, int b, int c)
{
    *(u8 * *)&((struct Obj06279 *)p)->fBC = a;
    ((struct Obj06279 *)p)->fC0 = BTL_POKEPARAM_GetPokeId(a);
    ((struct Obj06279 *)p)->fB8 = c;
    ((struct Obj06279 *)p)->fC4 = 0;
    ((struct Obj06279 *)p)->f175 = b;
    func_021E9728((struct QU *)p, (u32)func_021E964C);
}


/*
 * Tail-call thunk to func_021E9928 (ldr r3 pool, bx r3). Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 */
void func_021E979C(char *p) { func_021E9928(p); }


int func_021E97A4(char *p)
{
    if (func_021E9738((struct S *)p) != 0) {
        return ((struct Obj21552 *)p)->fC4;
    }
    return 0;
}


void func_021E97BC(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj06280 *)p)->fBC = a;
    ((struct Obj06280 *)p)->fC0 = BTL_POKEPARAM_GetPokeId(a);
    ((struct Obj06280 *)p)->fB8 = b;
    func_06899F40(((struct Obj06280 *)p)->f180, *(u8 * *)&((struct Obj06280 *)p)->fBC, b);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}


void func_021E9808(char *p, u32 *q, int c)
{
    u32 v = *q;

    ((struct Obj06281 *)p)->fBC = v;
    ((struct Obj06281 *)p)->fC0 = BTL_POKEPARAM_GetPokeId((u8 *)v);
    *(u32 * *)&((struct Obj06281 *)p)->f170 = q;
    ((struct Obj06281 *)p)->fB8 = c;
    func_06899F64(((struct Obj06281 *)p)->f180, q, c);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}


void func_021E9858(char *p)
{
    func_06899FDC(((struct Obj21554 *)p)->f180);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}


int func_021E9884(E64 *p) { return func_06899FD4(p[6].f0) != 0; }
