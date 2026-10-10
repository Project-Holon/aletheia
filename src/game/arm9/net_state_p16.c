/*
 * file:     net_state_p16.c
 * unit:     yes
 * function: func_0203DA68, func_0203DA7C
 * address:  0x0203DA68
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
 *   d_021469F0 0x021469F0 data a4
 *   g_021469F0     0x021469F0  data
 *   func_0203DC04  0x0203DC04  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

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

struct Ctx {
    u8  pad_00[0x84];
    u32 unk_84;
    u32 unk_88;
    u32 unk_8c;
};

extern void func_0203DC04(void);
void func_0203DA68(unsigned int value);
void *func_0203DA7C(void *a0, void *a1, void *a2);
extern unsigned char *d_021469F0;
extern struct Ctx *g_021469F0;

/*
 * Stores a word into the singleton at +0x74.
 */
void func_0203DA68(unsigned int value)
{
    *(unsigned int *)(d_021469F0 + 0x74) = value;
}


/*
 * Install the three wireless callbacks and hand back the state machine that
 * drives them.  With no live context (0x021469F0 null) the function returns
 * its first argument untouched - the image leaves r0 alone on that path, so
 * the early exit is `bxeq lr`, not a `moveq r0, #0`.  Otherwise each non-null
 * argument is stored at +0x84, +0x88 and +0x8C of the context, and the
 * function returns func_0203DC04.
 *
 * The context is re-read from the global for the second and third stores
 * (`ldrne r0, [pc, ...]; ldrne r0, [r0]`), because the first store could
 * alias the global: the source spells them g_021469F0->unk_88 rather than
 * reusing a cached local.  The first store uses the value already in r3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA7C.c \
 *       --func func_0203DA7C --addr 0x0203DA7C --cc 1.1p1 --arm
 */
void *func_0203DA7C(void *a0, void *a1, void *a2)
{
    struct Ctx *p = g_021469F0;

    if (p == 0)
        return a0;
    if (a0 != 0)
        p->unk_84 = (u32)a0;
    if (a1 != 0)
        g_021469F0->unk_88 = (u32)a1;
    if (a2 != 0)
        g_021469F0->unk_8c = (u32)a2;
    return func_0203DC04;
}
