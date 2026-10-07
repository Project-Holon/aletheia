/*
 * file:     unit_021E9728_p01.c
 * unit:     yes
 * function: func_021E9728, func_021E9730, func_021E9738, func_021E9760, func_021E979C
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E964C  0x021E964C  thumb  ov093
 *   func_021E9928 0x021E9928 thumb ov093
 */
#include "../../matched/include/Obj06279.h"

struct QU;
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

extern u8 func_021D5440(u8 *p);
extern int func_021E964C(char *p, int *st);
extern void func_021E9928(char *p);
void func_021E9728(struct QU *p, u32 v);
/* 021E9730 movs r1,#0; str r1,[r0,#0x14]; str r1,[r0,#0x18] */ void func_021E9730(struct QU *p);
int func_021E9738(struct S *s);
void func_021E9760(char *p, u8 *a, int b, int c);
void func_021E979C(char *p);

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
    ((struct Obj06279 *)p)->fC0 = func_021D5440(a);
    ((struct Obj06279 *)p)->fB8 = c;
    ((struct Obj06279 *)p)->fC4 = 0;
    ((struct Obj06279 *)p)->f175 = b;
    func_021E9728((struct QU *)p, (u32)func_021E964C);
}

/*
 * Tail-call thunk to func_021E9928 (ldr r3 pool, bx r3). Unlabelled leaf filed as the witness for the call in func_021CE4D0.
 */
void func_021E979C(char *p) { func_021E9928(p); }
