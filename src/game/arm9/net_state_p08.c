/*
 * file:     net_state_p08.c
 * unit:     yes
 * function: func_0203D17C, func_0203D1A4, func_0203D1B4, func_0203D1C0, func_0203D1E8, func_0203D210, func_0203D24C, func_0203D26C, func_0203D29C, func_0203D2CC, func_0203D34C, func_0203D378, func_0203D394, func_0203D3A8, func_0203D3F8, func_0203D4D0, func_0203D56C, func_0203D578
 * address:  0x0203D17C
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
 *   func_0203D788  0x0203D788  arm
 *   func_020395EC  0x020395EC  arm
 *   func_020399EC  0x020399EC  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020399B8  0x020399B8  arm
 *   g_021469E0     0x021469E0  data
 *   func_0203D798  0x0203D798  arm
 *   g_020A7CA0     0x020A7CA0  data
 *   g_020A7CE8     0x020A7CE8  data
 *   func_020338F8  0x020338F8  arm
 *   func_02034714  0x02034714  arm
 *   func_02037010  0x02037010  arm
 *   func_020370C8  0x020370C8  arm
 *   func_02037118  0x02037118  arm
 *   func_02039338  0x02039338  arm
 *   func_02038C18  0x02038C18  arm
 *   g_020A7CEC     0x020A7CEC  data
 *   func_02039468  0x02039468  arm
 *   func_020394C0  0x020394C0  arm
 */
struct NetCtx;
struct Entry;
struct Link;
struct NetEntry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

struct Entry {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
    u8    pad_42[2];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
    u8    pad_4b[5];
};

struct NetVtbl {
    void (*f00)(u32 a, u32 b);
    void (*f04)(u16 key, struct NetCtx *ctx, u32 zero, u32 arg);
    void (*f08)(u32 a);
    int  (*f0C)(u32 a);
    u32  (*f10)(u32 a, u32 b);
    u32  (*f14)(u32 a);
    u8   pad18[0x28 - 0x18];
    u32  (*f28)(u32 a);
    void *(*f2C)(u32 a);
    u8   pad30[0x38 - 0x30];
    u32  (*f38)(u32 a);
    void (*f3C)(void *cb);
    u32  (*f40)(u32 a, u32 b);
    u32  (*f44)(u32 a, u32 b);
    u32  (*f48)(u32 a, u32 b, u32 c, u32 d, u32 e);
    u8   pad4C[4];
    u32  (*f50)(int a, u32 b, u32 c);
    u32  (*f54)(u32 a, u32 b);
    u32  (*f58)(void);
    u32  (*f5C)(u32 a);
    u32  (*f60)(u32 a);
    u32  (*f64)(u32 a, u32 b, u32 c, void *d);
    void (*f68)(void *cb);
    u32  (*f6C)(void);
    int  (*f70)(void);
    u32  (*f74)(void);
    u32  (*f78)(void);
    u32  (*f7C)(void);
    int  (*f80)(void);
    u32  (*f84)(void);
    int  (*f88)(void);
    void (*f8C)(u32 a);
    u32  (*f90)(u32 a);
    u8   pad94[0x9C - 0x94];
    void (*f9C)(void);
    u32  (*fA0)(void);
    u32  (*fA4)(void);
    u32  (*fA8)(void);
    u32  (*fAC)(void);
    int  (*fB0)(void);
    void (*fB4)(void);
    void (*fB8)(void *arg);
    int  (*fBC)(void);
    void (*fC0)(int a);
    void (*fC4)(u32 a);
    void (*fC8)(u32 a);
};

struct NetCtx {
    u8   pad00[0x08];
    void (*f08)(u32 a, u32 b);
    void (*f0C)(int a, u32 b);
    u32  (*f10)(u32 a);
    u32  (*f14)(u32 a);
    u8   pad18[0x1C - 0x18];
    void (*f1C)(void);
    u8   pad20[0x24 - 0x20];
    void (*f24)(u32 a, u32 b, u32 c);
    void (*f28)(u32 a, u32 b, u32 c);
    void (*f2C)(u32 a);
    void (*f30)(u32 a);
    u8   pad34[0x40 - 0x34];
    u32  (*f40)(u32 a);
    u32  (*f44)(u32 a);
    u8   pad48[0x56 - 0x48];
    u16  f56;
    u16  f58;
    u16  f5A;
    u16  f5C;
    u16  f5E;
    u8   f60;
    u8   f61;
    u8   pad62[2];
    u8   f64;
    u8   f65;
    u8   f66;
    u8   f67;
    u8   pad68[4];
    u16  f6C;
    u16  f6E;
    struct Entry table[9];
    struct NetVtbl *vt;
    u32  f344;
    void (*f348)(u32 a);
    u32  f34C;
    u8   pad350[2];
    u8   f352;
};

typedef void (*Fn)(u32);

typedef signed int     s32;

typedef unsigned char u32_pad;

struct Singleton {
    u8    pad_00[8];
    void *unk_08;
};

typedef signed char s8;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetEntry {
    u8 pad_00[0x4a];
    u8 state;
};

extern struct NetCtx *func_0203D788(void);
extern int func_020395EC(struct Entry *a);
extern int func_020399EC(void);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_020399B8(u8 *p);
extern struct NetCtx *func_0203D798(void);
extern u32  func_020338F8(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern void func_02037010(u32 a, u32 b, u32 c, u32 d);
extern void func_020370C8(void);
extern void func_02037118(u32 a, u32 b);
extern u16 func_02039338(void);
extern int   func_02038C18(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32   func_02039468(u32 a, u32 b);
extern int func_020394C0(void);
void func_0203D17C(u32 a);
u32 func_0203D1A4(struct Link *p);
int func_0203D1B4(void);
u32 func_0203D1C0(u32 index);
void func_0203D1E8(u32 unused, void *arg);
u32 func_0203D210(void);
void func_0203D24C(u16 a, u16 b);
u32 func_0203D26C(void);
u32 func_0203D29C(void);
void func_0203D2CC(void);
void func_0203D34C(u32 a, u32 b);
u32 func_0203D378(void);
u32 func_0203D394(struct NetEntry *e);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_0203D56C(void);
void func_0203D578(int a, u32 b);
extern struct Singleton g_021469E0;
extern char g_020A7CA0[];
extern char g_020A7CE8[];
extern char g_020A7CEC[];





/*
 * Vtable dispatch with the *vtable pointer* null-checked (the state object
 * itself is not): the entry at +0xC4 takes the argument, and the hook's value
 * is dropped.  Two loads separate the two tests, which is what makes this
 * shape distinct from src/matched/func_0203CF10.c and
 * src/matched/func_0203CF3C.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D17C.c \
 *       --func func_0203D17C --addr 0x0203D17C --cc 1.1p1 --arm
 */
void func_0203D17C(u32 a)
{
    struct NetCtx *p;
    struct NetVtbl *vt;

    p = func_0203D788();
    vt = p->vt;
    if (vt == 0)
        return;
    vt->fC4(a);
}





/*
 * Forward to func_020395EC and mask the result to a byte.  func_020395EC is
 * called from func_0203D578 (outside this range), which is what attests the
 * `bl` here as a real function rather than a wildcarded relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1A4.c \
 *       --func func_0203D1A4 --addr 0x0203D1A4 --cc 1.1p1 --arm
 */
u32 func_0203D1A4(struct Link *p)
{
    return func_020395EC((struct Entry *)p) & 0xff;
}




int func_0203D1B4(void)
{
    return func_020399EC();
}




/*
 * TU: net.c (named by the assert site at 0x0203D2EC, which passes the
 * string at 0x020A7CA0, "net.c").
 *
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with func_0203996C and ask func_020399B8 about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1C0.c \
 *       --func func_0203D1C0 --addr 0x0203D1C0 --cc 1.1p1 --arm
 */
u32 func_0203D1C0(u32 index)
{
    if (func_0203D788() == 0) {
        return 0;
    }
    return func_020399B8((u8 *)func_0203996C(index));
}



void func_0203D1E8(u32 unused, void *arg)
{
    void (*fn)(void *) = func_0203D788()->vt->fB8;

    if (fn == 0) {
        return;
    }
    fn(arg);
}



/*
 * TU: net.c.
 *
 * "Nothing running, or the +0x6c hook says idle".  The first test reads
 * g_021469E0.unk_08 straight out of the singleton (the same two
 * instructions func_0203D788 is made of), while the second goes through the
 * real call; that asymmetry is what says the first read is a file-local
 * access and not an inlined copy of the extern.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D210.c \
 *       --func func_0203D210 --addr 0x0203D210 --cc 1.1p1 --arm
 */
u32 func_0203D210(void)
{
    if (g_021469E0.unk_08 == 0) {
        return 1;
    }
    return func_0203D788()->vt->f6C() == 0;
}





/*
 * TU: net.c.
 *
 * Store a halfword pair into +0x5c/+0x5e of the network state block, if it
 * exists.  Both stores are predicated off the one null test, which is why
 * the two parameters have to survive the accessor call in r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D24C.c \
 *       --func func_0203D24C --addr 0x0203D24C --cc 1.1p1 --arm
 */
void func_0203D24C(u16 a, u16 b)
{
    struct NetCtx *s = func_0203D798();

    if (s != 0) {
        s->f5C = a;
        s->f5E = b;
    }
}





/*
 * TU: net.c.
 *
 * "State is 3 or 4" predicate on the +0x65 mode byte of the network
 * singleton.  The range test is written as one unsigned compare on the
 * biased byte, so the original spells `- 3` as `add r0, r0, #0xfd` with the
 * `and r0, r0, #0xff` that the u8 cast forces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D26C.c \
 *       --func func_0203D26C --addr 0x0203D26C --cc 1.1p1 --arm
 */
u32 func_0203D26C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->f65 + 0xfd) <= 1) {
            return 1;
        }
    }
    return 0;
}





/*
 * TU: net.c.
 *
 * Sibling of func_0203D26C one range lower: "state is 1 or 2" on the +0x65
 * mode byte.  Same shape, `add r0, r0, #0xff` for the bias instead of
 * `#0xfd`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D29C.c \
 *       --func func_0203D29C --addr 0x0203D29C --cc 1.1p1 --arm
 */
u32 func_0203D29C(void)
{
    struct NetCtx *s = func_0203D788();

    if (s != 0) {
        if ((u8)(s->f65 + 0xff) <= 1) {
            return 1;
        }
    }
    return 0;
}





/*
 * TU: net.c.  This is the function that names it: the assert call at
 * 0x0203D2EC passes the string at 0x020A7CA0, which reads "net.c", with
 * line 0x364 (868) and the message string "0" at 0x020A7CE8.
 *
 * Refresh of the on-screen connection indicator.  Both accessors are
 * called even though they return the same singleton field (func_0203D798
 * null-checks it, func_0203D788 does not); the original keeps both results
 * live in r4 and r5 and uses r4 only for the mode test, so the two calls
 * are in the source, not an artefact.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D2CC.c \
 *       --func func_0203D2CC --addr 0x0203D2CC --cc 1.1p1 --arm
 */
void func_0203D2CC(void)
{
    struct NetCtx *a = func_0203D798();
    struct NetCtx *b = func_0203D788();

    if (func_020338F8() == 1) {
        func_02034714(g_020A7CA0, 868, g_020A7CE8);
        return;
    }
    if (b != 0 && a->f65 != 3) {
        u32 flag = 0;

        if ((u8)(b->f65 + 0xff) <= 1) {
            flag = 1;
        }
        func_02037010(b->f5C, b->f5E, flag, b->f56);
    } else {
        func_020370C8();
    }
}





/*
 * TU: net.c.
 *
 * Three-call sequence: stamp the (0xf0, 0) pair into the state block, run
 * the transfer at 0x02037118 with this function's own two arguments, then
 * kick the state machine at 0x0203D2CC.  Both arguments have to outlive the
 * first call, which is what spends r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D34C.c \
 *       --func func_0203D34C --addr 0x0203D34C --cc 1.1p1 --arm
 */
void func_0203D34C(u32 a, u32 b)
{
    func_0203D24C(0xf0, 0);
    func_02037118(a, b);
    func_0203D2CC();
}





/*
 * TU: net.c.
 *
 * Inverted forward: 1 when func_02039338 reports zero.  The result local is
 * initialised before the call, so the zero lands in r4 ahead of the `bl`
 * and the true case is a single `moveq`; writing `return f() == 0;`
 * instead puts the materialisation after the call and loses the shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D378.c \
 *       --func func_0203D378 --addr 0x0203D378 --cc 1.1p1 --arm
 */
u32 func_0203D378(void)
{
    u32 res = 0;

    if (func_02039338() == 0) {
        res = 1;
    }
    return res;
}





/*
 * TU: net.c.
 *
 * Leaf predicate on the +0x4a byte of an entry: "is this entry in state 5".
 * No relocation and no frame; the same three-instruction body appears
 * inlined inside func_020399B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D394.c \
 *       --func func_0203D394 --addr 0x0203D394 --cc 1.1p1 --arm
 */
u32 func_0203D394(struct NetEntry *e)
{
    return e->state == 5;
}




/*
 * TU: net.c.
 *
 * Seven-argument send wrapper.  The leading func_0203D798 call is made for
 * effect only, its result is dead in the original, and the four incoming
 * arguments all have to survive it, which is what spends r4-r7.  Arguments
 * five to seven go on the stack, hence the `sub sp, sp, #0xc`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D3A8.c \
 *       --func func_0203D3A8 --addr 0x0203D3A8 --cc 1.1p1 --arm
 */
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d)
{
    func_0203D798();
    return func_02038C18(b, d, c, 0, func_020395EC(a), 0xff, 0);
}




/*
 *           the image and it is the call inside this function, so `label` has
 *           no outside witness for either and no manifest entry covers them
 *           yet.  File those two addresses first and this graduates with no
 *           change to its C (every other site resolves).
 */
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h)
{
    u8 mask;

    func_0203D798();
    mask = 0xff;
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    if (sendID != 0xff) {
        if (sendID >= 7) {
            func_02034714(g_020A7CA0, 1019, g_020A7CEC);
        }
        mask = 1 << sendID;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}




/*
 * TU: net.c.
 *
 * The explicit-mask sibling of func_0203D3F8: identical guards, but the
 * destination bitmask arrives as the second parameter instead of being
 * derived from a send id, so there is no assert and no `lsl`, and the mask
 * stays in r6 across the whole body.  The two stack arguments that live
 * next to each other go out as one `stmib`.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D578 because the
 * follower at 0x0203D56C has no label.  It is not a byte difference; the
 * follower is a twelve-byte ARM long-branch veneer (ldr ip, [pc]; bx ip;
 * .word 0x020394C0) that saves no lr and so is invisible to disasm.py.  It
 * wants seeding into layout/function_starts.txt, which is the integrator's
 * file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D4D0.c \
 *       --func func_0203D4D0 --addr 0x0203D4D0 --cc 1.1p1 --arm
 */
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g,
                  u32 h)
{
    func_0203D798();
    if (func_0203D394((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && func_02039468(c, func_020395EC((void *)entry)) != 0) {
        return 0;
    }
    return func_02038C18(c, e, d, f, func_020395EC((void *)entry), mask, h);
}



void func_0203D56C(void)
{
    func_020394C0();
}




/*
 * Forwards the first argument through func_020395EC and passes the result
 * with the second argument to func_02039468.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D578.c \
 *       --func func_0203D578 --addr 0x0203D578 --arm --cc 1.1p1
 */
void func_0203D578(int a, u32 b)
{
    u32 r = func_020395EC((void *)a);

    func_02039468(b, r);
}
