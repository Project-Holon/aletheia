/*
 * file:     net_state_p10.c
 * unit:     yes
 * function: func_0203D9EC, func_0203DA20, func_0203DA4C
 * address:  0x0203D9EC
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
 *   g_021469F0  0x021469F0  data
 *   d_021469F0   0x021469F0  data  a4
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

extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);
void func_0203D9EC(void);
void func_0203DA20(void);
int func_0203DA4C(void);
extern u8 g_021469F0[];
extern u32 d_021469F0[];


/*
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through func_02034FB8(0x20) and the heap release, then clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D9EC.c \
 *       --func func_0203D9EC --addr 0x0203D9EC --arm --cc 1.1p1
 */
void func_0203D9EC(void)
{
    if (*(u32 *)g_021469F0 == 0) {
        return;
    }
    func_02034FB8(0x20);
    func_020307B0(*(void **)g_021469F0);
    *(u32 *)g_021469F0 = 0;
}


/*
 * Calls func_0203D9EC when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA20.c \
 *       --func func_0203DA20 --addr 0x0203DA20 --arm --cc 1.1p1
 */
void func_0203DA20(void)
{
    u8 *p = *(u8 **)g_021469F0;

    if (p == 0) {
        return;
    }
    if (p[0x101] != 0) {
        return;
    }
    func_0203D9EC();
}


int func_0203DA4C(void)
{
    return d_021469F0[0] != 0;
}
