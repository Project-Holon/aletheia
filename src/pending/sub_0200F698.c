/*
 * function: sub_0200F698
 * address:  0x0200F698
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0203D29C  0x0203D29C  arm
 *   func_02156B70  0x02156B70  thumb
 *   func_02005F24  0x02005F24  thumb
 *
 * Forwards its two arguments to func_02005F24 unless both func_0203D29C()
 * and func_02156B70() report nonzero; func_0203D29C is always called,
 * func_02156B70 only when the first call reports zero (a genuine
 * short-circuit, not an independent second check).
 *
 * Every concrete byte matches; func_02156B70 is called from exactly this
 * one site in the whole ROM, so that relocation stays unresolved under
 * the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200F698.c \
 *       --func sub_0200F698 --addr 0x0200F698 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_02156B70 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day either
 * func_02156B70 gets a second caller elsewhere in the image, or is itself
 * matched.
 */

typedef unsigned int u32;

extern u32  func_0203D29C(void);
extern u32  func_02156B70(void);
extern void func_02005F24(void *a, void *b);

void sub_0200F698(void *a, void *b)
{
    if (func_0203D29C() == 0 || func_02156B70() == 0) {
        func_02005F24(a, b);
    }
}
