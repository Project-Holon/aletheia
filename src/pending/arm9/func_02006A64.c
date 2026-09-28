/*
 * function: func_02006A64
 * address:  0x02006A64
 * packet:   pkt_02006948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02140488  0x02140488  data
 *   func_02006868  0x02006868  thumb
 *   func_02006948  0x02006948  thumb
 *
 * Free voice `idx`: 0x34-byte entries off the global at 0x02140488.  The
 * index is scaled into the parameter rather than into a pointer local, and
 * the base + index expression is recomputed for the second call, so the
 * source wrote the address expression twice.  The test is on the *word* at
 * +0 of the entry (`[r0]` through the same base register), not on the call
 * result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006A64.c \
 *       --func func_02006A64 --addr 0x02006A64 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char g_02140488[];
extern int  func_02006868(void *voice);
extern void func_02006948(void *voice);

int func_02006A64(u32 idx)
{
    if (func_02006868(g_02140488 + 0x34 * idx) == 0) {
        func_02006948(g_02140488 + 0x34 * idx);
        return 0;
    }
    return 1;
}
