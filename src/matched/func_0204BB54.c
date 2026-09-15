/*
 * function: func_0204BB54
 * address:  0x0204BB54
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204BB38  0x0204BB38  arm
 *   func_0204BD18  0x0204BD18  arm
 *   func_0204BB20  0x0204BB20  arm
 *
 * Drop the singleton's +0xfc latch: if it is set, release the two OAM
 * sub-records hanging off the singleton itself and clear the latch.
 *
 * Two early returns, each predicated into its own `popeq`, so they are two
 * separate `if`s rather than one `&&`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * is the opposite shape: one shared exit block).  The address of the global
 * is held in r4 across both calls, but the pointer itself is re-read for the
 * third call because func_0204BB38 may have stored to it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB54.c \
 *       --func func_0204BB54 --addr 0x0204BB54 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8 pad_000[4];
};

extern struct Sys *g_02146A74;

extern u32  func_0204BB38(void);
extern void func_0204BD18(struct Sys *s);
extern void func_0204BB20(u32 v);

void func_0204BB54(void)
{
    if (g_02146A74 == 0) {
        return;
    }
    if (func_0204BB38() == 0) {
        return;
    }

    func_0204BD18(g_02146A74);
    func_0204BB20(0);
}
