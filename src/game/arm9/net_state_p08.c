/*
 * file:     net_state_p08.c
 * unit:     yes
 * function: func_0203D798, func_0203D7B0
 * address:  0x0203D798
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
 *   g_021469E0  0x021469E0  data
 *   func_0203C8E8  0x0203C8E8  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;
typedef unsigned int u32;

struct NetCtx;

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

struct NetCtx;

struct NetCtx;

struct NetCtx;

struct NetCtx;

struct NetCtx;

struct Singleton {
    u8    pad_00[8];
    void *unk_08;
};

extern void func_0203C8E8(u8 v);
void *func_0203D798(void);
void func_0203D7B0(u8 a0);
extern struct Singleton g_021469E0;


/*
 * Accessor for the +8 handle of the singleton at 0x021469E0, with the null
 * case spelled out.  The `moveq r0, #0` is a no-op on the value it guards,
 * so it is only there because the source writes the null return
 * explicitly; a plain `return g->unk_08;` loses the `cmp` and the `moveq`
 * and is eight bytes short.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D7C8 because the
 * follower at 0x0203D7B0 has no label.  It is not a byte difference; the
 * follower is a pair of eight-byte ARM long-branch veneers (0x0203D7B0 ->
 * 0x0203C8E8 and 0x0203D7BC -> 0x0203C900), which save no lr and so are
 * invisible to disasm.py.  Both want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D798.c \
 *       --func func_0203D798 --addr 0x0203D798 --cc 1.1p1 --arm
 */
void *func_0203D798(void)
{
    if (g_021469E0.unk_08 == 0) {
        return 0;
    }
    return g_021469E0.unk_08;
}


/*
 *           prologue is `ldr r1, [pc, #0xc]` and saves no lr, so disasm.py
 *           emitted no func_ label there (the unlabelled-leaf idiom) and
 *           evidence().labels has no entry.  sole-ref/code therefore refuses
 *           it, veneer_at() does not recognise it, and the pool word under
 *           test is the only reference to it in the image, so `literal` and
 *           `label` both discard their only witness.  All 12 bytes are
 *           correct.  It becomes EXACT the moment 0x0203C8E8 is seeded into
 *           layout/function_starts.txt (the integrator's file) or a second
 *           referrer is decompiled.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0203D7B0.c \
 *       --func func_0203D7B0 --addr 0x0203D7B0 --cc 1.1p1 --arm
 */
void func_0203D7B0(u8 a0)
{
    func_0203C8E8(a0);
}
