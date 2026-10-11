/*
 * file:     net_state_p06.c
 * unit:     yes
 * function: func_0203D650, func_0203D668, func_0203D680, func_0203D6BC, func_0203D6CC, func_0203D700, func_0203D720, func_0203D754
 * address:  0x0203D650
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
 *   func_02034714  0x02034714  arm
 *   file_020A7CA0  0x020A7CA0  data
 *   file_020A7CF8  0x020A7CF8  data
 *   file_020A7D2C  0x020A7D2C  data
 */
#include "../../matched/include/Obj15990.h"
#include "../../matched/include/Obj11379.h"

struct NetCtx;
struct Entry;
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

extern struct NetCtx *func_0203D788(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern struct Entry *func_020399A8(void);
u32 func_0203D650(void);
void func_0203D668(u32 v);
u32 func_0203D680(void);
u32 func_0203D6BC(void);
u32 func_0203D6CC(void);
void func_0203D700(void);
void func_0203D720(u32 a);
void func_0203D754(u32 a);
extern const char file_020A7CA0[];
extern const char file_020A7CF8[];
extern const char file_020A7D2C[];




/*
 * Returns the word at +0x34c of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D650.c \
 *       --func func_0203D650 --addr 0x0203D650 --arm --cc 1.1p1
 */
u32 func_0203D650(void)
{
    struct NetCtx *p = func_0203D788();

    return p != 0 ? p->f34C : 0;
}




/*
 * Stores the argument at +0x34c of the net context, when there is one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D668.c \
 *       --func func_0203D668 --addr 0x0203D668 --arm --cc 1.1p1
 */
void func_0203D668(u32 v)
{
    struct NetCtx *p = func_0203D788();

    if (p != 0) {
        p->f34C = v;
    }
}



/*
 * Returns the net context's +0x60 byte, reporting through func_02034714 with
 * the source file at 0x020A7CA0 ("net.c") and line 0x593 (1427) when the byte
 * is past 8.  The guard is unsigned (`bls`), so the comparison is
 * `> 8` against an unsigned char.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D680.c \
 *       --func func_0203D680 --addr 0x0203D680 --cc 1.1p1 --arm
 */
u32 func_0203D680(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f60 > 8)
        func_02034714(file_020A7CA0, 0x593, file_020A7CF8);
    return p->f60;
}




/*
 * Returns the byte at +0x61 of the net context.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6BC.c \
 *       --func func_0203D6BC --addr 0x0203D6BC --arm --cc 1.1p1
 */
u32 func_0203D6BC(void)
{
    return func_0203D788()->f61;
}




/*
 * Halfword getter for the null-test sibling of func_0203D680: reports through
 * func_02034714 at line 0x5B1 (1457) when func_0203D788 comes back null, then
 * reads +0x6C from it regardless.  The null test is the `movs r4, r0` /
 * `bne` pair, so the result is kept in a local that the tail still
 * dereferences rather than being re-requested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6CC.c  *       --func func_0203D6CC --addr 0x0203D6CC --cc 1.1p1 --arm
 */
u32 func_0203D6CC(void)
{
    struct NetCtx *p = func_0203D788();

    if (p == 0)
        func_02034714(file_020A7CA0, 0x5B1, file_020A7D2C);
    return p->f6C;
}




/*
 * Calls the net context's +0x30 callback with its +0x34c argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D700.c \
 *       --func func_0203D700 --addr 0x0203D700 --arm --cc 1.1p1
 */
void func_0203D700(void)
{
    struct NetCtx *p = func_0203D788();

    if (p->f30 != 0) {
        ((void (*)(u32)) p->f30)(p->f34C);
    }
}




/*
 * Calls the net context's +0x28 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D720.c \
 *       --func func_0203D720 --addr 0x0203D720 --arm --cc 1.1p1
 */
void func_0203D720(u32 a)
{
    struct NetCtx *p = func_0203D788();

    if (p->f28 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) p->f28)(
        (u32)func_020399A8(), a, p->f34C);
}




/*
 * Calls the net context's +0x24 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D754.c \
 *       --func func_0203D754 --addr 0x0203D754 --arm --cc 1.1p1
 */
void func_0203D754(u32 a)
{
    struct NetCtx *p = func_0203D788();

    if (p->f24 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) p->f24)(
        (u32)func_020399A8(), a, p->f34C);
}
