/*
 * file:     net_state_p41.c
 * unit:     yes
 * function: func_0203BBB0, func_0203BC58, func_0203BCE0, func_0203BD30, func_0203BDEC, func_0203BE5C, func_0203BEAC, func_0203BEC8, func_0203BF4C, func_0203BF9C, func_0203BFF0, func_0203C00C
 * address:  0x0203BBB0
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
 *   func_0203AD80   0x0203AD80  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D798   0x0203D798  arm
 *   func_0203AEEC   0x0203AEEC  arm
 */
#include "../../matched/include/Obj06945.h"
#include "../../matched/include/Obj11878.h"

struct Slot;
struct NetState;
struct Entry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

extern void *func_0203D788(void);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_0203B950(u8 *p);
extern void func_0203B90C(void);
extern void func_0203B5D4(struct Slot *p);
extern void func_0203B48C(void);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_0203D798(void);
extern int func_0203CEAC(int a0);
extern u16 func_02039338(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_0203AEEC(u8 *p);
void func_0203BBB0(u32 a);
void func_0203BC58(u8 v56, u8 v53, const void *src);
void func_0203BCE0(u8 *p);
void func_0203BD30(u32 a0, u32 a1, u8 *a2);
void func_0203BDEC(void);
void func_0203BE5C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0203BEAC(void);
void func_0203BEC8(u8 *p);
void func_0203BF4C(void);
void func_0203BF9C(u32 v);
void func_0203BFF0(void);
void func_0203C00C(void);
extern u8 *g_021469DC;


/*
 * Two presets that differ only in the state byte they match and the handler
 * they advertise.  Each test is a conjunction of the state byte and the
 * eight-byte pointer stored beside it, and the first arm also refuses when
 * the vtable's +0x10 hook answers zero.
 *
 * The four code addresses are declared as the functions they are: written as
 * integer literals the front end folds two nearby ones into one pool word plus
 * a `sub`, which is four bytes shorter than the original.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BBB0.c \
 *       --func func_0203BBB0 --addr 0x0203BBB0 --cc 1.1p1 --arm
 */
void func_0203BBB0(u32 a)
{
    u8 *s = func_0203D788();
    u8 *g;

    g = g_021469DC;
    if (g[0x56] == 2 && ((struct Obj06945 *)g)->f8 == (u32)func_0203B950) {
        if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) != 0) {
            func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203B90C, 0, 0x3E0);
        }
    }

    g = g_021469DC;
    if (g[0x56] == 1 && ((struct Obj06945 *)g)->f8 == (u32)func_0203B5D4) {
        func_0203AD80((struct NetState *)g, (void *)func_0203B48C, 0, 0x3E9);
    }
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BC58.c \
 *       --func func_0203BC58 --addr 0x0203BC58 --cc 1.1p1 --arm
 */
void func_0203BC58(u8 v56, u8 v53, const void *src)
{
    func_0203D788();
    g_021469DC[0x53] = v53;
    g_021469DC[0x56] = v56;

    if (src != 0) {
        MI_CpuCopy8(src, g_021469DC + 0x57, 6);
    } else {
        MI_CpuFill8(g_021469DC + 0x57, 0xFF, 6);
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203BBB0, 0, 0x406);
    func_0203BBB0((u32)g_021469DC);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BCE0.c \
 *       --func func_0203BCE0 --addr 0x0203BCE0 --cc 1.1p1 --arm
 */
void func_0203BCE0(u8 *p)
{
    u8 *s = func_0203D788();

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B90C, 0, 0x411);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BD30.c \
 *       --func func_0203BD30 --addr 0x0203BD30 --cc 1.1p1 --arm
 */
void func_0203BD30(u32 a0, u32 a1, u8 *a2)
{
    func_0203D788();

    g_021469DC[0x53] = (u8)a1;
    g_021469DC[0x56] = (u8)a0;

    if (a2 != 0)
        MI_CpuCopy8(a2, g_021469DC + 0x57, 6);
    else
        MI_CpuFill8(g_021469DC + 0x57, 0xFF, 6);

    if (g_021469DC[0x56] == 2)
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B48C, 0, 0x430);

    if (g_021469DC[0x56] == 1) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203BCE0, 0, 0x438);
        func_0203BCE0(g_021469DC);
    }
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BDEC.c \
 *       --func func_0203BDEC --addr 0x0203BDEC --cc 1.1p1 --arm
 */
void func_0203BDEC(void)
{
    u8 *p = func_0203D798();
    u8 *s = func_0203D788();

    if ((u8)(p[0x65] + 0xFD) <= 1) {
        if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0xAC))() != 0)
            return;
        func_0203CEAC(0);
    } else {
        u8 *s2 = func_0203D788();

        if (((*(u32 (**)(void))(*(u32 *)(s2 + 0x340) + 0x7C))() & 0xFFFE) != 0)
            return;
        func_0203CEAC(0);
    }
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BE5C.c \
 *       --func func_0203BE5C --addr 0x0203BE5C --cc 1.1p1 --arm
 */
void func_0203BE5C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    func_0203D3A8((void *)a4, 2, 0, 0);

    if (func_02039338() != 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203BDEC, 0, 0x46C);
}



/*
 * "If the state is non-zero, park the card interface."  The result of the
 * test is kept in a local and returned, so the zero path is the `popeq` that
 * gives back r0 == 0 and the busy path returns whatever func_0203CEAC leaves
 * in r0 - no second `mov r0, #0` anywhere.
 *
 * The local is load-bearing: spelling it `if (func_02039338() == 0) return 0;
 * return func_0203CEAC(0);` hoists the `mov r0, #0` that sets up the call's
 * argument above the conditional return and lands two instructions late.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEAC.c \
 *       --func func_0203BEAC --addr 0x0203BEAC --cc 1.1p1 --arm
 */
u32 func_0203BEAC(void)
{
    u32 r;

    r = func_02039338();
    if (r != 0)
        r = func_0203CEAC(0);
    return r;
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEC8.c \
 *       --func func_0203BEC8 --addr 0x0203BEC8 --cc 1.1p1 --arm
 */
void func_0203BEC8(u8 *p)
{
    u8 *s;

    func_0203D798();
    s = func_0203D788();

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x78))() != 0) {
        if ((*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0) == 0)
            return;
        func_0203AEEC(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x6C))() != 0)
        return;
    if ((*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0) == 0)
        return;
    func_0203AEEC(p);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BF4C.c \
 *       --func func_0203BF4C --addr 0x0203BF4C --cc 1.1p1 --arm
 */
void func_0203BF4C(void)
{
    u8 *s = func_0203D788();

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203BEC8, 0, 0x4A4);
}



/*
 * 116 bytes, three functions: the setter, the 28-byte leaf that clears the
 * same flag, and the four-byte `bx lr` stub the card task is handed as a
 * callback (src/pending/func_0203C010.c passes it at 0x0203C00C).
 *
 * The two leaves carry no label in the generated listing - neither saves `lr`
 * - so this range used to stop at 0x0203BF9C with an `EXACT*`, the inferred
 * extent running on to the next labelled function at 0x0203C010.  Writing
 * them as the unit's own functions is what closes the range.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203BF9C.c \
 *       --addr 0x0203BF9C --arm --cc 1.1p1
 */
void func_0203BF9C(u32 v)
{
    u8 *p = g_021469DC;

    if (p != 0 && p[0x51] != 0)
        return;

    ((struct Obj11878 *)p)->f28 = v;
    g_021469DC[0x51] = 1;
    func_0203AD80((struct NetState *)g_021469DC, (void *)func_0203BF4C, 5, 0x4B7);
}



void func_0203BFF0(void)
{
    if (g_021469DC != 0)
        g_021469DC[0x51] = 0;
}



void func_0203C00C(void)
{
}
