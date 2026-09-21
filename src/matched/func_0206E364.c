/*
 * function: func_0206E364
 * address:  0x0206E364
 * packet:   pkt_0206E364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0010 PC24 func_02069C14           -> unresolved: 02069C14 (arm, from header) has no witness outside 0206E364..0206E388
 *
 * symbols:
 *   func_02069C14    0x02069C14  arm
 *   func_02061330    0x02061330  arm
 *
 * Forwards the two tail arguments through func_02069C14 and hands the result,
 * with the first argument, to func_02061330 -- the argument shuffle is why the
 * first parameter moves into r4 before either call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E364.c \
 *       --func func_0206E364 --addr 0x0206E364 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 func_02069C14(u32 a, u32 b);
extern void func_02061330(u32 a, u32 b);

void func_0206E364(u32 a, u32 b, u32 c)
{
    func_02061330(a, func_02069C14(b, c));
}
