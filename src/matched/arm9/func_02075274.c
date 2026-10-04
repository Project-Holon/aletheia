/*
 * function: func_02075274
 * address:  0x02075274
 * packet:   pkt_0207524C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0020 PC24 func_020896CC           -> unresolved: 020896CC (arm, from header) has no witness outside 02075274..020752A4; +0028 PC24 func_0208A38C           -> unresolved: 0208A38C (arm, from header) has no witness outside 02075274..020752A4
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   func_020751F4    0x020751F4  arm
 *   func_020896CC    0x020896CC  arm
 *   func_0208A38C    0x0208A38C  arm
 *
 * The bank flavour: same range invalidate plus the bank teardown.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02075274.c \
 *       --func func_02075274 --addr 0x02075274 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_020751F4(u32 a, u32 b, u32 c);
extern void func_020896CC(const void *start, const void *end);
extern void func_0208A38C(u8 *p);

void func_02075274(u8 *p, u32 len, u32 b, u32 c)
{
    func_020751F4((u32)p, b, c);
    func_020896CC(p, p + len);
    func_0208A38C(p);
}
