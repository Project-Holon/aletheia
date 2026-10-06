/*
 * file:     btl_setup_p02.c
 * unit:     yes
 * function: func_02013528, func_020135C0, func_02013610, func_02013644, func_02013678, func_020136AC
 * address:  0x02013528
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020130C4   0x020130C4  thumb
 *   func_0201333C   0x0201333C  thumb
 *   func_02013360   0x02013360  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_0200846C   0x0200846C  thumb
 *   func_0201320C   0x0201320C  thumb
 *   func_0201AC2C   0x0201AC2C  thumb
 *   func_020134F4     0x020134F4  thumb
 *   func_02013284     0x02013284  thumb
 */
#include "../../matched/include/Obj00155.h"
#include "../../matched/include/Obj06858.h"

struct Party;
struct Rec534;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_020130C4(u8 *p);
extern void func_0201320C(int p0);
extern void func_02013360(u8 *o, void *a1, const void *a2);
extern void func_0201333C(u8 *o, void *a1, int a2);
extern void *func_0200846C(int a0);
extern u32  func_0201A920(u16 a);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020134F4(u8 *p, u32 a, u32 id, u32 c, u16 d);
extern void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h);
void func_02013528(u8 *o, void *a1, u32 a2, u8 a3, u32 a4, u8 a5, u8 a6, u16 a7);
void func_020135C0(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5);
void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_02013678(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d);




/*
 * btl_setup.c. The eight-argument setup builder (sibling of func_020135C0).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 152/152, 6 bytes out for four
 * waves, docs/notes/pkt_02013528.c.txt): the eighth (stack) parameter is a
 * heap id and is u16, with u16 on the matching parameter of func_0201333C,
 * func_0200846C and func_0201A920 (func_020135C0 already declares the first
 * and last that way). With u32 there, 1.1p1 schedules the r3 home store
 * `str r3, [sp]` after the three parameter copies; with u16 it comes first,
 * as in the image. docs/idioms/a-u16-stack-parameter-passed-to-a-u16-callee-
 * stays-behind-a-spill-store.md is the same lever.
 */
void func_02013528(u8 *o, void *a1, u32 a2, u8 a3, u32 a4, u8 a5, u8 a6, u16 a7)
{
    u32 sub[4];
    u32 i;

    func_020130C4(o);
    func_0201320C((int)sub);
    sub[0] = 9;
    sub[1] = 1;
    func_02013360(o, a1, sub);
    func_0201333C(o, a1, a7);
    ((struct Obj00155 *)o)->f0 = 3;
    ((struct Obj00155 *)o)->f4 = a2;
    ((struct Obj00155 *)o)->f1C = a4;
    *(o + 0x20) = a5;
    *(o + 0x22) = a3;
    *(o + 0x21) = a6;
    ((struct Obj00155 *)o)->f84 = 0xff;
    ((struct Obj00155 *)o)->f1A = 0x47d;
    i = 0;
    do {
        if (i != 0) {
            u8 *e = o + i * 4;
            if (((struct Obj06858 *)e)->f34 == 0)
                ((struct Obj06858 *)e)->f34 = (u32)func_0200846C(a7);
            if (((struct Obj06858 *)e)->f24 == 0)
                ((struct Obj06858 *)e)->f24 = func_0201A920(a7);
        }
        i++;
    } while (i < 4);
}




/*
 * btl_setup.c.  The four-argument variant of the setup builder: the shared
 * writers run first, then up to two optional attachments are bound through
 * func_0201AC2C, and the object is left in mode 4.
 *
 * This closes the near miss documented in docs/notes/pkt_02013528.c.txt.
 * That note was right that func_0201AC2C cannot carry a fixed two-parameter
 * prototype - the first call site passes r0 and r1, the second passes only
 * r0 - and right that a variadic declaration, `void func_0201AC2C(u32 a,
 * ...)`, is the only one under which both sites emit the original bytes.
 * What it could not recover was the `adds r1, r0, #0` the original keeps
 * before the +0x28 store, and it concluded that binding the result to a
 * named local did not help.
 *
 * The resolution is that r1 is not a register copy at all: it is the SECOND
 * ARGUMENT of the second func_0201AC2C call.  Writing the call as
 * `func_0201AC2C(a3, r)` - handing it the func_0201A920 result the +0x28
 * store also consumes - produces `adds r1, r0, #0; str r1, [r5, #0x28]`
 * exactly, because the value has to reach r1 for the call and the store
 * then reads it from there.  The "leftover" register really is a passed
 * argument, the same tell as
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 * The variadic declaration is what lets the two sites differ in arity.
 *
 * Permuter note: tools/permuter.py hill (179 mutations tried) reached
 * 6 bytes out at the right size with copy(r->r_@6), but its mutation was
 * `r_ = r;` BEFORE r is assigned - an uninitialised read that scores well
 * and is not admissible C.  It did correctly localise the residue to a
 * single r1 -> r0 substitution at the store, which is what pointed at the
 * argument reading rather than at a copy.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020135C0.c \
 *       --func func_020135C0 --addr 0x020135C0 --cc 1.1p1 --thumb
 */
void func_020135C0(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5)
{
    u32 r;

    func_020130C4(a0);
    func_02013360(a0, a1, (const void *)a4);
    func_0201333C(a0, a1, a5);
    if (a2 != 0) {
        func_0201AC2C((const struct Rec534 *)a2, (struct Rec534 *)(((struct Obj00155 *)a0)->f24));
    }
    r = (u32)func_0201A920(a5);
    ((struct Obj00155 *)a0)->f28 = r;
    if (a3 != 0) {
        func_0201AC2C((const struct Rec534 *)a3, (struct Rec534 *)r);
    }
    ((struct Obj00155 *)a0)->f0 = 4;
    ((struct Obj00155 *)a0)->f4 = 0;
}




/*
 * One of a family of four (0x02013610, 0x02013644, 0x02013678, 0x020136AC)
 * that differ only in the constant handed to func_020134F4 as its third
 * argument - 0, 1, 2 and 3 - so this is the id-0 member of a table of
 * builders.  The fifth argument arrives on the stack (the `add r2, sp, #0x20`
 * / `ldrh` pair), which is why the prologue pushes six registers and then
 * takes eight more bytes.
 *
 * The same object goes to both calls; the second call's fourth argument is
 * the object plus 0x28 (the tail of the two stack arguments it forwards).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013610.c \
 *       --func func_02013610 --addr 0x02013610 --cc 1.1p1 --thumb
 */
void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    func_020134F4(p, a, 0, b, d);
    func_02013284(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}




/*
 * Member 1 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * func_020134F4 (1 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013644.c \
 *       --func func_02013644 --addr 0x02013644 --cc 1.1p1 --thumb
 */
void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    func_020134F4(p, a, 1, b, d);
    func_02013284(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}




/*
 * Member 2 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * func_020134F4 (2 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013678.c \
 *       --func func_02013678 --addr 0x02013678 --cc 1.1p1 --thumb
 */
void func_02013678(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    func_020134F4(p, a, 2, b, d);
    func_02013284(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}


/*
 * Member 3 of the four-member family at 0x02013610..0x020136E0 - the same
 * two calls with the same object, differing only in the id handed to
 * func_020134F4 (3 here, and 0, 1, 2, 3 across the family).  The fifth
 * argument arrives on the stack.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020136AC.c \
 *       --func func_020136AC --addr 0x020136AC --cc 1.1p1 --thumb
 */
void func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d)
{
    func_020134F4(p, a, 3, b, d);
    func_02013284(p, (u32 *)a, 1, (u32 *)(p + 0x28), c, d);
}
