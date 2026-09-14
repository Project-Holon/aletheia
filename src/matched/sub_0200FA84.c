/*
 * function: sub_0200FA84
 * address:  0x0200FA84
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010054  0x02010054  thumb
 *
 * Guard: if func_02010054() reports nonzero, calls the abort path
 * sub_0200FA94.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FA84.c \
 *       --func sub_0200FA84 --addr 0x0200FA84 --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  func_02010054(void);
extern void sub_0200FA94(void);

void sub_0200FA84(void)
{
    if (func_02010054() != 0) {
        sub_0200FA94();
    }
}
