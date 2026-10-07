/*
 * file:     wipe_sub_p05.c
 * unit:     yes
 * function: func_020222EC, func_02022340, func_02022390, func_020223AC, func_020223C0, func_02022424, func_02022430, func_02022458, func_02022478, func_02022490
 * address:  0x020222EC
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
 *   g_021467A4     0x021467A4  data
 *   func_02022608  0x02022608  thumb
 *   func_02022670  0x02022670  thumb
 *   func_020226A0  0x020226A0  thumb
 *   g_0209F538  0x0209F538  data
 *   func_020225F0  0x020225F0  thumb
 *   g_021468A4     0x021468A4  data
 *   func_02005624  0x02005624  thumb
 */
#include "../../matched/include/Obj16741.h"
#include "../../matched/include/Obj11272.h"

struct Obj;
struct Screen;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub {
    u8    pad00[0x28];
    void *f28;
    u8    pad2C[4];
};

struct G {
    u8          pad00[4];
    void       *f04;
    void       *f08;
    void       *f0C;
    void       *f10;
    struct Sub  f14;
    struct Sub  f44;
    u8          f74[0x18];
    u8          f8C[0xC0];
    u16         f14C;
    u8          f14E;
    u8          f14F;
    u16         f150;
};

struct Cluster {
    u32    mode;
    void  *top;
    void  *bottom;
};

typedef u32 (*FuncPtr)(void *);

struct Mode {
    u32 kind;
    u32 a;
    u32 b;
    u32 a2;
    u32 b2;
};

typedef signed int     s32;

struct Screen {
    u32   f00;
    u32   f04;
    s32   f08;
    u32   f0C;
    u32   f10;
    u32   f14;
    void *f18;
    void *f1C;
    u32   f20;
    u16   f24;
};

typedef void (*Handler)(void);

struct Slots {
    void   *ctx[2];
    Handler fn[2];
    u32     arg[2];
};

extern u16 func_02022608(struct Obj *p);
extern void func_02022670(struct Screen *s);
extern void func_020226A0(u8 *p);
void func_02022390(u32 *obj, void *arg);
u32 func_020223AC(void *p);
extern void func_020225F0(void);
extern void *func_02005624(u32 a, u32 b, u32 c);
void func_02022478(int a0, int *p);
void func_02022490(char *p, int a1, int a2, int a3);
extern struct G g_021467A4;
extern FuncPtr g_0209F538[];
extern char g_021468A4[];



/*
 * Teardown for the dual-screen text cluster, run by func_02022174 once both
 * screen slots have gone null.  It clears the live flag at +0x14C, latches the
 * value func_02022608 returns into the sentinel colour slot at +0x150, and for
 * each of the two delegates at +0x0C and +0x10 runs the per-screen finaliser
 * func_02022670 on the matching sub-object.
 *
 * Two notes on the original's shape.  Both delegate arms retest the *same*
 * field, +0x3C, which is the top sub-object's task handle at 0x14 + 0x28; the
 * bottom arm does not use its own +0x6C.  That is the image's behaviour, not a
 * transcription slip, and it is reproduced literally.  Both flag writes also go
 * through the global rather than the incoming pointer, which the encoding
 * distinguishes: the pointer form would reuse r5, the global form spends a
 * pool word at 0x0202233C.
 *
 * 0x14C and 0x150 are both past the strh immediate reach, so the first is
 * materialised as 0x53 << 2 into a register offset and the second derived from
 * it with a single `adds r1, r4, #4`; see
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md for the
 * same derivation on line-number arguments.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222EC.c \
 *       --func func_020222EC --addr 0x020222EC --cc 1.1p1 --thumb
 */
void func_020222EC(struct G *p)
{
    p->f14C = 0;
    p->f150 = func_02022608((struct Obj *)p);
    if (p->f0C != 0) {
        func_02022670((struct Screen *)(&p->f14));
        if (p->f14.f28 == 0)
            g_021467A4.f14E = 0;
    }
    if (p->f10 != 0) {
        func_02022670((struct Screen *)(&p->f44));
        if (p->f14.f28 == 0)
            g_021467A4.f14F = 0;
    }
    func_020226A0((u8 *)p);
}


/*
 * One poll step of the dual-screen cluster.  The mode word at +0x00 (the one
 * func_020223C0 wrote) selects which of the two screen slots gets pumped:
 * mode 0 pumps both, mode 1 prefers the top slot and falls back to the bottom
 * one, mode 2 the mirror of that.  It reports 1 only once both slots have gone
 * null, which is what func_02022174 tests before running the teardown.
 *
 * Three cases starting at zero still compile to a cmp chain, not a halfword
 * table: the table form only wins from four cases up.  The two pump calls are
 * written once per arm and cross-jumped by the compiler into the two shared
 * blocks at 0x0202235C and 0x02022376; factoring them behind a label instead
 * moves the branch targets.  See
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * The tail has to be written as the positive `if (both null) return 1; return
 * 0;`.  The equivalent `if (top || bottom) return 0; return 1;` inverts the
 * second branch and swaps the two constant returns, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022340.c \
 *       --func func_02022340 --addr 0x02022340 --cc 1.1p1 --thumb
 */
u32 func_02022340(struct Cluster *p, void *top, void *bottom)
{
    switch (p->mode) {
    case 0:
        func_02022390((u32 *)(&p->top), top);
        func_02022390((u32 *)(&p->bottom), bottom);
        break;
    case 1:
        if (p->top != 0)
            func_02022390((u32 *)(&p->top), top);
        else
            func_02022390((u32 *)(&p->bottom), bottom);
        break;
    case 2:
        if (p->bottom != 0)
            func_02022390((u32 *)(&p->bottom), bottom);
        else
            func_02022390((u32 *)(&p->top), top);
        break;
    }
    if (p->top == 0 && p->bottom == 0)
        return 1;
    return 0;
}


void func_02022390(u32 *obj, void *arg)
{
    if (*obj != 0) {
        if (func_020223AC(arg) == 1) {
            *obj = 0;
        }
    }
}


u32 func_020223AC(void *p)
{
    u32 idx = ((struct Obj16741 *)p)->f0;
    return g_0209F538[idx](p);
}


static void sub_02022424(struct Mode *p, u32 kind, u32 a, u32 b);



/*
 * Mode decoder for the dual-screen text cluster: a five-case dense switch on
 * the mode index that fills the five leading words of the object with one of
 * five fixed (kind, flagA, flagB) triples.  The writer at 0x02022424 is an
 * unlabelled leaf static in the same translation unit (no lr save, so
 * disasm.py never labels it); it stores the triple twice, once at +0x00/+0x04/
 * +0x08 and once more at +0x0C/+0x10, which is what makes the two later
 * readers see the same pair of values from either half.  It carries its
 * address as its name, and is listed in `function:` above, so the manifest
 * records the address it covers: coverage is counted per address named by an
 * entry, and a range covered only by a unit names nothing on its own.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020223C0.c \
 *       --addr 0x020223C0 --thumb
 */
void func_020223C0(u32 mode, struct Mode *p)
{
    switch (mode) {
    case 0:
        sub_02022424(p, 0, 1, 1);
        break;
    case 1:
        sub_02022424(p, 1, 1, 1);
        break;
    case 2:
        sub_02022424(p, 2, 1, 1);
        break;
    case 3:
        sub_02022424(p, 1, 1, 0);
        break;
    case 4:
        sub_02022424(p, 2, 0, 1);
        break;
    }
}

static void sub_02022424(struct Mode *p, u32 kind, u32 a, u32 b)
{
    p->kind = kind;
    p->a = a;
    p->b = b;
    p->a2 = a;
    p->b2 = b;
}


/*
 * The eleven-argument screen descriptor builder func_0202208C runs twice, once
 * per screen: a pure field-by-field copy of the argument list into the 0x26
 * byte sub-object, with no validation at all.  The four register arguments
 * land at +0x00..+0x0C and the seven stacked ones at +0x10..+0x24.
 *
 * Two shape facts the encoding pins down.  The sixth and seventh arguments are
 * stored the other way round from the argument order, +0x14 before +0x10, so
 * the struct's own field order is not the parameter order; writing them in
 * parameter order and letting the scheduler interleave is what reproduces the
 * ldr/str pairing.  The last argument is a u16, not a pointer: it is read back
 * with `add r1, sp, #0` + `ldrh r1, [r1, #0x18]` because Thumb has no
 * halfword load with an sp base, and stored with `strh`.  That is the value
 * func_020225F4 resolved, so the sentinel slot at +0x150 is a u16 end to end.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022430.c \
 *       --func func_02022430 --addr 0x02022430 --cc 1.1p1 --thumb
 */
void func_02022430(struct Screen *s, u32 a, u32 b, s32 c, u32 d, u32 e,
                   u32 f, void *g, void *h, u32 i, u16 j)
{
    s->f00 = a;
    s->f04 = b;
    s->f08 = c;
    s->f0C = d;
    s->f14 = e;
    s->f10 = f;
    s->f18 = g;
    s->f1C = h;
    s->f20 = i;
    s->f24 = j;
}



/*
 * Resets the 24-byte two-entry callback block at +0x74 of the dual-screen
 * text object (the buffer func_0202208C hands to both screen builders):
 * three parallel two-element arrays, the context pointers at +0x00, the
 * handlers at +0x08 and the user words at +0x10.  Both handler slots are
 * armed with the do-nothing func_020225F0 rather than a null, so the
 * dispatcher never has to test them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022458.c \
 *       --func func_02022458 --addr 0x02022458 --cc 1.1p1 --thumb
 */
void func_02022458(struct Slots *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        p->ctx[i] = 0;
        p->fn[i] = func_020225F0;
        p->arg[i] = 0;
    }
}

void func_02022478(int a0, int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        ((void (*)(int))p[i + 2])(p[i]);
}


/*
 * Arms one entry of the two-slot callback block at +0x74 of the dual-screen
 * text cluster: the exact inverse of func_020224DC.  It publishes the
 * context pointer at ctx[idx], the handler at fn[idx] (falling back to the
 * do-nothing func_020225F0 when the caller passes none, the same convention
 * func_02022458 uses), and marks the slot live with arg[idx] = 1.  Before
 * any of that, if BOTH user words are still zero the block was idle, so it
 * registers the dispatcher func_02022478 as a task through func_02005624 and
 * parks the handle at g_021468A4 +0x54 -- the same handle func_020224DC
 * releases once both words go back to zero.
 *
 * CLOSED 2026-09-21 by tools/permuter.py after this address had resisted
 * four hand passes (docs/notes/pkt_02022490.c.txt, four appended sections,
 * ~70 spellings measured plus a negative ../2.0/sp2 probe).  All of those
 * passes reached 76 bytes with 16 concrete out and diagnosed the residue
 * correctly as a three-way register rotation over +0x24..+0x3E: the image
 * keeps the scaled index in r2 and recomputes the slot base into r0 before
 * each offset store, the compile puts the index in r0 and the base in r1
 * (`--explain` prints it as r2->r0 x3, r1->r0 x3, r0->r1 x2).  The lever is
 * `temp(tmp = (char *)p)`, found by the hill search at compile 160 of 800:
 *
 *   a SECOND `char *` alias of the base pointer, declared AFTER the first
 *   store and used in exactly ONE of the two arms.
 *
 * That is why every uniform spelling failed.  The alias is a fresh value
 * with its own definition point and a use count of one, so Chaitin numbering
 * gives it a colour of its own and pushes the index and the base into the
 * image's registers; making it live in both arms, or hoisting its
 * declaration above the `i4` assignment, coalesces it straight back into `p`
 * and restores the 16-byte residue.  The `(char *)` re-cast on the other two
 * stores, which the note's last section identified as load-bearing, remains
 * load-bearing: dropping it costs four bytes.
 *
 * The mid-block declaration needs `-lang c99`, which this file's `lang:`
 * header field supplies.  Note that `match.py one` does NOT read that field
 * and defaults to no `-lang` at all, so re-verifying this file by hand needs
 * `--lang c99` on the command line or it reports CCERR; the manifest path
 * reads the header and is unaffected.
 *
 * Data flow checked against both neighbours: func_020224DC clears arg[idx]
 * first and only then tests both words, this function tests both words first
 * and only then writes, so the handle is created exactly once per
 * idle-to-live transition and released exactly once per live-to-idle one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022490.c \
 *       --func func_02022490 --addr 0x02022490 --cc 1.1p1 --thumb --lang c99
 */
void func_02022490(char *p, int a1, int a2, int a3)
{
    int i4;

    if (((struct Obj11272 *)p)->f10 == 0 && ((struct Obj11272 *)p)->f14 == 0)
        *(u32 *)(g_021468A4 + 0x54) =
            (u32)func_02005624((int)func_02022478, (u32)p, 0);

    i4 = a3 * 4;
    *(u32 *)(p + i4) = a1;

    char *q = (char *)p;

    if (a2 != 0)
        ((u32 *)(q + i4))[2] = a2;
    else
        ((u32 *)((char *)p + i4))[2] = (u32)func_020225F0;
    ((u32 *)((char *)p + i4))[4] = 1;
}
