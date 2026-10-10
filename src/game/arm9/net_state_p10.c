/*
 * file:     net_state_p10.c
 * unit:     yes
 * function: func_0203C494, func_0203C554, func_0203C5C8, func_0203C5EC, func_0203C600, func_0203C628, func_0203C65C, func_0203C710, func_0203C774, func_0203C7E0, func_0203C864, func_0203C8A8, func_0203C8E8, func_0203C900, func_0203C934, func_0203C938, func_0203C968, func_0203C990, func_0203C9AC, func_0203CA04
 * address:  0x0203C494
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
 *   func_0203C464  0x0203C464  arm
 *   func_0203C05C  0x0203C05C  arm
 *   unk_021469DC   0x021469DC  data
 *   func_0203C0F4  0x0203C0F4  arm
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_0203AEEC   0x0203AEEC  arm
 *   func_02039548  0x02039548  arm
 *   func_02039578  0x02039578  arm
 *   func_02039560  0x02039560  arm
 *   g_020A7BA8      0x020A7BA8  data
 *   g_020A7BEC      0x020A7BEC  data
 *   func_02034714   0x02034714  arm
 */
#include "../../matched/include/Obj15970.h"

typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed char   s8;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetState {
    u32  f00;
    u32  f04;
    void (*f08)(struct NetState *s);
    MATHRandContext64 rng;
    u32  f24;
    void (*f28)(void);
    void (*f2C)(u32 a);
    u32  err[4];
    u8   mac[6];
    u16  f46;
    s8   flag;
    u8   pad49;
    u8   f4A;
    u8   f4B;
    u8   f4C;
    u8   f4D;
    u8   f4E;
    u8   f4F;
    u8   f50;
    u8   f51;
    u8   pad52;
    u8   f53;
    u8   pad54[2];
    u8   f56;
    u8   addr[6];
    u8   pad5D[7];
};

extern void *func_0203D788(void);
extern int func_0203C464(int a0, int a1, int a2, int a3);
extern void func_0203C05C(void);
extern void func_0203AD80(struct NetState *s, void *p, u32 v, int line);
extern void func_020394DC(u8 v);
extern void func_02037D78(void);
extern void func_020398B4(u32 a);
extern void func_02039834(u32 a);
extern u16 func_02039338(void);
extern void func_0203C0F4(void *p);
extern void *func_0203D798(void);
extern void func_0203AEEC(struct NetState *p);
extern int func_020351A0(u32 v);
extern void func_0203C0DC(struct NetState *p, u32 v);
extern int func_02037700(u32 a0, u32 a1);
extern int  func_020392EC(void);
extern void func_0203516C(u32 a);
extern void func_02039548(void);
extern void func_02039578(void);
extern void func_02039560(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_0203C494(struct NetState *p);
void func_0203C554(u32 a);
void func_0203C5C8(void);
int func_0203C5EC(void);
int func_0203C600(void);
int func_0203C628(void);
void func_0203C65C(struct NetState *p);
void func_0203C710(void);
void func_0203C774(u32 v);
void func_0203C7E0(struct NetState *p);
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
extern struct NetState *g_021469DC;
extern u8  g_020A7BA8[];
extern u8  g_020A7BEC[];





/*
 * The other half of the connect/disconnect pair whose partner is
 * src/matched/func_0203C554.c: it turns the state byte at +0x4B into the
 * vtable's +0x54 hook, then either starts the link layer or, when the +0x0C
 * hook reports a negative result, files line 0x655.
 *
 * `v` is materialised as 0 before the first call and raised to 1 by
 * `moveq` on the state byte's own compare, so the hook's first argument
 * shares a register with the loop's zero rather than being rematerialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C494.c \
 *       --func func_0203C494 --addr 0x0203C494 --cc 1.1p1 --arm
 */
void func_0203C494(struct NetState *p)
{
    u8 *s = func_0203D788();
    u32 v = 0;

    func_020394DC(0);

    if (p->f4B == 0)
        v = 1;

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(v, 0) != 0) {
        func_02037D78();
        func_020398B4((u32)s);
        func_02039834((u32)s);
        func_0203AD80(g_021469DC, (void *)func_0203C464, 0, 0x64F);
    } else if ((*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0) < 0) {
        func_0203AD80(g_021469DC, (void *)func_0203C05C, 0, 0x655);
    }
}





/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C554.c \
 *       --func func_0203C554 --addr 0x0203C554 --cc 1.1p1 --arm
 */
void func_0203C554(u32 a)
{
    struct NetState *p = g_021469DC;

    if (p == 0)
        return;

    if (a != 0) {
        if (func_02039338() == 0)
            g_021469DC->f4B = 0;
        else
            g_021469DC->f4B = 1;
    } else {
        p->f4B = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C494, 0, 0x671);
    func_0203C494(g_021469DC);
}





/*
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C5C8.c \
 *       --func func_0203C5C8 --addr 0x0203C5C8 --cc 1.1p1 --arm
 */
void func_0203C5C8(void)
{
    func_0203C554(1);
    g_021469DC->f4A = 1;
}





/*
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 */
int func_0203C5EC(void)
{
    return g_021469DC->f4A;
}




/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4.
 */
int func_0203C600(void)
{
    return g_021469DC->f08 == (void *)func_0203C0F4;
}




/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4 or func_0203C464.
 */
int func_0203C628(void)
{
    void *cb = g_021469DC->f08;
    return cb == (void *)func_0203C0F4 || cb == (void *)func_0203C464;
}




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C65C.c \
 *       --func func_0203C65C --addr 0x0203C65C --cc 1.1p1 --arm
 */
void func_0203C65C(struct NetState *p)
{
    u8 *s;

    func_0203D798();
    s = func_0203D788();

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(1);

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x78))() != 0) {
        (*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0);
        func_0203AEEC(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x6C))() == 0) {
        (*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0);
        func_0203AEEC(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x74))() == 0)
        return;

    (*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0);
    func_0203AEEC(p);
}




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

    func_0203AD80(g_021469DC, (void *)0x0203C65C, 0, 0x702);
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
    g_021469DC->f28 = (void (*)(void))v;
    (*(void (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(1, 0);

    func_0203AD80(g_021469DC, (void *)0x0203C710, 5, 0x719);
}




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C7E0.c \
 *       --func func_0203C7E0 --addr 0x0203C7E0 --cc 1.1p1 --arm
 */
void func_0203C7E0(struct NetState *p)
{
    u8 *s = func_0203D788();
    int r = (*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);

    if (r < 0) {
        func_0203C0DC(p, (u32)r);
        func_0203AD80(g_021469DC, (void *)0x0203C05C, 0, 0x72E);
    } else if (r > 0) {
        func_0203AD80(g_021469DC, (void *)0x0203C464, 0, 0x737);
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

    func_0203AD80(g_021469DC, (void *)0x0203C7E0, 0, 0x74A);
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
    func_0203AD80(g_021469DC, (void *)0x0203C864, 0, 0x760);
}




void func_0203C8E8(u8 v)
{
    if (g_021469DC != 0)
        g_021469DC->f4F = v;
}




void func_0203C900(u8 v)
{
    u8 *s = func_0203D788();

    if (g_021469DC != 0)
        g_021469DC->f50 = v;

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
    struct NetState *p;

    p = g_021469DC;
    if (p == 0)
        return 0;
    p->f4D = mode;
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
    struct NetState *p;

    p = g_021469DC;
    if (p == 0)
        return;
    p->f4D = 0;
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
    struct NetState *p;

    p = g_021469DC;
    return p ? p->f4D : 0;
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

    g_021469DC->err[0] = a;
    g_021469DC->err[1] = b;
    g_021469DC->err[2] = c;
    g_021469DC->err[3] = d;

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

    g_021469DC->err[0] = 0;
    g_021469DC->err[1] = 0;
    g_021469DC->err[2] = 0;
    g_021469DC->err[3] = 0;
}
