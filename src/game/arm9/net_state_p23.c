/*
 * file:     net_state_p23.c
 * unit:     yes
 * function: sub_020393D0, func_02039414, func_02039468, func_020394C0
 * address:  0x020393D0
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
 *   unk_021469D0   0x021469D0  data
 *   g_021469D0   0x021469D0  data
 *   func_0203D798 0x0203D798 arm
 *   func_02036B98 0x02036B98 arm
 *   func_020366A8  0x020366A8  arm
 */
#include "../../matched/include/Obj15941.h"

struct Conn;
typedef unsigned char u8;

struct LinkState {
    u8 pad000[0x1e9];
    u8 unk_1e9;
};

struct LinkDriver {
    u8 pad00[0x88];
    int (*busy)(void);
};

struct LinkRoot {
    u8 pad000[0x340];
    struct LinkDriver *driver;
};

typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern int func_02036B98(char *p, int v);
extern int func_020366A8(struct Conn *p);
int sub_020393D0(void);
u32 func_02039414(void);
void func_02039468(u32 a, u32 b);
int func_020394C0(void);
extern struct LinkState *unk_021469D0;
extern u8 *g_021469D0;


/*
 * Is the link busy?  The +0x1e9 flag on the link state forces a yes, and
 * otherwise the driver's own predicate at +0x88 decides.
 *
 * The two halves of the flag test share one `ne` chain and a single `popne`,
 * so they are one `&&` rather than nested `if`s.  func_0203D788 is called
 * before the flag is even read because its result is needed on the fall
 * through path, and the compiler will not sink a call past a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020393D0.c \n *       --func sub_020393D0 --addr 0x020393D0 --cc 1.1p1 --arm
 */
int sub_020393D0(void)
{
    struct LinkRoot *root;

    root = func_0203D788();

    if (unk_021469D0 != 0 && unk_021469D0->unk_1e9 != 0) {
        return 1;
    }
    return root->driver->busy() != 0;
}



/*
 * Asks the transport's +0x88 virtual whether the link is up, falling back to
 * the +0x1E9 flag of the object at 0x021469D0 when the virtual is missing or
 * answers zero.  Both re-tests are conditional-execution chains (`cmpne`), so
 * the source is the `!= 0 && ...` spelling in each place.  The result local
 * is declared after the context refresh and assigned at its first use: with
 * `u32 r = 0;` ahead of the refresh the value is live across func_0203D788
 * and the allocator spends a callee-saved register on it (`push {r4, lr}`
 * instead of the original's `push {r3, lr}`).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039414.c  *       --func func_02039414 --addr 0x02039414 --cc 1.1p1 --arm
 */
u32 func_02039414(void)
{
    u8 *p = func_0203D788();
    u32 r = 0;

    if (p != 0 && ((struct Obj15941 *)p)->f340 != 0)
        r = ((u32 (*)(void))*(u32 *)(*(u32 *)(p + 0x340) + 0x88))();
    if (r == 0) {
        u8 *q = *(u8 **)(0x21469D0);

        if (q != 0 && q[0x1E9] != 0)
            r = 1;
    }
    return r;
}



void func_02039468(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0203D798();

    if (s[0x64] != 0 && b == 0xff) {
        func_02036B98((char *)(g_021469D0 + 0xf4), a);
    } else {
        func_02036B98((char *)(g_021469D0 + 0xcc), a);
    }
}



/*
 * Leaf that saves no lr: tail-calls func_020366A8 on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, fCC).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */
int func_020394C0(void)
{
    return func_020366A8((struct Conn *)(g_021469D0 + 0xCC));
}
