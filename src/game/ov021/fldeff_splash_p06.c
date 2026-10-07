/*
 * file:     fldeff_splash_p06.c
 * unit:     yes
 * function: func_021C4BC4, func_021C4BE0, func_021C4C0C
 * address:  0x021C4BC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA18     0x021DAA18  data  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */
#include "../../matched/include/Obj07561.h"

struct Actor;
struct VecFx32;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 owner;
    u16 h4;
    u16 h6;
} S_021C4BC4;

typedef unsigned char  u8;

typedef struct {
    u32 a;
    u32 b;
} P2;

typedef struct { int a; int b; } S_021C4C0C;

extern u32 func_021ABE18(unsigned char *p);
extern void func_021C6628(u32 o, u16 v);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *fn, u32 c, u32 d, P2 *e, u32 f);
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021AC1CC(int a, int *v);
void func_021C4BC4(S_021C4BC4 *s);
void func_021C4BE0(void *a, u32 b);
void func_021C4C0C(int a, int *b);
extern char d_021DAA18[];


/*
 * Applies the record's two parameters to the owner's map object.
 */
void func_021C4BC4(S_021C4BC4 *s)
{
    u32 o = func_021ABE18((unsigned char *)s->owner);

    func_021C6628(o, s->h6);
    func_021C6580((u8 *)o, s->h4);
}


/*
 * Queues callback d_021DAA18 with a two-word argument block.
 */
void func_021C4BE0(void *a, u32 b)
{
    P2 t;

    t.a = func_021ABEA0((u32)a, 0x11);
    t.b = b;
    func_021ABFA8(a, d_021DAA18, 0, 0, &t, 0);
}


void func_021C4C0C(int a, int *b)
{
    int v[3];
    int *p = (int *)func_021AC1AC(a);

    *(S_021C4C0C *)b = *(S_021C4C0C *)p;
    func_0216E1A4(b[1], (int)(b + 2));
    func_0216D88C((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
    ((struct Obj07561 *)b)->f10 = *(u16 *)(b[0] + 6);
}
