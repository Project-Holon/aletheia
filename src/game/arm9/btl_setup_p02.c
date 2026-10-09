/*
 * file:     btl_setup_p02.c
 * unit:     yes
 * function: func_02013528, func_020135C0, func_02013610, func_02013644, func_02013678, func_020136AC, func_020136E0, func_02013734, func_02013790, func_020137C0, func_020137F0, func_02013810, func_02013864, func_02013894, func_020138C4, func_02013930, func_0201394C, func_02013980
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
 *   func_020307B0     0x020307B0  arm
 *   func_020130DC     0x020130DC  thumb
 *   func_0202A3FC  0x0202A3FC  thumb
 *   func_02030734  0x02030734  arm
 *   sZonedataFile  0x020A729C  data
 */
#include "../../matched/include/Obj00155.h"
#include "../../matched/include/Obj06858.h"
#include "../../matched/include/Obj15647.h"

struct Party;
struct Rec534;
struct Link;
struct Big;
struct Sub02008700Obj;
struct ZoneData;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj020136E0 {
    u8  pad00[0x22];
    u8  f22;            /* +0x22 */
};

struct Obj02013734 {
    u8  pad00[0x22];
    u8  f22;            /* +0x22 */
};

typedef struct {
    char pad0[0x23];
    u8 b23;
    void *a24[4];
    void *a34[4];
    char pad1[4];
    void *a48[4];
    int f58;
    int f5c;
    char pad2[8];
    int f68;
} S;

struct Obj {
    u8  pad00[0x5C];
    u32 f5c;        /* +0x5C */
};

struct ZoneData_0201394C {
    u32 f0;             /* +0x00 */
    u8  pad04[0x14];
    u16 f18;            /* +0x18 */
    u16 f1a;            /* +0x1A */
    u8  pad1c[0x30];
    u8 *f4c;            /* +0x4C */
};

struct ZoneData_02013980 {
    u8  pad00[0x94];
    u8 *f94;            /* +0x94 */
};

extern void func_020130C4(u8 *p);
extern void func_0201320C(int p0);
extern void func_02013360(u8 *o, void *a1, const void *a2);
extern void func_0201333C(u8 *o, void *a1, int a2);
extern void *func_0200846C(int a0);
extern u32  func_0201A920(u16 a);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020134F4(u8 *p, u32 a, u32 id, u32 c, u16 d);
extern void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u16 h);
extern u8 func_0203D1A4(struct Link *p);
extern struct Party *sub_0201A920(u32 heap);
extern void *sub_0200846C(int a0);
extern void *sub_02013234(u32 heap);
extern void *sub_02012EBC(struct Big *p);
extern struct Sub02008700Obj *sub_0200873C(void *sys);
extern void *sub_020082EC(int a0);
extern void sub_02008314(void *a0, void *a1);
extern void *sub_0200CA1C(void *a);
extern void sub_02013980(struct ZoneData *o, u32 heap);
extern void sub_02082BCC(void *p, int c, int n);
extern u32 func_020307B0(void *p);
extern void func_020130DC(struct Obj *p);
extern u8 func_0202A3FC(u32 key);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_02013528(u8 *o, void *a1, u32 a2, u8 a3, u32 a4, u8 a5, u8 a6, u16 a7);
void func_020135C0(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5);
void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_02013678(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d);
void func_020136E0(struct Obj020136E0 *o, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5);
void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
void func_02013790(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4);
void func_020137C0(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4);
void func_020137F0(u8 *p0, void *p1, u32 p2, u8 p3, u8 p4, u16 p5);
void func_02013810(u8 *o, void *a1, u32 a2, u8 a3, u8 a4, u32 a5, u32 a6, u16 a7);
void func_02013864(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4);
void func_02013894(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4);
void sub_020138C4(S *p, int a1, void *a2);
void func_02013930(struct Obj *p);
void func_0201394C(struct ZoneData_0201394C *o);
void func_02013980(struct ZoneData_02013980 *o, u32 heap);
extern u8 sZonedataFile;





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


/*
 * The main variant of the three-slot setup (see func_02013734, the brief
 * one): the first call is the four-register form of the same writer with
 * count 1, then two calls into func_02013284 that each carry the source's
 * own stack arguments - a word and the halfword at +4 of the argument
 * block - plus the two object sub-blocks at +0x28 and +0x30.  The last
 * store marks the object's +0x22 byte as the count of sub-blocks.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020136E0.c \
 *       --func func_020136E0 --addr 0x020136E0 --cc 1.1p1 --thumb
 */
void func_020136E0(struct Obj020136E0 *o, u32 a1, u32 a2, u32 a3, u32 a4,
                   u16 a5)
{
    func_020134F4((u8 *)o, a1, 1, a2, a5);
    func_02013284((u8 *)o, (u32 *)a1, 1, (u32 *)((u8 *)o + 0x28), a3, a5);
    func_02013284((u8 *)o, (u32 *)a1, 3, (u32 *)((u8 *)o + 0x30), a4, a5);
    *((u8 *)o + 0x22) = 4;
}


/*
 * The three-slot setup that takes a single word argument block: the shared
 * halfword is the first word of that block (its low half, copied into the
 * outgoing stack slot of the first call) and the fourth word of the object
 * is the outer value both other calls carry.  Only three sub-blocks here,
 * so the trailing byte is 3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013734.c \
 *       --func func_02013734 --addr 0x02013734 --cc 1.1p1 --thumb
 */
void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4,
                   u32 a5, u16 a6)
{
    func_020134F4((u8 *)o, a1, 1, a2, a6);
    func_02013284((u8 *)o, (u32 *)a1, 2, (u32 *)((u8 *)o + 0x2c), a3, a6);
    func_02013284((u8 *)o, (u32 *)a1, 1, (u32 *)((u8 *)o + 0x28), a4, a6);
    func_02013284((u8 *)o, (u32 *)a1, 3, (u32 *)((u8 *)o + 0x30), a5, a6);
    *((u8 *)o + 0x22) = 3;
}


/*
 * The id-0 member of the second builder family in this packet: the fourth
 * argument of the shared 8-argument helper func_02013528 is 0, and the
 * object's argument is first run through func_0203D1A4 (ARM) whose result
 * becomes the seventh argument.  func_02013528's last four parameters live
 * on the stack, which is the sixteen-byte frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013790.c \
 *       --func func_02013790 --addr 0x02013790 --cc 1.1p1 --thumb
 */
void func_02013790(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4)
{
    u8 r = func_0203D1A4((struct Link *)p2);

    func_02013528(p0, p1, 0, 0, p2, p3, r, p4);
}


/*
 * The id-1 member of the same family - byte for byte func_02013790 with a 1
 * where it has a 0 (the third argument of func_02013528).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020137C0.c \
 *       --func func_020137C0 --addr 0x020137C0 --cc 1.1p1 --thumb
 */
void func_020137C0(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4)
{
    u8 r = func_0203D1A4((struct Link *)p2);

    func_02013528(p0, p1, 1, 0, p2, p3, r, p4);
}



/*
 * The shortest member of the family: no func_0203D1A4 call, and the two stack
 * arguments the caller passes (a byte at +0x00 and a halfword at +0x04 of the
 * caller's stack block) are forwarded as the seventh and eighth arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020137F0.c \
 *       --func func_020137F0 --addr 0x020137F0 --cc 1.1p1 --thumb
 */
void func_020137F0(u8 *p0, void *p1, u32 p2, u8 p3, u8 p4, u16 p5)
{
    func_02013528(p0, p1, 1, 1, p2, p3, p4, p5);
}



/*
 * btl_setup.c.  The three-slot builder on the eight-argument writer: the
 * same shape as func_020136E0 and func_02013734 (both EXACT), but the lead
 * call is func_02013528 rather than func_020134F4, so the object's mode is
 * stored by this function (1) instead of by the writer.
 *
 * The documented near miss in docs/notes/pkt_02013810.c.txt compiled 56
 * bytes against 84 because it gave func_02013528 six parameters and
 * func_02013284 seven, and passed the object's +0x28 sub-block as a bare
 * constant.  The arity is fixed by the matched members of both families:
 * func_02013528 takes eight (func_02013790, func_020137F0 et al) and
 * func_02013284 takes six (func_02013610, func_020136E0 et al).  With those
 * two prototypes and the shared halfword forwarded to all three calls, the
 * body is the ordinary family shape and matches first try.
 *
 * The incoming stack block is what `add r6, sp, #0x28` addresses (0x10 of
 * frame plus six pushed registers): a4 is the byte at +0x00, a5 the word at
 * +0x04, a6 the word at +0x08 and a7 the halfword at +0x0C, which is why a7
 * is re-loaded with `ldrh [r6, #0xc]` before each of the three calls rather
 * than kept in a register.
 *
 * EXACT*: all 82 code bytes reproduce (3 of 3 relocation sites resolved);
 * the inferred extent ran two bytes long only on the `movs r0, r0` alignment
 * pad at 0x02013862 before func_02013864, which has a label.  Never a byte
 * difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013810.c \
 *       --func func_02013810 --addr 0x02013810 --cc 1.1p1 --thumb
 */
void func_02013810(u8 *o, void *a1, u32 a2, u8 a3, u8 a4, u32 a5, u32 a6, u16 a7)
{
    func_02013528(o, a1, 1, 2, a2, a3, a4, a7);
    ((struct Obj00155 *)o)->f0 = 1;
    func_02013284(o, (u32 *)a1, 1, (u32 *)(o + 0x28), a5, a7);
    func_02013284(o, (u32 *)a1, 3, (u32 *)(o + 0x30), a6, a7);
}


/*
 * The id-2 member of the same family - byte for byte func_02013790 with a 2
 * where it has a 0 (the third argument of func_02013528).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013864.c \
 *       --func func_02013864 --addr 0x02013864 --cc 1.1p1 --thumb
 */
void func_02013864(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4)
{
    u8 r = func_0203D1A4((struct Link *)p2);

    func_02013528(p0, p1, 2, 0, p2, p3, r, p4);
}


/*
 * The id-3 member of the same family - byte for byte func_02013790 with a 3
 * where it has a 0 (the third argument of func_02013528).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013894.c \
 *       --func func_02013894 --addr 0x02013894 --cc 1.1p1 --thumb
 */
void func_02013894(u8 *p0, void *p1, u32 p2, u8 p3, u16 p4)
{
    u8 r = func_0203D1A4((struct Link *)p2);

    func_02013528(p0, p1, 3, 0, p2, p3, r, p4);
}



void sub_020138C4(S *p, int a1, void *a2)
{
    u32 i;
    int t;
    int v;

    sub_02082BCC(p, 0, 0xf0);
    for (i = 0; i < 4; i++) {
        p->a24[i] = (void *)sub_0201A920((u32)a2);
        p->a34[i] = (void *)sub_0200846C((int)a2);
        p->a48[i] = (void *)sub_02013234((u32)a2);
    }
    p->f58 = a1;
    t = (int)sub_0200873C(sub_02012EBC((void *)a1));
    v = (int)sub_020082EC((int)a2);
    p->f5c = v;
    sub_02008314((void *)t, (void *)v);
    p->f68 = (int)sub_0200CA1C((void *)a1);
    p->b23 = 1;
    sub_02013980((struct ZoneData *)p, (u32)a2);
}



/*
 * The subsystem destructor: the +0x5C buffer is released and its pointer
 * cleared (the store inside the guard, not after it), then the teardown is
 * handed to func_020130DC with the object left in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013930.c  *       --func func_02013930 --addr 0x02013930 --cc 1.1p1 --thumb
 */
void func_02013930(struct Obj *p)
{
    if (p->f5c != 0) {
        func_020307B0((void *)p->f5c);
        p->f5c = 0;
    }
    func_020130DC(p);
}



/*
 * zonedata.c.  A one-shot state step: only while the state word is 1 does it
 * advance to 2 and choose a pair of halfword bounds, keyed off a value read
 * through the object's +0x4c pointer.  The 0x470/0x480 pair is built by
 * `movs`+`lsls` (Thumb has no wide immediate), the 0x46b/0x47d pair comes
 * from the literal pool because 0x46b does not fit a Thumb immediate - both
 * spellings are a plain `u16` store of a constant.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201394C.c \
 *       --func func_0201394C --addr 0x0201394C --cc 1.1p1 --thumb
 */
void func_0201394C(struct ZoneData_0201394C *o)
{
    if (o->f0 == 1) {
        o->f0 = 2;
        if (func_0202A3FC(((struct Obj15647 *)(o->f4c))->f4) != 0xb) {
            o->f18 = 0x46b;
            o->f1a = 0x47d;
        } else {
            o->f18 = 0x470;
            o->f1a = 0x480;
        }
    }
}



/*
 * zonedata.c.  A lazy 0xc00-byte zeroed allocation hung off the object at
 * +0x94: the allocator gets the caller's heap (its own r0 is overwritten by
 * the pointer arithmetic, so the heap is carried in r1 at entry), the class
 * id 3 << 10 and the file name/line pair.  The `str r0, [sp]` is the fifth
 * argument, i.e. the source line 0x39a.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013980.c \
 *       --func func_02013980 --addr 0x02013980 --cc 1.1p1 --thumb
 */
void func_02013980(struct ZoneData_02013980 *o, u32 heap)
{
    if (o->f94 == 0) {
        o->f94 = func_02030734(heap, 3 << 10, 0, (const char *)&sZonedataFile, 0x39a);
    }
}
