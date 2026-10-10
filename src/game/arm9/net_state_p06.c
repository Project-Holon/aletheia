/*
 * file:     net_state_p06.c
 * unit:     yes
 * function: func_0203B6EC, func_0203B758, func_0203B794, func_0203B7F8, func_0203B868, func_0203B90C, func_0203B950, func_0203B9D4, func_0203BA98, func_0203BBB0, func_0203BC58, func_0203BCE0, func_0203BD30, func_0203BDEC, func_0203BE5C, func_0203BEAC, func_0203BEC8, func_0203BF4C, func_0203BF9C, func_0203BFF0, func_0203C00C
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
 *   MI_CpuCopy8     0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203AEEC   0x0203AEEC  arm
 */
struct Entry;
struct Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

typedef signed int     s32;

typedef unsigned long long u64;

typedef signed char s8;

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
    u8   pad4E;
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

extern u8 *func_0203D788(void);
extern void func_0203AD80(struct NetState *s, void *p, u32 v, int line);
extern u32 func_02037894(u32 a, u32 b, u32 c, u32 d);
extern int func_0203B6B4(void);
extern void func_0203B688(struct NetState *p);
extern void *func_0203D798(void);
extern int func_02039ACC(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern u32 func_0203D650(void);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_020399EC(u32 a);
extern u16 func_02039338(void);
extern int func_0203DA4C(void);
extern u32  func_020377B8(u8);
extern void func_0203B01C(void);
extern u32  func_02037928(u32, u16);
extern u32 func_02037A6C(u32, u32, u16, u32);
extern void func_0203B5D4(struct NetState *p);
extern void func_0203B48C(void);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern int func_0203CEAC(int a0);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_0203AEEC(struct NetState *p);
void func_0203B6EC(struct NetState *p);
void func_0203B758(void);
void func_0203B794(struct NetState *p);
void func_0203B7F8(struct NetState *p);
void func_0203B868(struct NetState *p);
void func_0203B90C(void);
void func_0203B950(struct NetState *p);
void func_0203B9D4(struct NetState *p);
void func_0203BA98(u16 a0, u32 a1, u8 a2);
void func_0203BBB0(struct NetState *a);
void func_0203BC58(u8 v56, u8 v53, const void *src);
void func_0203BCE0(struct NetState *p);
void func_0203BD30(u32 a0, u32 a1, u8 *a2);
void func_0203BDEC(void);
void func_0203BE5C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0203BEAC(void);
void func_0203BEC8(struct NetState *p);
void func_0203BF4C(void);
void func_0203BF9C(u32 v);
void func_0203BFF0(void);
void func_0203C00C(void);
extern struct NetState *g_021469DC;




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B6EC.c \
 *       --func func_0203B6EC --addr 0x0203B6EC --cc 1.1p1 --arm
 */
void func_0203B6EC(struct NetState *p)
{
    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0x78))() == 0)
        return;
    if (func_02037894(0, 0x200, 0, (u32)func_0203B6B4) == 0)
        return;

    p->f4C = 0;
    func_0203AD80(g_021469DC, (void *)func_0203B688, 0x1E, 0x2FC);
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

    func_0203AD80(g_021469DC, (void *)0x0203B794, 0, 0x30E);
}




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B794.c \
 *       --func func_0203B794 --addr 0x0203B794 --cc 1.1p1 --arm
 */
void func_0203B794(struct NetState *p)
{
    u8 *s = func_0203D798();

    if (func_020399B8((u8 *)((u32)func_020399A8())) == 0)
        return;

    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C00C, 0, 0x325);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B7F8.c \
 *       --func func_0203B7F8 --addr 0x0203B7F8 --cc 1.1p1 --arm
 */
void func_0203B7F8(struct NetState *p)
{
    func_0203D798();

    func_0203996C(0xFF);
    if ((int)func_020399EC((u32)func_020399A8()) < 2)
        return;

    func_02039338();

    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C00C, 0, 0x33F);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B868.c \
 *       --func func_0203B868 --addr 0x0203B868 --cc 1.1p1 --arm
 */
void func_0203B868(struct NetState *p)
{
    func_0203D798();

    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0xA8))() != 1)
        return;
    if (func_02039ACC() == 0)
        return;

    if (func_0203DA4C() == 1) {
        func_0203AD80(g_021469DC, (void *)0x0203B7F8, 0, 0x354);
        return;
    }

    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }

    func_0203AD80(g_021469DC, (void *)0x0203C00C, 0, 0x35B);
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

    func_0203AD80(g_021469DC, (void *)0x0203B6EC, 0, 0x371);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B950.c \
 *       --func func_0203B950 --addr 0x0203B950 --cc 1.1p1 --arm
 */
void func_0203B950(struct NetState *p)
{
    if (func_02039338() != 0) {
        func_0203AD80(g_021469DC, (void *)0x0203B758, 0, 0x383);
        return;
    }

    if (p->f56 == 2)
        return;

    if (p->f46 != 0) {
        p->f46--;
        return;
    }

    func_0203AD80(g_021469DC, (void *)0x0203BCE0, 0, 0x390);
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
void func_0203B9D4(struct NetState *p)
{
    u8 *s = func_0203D788();
    u64 x, y, r;

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0xAC))() == 1) {
        (*(void (**)(void))(*(u32 *)(s + 0x340) + 0xB4))();
        func_0203AD80(g_021469DC, (void *)0x0203B868, 0, 0x3A5);
        return;
    }

    if (p->f46 != 0) {
        p->f46 = p->f46 - 1;
        return;
    }

    x = p->rng.x;
    y = p->rng.mul;
    r = y * x + p->rng.add;

    p->f46 = (u16)((u32)(((u64)(u32)(r >> 32) * 30) >> 32) + 15);
    p->rng.x = r;

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x08))(0);
}



void func_0203BA98(u16 a0, u32 a1, u8 a2)
{
    u8 *s = func_0203D798();
    struct NetState *p;
    u64 x, y, r;
    u32 delay = 30;

    func_0203D788();
    func_0203BC58(0, a2, 0);

    if (s[0x65] == 3 || s[0x65] == 4) {
        func_020377B8(0);
        g_021469DC->f2C = (void (*)(u32))a1;
        p = g_021469DC;
        x = p->rng.x;
        y = p->rng.mul;
        r = y * x + p->rng.add;
        p->rng.x = r;
        func_0203AD80(p, (void *)func_0203B9D4, (u32)(((u64)(u32)(r >> 32) * delay) >> 32), delay + 0x3A8);
    } else {
        p = g_021469DC;
        if (p->f53 != 0 && p->f56 != 1) {
            func_02037A6C(1, (u32)p->addr, 0x200, (u32)func_0203B01C);
        } else {
            func_02037928(1, 0x200);
        }
        g_021469DC->f2C = (void (*)(u32))a1;
        p = g_021469DC;
        func_0203AD80(p, (void *)func_0203B950, delay, delay + 0x3B4);
    }
}




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
void func_0203BBB0(struct NetState *a)
{
    u8 *s = func_0203D788();
    struct NetState *g;

    g = g_021469DC;
    if (g->f56 == 2 && g->f08 == func_0203B950) {
        if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) != 0) {
            func_0203AD80(g_021469DC, ((void *)func_0203B90C), 0, 0x3E0);
        }
    }

    g = g_021469DC;
    if (g->f56 == 1 && g->f08 == func_0203B5D4) {
        func_0203AD80(g, ((void *)func_0203B48C), 0, 0x3E9);
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
    g_021469DC->f53 = v53;
    g_021469DC->f56 = v56;

    if (src != 0) {
        MI_CpuCopy8(src, g_021469DC->addr, 6);
    } else {
        MI_CpuFill8(g_021469DC->addr, 0xFF, 6);
    }

    func_0203AD80(g_021469DC, ((void *)0x0203BBB0), 0, 0x406);
    func_0203BBB0(g_021469DC);
}





/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BCE0.c \
 *       --func func_0203BCE0 --addr 0x0203BCE0 --cc 1.1p1 --arm
 */
void func_0203BCE0(struct NetState *p)
{
    u8 *s = func_0203D788();

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) == 0)
        return;

    func_0203AD80(g_021469DC, ((void *)0x0203B90C), 0, 0x411);
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

    g_021469DC->f53 = (u8)a1;
    g_021469DC->f56 = (u8)a0;

    if (a2 != 0)
        MI_CpuCopy8(a2, g_021469DC->addr, 6);
    else
        MI_CpuFill8(g_021469DC->addr, 0xFF, 6);

    if (g_021469DC->f56 == 2)
        func_0203AD80(g_021469DC, ((void *)0x0203B48C), 0, 0x430);

    if (g_021469DC->f56 == 1) {
        func_0203AD80(g_021469DC, ((void *)0x0203BCE0), 0, 0x438);
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

    func_0203AD80(g_021469DC, ((void *)0x0203BDEC), 0, 0x46C);
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
void func_0203BEC8(struct NetState *p)
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

    func_0203AD80(g_021469DC, ((void *)0x0203BEC8), 0, 0x4A4);
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
    struct NetState *p = g_021469DC;

    if (p != 0 && p->f51 != 0)
        return;

    p->f28 = (void (*)(void))v;
    g_021469DC->f51 = 1;
    func_0203AD80(g_021469DC, ((void *)func_0203BF4C), 5, 0x4B7);
}





void func_0203BFF0(void)
{
    if (g_021469DC != 0)
        g_021469DC->f51 = 0;
}





void func_0203C00C(void)
{
}
