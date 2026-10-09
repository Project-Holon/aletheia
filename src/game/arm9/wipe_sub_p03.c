/*
 * file:     wipe_sub_p03.c
 * unit:     yes
 * function: func_020224DC, func_02022518, func_02022568, func_020225B4
 * address:  0x020224DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021468A4     0x021468A4  data
 *   func_020225F0  0x020225F0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   g_020A73C8     0x020A73C8  data
 *   func_020225D4  0x020225D4  thumb
 *   func_020307B0  0x020307B0  arm
 */
struct Node;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef void (*Handler)(void);

struct Slots {
    void   *ctx[2];
    Handler fn[2];
    u32     arg[2];
};

struct G021468A4 {
    u8    pad00[0x54];
    void *f54;
};

typedef unsigned short u16;

extern void func_020225F0(void);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020056A0(void *a0, void *a1, u32 a2);
extern int func_020225D4(int a0, int a1, int a2, int a3);
void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_02022568(u32 a0, u32 a1, u32 a2);
extern void func_02022490(char *p, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
void func_020225B4(void *a0, u32 *a1);
extern struct G021468A4 g_021468A4;
extern char  g_020A73C8[];



/*
 * Drops one entry of the two-slot callback block func_02022458 arms (the
 * 0x18-byte object at +0x74 of the dual-screen cluster): three parallel
 * two-element arrays, ctx[] at +0x00, fn[] at +0x08 and arg[] at +0x10.
 * func_020221B8 calls it once per slot during shutdown.
 *
 * It clears this slot's user word FIRST, and only then checks whether both
 * user words have gone to zero; when they have and the vblank/task handle at
 * g_021468A4 +0x54 is still live, it releases that handle through
 * func_02030EAC and nulls it.  The slot's handler is then re-armed with the
 * do-nothing func_020225F0 rather than a null, the same convention
 * func_02022458 uses, and the context pointer cleared last.
 *
 * Shape notes.  The zero written to arg[idx] and the zero written back to
 * +0x54 are one value kept in r6 across the call, which is what makes them
 * one named local rather than two literal zeroes; the final ctx[idx] = 0
 * uses a fresh `movs r0, #0` after the call instead, so it must be written
 * as a plain constant.  The two `adds r0, r5, r4` recomputations of
 * &slot[idx] on either side of the guard are the compiler's own
 * rematerialisation of the scaled index, not two separate cursors; keeping
 * the address in a named local costs a callee-saved register, see
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020224DC.c \
 *       --func func_020224DC --addr 0x020224DC --cc 1.1p1 --thumb
 */
void func_020224DC(struct Slots *p, u32 idx)
{
    u32 zero = 0;

    p->arg[idx] = zero;
    if (p->arg[0] == 0 && p->arg[1] == 0 && g_021468A4.f54 != 0) {
        func_02030EAC(g_021468A4.f54);
        g_021468A4.f54 = (void *)zero;
    }
    p->fn[idx] = func_020225F0;
    p->ctx[idx] = 0;
}


/*
 *           The only branch reaching 0x020225B4 image-wide is this pool word; 0x020225B4
 *           itself is src/pending/func_020225B4.c, MATCH-capped on 0x02022490, so the
 *           'matched' class has nothing to offer. Every concrete byte is identical
 *           (0 concrete diffs, 4/4 relocations correct, 3 resolved).
 */
void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 *p;

    p = (u32 *)func_02030734((u16)(((u16)a4 & 0x7FFF) | 0x8000), 0x10, 0,
                             g_020A73C8, 0x3E8);
    p[0] = a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    func_020056A0((void *)func_020225B4, p, 0x400);
}


void func_02022568(u32 a0, u32 a1, u32 a2)
{
    u32 *p = func_02030734((u16)(((u16)a2 & 0x7fff) | 0x8000), 8, 0, g_020A73C8, 0x401);

    p[0] = a0;
    p[1] = a1;
    func_020056A0((void *)func_020225D4, p, 8 << 7);
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void func_020225B4(void *a0, u32 *a1)
{
    func_02022490((void *)a1[0], (int)((void *)a1[1]), (int)((void *)a1[2]), (int)a1[3]);
    func_02030EAC(a0);
    func_020307B0(a1);
}
