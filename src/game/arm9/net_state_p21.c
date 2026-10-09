/*
 * file:     net_state_p21.c
 * unit:     yes
 * function: func_0203B6EC, func_0203B758, func_0203B794, func_0203B7F8, func_0203B868, func_0203B90C, func_0203B950, func_0203B9D4
 * address:  0x0203B6EC
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
 *   g_021469DC     0x021469DC  data
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_02039ACC   0x02039ACC  arm
 *   func_0203DA4C   0x0203DA4C  arm
 *   func_0203D650   0x0203D650  arm
 *   func_0203AD80   0x0203AD80  arm
 */
#include "../../matched/include/Obj08841.h"
#include "../../matched/include/Obj03451.h"

struct NetState;
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

struct B794 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

typedef signed int     s32;

struct B868 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

typedef unsigned long long u64;

extern u8 *func_0203D788(void);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern u32 func_02037894(u32 a, u32 b, u32 c, u32 d);
extern int func_0203B6B4(int a0, int a1, int a2, int a3);
extern int func_0203B688(int a0, int a1, int a2, int a3);
extern void *func_0203D798(void);
extern int func_02039ACC(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern u32 func_0203D650(void);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_020399EC(u32 a);
extern u16 func_02039338(void);
extern int func_0203DA4C(void);
extern void func_0203BCE0(u8 *p);
void func_0203B90C(void);
void func_0203B950(u8 *p);
void func_0203B6EC(u8 *p);
void func_0203B758(void);
void func_0203B9D4(u8 *p);
extern u8 *g_021469DC;



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B6EC.c \
 *       --func func_0203B6EC --addr 0x0203B6EC --cc 1.1p1 --arm
 */
void func_0203B6EC(u8 *p)
{
    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0x78))() == 0)
        return;
    if (func_02037894(0, 0x200, 0, (u32)func_0203B6B4) == 0)
        return;

    p[0x4C] = 0;
    func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203B688, 0x1E, 0x2FC);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B758.c \
 *       --func func_0203B758 --addr 0x0203B758 --cc 1.1p1 --arm
 */
void func_0203B758(void)
{
    func_0203D798();
    if (func_02039ACC() == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B794, 0, 0x30E);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B794.c \
 *       --func func_0203B794 --addr 0x0203B794 --cc 1.1p1 --arm
 */
void func_0203B794(struct B794 *p)
{
    u8 *s = func_0203D798();

    if (func_020399B8((u8 *)((u32)func_020399A8())) == 0)
        return;

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C00C, 0, 0x325);
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B7F8.c \
 *       --func func_0203B7F8 --addr 0x0203B7F8 --cc 1.1p1 --arm
 */
void func_0203B7F8(struct B794 *p)
{
    func_0203D798();

    func_0203996C(0xFF);
    if ((int)func_020399EC((u32)func_020399A8()) < 2)
        return;

    func_02039338();

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C00C, 0, 0x33F);
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B868.c \
 *       --func func_0203B868 --addr 0x0203B868 --cc 1.1p1 --arm
 */
void func_0203B868(struct B868 *p)
{
    func_0203D798();

    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0xA8))() != 1)
        return;
    if (func_02039ACC() == 0)
        return;

    if (func_0203DA4C() == 1) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B7F8, 0, 0x354);
        return;
    }

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C00C, 0, 0x35B);
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B90C.c \
 *       --func func_0203B90C --addr 0x0203B90C --cc 1.1p1 --arm
 */
void func_0203B90C(void)
{
    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0x78))() == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B6EC, 0, 0x371);
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B950.c \
 *       --func func_0203B950 --addr 0x0203B950 --cc 1.1p1 --arm
 */
void func_0203B950(u8 *p)
{
    if (func_02039338() != 0) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B758, 0, 0x383);
        return;
    }

    if (p[0x56] == 2)
        return;

    if (((struct Obj08841 *)p)->f46 != 0) {
        (((struct Obj08841 *)p)->f46)--;
        return;
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203BCE0, 0, 0x390);
    func_0203BCE0(p);
}


/*
 * A frame's 64-bit accumulator advanced by a 64-bit multiply: the pair at
 * +0x0c (little-endian u64) is multiplied by the pair at +0x14, the pair at
 * +0x1c is added in, both halves are stored back, and the new high half is
 * re-scaled by 30/2^32 into the u16 countdown at +0x46.
 *
 * Two spellings are load-bearing.  The multiply has to be written `y * x`
 * with x at +0x0c and y at +0x14: the other order loads +0x0c first and
 * swaps two `ldr`s.  And the addend has to stay inline in the multiply's own
 * statement (`r = y * x + *(u64 *)(p + 0x1c);`) with the low half stored by
 * a single 64-bit store: with a named addend and two u32 stores mwcc puts
 * the sum's low half in `ip` and the high half in `r2`, a five-instruction
 * difference in register choice alone.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B9D4.c \
 *       --func func_0203B9D4 --addr 0x0203B9D4 --cc 1.1p1 --arm
 */
void func_0203B9D4(u8 *p)
{
    u8 *s = func_0203D788();
    u64 x, y, r;

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0xAC))() == 1) {
        (*(void (**)(void))(*(u32 *)(s + 0x340) + 0xB4))();
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B868, 0, 0x3A5);
        return;
    }

    if (((struct Obj03451 *)p)->f46 != 0) {
        ((struct Obj03451 *)p)->f46 = ((struct Obj03451 *)p)->f46 - 1;
        return;
    }

    x = *(u64 *)(p + 0x0C);
    y = *(u64 *)(p + 0x14);
    r = y * x + *(u64 *)(p + 0x1C);

    ((struct Obj03451 *)p)->f46 = (u16)((u32)(((u64)(u32)(r >> 32) * 30) >> 32) + 15);
    *(u64 *)(p + 0x0C) = r;

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x08))(0);
}
