/*
 * file:     procsys_p01.c
 * unit:     yes
 * function: func_0203129C, func_020312B4, func_020312CC, func_020312F8, func_02031324, func_02031330, func_0203133C, func_02031348, func_02031354, func_020313A0
 * address:  0x0203129C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146990 0x02146990 data
 *   func_020313EC  0x020313EC  arm
 *   func_020314F4  0x020314F4  arm
 *   sub_020314DC   0x020314DC  arm
 *   sub_020314B8  0x020314B8  arm
 *   data_020A783C  0x020A783C  data
 */
#include "../../matched/include/Obj03442.h"
#include "../../matched/include/Obj00371.h"
#include "../../matched/include/Obj03005.h"

struct Obj020314F4;
struct S020314DC;
struct S020314B8;
typedef unsigned int u32;

typedef unsigned short u16;

extern int func_020313EC(void *arg);
extern void func_020314F4(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);
extern void sub_020314DC(struct S020314DC *p, u32 a, u32 b, u32 c);
extern void sub_020314B8(struct S020314B8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
asm void func_0203129C(void);
int func_020312B4(void);
void func_020312CC(u32 a1, u32 a2, u32 a3);
void func_020312F8(u32 a1, u32 a2, u32 a3);
void *func_02031324(int a0);
unsigned int func_02031330(void *p);
void sub_0203133C(struct S020314B8 *p);
void func_02031348(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);
void *func_02031354(int a0);
int func_020313A0(int a0);
extern void *g_02146990;
extern char data_020A783C[];

asm void func_0203129C(void)
{
    stmfd sp!, {r3, lr}
    bl func_02031354
    ldr r1, =g_02146990
    str r0, [r1]
    ldmfd sp!, {r3, pc}
}

/*
 * Tail-call forwarder passing g_02146990 to func_020313EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020312B4.c \
 *       --func func_020312B4 --addr 0x020312B4 --cc 1.1p1 --arm
 */
int func_020312B4(void)
{
    return func_020313EC(g_02146990);
}

/*
 * Forwarder: passes the object held in g_02146990 to func_020314F4 with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/func_020312CC.c \
 *       --func func_020312CC --addr 0x020312CC --cc 1.1p1 --arm
 */
void func_020312CC(u32 a1, u32 a2, u32 a3)
{
    func_020314F4(g_02146990, a1, a2, a3);
}

/*
 * Forwarder: passes the object held in g_02146990 to sub_020314DC with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/func_020312F8.c \
 *       --func func_020312F8 --addr 0x020312F8 --cc 1.1p1 --arm
 */
void func_020312F8(u32 a1, u32 a2, u32 a3)
{
    sub_020314DC(g_02146990, a1, a2, a3);
}

void *func_02031324(int a0)
{
    return func_02031354(a0);
}

unsigned int func_02031330(void *p)
{
    return func_020313EC(p);
}

/*
 * A four-instruction tail call to sub_020314B8
 * (src/matched/sub_020314B8.c, this same packet), attested by the
 * `matched` class: sub_020314B8's own EXACT entry pins its address, and
 * this call is the only branch to it found in the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203133C.c \
 *       --func sub_0203133C --addr 0x0203133C --cc 1.1p1
 */
void sub_0203133C(struct S020314B8 *p)
{
    sub_020314B8(p);
}

void func_02031348(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3)
{
    func_020314F4(obj, a1, a2, a3);
}

/*
 * Allocates a 0x20-byte node and lays down a sentinel ring: the first
 * halfword is the caller's key, +4 and +0x14 hold -1 (the two ends of a list
 * with no members) and every other word is 0.  The linker merges the two
 * adjacent zero stores at +4/+8 into one `stmib r0, {r1, r4}`.
 *
 * The first argument handed to func_02030734 is the caller's own parameter -
 * the original never writes r0 before the call, so r0 still holds a0.  A
 * literal first argument makes the compiler materialise it and shifts the
 * whole prologue.
 *
 * The pool word 0x020A783C is a `literal` site: it appears in ten other
 * pools in the image, e.g. 0x0203158C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031354.c \
 *       --func func_02031354 --addr 0x02031354 --cc 1.1p1 --arm
 */
void *func_02031354(int a0)
{
    char *p = func_02030734(a0, 0x20, 0, (const char *)((int)data_020A783C), 0xc5);

    ((struct Obj03442 *)p)->f0 = a0;
    ((struct Obj03442 *)p)->f4 = -1;
    ((struct Obj03442 *)p)->f8 = 0;
    ((struct Obj03442 *)p)->fC = 0;
    ((struct Obj03442 *)p)->f10 = 0;
    ((struct Obj03442 *)p)->f14 = -1;
    ((struct Obj03442 *)p)->f18 = 0;
    ((struct Obj03442 *)p)->f1C = 0;
    return p;
}

int func_020313A0(int a0){ int t0; t0 = func_02031538((int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f14, (int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f18, (int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f1C, (int)((struct Obj00371 *)((char *)(a0)))->f0); *(int *)&((struct Obj03005 *)((char *)(t0)))->f18 = (int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f8; *(int *)(((char *)(*(int *)&((struct Obj00371 *)((char *)(a0)))->f8) + 28)) = (int)t0; *(int *)&((struct Obj00371 *)((char *)(a0)))->f8 = (int)t0; *(int *)&((struct Obj00371 *)((char *)(a0)))->fC = (int)0; *(int *)&((struct Obj00371 *)((char *)(a0)))->f14 = (int)(0 - 1); *(int *)&((struct Obj00371 *)((char *)(a0)))->f18 = (int)0; *(int *)&((struct Obj00371 *)((char *)(a0)))->f1C = (int)0; return t0; }
