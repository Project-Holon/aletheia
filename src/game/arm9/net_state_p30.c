/*
 * file:     net_state_p30.c
 * unit:     yes
 * function: func_0203C710, func_0203C774, func_0203C7E0, func_0203C864, func_0203C8A8, func_0203C8E8, func_0203C900, func_0203C934, func_0203C938, func_0203C968, func_0203C990, func_0203C9AC, func_0203CA04
 * address:  0x0203C710
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
 *   unk_021469DC   0x021469DC  data
 *   func_02039548  0x02039548  arm
 *   func_02039578  0x02039578  arm
 *   func_02039560  0x02039560  arm
 *   g_020A7BA8      0x020A7BA8  data
 *   g_020A7BEC      0x020A7BEC  data
 *   func_0203D798   0x0203D798  arm
 *   func_02034714   0x02034714  arm
 */
#include "../../matched/include/Obj15970.h"

struct NetState;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

typedef signed char   s8;

extern void *func_0203D788(void);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern int func_020351A0(u32 v);
extern void func_0203C0DC(u8 *p, u32 v);
extern void *func_0203D798(void);
extern int func_02037700(u32 a0, u32 a1);
extern int  func_020392EC(void);
extern void func_0203516C(u32 a);
extern void func_02039548(void);
extern void func_02039578(void);
extern void func_02039560(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_0203C710(void);
void func_0203C774(u32 v);
void func_0203C7E0(u8 *p);
void func_0203C864(void);
void func_0203C8A8(void);
void func_0203C8E8(u8 v);
void func_0203C900(u8 v);
void func_0203C934(void);
u32 func_0203C938(u8 mode);
void func_0203C968(void);
u32 func_0203C990(void);
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
void func_0203CA04(void);
extern u8 *g_021469DC;
extern u32 unk_021469DC;
extern u8  g_020A7BA8[];
extern u8  g_020A7BEC[];



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C710.c \
 *       --func func_0203C710 --addr 0x0203C710 --cc 1.1p1 --arm
 */
void func_0203C710(void)
{
    u8 *s = func_0203D788();

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);
    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C65C, 0, 0x702);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C774.c \
 *       --func func_0203C774 --addr 0x0203C774 --cc 1.1p1 --arm
 */
void func_0203C774(u32 v)
{
    u8 *s;

    if (g_021469DC == 0)
        return;

    s = func_0203D788();
    func_020351A0(1);
    *(u32 *)(g_021469DC + 0x28) = v;
    (*(void (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(1, 0);

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C710, 5, 0x719);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C7E0.c \
 *       --func func_0203C7E0 --addr 0x0203C7E0 --cc 1.1p1 --arm
 */
void func_0203C7E0(u8 *p)
{
    u8 *s = func_0203D788();
    int r = (*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);

    if (r < 0) {
        func_0203C0DC(p, (u32)r);
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C05C, 0, 0x72E);
    } else if (r > 0) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C464, 0, 0x737);
    }
}



/*
 * Promoted from src/pending/ on lane 1.  Every concrete byte is right; the one
 * open site was the `bl` to 0x02037700, whose only branch anywhere in the
 * image is this one, so `label` had no outside witness.  With
 * src/matched/func_02037700.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C864.c \
 *       --func func_0203C864 --addr 0x0203C864 --cc 1.1p1 --arm
 */
void func_0203C864(void)
{
    u8 *p = func_0203D798();

    if (func_02037700(0x200, ((struct Obj15970 *)p)->f56) == 0)
        return;

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C7E0, 0, 0x74A);
}



/*
 * 140 bytes, three functions.  The middle one, 0x0203C8E8, is a 16-byte leaf
 * that saves nothing and so carries no label in the generated listing; the
 * per-function file for 0x0203C8A8 therefore reported an `EXACT*`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203C8A8.c \
 *       --addr 0x0203C8A8 --arm --cc 1.1p1
 */
void func_0203C8A8(void)
{
    if (func_020392EC() != 0)
        return;

    func_0203D798();
    func_0203516C(1);
    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C864, 0, 0x760);
}



void func_0203C8E8(u8 v)
{
    if (g_021469DC != 0)
        g_021469DC[0x4F] = v;
}



void func_0203C900(u8 v)
{
    u8 *s = func_0203D788();

    if (g_021469DC != 0)
        g_021469DC[0x50] = v;

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x8C))(v);
}


void func_0203C934(void){ }



/*
 * Opens the state: with no live object the answer is 0, otherwise the mode
 * byte at +0x4D is written, the two setup calls run and the answer is 1.
 * src/matched/func_0203C968.c is the matching close.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C938.c \
 *       --func func_0203C938 --addr 0x0203C938 --cc 1.1p1 --arm
 */
u32 func_0203C938(u8 mode)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    if (p == 0)
        return 0;
    p[0x4D] = mode;
    func_02039548();
    func_02039578();
    return 1;
}



/*
 * Closes the state src/matched/func_0203C938.c opens: clears the mode byte and
 * runs the teardown call.  With no live object it is a bare `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C968.c \
 *       --func func_0203C968 --addr 0x0203C968 --cc 1.1p1 --arm
 */
void func_0203C968(void)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    if (p == 0)
        return;
    p[0x4D] = 0;
    func_02039560();
}



/*
 * The mode byte src/matched/func_0203C938.c writes, read back - 0 when there
 * is no object.  Both loads are conditional, so the function is two
 * instructions plus the two pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C990.c \
 *       --func func_0203C990 --addr 0x0203C990 --cc 1.1p1 --arm
 */
u32 func_0203C990(void)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    return p ? p[0x4D] : 0;
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C9AC.c \
 *       --func func_0203C9AC --addr 0x0203C9AC --cc 1.1p1 --arm
 */
void func_0203C9AC(int a, u32 b, u32 c, u32 d)
{
    if (g_021469DC == 0)
        return;

    if ((u32)(a - 0x3ED) > 1)
        a = -a;

    *(u32 *)(g_021469DC + 0x30) = (u32)a;
    *(u32 *)(g_021469DC + 0x34) = b;
    *(u32 *)(g_021469DC + 0x38) = c;
    *(u32 *)(g_021469DC + 0x3C) = d;

    if (d != 0)
        func_02039548();
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA04.c \
 *       --func func_0203CA04 --addr 0x0203CA04 --cc 1.1p1 --arm
 */
void func_0203CA04(void)
{
    u8 *q;
    u32 t;

    if (g_021469DC == 0)
        return;

    q = func_0203D798();

    t = 0;
    if ((u8)(q[0x65] + 0xFF) <= 5) {
        if (((1 << (u8)(q[0x65] + 0xFF)) & 0x23) != 0)
            t = 1;
    }

    if (t == 0)
        func_02034714((const char *)((u32)g_020A7BA8), 0x8B7, (const char *)((u32)g_020A7BEC));

    *(u32 *)(g_021469DC + 0x30) = 0;
    *(u32 *)(g_021469DC + 0x34) = 0;
    *(u32 *)(g_021469DC + 0x38) = 0;
    *(u32 *)(g_021469DC + 0x3C) = 0;
}
