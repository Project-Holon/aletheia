/*
 * file:     wipe_sub_p04.c
 * unit:     yes
 * function: func_02022174, func_020221A4, func_020221B8, func_02022224, func_02022230, func_0202223C, func_02022268, func_020222A8, func_020222CC
 * address:  0x02022174
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
 *   func_02022340  0x02022340  thumb
 *   func_020222EC  0x020222EC  thumb
 *   func_020224DC  0x020224DC  thumb
 *   func_02022390  0x02022390  thumb
 *   func_020226A0  0x020226A0  thumb
 *   func_02023B48  0x02023B48  thumb
 *   g_021468E4     0x021468E4  data
 *   func_0207E3D0  0x0207E3D0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_0207D534  0x0207D534  arm
 */
struct Cluster;
struct Slots;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub {
    u8  pad00[0x0C];
    u32 f0C;
    u8  pad10[0x20];
};

struct G_02022174 {
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
};

struct G_020221A4 {
    u8  pad00[0x14C];
    u16 f14C;
};

struct G_020221B8 {
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
};

struct G {
    u8  pad[0x10];
    u16 f10;
};

extern u32 func_02022340(struct Cluster *p, void *top, void *bottom);
extern void func_020222EC(struct G_02022174 *g);
extern void func_020224DC(struct Slots *p, u32 idx);
extern void func_02022390(u32 *obj, void *arg);
extern void func_020226A0(u8 *p);
extern u32 func_02023B48(u32 kind, void *win);
extern void func_0207E3D0(u32 *p, u32 b, u32 c);
extern void func_0207E468(u32 *p, u32 b, u32 c);
extern void func_0207D534(volatile u16 *reg, int brightness);
void func_02022174(void);
u32 func_020221A4(void);
void func_020221B8(void);
u32 func_02022224(void *win);
void func_02022230(u32 which);
void func_0202223C(u32 a, u32 color);
void func_02022268(u32 color);
void func_020222A8(u32 a);
void func_020222CC(u32 which, int brightness);
extern struct G_02022174 g_021467A4;
extern struct G g_021468E4;



/*
 * Per-frame poll for the dual-screen text cluster at 0x021467A4: while the
 * cluster is live (the u16 at +0x14C non-zero) it steps both sub-objects and,
 * when the stepper reports 1, runs the completion handler on the cluster.
 *
 * The +0x14C read costs its own pool word because 0x14C is far past the
 * ldrh immediate reach; it is g_021467A4 + 0x140 with a +0xC displacement,
 * one symbol and not a second object, see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The follower at 0x020221A4 is a separate leaf function with fan-in 111 and
 * is deliberately NOT folded into a unit here; it keeps its own entry, see
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.  EXACT* is the
 * inferred extent running into that follower, not a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022174.c \
 *       --func func_02022174 --addr 0x02022174 --cc 1.1p1 --thumb
 */
void func_02022174(void)
{
    struct G_02022174 *g;

    g = &g_021467A4;
    if (g_021467A4.f14C != 0) {
        if (func_02022340((struct Cluster *)g, &g->f14, &g->f44) == 1)
            func_020222EC(g);
    }
}



/*
 * "Is the dual-screen text cluster idle?", the image's most-called predicate
 * on this object (fan-in 111, mostly from overlay script code): it reports 1
 * when the live counter at +0x14C is zero.  It is a leaf that saves no lr, so
 * disasm.py never labels it and it prints as an anonymous run between two
 * literal pools; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * It deliberately does not share a file with func_02022174 above it: a unit
 * records only its start address, and this address has 111 call sites that
 * need a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221A4.c \
 *       --func func_020221A4 --addr 0x020221A4 --cc 1.1p1 --thumb
 */
u32 func_020221A4(void)
{
    if (g_021467A4.f14C == 0)
        return 1;
    return 0;
}



/*
 * Shutdown of the dual-screen text cluster, the counterpart of func_0202208C.
 * It drops both entries of the callback block at +0x74, forces each live screen
 * into state 2, unpublishes both sub-objects through the same func_02022390
 * slot writer the setup used, clears the live counter and the two delegate
 * flags at +0x14C/+0x14E/+0x14F, and releases the object.
 *
 * Every pool word here is g_021467A4 with a different displacement (+0x74,
 * +0x00, +0x04, +0x14, +0x08, +0x44, +0x140), one symbol and not seven
 * objects; see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221B8.c \
 *       --func func_020221B8 --addr 0x020221B8 --cc 1.1p1 --thumb
 */
void func_020221B8(void)
{
    func_020224DC((struct Slots *)g_021467A4.f74, 0);
    func_020224DC((struct Slots *)g_021467A4.f74, 1);
    if (g_021467A4.f04 != 0)
        g_021467A4.f14.f0C = 2;
    if (g_021467A4.f08 != 0)
        g_021467A4.f44.f0C = 2;
    func_02022390((u32 *)(&g_021467A4.f04), &g_021467A4.f14);
    func_02022390((u32 *)(&g_021467A4.f08), &g_021467A4.f44);
    g_021467A4.f14C = 0;
    g_021467A4.f14E = 0;
    g_021467A4.f14F = 0;
    func_020226A0((u8 *)(&g_021467A4));
}



/*
 * A two-instruction forwarder (fan-in 22) that pins the first argument of
 * func_02023B48 to zero and passes the caller's window pointer through as the
 * second.  Tail calls in this compiler are always a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section;
 * see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * EXACT* is the extent walk running into the second forwarder at 0x02022230,
 * which is an unlabelled leaf with its own callers and keeps its own file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022224.c \
 *       --func func_02022224 --addr 0x02022224 --cc 1.1p1 --thumb
 */
u32 func_02022224(void *win)
{
    return func_02023B48(0, win);
}



/*
 * The companion forwarder to func_02022224: it passes the caller's engine
 * selector straight through to func_020222CC and supplies the unused second
 * argument as zero.  Same pool-word-and-`bx` tail call shape.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022230.c \
 *       --func func_02022230 --addr 0x02022230 --cc 1.1p1 --thumb
 */
void func_02022230(u32 which)
{
    func_020222CC(which, 0);
}



/*
 * Maps two sentinel colour values (0xFFFF, "read back the last value
 * written"; 0x7FFF, "white") to two hardware-register-friendly constants
 * and forwards to func_020222CC, which selects one of two hardware
 * addresses from its first argument and ignores the colour entirely
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md; func_020222CC's own file spells this out).
 *
 * The sentinel readback is `g_021468E4.f10`, a halfword sixteen bytes into
 * a fixed object.  Writing it as `*(u16 *)(0x021468E4 + 0x10)` folds the
 * base and the offset into a single pool word (a plain integer constant
 * has no reason not to), which does not reproduce the original's separate
 * `ldr r1, [pc]; ldrh r1, [r1, #0x10]`.  Declaring the object as an extern
 * struct and taking a real relocation on its base keeps the offset in the
 * instruction encoding instead, matching
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-
 * the-load-reach.md.  The base address is attested by ten other literal
 * pools in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202223C.c \
 *       --func func_0202223C --addr 0x0202223C --cc 1.1p1 --thumb
 */
void func_0202223C(u32 a, u32 color)
{
    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        color = 0x10;
    } else {
        color = ~(u32)0xF;
    }
    func_020222CC(a, color);
}



/*
 * Same sentinel-mapping shape as func_0202223C.c, but read-modify-write:
 * it substitutes the sentinel readback the same way, maps the result to
 * one of the same two hardware constants, forwards it to both of
 * func_020222CC's hardware selections (0 and 1), and then stores the
 * *pre-mapping* colour back into the same halfword field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022268.c \
 *       --func func_02022268 --addr 0x02022268 --cc 1.1p1 --thumb
 */
void func_02022268(u32 color)
{
    u32 mapped;

    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        mapped = 0x10;
    } else {
        mapped = ~(u32)0xF;
    }
    func_020222CC(0, mapped);
    func_020222CC(1, mapped);
    g_021468E4.f10 = color;
}



void func_020222A8(u32 a)
{
    u32 *p = &a;

    func_0207E3D0(p, 0, 2);
    func_0207E468(p, 0, 2);
}



/*
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the master brightness registers of the two DS display engines) from its
 * first argument and passes it to func_0207D534 together with the second
 * argument, the brightness level, which stays in r1 untouched (an argument
 * passed through a register must be named in the C).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222CC.c \
 *       --func func_020222CC --addr 0x020222CC --cc 1.1p1 --thumb
 */
void func_020222CC(u32 which, int brightness)
{
    if (which == 0) {
        func_0207D534((volatile u16 *)0x0400006C, brightness);
    } else {
        func_0207D534((volatile u16 *)0x0400106C, brightness);
    }
}
