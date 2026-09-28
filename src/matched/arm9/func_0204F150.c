/*
 * function: func_0204F150
 * address:  0x0204F150
 * packet:   pkt_0204F150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020470D0   0x020470D0  arm
 *   func_02046EFC   0x02046EFC  arm
 *
 * The direct form of the entry teardown: release the 0x28-byte entry's first
 * word if it is live, zero it, and stamp 5 into the halfword-style state word
 * at +0x14, which is what func_0204EE0C's scan looks for.
 *
 * Every access re-reads the descriptor's +4 word, so the source spells the
 * base out at each use instead of binding it to a pointer local; the two
 * release calls take a fresh read of the entry's first word each, since the
 * first call may have changed it.  The value the `cmp` tested is the one the
 * first call receives, which is why there is no reload between them.
 *
 * The sibling entry points are func_0204F1A0 (guarded, through two
 * function-pointer globals) and func_0204F214 (unguarded, same two globals);
 * neither is contiguous with this one.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020470D0(u32 v);
extern void func_02046EFC(u32 v);

void func_0204F150(u8 *a0, int i)
{
    u32 off = i * 0x28;

    if (*(u32 *)(*(u32 *)(a0 + 4) + off) != 0) {
        func_020470D0(*(u32 *)(*(u32 *)(a0 + 4) + off));
        func_02046EFC(*(u32 *)(*(u32 *)(a0 + 4) + off));
        *(u32 *)(*(u32 *)(a0 + 4) + off) = 0;
    }
    *(u32 *)(*(u32 *)(a0 + 4) + off + 0x14) = 5;
}
