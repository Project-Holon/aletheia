/*
 * file:     unit_020911D4_p04.c
 * unit:     yes
 * function: func_02091284, func_0209128C, func_020912A8, func_02091374, func_0209138C, func_020913A4, func_020913BC, func_020913D0, func_020913E8, func_020913FC, func_0209146C, func_0209149C, func_02091524, func_02091588, func_02091594, func_02091598, func_0209159C, func_020915C4, func_02091650, func_020916D4, func_020917D4, func_02091AE8, func_02091B5C, func_02091C40, func_02091CBC
 * address:  0x02091284
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
 *   g_02153B88  0x02153B88  data
 *   func_02086028  0x02086028  arm
 *   func_020860D0  0x020860D0  arm
 *   func_02086078  0x02086078  arm
 *   func_0209D728  0x0209D728  arm
 *   g_02150FEC  0x02150FEC  data
 *   g_02153B8C  0x02153B8C  data
 *   g_02153BB0  0x02153BB0  data
 *   g_02153BD4  0x02153BD4  data
 *   g_020A8818  0x020A8818  data
 *   func_0209BD38  0x0209BD38  arm
 *   OS_AllocFromHeap  0x020868E0  arm
 *   OS_FreeToHeap  0x020869E8  arm
 *   ENV_InsertResourceSet  0x02086C54  arm
 *   func_02092344  0x02092344  arm
 *   func_020923B0  0x020923B0  arm
 *   g_020A8730  0x020A8730  data
 *   arr_02153B8C  0x02153B8C  data
 *   arr_02153BB0  0x02153BB0  data
 *   func_02096508  0x02096508  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   g_020A60DC  0x020A60DC  data
 *   g_02153FAC  0x02153FAC  data
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02086028(void *a0);
extern int func_020860D0(void *a0);
extern void func_02086078(void *a0);
extern int func_0209D728(int a);
extern int func_0209BD38(int x);
extern void *OS_AllocFromHeap(u32 a, u32 b, u32 heap);
extern void OS_FreeToHeap(u32 a, u32 b, u32 heap);
u32 ENV_InsertResourceSet(void *prev, void *resSet);
asm void func_02091284(void);
void func_0209128C(int x);
u32 func_020912A8(u32 a0);
int func_02091374(void);
void *func_0209138C(u32 heap);
void func_020913A4(u32 heap);
u32 func_020913BC(void *resSet);
void *func_020913D0(u32 heap);
extern u8 g_02153B88;
struct H { u32 unk00; u32 *unk04; };
extern struct H g_02150FEC;
extern u32 g_02153B8C;
extern u32 g_02153BB0;
extern u32 g_02153BD4;
extern int g_020A8818;

/*
 * An eight-byte ARM linker veneer, `ldr pc, [pc, #-4]; .word 0x02731920`, the
 * long-branch stub reached from 0x0209125C.  No C spelling produces it
 * (docs/idioms/an-arm-stub-pointing-outside-every-region-cannot-be-attested.md),
 * so it is written as an asm function in the form of src/matched/func_02005B6C.c;
 * the pointer word is a plain constant, not a relocation, because 0x02731920
 * lies outside every region of layout/layout.json.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091284.c  *       --func func_02091284 --addr 0x02091284 --cc 1.1p1 --arm
 */
asm void func_02091284(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02731920
}

/*
 * The image keeps BOTH arms predicated (`movne r1, #1` ... `moveq r1, #0`).
 * A single `x != 0` test lets 1.1p1 drop the first predicate (plain
 * `mov r1, #1`, one byte out, ~80 spellings in docs/notes/func_0209128C.c.txt).
 * A two-term `&&` condition goes through the short-circuit if-conversion
 * path, which predicates both arms; the redundant second test is folded away
 * afterwards, leaving the single `cmp r0, #0`.  Same shape in 1.1p1 matched
 * code: src/matched/func_02037700.c (`if (a && b) flag = 1;`).
 */
void func_0209128C(int x)
{
    u8 v;

    if (x && x) {
        v = 1;
    } else {
        v = 0;
    }
    g_02153B88 = v;
}

/*
 *           `bl` at +0x90 inside this very function.  `label` needs a site from
 *           outside 020912A8..02091374 and there is none, and func_0209D728 is
 *           itself parked at MATCH in src/pending/func_0209D728.c, so the
 *           `matched` class has no manifest entry to cite either.  Filing the
 *           callee is the fix, but it lives in pkt_0209D728, which is not one
 *           of this lane's packets (write-set rule 9).
 *
 * harness output:
 *   MATCH  compiled 204 = original 204, 7 of 8 sites resolved
 *     +0010 func_020860D0 [label x20]   +0070 func_02086028 [label x25]
 *     +0090 func_0209D728 [UNRESOLVED - no witness outside this range]
 *     +00B0 func_02086078 [label x25]
 *     +00BC g_02153BD4 [literal x15]    +00C0 g_02150FEC [literal x60]
 *     +00C4 g_02153B8C [literal x15]    +00C8 g_02153BB0 [literal x15]
 *   every concrete byte right, no wildcard byte is inside a branch opcode.
 */
u32 func_020912A8(u32 a0)
{
    u32 r;

    if (func_020860D0(&g_02153BD4) == 0) {
        g_02153B8C = g_02150FEC.unk04[0x1b];
        g_02153BB0 = 1;
    } else if (g_02153B8C == g_02150FEC.unk04[0x1b]) {
        g_02153BB0 = g_02153BB0 + 1;
    } else {
        func_02086028(&g_02153BD4);
        g_02153B8C = g_02150FEC.unk04[0x1b];
        g_02153BB0 = 1;
    }
    r = func_0209D728(a0);
    if (--g_02153BB0 == 0) {
        func_02086078(&g_02153BD4);
    }
    return r;
}

int func_02091374(void)
{
    return func_0209BD38(g_020A8818);
}

void *func_0209138C(u32 heap)
{
    return OS_AllocFromHeap(0, (u32)-1, heap);
}

void func_020913A4(u32 heap)
{
    OS_FreeToHeap(0, (u32)-1, heap);
}

/*
 * note:     env_system.o ENV_PrependResourceSet; target named OS_ReferentSize by libmatch.
 */
u32 func_020913BC(void *resSet)
{
    return ENV_InsertResourceSet(0, resSet);
}

void *func_020913D0(u32 heap)
{
    if (heap == 0)
        return 0;
    return func_0209138C(heap);
}

#include "../../matched/include/Obj00481.h"
#include "../../matched/include/Obj16696.h"

struct P02091B5C;
struct S0209159C;
struct FILE;
struct S020915C4;
struct S02091650;

struct Cfg4 {
    u32 pad : 7;
    u32 f3  : 3;
    u32 rest : 22;
};

struct Cfg0209149C {
    u32 mode : 3;
    u32 rest : 29;
};

struct S0209159C {
    u32 pad00[6];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 pad30;
    u32 f34;
};

struct S020915C4 {
    u32 f00;
    u32 f04;
    u32 pad08[4];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 pad30[3];
    u32 f3c;
    u32 f40;
    u32 pad44;
    u32 f48;
};

typedef u32 (*Fn020915C4)(u32, u32, u32 *, u32);

struct S02091650 {
    u32 f00;
    u32 f04;
    u32 pad08[4];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 pad30[3];
    u32 f3c;
    u32 f40;
    u32 pad44;
    u32 f48;
};

typedef u32 (*Fn02091650)(u32, u32, u32 *, u32);

typedef int            s32;


typedef unsigned short u16;

typedef unsigned int   size_t;

typedef unsigned short wchar_t;

typedef struct {
    u32 open_mode        : 2;
    u32 io_mode          : 3;
    u32 buffer_mode      : 2;
    u32 file_kind        : 3;
    u32 file_orientation : 2;
    u32 binary_io        : 1;
} file_modes;

typedef struct {
    u32 io_state    : 3;
    u32 free_buffer : 1;
} file_state;

typedef struct FILE {
    u32        handle;              /* 0x00 */
    file_modes mode;                /* 0x04 */
    file_state state;               /* 0x08 */
    u8         eof;                 /* 0x0c */
    u8         error;               /* 0x0d */
    u8         char_buffer;         /* 0x0e */
    u8         char_buffer_overflow;/* 0x0f */
    u8         pad10[2];            /* 0x10 */
    u8         ungetc_buffer[2];    /* 0x12 */
    wchar_t    ungetwc_buffer[2];   /* 0x14 */
    u32        position;            /* 0x18 */
    u8        *buffer;              /* 0x1c */
    u32        buffer_size;         /* 0x20 */
    u8        *buffer_ptr;          /* 0x24 */
    u32        buffer_len;          /* 0x28 */
    u32        buffer_alignment;    /* 0x2c */
    u32        saved_buffer_len;    /* 0x30 */
} FILE;

struct P02091B5C {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  f0c;
    u8  f0d;
    u8  pad0e[0xa];
    u32 f18;
    u32 pad1c[3];
    u32 f28;
};

struct F04hi { u32 lo : 7; u32 mode : 3; u32 hi : 22; };

struct F04lo { u32 lo : 2; u32 sub : 3; u32 hi : 27; };

struct F08   { u32 mode : 3; u32 hi : 29; };

struct P02091CBC {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  f0c;
    u8  f0d;
    u8  pad0e[0xa];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
};

struct F04hiP { u32 lo : 7; u32 mode : 3; u32 hi : 22; };

struct F08P   { u32 mode : 3; u32 hi : 29; };

extern void func_020913A4(u32 heap);
extern void *func_020913D0(u32 heap);
extern void func_020913E8(void *p);
extern u32 func_020913BC(void *p);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void *func_020923B0(void *p, int c, u32 n);
extern int func_02091B5C(struct P02091B5C *p);
extern void func_0209159C(struct S0209159C *p);
extern s32 func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);
extern unsigned int func_020917D4(void *ptr, unsigned int memb_size, unsigned int num_memb, struct FILE *file);
extern int func_02091650(struct S02091650 *p, u32 *a1);
asm void ghiFreeTempBuffer(void);
void *func_020913FC(u32 a0, u32 a1);
void *func_0209146C(u32 a0, u32 a1);
int func_0209149C(void);
int func_02091524(void);
int func_02091588(int x);
void func_02091594(int a, void *b);
void func_02091598(int a, void *b);
s32 func_020916D4(void *a0, u32 a1, u32 a2, u32 a3);
int func_02091AE8(u8 *p);
int func_02091C40(const u8 *s1, const u8 *s2, int n);
extern u8 g_020A8730[];
extern u32 arr_02153B8C[];
extern u32 arr_02153BB0[];
extern const u8 g_020A60DC[];
extern u32 g_02153FAC;

asm void ghiFreeTempBuffer(void)
{
    stmfd sp!, {r3, lr}
    cmp r0, #0
    ldmeqfd sp!, {r3, pc}
    bl func_020913A4
    ldmfd sp!, {r3, pc}
}

/*
 *           callees func_020913E8 and func_020913BC have no witness
 *           outside 020913FC..0209146C (the only branches to them are
 *           the three sites inside this file), so those call sites stay
 *           wildcarded.  No C change is possible; the file becomes
 *           EXACT once either callee has its own shard entry.
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void *func_020913FC(u32 a0, u32 a1)
{
    void *p;
    u32 n;

    if (a0 == 0)
        return func_020913D0(a1);
    if (a1 == 0) {
        func_020913E8((void *)a0);
        return 0;
    }
    n = func_020913BC((void *)a0);
    p = func_020913D0(a1);
    if (p != 0) {
        if (n >= a1)
            n = a1;
        func_02092344(p, (const void *)a0, n);
        func_020913E8((void *)a0);
    }
    return p;
}

void *func_0209146C(u32 a0, u32 a1)
{
    u32 size = a1;
    void *p;

    size = size * a0;
    p = func_020913D0(size);
    if (p != 0)
        func_020923B0(p, 0, size);
    return p;
}

/*
 * The gated sweep of g_020A8730: same three 0x4C-byte records as
 * func_02091524, but each record is only offered to func_02091B5C when three
 * bits of its own header agree, and the record is rejected as soon as any of
 * them fails.
 *
 * Two shapes carry the bytes:
 *
 *  - the 3-bit field at bits 7..9 of the record word at +4 has to be read as
 *    a bitfield, not as `(x << 22) >> 29`.  Writing the shifts out gives the
 *    same value but lets the register allocator put the loaded word in r2 and
 *    the extracted value in r1; the bitfield spelling puts the word in r1 and
 *    the extraction in r2, which is what the original has.  The pad member is
 *    what places the field at bit 7: a `lsl #0x16` (32 - (7 + 3)) extraction
 *    is only produced for a field whose offset is 7.
 *  - the middle test is `((x << 25) >> 30) & 1`, an unequal shift pair (the
 *    docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift
 *    shape) and not a bitfield read: `tst r1, #1` after a 2-bit extraction is
 *    bit 5 selected out of a two-bit field, which no single declaration
 *    produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209149C.c \
 *       --func func_0209149C --addr 0x0209149C --cc 1.1p1 --arm
 *   EXACT, 136 bytes, 2 relocation sites, both resolved.
 */
int func_0209149C(void)
{
    u8 *p = g_020A8730;
    int i = 1;
    int r = 0;

    do {
        if (((struct Cfg4 *)(p + 4))->f3 != 0 &&
            (((((struct Obj00481 *)p)->f4 << 25) >> 30) & 1) != 0 &&
            ((struct Cfg0209149C *)(p + 8))->mode == 1) {
            if (func_02091B5C((struct P02091B5C *)p) != 0)
                r = -1;
        }
        p = (i < 3) ? g_020A8730 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}

/*
 * Walks the three 0x4C-byte records of g_020A8730 and asks func_02091B5C
 * about every record whose +4 bitfield 3..5 is set, returning -1 as soon as
 * one of them fails and 0 otherwise.
 *
 * The two `!= 0` conditions are what put the g_020A8730 address in a
 * callee-saved register: the source names the global in the loop's own
 * advance expression (`p = (i < 3) ? g_020A8730 + i++ * 0x4c : 0`) rather
 * than binding it to a pointer local, so the loaded address is CSE'd into one
 * value that stays live across the func_02091B5C call and lands in r8, while
 * the cursor itself dies as that call's argument and lives in r0.  A `u8
 * *base` local instead sends the address to r5 and the induction variable to
 * r6, and the loop tail then renumbers (16 bytes of diff, and 0209149C's
 * sibling goes the same way).
 *
 * `i++ * 0x4c` rather than `i * 0x4c` is pinned by the increment sitting in
 * the true arm only: the whole ternary is if-converted, so the increment is
 * `addlt r5, r5, #1` and the false arm's 0 is rematerialised in its own
 * register (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091524.c \
 *       --func func_02091524 --addr 0x02091524 --cc 1.1p1 --arm
 *   EXACT, 100 bytes, 2 relocation sites, both resolved.
 */
int func_02091524(void)
{
    u8 *p = g_020A8730;
    int i = 1;
    int r = 0;

    do {
        if (((((struct Obj00481 *)p)->f4 << 22) >> 29) != 0) {
            if (func_02091B5C((struct P02091B5C *)p) != 0)
                r = -1;
        }
        p = (i < 3) ? g_020A8730 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}

int func_02091588(int x){ return x < 0 ? -x : x; }

void func_02091594(int a, void *b){ }

void func_02091598(int a, void *b){ }

/*
 * Three field moves on the object, in source order and nothing else:
 * `p->f24 = p->f1c; p->f28 = p->f20 - (p->f18 & p->f2c); p->f34 = p->f18;`.
 *
 * The load order (0x18, 0x2c, 0x1c, 0x20) is the scheduler hoisting the
 * second statement's two loads above the first statement's store, and the
 * register numbering ([r2, r1, ip, r3] for the four loads) follows from the
 * object being a struct: reading the fields through a `struct S *` keeps the
 * word loads independent, and the whole function is then a straight line with
 * no prologue at all.  No relocation sites, so the 40 bytes are compared
 * byte for byte with nothing wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209159C.c \
 *       --func func_0209159C --addr 0x0209159C --cc 1.1p1 --arm
 *   EXACT, 40 bytes, no relocation sites.
 */
void func_0209159C(struct S0209159C *p)
{
    p->f24 = p->f1c;
    p->f28 = p->f20 - (p->f18 & p->f2c);
    p->f34 = p->f18;
}

/*
 * One deferred transaction against the object: re-derive the working fields
 * (func_0209159C), optionally preload the amount from the object's f20 when
 * the mode argument is 1, run the object's own f3c handler with four
 * arguments (f00, f1c, &f28 and f48 - the fourth is only visible as the dead
 * `ldr r3, [r4, #0x48]` the call does not otherwise need), publish f28 to the
 * caller's out parameter, and on success fold f28 into the running f18.
 *
 * The handler is called through a plain cast of the field
 * (`((Fn)p->f3c)(...)`, i.e. the field itself declared as a function
 * pointer).  Spelling it as a guarded indirect call (`p->f3c ? ... : 0`)
 * compiles to a branchy 102-byte-different body: the original is a bare
 * `blx ip`.
 *
 * The flag test is `((p->f04 << 19) >> 31) == 0`, one bit selected out of the
 * word at +4; the unequal shift pair keeps both shifts (a mask would fold to
 * `tst #0x1000`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020915C4.c \
 *       --func func_020915C4 --addr 0x020915C4 --cc 1.1p1 --arm
 *   EXACT, 140 bytes, 2 relocation sites, both resolved.
 */
int func_020915C4(struct S020915C4 *p, u32 *a1, int a2)
{
    u32 r;

    func_0209159C((struct S0209159C *)p);
    if (a2 == 1)
        p->f28 = p->f20;
    r = ((Fn020915C4)p->f3c)(p->f00, p->f1c, &p->f28, p->f48);
    if (r == 2)
        p->f28 = 0;
    if (a1 != 0)
        *a1 = p->f28;
    if (r != 0)
        return r;
    p->f18 += p->f28;
    if (((p->f04 << 19) >> 31) == 0)
        func_02091598(p->f1c, &p->f28);
    return 0;
}

/*
 * The commit half of the pair whose prepare half is func_020915C4: work out
 * the amount still to apply (f24 - f1c), and if there is one, publish it to
 * f28, pre-process it through func_02091594, run the object's f40 handler with
 * the same four arguments func_020915C4 uses, hand f28 back through the out
 * parameter, and fold the applied amount into f18 on success.  The trailing
 * func_0209159C and `return 0` are shared by both paths, which is why the
 * body's early exit is the loop-free `if (d != 0) { ... }` shape rather than a
 * `goto`.
 *
 * The handler is again a bare `blx ip` off a cast field; the f04 flag bit is
 * the same unequal-shift-pair test as in func_020915C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091650.c \
 *       --func func_02091650 --addr 0x02091650 --cc 1.1p1 --arm
 *   EXACT, 132 bytes, 2 relocation sites, both resolved.
 */
int func_02091650(struct S02091650 *p, u32 *a1)
{
    u32 d;
    u32 r;

    d = p->f24 - p->f1c;
    if (d != 0) {
        p->f28 = d;
        if (((p->f04 << 19) >> 31) == 0)
            func_02091594(p->f1c, &p->f28);
        r = ((Fn02091650)p->f40)(p->f00, p->f1c, &p->f28, p->f48);
        if (a1 != 0)
            *a1 = p->f28;
        if (r != 0)
            return r;
        p->f18 += p->f28;
    }
    func_0209159C((struct S0209159C *)p);
    return 0;
}

/*
 * A refcounted-resource wrapper: the 4-argument twin of
 * src/matched/func_02092004.c (which is the 3-argument one with a three-way
 * id dispatch).  The id here is the FOURTH argument and the dispatch is
 * two-way, `a3 == g_020A8730 ? 2 : 5`, which is what the image's
 * `mov r6,#2 / cmp r7,r4 / movne r6,#5` is.
 *
 * docs/notes/pkt_020916D4.c.txt records an earlier pass that got to 248
 * bytes against 256 and diagnosed the residue as a register tie on the
 * `mul` destination plus an unreachable CSE of the 0x02153B8C base.  Both
 * readings were wrong: the shortfall was an arm structure difference, not
 * an allocator tie.  The sibling's exact shape -- the `cur`/`ref` pair named
 * as two locals in the else arm, the two table stores written out in full in
 * BOTH the then arm and the inner else arm rather than factored, and
 * `g_02150FEC.unk04[0x1b]` re-read at each of its three use sites -- closes
 * it with no permuter run at all.  The `str r3,[r2,r6,lsl #2]` addressing-
 * mode store and the per-site pool reloads the note despaired of follow from
 * writing the arms out rather than from any register hint.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020916D4.c \
 *       --func func_020916D4 --addr 0x020916D4 --arm --cc 1.1p1
 */
s32 func_020916D4(void *a0, u32 a1, u32 a2, u32 a3)
{
    u32 idx = (a3 == (u32)g_020A8730) ? 2 : 5;
    u8 *blk = (u8 *)&g_02153BD4 + idx * 0x18;
    s32 r;

    if (func_020860D0(blk) == 0) {
        arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
        arr_02153BB0[idx] = 1;
    } else {
        u32 cur = arr_02153B8C[idx];
        u32 ref = g_02150FEC.unk04[0x1b];

        if (cur == ref) {
            arr_02153BB0[idx]++;
        } else {
            func_02086028(blk);
            arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
            arr_02153BB0[idx] = 1;
        }
    }
    r = func_020917D4((void *)a0, a1, a2, (struct FILE *)a3);
    arr_02153BB0[idx]--;
    if (arr_02153BB0[idx] == 0) func_02086078(blk);
    return r;
}

enum { __neutral, __writing, __reading, __rereading };

enum { __no_io_error, __io_error, __io_EOF };

extern int func_02096508(u8 *p, int v);                 /* fwide */
extern int  func_0209149C(void);                                 /* __flush_line_buffered_output_files */
extern int func_020915C4(struct S020915C4 *p, u32 *a1, int a2); /* __load_buffer */
extern void *func_02092344(void *dest, const void *src, unsigned int n); /* memcpy */
extern void func_0209159C(struct S0209159C *p);                           /* __prep_buffer */
extern u32  func_0209C2B0(u32 a, u32 b);                         /* udiv */

/*
 * MSL C `__fread` (buffered stdio read), transcribed from the Metrowerks MSL
 * shape: fwide orientation probe, pushback drain through ungetc_buffer /
 * ungetwc_buffer, buffered copy loop through __load_buffer (func_020915C4)
 * and memcpy (func_02092344), then the unbuffered direct read that borrows
 * buffer/buffer_size.  Returns bytes_read / memb_size (func_0209C2B0).
 * The two levers over the earlier 788/456 note body were (1) writing it as
 * MSL writes it (always_buffer = !binary_io || buffer_mode == _IOFBF, the
 * set_error / set_eof bodies spelled out in each arm) and (2) the FILE
 * layout: eof/error are plain u8 members at +0x0c/+0x0d, NOT inside an
 * 8-byte state struct, which puts ungetc_buffer at +0x12 and ungetwc_buffer
 * at +0x14.  Project default compiler; EXACT on the first full transcription.
 */
size_t func_020917D4(void *ptr, size_t memb_size, size_t num_memb, FILE *file)
{
    u8 *read_ptr;
    size_t num_bytes, bytes_requested, bytes_read;
    int ioresult, always_buffer;

    if (func_02096508((u8 *)file, 0) == 0)
        func_02096508((u8 *)file, -1);

    bytes_requested = memb_size * num_memb;

    if (!bytes_requested || file->error || file->mode.file_kind == 0)
        return 0;

    always_buffer = !file->mode.binary_io || file->mode.buffer_mode == 2;

    if (file->state.io_state == __neutral) {
        if (file->mode.io_mode & 1) {
            file->state.io_state = __reading;
            file->buffer_len = 0;
        }
    }

    if (file->state.io_state < __reading) {
        file->error = 1;
        file->buffer_len = 0;
        return 0;
    }

    if (file->mode.buffer_mode & 1) {
        if (func_0209149C()) {
            file->error = 1;
            file->buffer_len = 0;
            return 0;
        }
    }

    read_ptr = (u8 *)ptr;
    bytes_read = 0;

    if (bytes_requested && file->state.io_state >= __rereading) {
        do {
            if (func_02096508((u8 *)file, 0) == 1) {
                ((struct Obj16696 *)read_ptr)->f0 = file->ungetwc_buffer[file->state.io_state - __rereading];
                read_ptr += sizeof(wchar_t);
                bytes_read += sizeof(wchar_t);
                bytes_requested -= sizeof(wchar_t);
            } else {
                *read_ptr++ = file->ungetc_buffer[file->state.io_state - __rereading];
                bytes_read++;
                bytes_requested--;
            }
            file->state.io_state--;
        } while (bytes_requested && file->state.io_state >= __rereading);

        if (file->state.io_state == __reading)
            file->buffer_len = file->saved_buffer_len;
    }

    if (bytes_requested && (file->buffer_len || always_buffer)) {
        do {
            if (!file->buffer_len) {
                ioresult = func_020915C4((struct S020915C4 *)file, 0, 0);
                if (ioresult) {
                    if (ioresult == __io_error) {
                        file->error = 1;
                        file->buffer_len = 0;
                    } else {
                        file->state.io_state = __neutral;
                        file->eof = 1;
                        file->buffer_len = 0;
                    }
                    bytes_requested = 0;
                    break;
                }
            }

            num_bytes = file->buffer_len;
            if (num_bytes > bytes_requested)
                num_bytes = bytes_requested;

            func_02092344(read_ptr, file->buffer_ptr, num_bytes);

            read_ptr += num_bytes;
            bytes_read += num_bytes;
            bytes_requested -= num_bytes;

            file->buffer_ptr += num_bytes;
            file->buffer_len -= num_bytes;
        } while (bytes_requested && always_buffer);
    }

    if (bytes_requested && !always_buffer) {
        u8 *save_buffer = file->buffer;
        size_t save_size = file->buffer_size;

        file->buffer = read_ptr;
        file->buffer_size = bytes_requested;

        ioresult = func_020915C4((struct S020915C4 *)file, &num_bytes, 1);
        if (ioresult) {
            if (ioresult == __io_error) {
                file->error = 1;
                file->buffer_len = 0;
            } else {
                file->state.io_state = __neutral;
                file->eof = 1;
                file->buffer_len = 0;
            }
        }

        bytes_read += num_bytes;

        file->buffer = save_buffer;
        file->buffer_size = save_size;

        func_0209159C((struct S0209159C *)file);

        file->buffer_len = 0;
    }

    return func_0209C2B0(bytes_read, memb_size);
}

int func_02091AE8(u8 *p)
{
    u32 mode;
    int r;
    int x;

    if (p == 0)
        return -1;
    mode = (((struct Obj00481 *)p)->f4 << 22) >> 29;
    if (mode == 0)
        return 0;
    r = (int)func_02091B5C((struct P02091B5C *)p);
    x = ((int (*)(u32))*(u32 *)(p + 0x44))(((struct Obj00481 *)p)->f0);
    ((struct Obj00481 *)p)->f4 &= ~0x380u;
    ((struct Obj00481 *)p)->f0 = 0;
    if ((((struct Obj00481 *)p)->f8 << 28) >> 31)
        return -1;
    return (r != 0 || x != 0) ? -1 : 0;
}

/*
 * The state machine the g_020A8730 sweep calls per record (and the entry the
 * null argument routes to func_02091524).  A record is rejected when its +0xd
 * byte is set or when its +4 field at bits 7..9 is zero, is a no-op when the
 * +4 field at bits 2..4 is 1, otherwise its +8 three-bit mode is forced to 2
 * when it is 3 or more (clearing the low three bits first), the record is
 * cleared when that mode is 2, and anything but mode 1 clears the mode and
 * returns.  Mode 1 runs the transaction func_02091650, and either sets the
 * +0xd byte and returns -1 or clears mode, +0x18 and +0x28 and returns 0.
 *
 * Every one of the five field accesses is a bitfield read/write against a
 * view struct cast onto the word, and that is load-bearing: written as
 * `(p->f08 << 29) >> 29` the three-mode tests are re-derived as `and #7` and
 * the whole tail renumbers, while a bitfield extraction is emitted as the
 * shift pair directly and is never folded (this is the same finding as
 * src/matched/func_0209149C.c and func_02091524.c's neighbour).  The mode
 * writes come out as exactly `bic`/`orr` on the low three bits, which is what
 * a bitfield assignment emits, and the constant -1 the failure path returns is
 * derived by the compiler from the 1 it has just stored (`subne r0, r0, #2`).
 *
 * The `||` over the two rejection tests is what shares the `mvn r0, #0`
 * epilogue; two separate `if`s cost 20 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091B5C.c \
 *       --func func_02091B5C --addr 0x02091B5C --cc 1.1p1 --arm
 *   EXACT, 228 bytes, 2 relocation sites, both resolved.
 */
int func_02091B5C(struct P02091B5C *p)
{
    int r;

    if (p == 0)
        return func_02091524();
    if (p->f0d != 0 || ((struct F04hi *)&p->f04)->mode == 0)
        return -1;
    if (((struct F04lo *)&p->f04)->sub == 1)
        return 0;
    if (((struct F08 *)&p->f08)->mode >= 3)
        ((struct F08 *)&p->f08)->mode = 2;
    if (((struct F08 *)&p->f08)->mode == 2)
        p->f28 = 0;
    if (((struct F08 *)&p->f08)->mode != 1) {
        ((struct F08 *)&p->f08)->mode = 0;
        return 0;
    }
    r = func_02091650((struct S02091650 *)p, 0);
    if (r != 0) {
        p->f0d = 1;
        p->f28 = 0;
        return -1;
    }
    ((struct F08 *)&p->f08)->mode = 0;
    p->f18 = 0;
    p->f28 = 0;
    return 0;
}

/*
 * Bounded case-insensitive string compare (the `strncmp` twin of
 * src/matched/func_0209AB8C.c, which is the unbounded `strcmp`): each byte is
 * mapped through the 256-byte table at 0x020A60DC when it is below 0x80, then
 * compared as unsigned, for at most n bytes.
 *
 * Three spellings are load-bearing, and docs/notes/pkt_02091C40.c.txt records
 * a whole earlier pass that got the first two but not the third:
 *
 *  - the guard is `if (n > 0) { <loop> } return 0;`, not `if (n <= 0)
 *    return 0;`.  The early-return spelling predicates the guard
 *    (`movle r0,#0` / `pople`) and is 128 bytes; the block spelling branches
 *    to the single shared epilogue the image has at 0x02091CB0.
 *  - the two byte temps are the interleaved `int c1; u8 m1; int c2; u8 m2;`
 *    of the sibling, which is what colours the masked c1 into r4 and the raw
 *    c2 into r5.  Declaring the two masks together swaps those registers.
 *    Writing the masks as `c1 &= 0xff` on the `int`s instead (the earlier
 *    pass's spelling) leaves the same 26-byte register swap that note
 *    describes: lr/ip carry the loop counter and the table there, r4/ip here.
 *  - THE TABLE BASE IS ASSIGNED INSIDE THE GUARD.  `const u8 *tab =
 *    g_020A60DC;` at the top of the function hoists its pool load above the
 *    `ble`, which is the last 12-byte residue: the image emits
 *    `mov lr,#0 / ble / ldr ip,[pc,#0x60]`, i.e. the table is not loaded at
 *    all on the n <= 0 path.  Declaring it at the top and assigning it in
 *    the block reproduces that order exactly.
 *
 * Also measured by the earlier pass, and still true: mwccarm 1.1p1 in
 * `-lang c99` mode REJECTS a C99 for-statement declaration
 * (`for (int i = 0; ...)` -> "expression syntax error"), so the counter is
 * declared at block scope.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091C40.c \
 *       --func func_02091C40 --addr 0x02091C40 --arm --cc 1.1p1
 */
int func_02091C40(const u8 *s1, const u8 *s2, int n)
{
    const u8 *tab;
    int i = 0;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    if (n > 0)
    {
        tab = g_020A60DC;
        do
        {
            c1 = *s1++;
            if (c1 >= 0 && c1 < 0x80)
                c1 = tab[c1];
            m1 = (u8)c1;

            c2 = *s2++;
            if (c2 >= 0 && c2 < 0x80)
                c2 = tab[c2];
            m2 = (u8)c2;

            if (m1 < m2)
                return -1;
            if (m1 > m2)
                return 1;
            if (m1 == 0)
                return 0;
            i++;
        } while (i < n);
    }
    return 0;
}

/*
 * Reads back the amount a record still owes: reject the record when its +4
 * bits 7..9 mode is neither 0 nor 1 or when its +0xd byte is set (leaving
 * 0x28 in the reserved word and returning -1), return the running f18 when
 * the +8 three-bit mode is 0, otherwise f34 + (f24 - f1c), reduced by
 * (mode - 2) for modes of 3 or more.
 *
 * Two spellings are pinned here and neither is the obvious one:
 *
 *  - `u8 sel = mode + 0xff;` is the decrement.  `mode - 1` compiles to
 *    `sub r1, r1, #1`; the original has `and #0xff; add r1, r1, #0xff;
 *    and #0xff`, i.e. the wrap-around add the source wrote, narrow once on
 *    being stored into the `u8 mode` and once on the sum
 *    (docs/idioms/a-u8-decrement-is-spelled-as-the-wraparound-add.md).
 *  - the +8 mode is read through a bitfield view struct.  A shift-pair
 *    spelling that feeds a `== 0` test is folded to `ands`, which loses both
 *    the second `lsr` and the register the original keeps.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091CBC.c \
 *       --func func_02091CBC --addr 0x02091CBC --cc 1.1p1 --arm
 *   EXACT, 124 bytes, 1 relocation site, resolved.
 */
int func_02091CBC(struct P02091CBC *p)
{
    struct F08P *m08 = (struct F08P *)&p->f08;
    u8 mode;
    u8 sel;
    u32 m;
    u32 v;

    mode = ((struct F04hiP *)&p->f04)->mode;
    sel = mode + 0xff;
    if (sel > 1 || p->f0d != 0) {
        g_02153FAC = 0x28;
        return -1;
    }
    m = m08->mode;
    if (m == 0)
        return p->f18;
    v = p->f34 + (p->f24 - p->f1c);
    if (m >= 3)
        v -= m - 2;
    return v;
}
