/*
 * function: func_020266E0
 * address:  0x020266E0
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0xbb4-byte beacon system block on the caller's heap and
 * publishes it through g_02146940, after releasing any previous one.
 *
 * The two spellings that decided it:
 *   - the third argument (1) is bound to a NAMED local `one`, which keeps
 *     it alive in the callee-saved r4 across the call to func_02030734;
 *     the trailing -1 store is then derived from it as `subs r2, r4, #2`.
 *     Written as a plain -1 / 0xff / (u8)-1, the compiler folds it to
 *     `movs r2, #0xff` before the call and the r4/r5 assignment flips.
 *   - 0xbb4 stays a plain integer literal: the compiler pools it of its
 *     own accord, so no absolute linker symbol is needed (an earlier
 *     attempt that declared it as `extern char sBeaconSize[]` produced
 *     the same 72 bytes but capped at MATCH on that unattestable ABS32).
 *
 * 0x020A74BC resolves through sole-ref; 0x020A74C0 is the __FILE__ string.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   g_02146940     0x02146940  data
 *   g_020A74BC     0x020A74BC  data
 *   g_020A74C0     0x020A74C0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char  *g_02146940;
extern char   g_020A74BC[];
extern char   g_020A74C0[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void func_020266E0(u32 a0)
{
    u32 one = 1;

    if (g_02146940 != 0) {
        func_02034714(g_020A74BC, 0, g_020A74BC);
    }
    g_02146940 = func_02030734(a0, 0xbb4, one, g_020A74C0, 0x5a);
    g_02146940[0xbb4 - 7] = (u8)(one - 2);
}
