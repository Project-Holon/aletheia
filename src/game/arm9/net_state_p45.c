/*
 * file:     net_state_p45.c
 * unit:     yes
 * function: func_0203D7BC, func_0203D7C8, func_0203D7FC, func_0203D814, func_0203D828, func_0203D844, func_0203D864, func_0203D880, func_0203D88C, func_0203D8AC, func_0203D8C4, func_0203D8F0
 * address:  0x0203D7BC
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
 *   func_0203C900  0x0203C900  arm
 *   g_021469E0  0x021469E0  data
 *   g_021469F0     0x021469F0  data
 *   d_020A7D34     0x020A7D34  data
 *   func_02030734  0x02030734  arm
 *   func_02034F84  0x02034F84  arm
 *   func_0203DC4C  0x0203DC4C  arm
 *   func_0203E420  0x0203E420  arm
 *   func_0203E458  0x0203E458  arm
 */
#include "../../matched/include/Obj11380.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int  u32;

typedef struct Base {
    u8   pad_00[0x18];
    void *fn_18;
    void *fn_1c;
    u8   pad_20[0x2c - 0x20];
    void *fn_2c;
    u8   pad_30[0x54 - 0x30];
    u16  heap;
    u8   pad_56[0x60 - 0x56];
    u8   f60;
    u8   pad_61[3];
    u8   f64;
    u8   f65;
    u8   pad_66[0x70 - 0x66];
} Base;

typedef struct Wrap {
    Base  base;
    u32   arg;
    u32   pad_74;
    void *fn_18;
    void *fn_1c;
    void *fn_2c;
    u8    pad_84[0x101 - 0x84];
    u8    f101;
    u8    pad_102[2];
    u8    f104;
    u8    pad_105[2];
    u8    f107;
    u8    pad_108[0x10C - 0x108];
} Wrap;

extern void func_0203C900(u8 v);
extern void *func_02030734(u32 a, u32 b, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_0203D788(void);
extern void func_02082D44(void *dst, const void *src, u32 size);
extern u32 func_02039414(void);
extern void func_020371AC(unsigned short a, unsigned int b);
extern void func_0203D2CC(void);
extern void func_02034F84(u32 v);
extern void func_0203DC4C(void);
extern void *func_0203E420(void *arg);
extern void *func_0203E458(void *arg);
void func_0203D7BC(u8 a0);
void *func_0203D7C8(u32 a, u32 size, const char *c, u16 d);
void func_0203D7FC(void *p);
void func_0203D814(u32 a, u32 b);
void func_0203D828(u32 *a, u32 *b);
void func_0203D844(void *dst);
void func_0203D864(void);
u32 func_0203D880(void);
void func_0203D88C(u32 a, u32 b);
void func_0203D8AC(void);
void func_0203D8C4(u32 a);
Base *func_0203D8F0(const Base *src, u32 a1);
extern u8 g_021469E0[];
extern Wrap *g_021469F0;
extern u8 d_020A7D34[];



/*
 * A long-branch veneer pair with func_0203D7B0: the image spells both as
 * `ldr ip, [pc]; bx ip; .word target`, which this compiler emits for a
 * tail call to an ARM callee whose address must come from a pool.
 *
 * The ABS32 at +0008 resolves through sole-ref/code: 0x0203C900 is a
 * traced ARM function start (its prologue saves lr, so disasm.py labelled
 * it), and sole-ref/code accepts an exact label start without requiring a
 * second referrer.  Its neighbour func_0203D7B0 is NOT filable the same
 * way -- 0x0203C8E8 opens with a bare `ldr` and saves no lr, so disasm.py
 * never labelled it and no class can carry the site.  That is why these
 * two 12-byte twins are in different directories.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0203D7BC.c \
 *       --func func_0203D7BC --addr 0x0203D7BC --cc 1.1p1 --arm
 */
void func_0203D7BC(u8 a0)
{
    func_0203C900(a0);
}



/*
 * Allocates size rounded up to 0x20 plus 0x20, rounds the result up to a
 * 0x20 boundary and stores the raw pointer in the word just before the
 * aligned block, which func_0203D7FC releases it by.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D7C8.c \
 *       --func func_0203D7C8 --addr 0x0203D7C8 --arm --cc 1.1p1
 */
void *func_0203D7C8(u32 a, u32 size, const char *c, u16 d)
{
    u8 *p = (u8 *)func_02030734(a, ((size + 0x24) & ~0x1fu) + 0x20, 1, c, d);
    u8 *q = (u8 *)(((u32)p + 0x20) & ~0x1fu);

    *(void **)(q - 4) = p;
    return q;
}



/*
 * Releases the aligned block func_0203D7C8 returns, via the pointer kept
 * just before it, and tolerates a null.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D7FC.c \
 *       --func func_0203D7FC --addr 0x0203D7FC --arm --cc 1.1p1
 */
void func_0203D7FC(void *p)
{
    if (p == 0) {
        return;
    }
    func_020307B0(*(void **)((u8 *)p - 4));
}



/*
 * Stores the two net_irc_wireless context words at +0xc and +4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D814.c \
 *       --func func_0203D814 --addr 0x0203D814 --arm --cc 1.1p1
 */
void func_0203D814(u32 a, u32 b)
{
    *(u32 *)(g_021469E0 + 0xc) = a;
    *(u32 *)(g_021469E0 + 4) = b;
}



/*
 * Reads back the two net_irc_wireless context words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D828.c \
 *       --func func_0203D828 --addr 0x0203D828 --arm --cc 1.1p1
 */
void func_0203D828(u32 *a, u32 *b)
{
    *a = *(u32 *)(g_021469E0 + 0xc);
    *b = *(u32 *)(g_021469E0 + 4);
}



/*
 * Copies 0x70 bytes from the net context into the destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D844.c \
 *       --func func_0203D844 --addr 0x0203D844 --arm --cc 1.1p1
 */
void func_0203D844(void *dst)
{
    func_02082D44(dst, func_0203D788(), 0x70);
}



/*
 * Clears the net context's +0x2c and +0x1c words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D864.c \
 *       --func func_0203D864 --addr 0x0203D864 --arm --cc 1.1p1
 */
void func_0203D864(void)
{
    u8 *p = func_0203D788();

    if (p != 0) {
        ((struct Obj11380 *)p)->f2C = 0;
        ((struct Obj11380 *)p)->f1C = 0;
    }
}



/*
 * A bare tail-call thunk to func_02039414.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D880.c \
 *       --func func_0203D880 --addr 0x0203D880 --arm --cc 1.1p1
 */
u32 func_0203D880(void)
{
    return func_02039414();
}



/*
 * Truncates both arguments to 16 bits, then runs the pair through
 * func_020371AC and func_0203D2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D88C.c \
 *       --func func_0203D88C --addr 0x0203D88C --arm --cc 1.1p1
 */
void func_0203D88C(u32 a, u32 b)
{
    func_020371AC((u16)a, (u16)b);
    func_0203D2CC();
}



/*
 * Runs func_020371AC(0, 0) and func_0203D2CC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D8AC.c \
 *       --func func_0203D8AC --addr 0x0203D8AC --arm --cc 1.1p1
 */
void func_0203D8AC(void)
{
    func_020371AC(0, 0);
    func_0203D2CC();
}



/*
 * Writes 1 or 0 to the net context's +0x352 byte depending on whether the
 * argument is 1; a null context is a no-op.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D8C4.c \
 *       --func func_0203D8C4 --addr 0x0203D8C4 --arm --cc 1.1p1
 */
void func_0203D8C4(u32 a)
{
    u8 *p = *(u8 **)(g_021469E0 + 8);

    if (p == 0) {
        return;
    }
    if (a == 1) {
        p[0x352] = 1;
    } else {
        p[0x352] = 0;
    }
}



/*
 * net_irc_wireless.c.  Wraps a caller's 0x70-byte task header: allocates a
 * 0x10C-byte record low on the header's own heap (id | 0x8000, __FILE__
 * 0x020A7D34, line 0x72), copies the header in, saves the header's three
 * callbacks (+0x2C, +0x18, +0x1C) at +0x80/+0x78/+0x7C, installs the
 * wireless callbacks func_0203DC4C, func_0203E420, func_0203E458 in their
 * place, publishes the record at 0x021469F0 and returns it.  With a live
 * record whose +0x101 is 1 it returns the header untouched.
 *
 * The lever (docs/notes/pkt_0203D8F0.c.txt had 63 bytes out, 40 after
 * the permuter): the header parameter is `const Base *`.  Without const
 * the stores into the new record may alias the header, so the compiler
 * keeps the header loads behind them and schedules the allocator's stack
 * argument differently; with const both regions reproduce.
 */
Base *func_0203D8F0(const Base *src, u32 a1)
{
    Wrap *obj;

    if (g_021469F0 != 0 && g_021469F0->f101 == 1)
        return (Base *)src;

    obj = func_02030734((u16)((src->heap & 0x7FFF) | 0x8000), sizeof(Wrap), 1, (const char *)d_020A7D34, 0x72);
    obj->base = *src;
    obj->arg = a1;
    obj->fn_2c = src->fn_2c;
    obj->fn_18 = src->fn_18;
    obj->fn_1c = src->fn_1c;
    obj->base.f65 = 3;
    obj->base.fn_2c = func_0203DC4C;
    obj->base.fn_18 = func_0203E420;
    obj->base.fn_1c = func_0203E458;
    obj->f104 = obj->base.f64;
    obj->base.f64 = 0;
    obj->f107 = obj->base.f60;

    g_021469F0 = obj;
    func_02034F84(0x20);
    return &g_021469F0->base;
}
