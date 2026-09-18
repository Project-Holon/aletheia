/*
 * function: func_0206E364
 * address:  0x0206E364
 * packet:   pkt_0206E364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  label -- func_02069C14 (0x02069C14, arm) has no witness outside
 *           0206E364..0206E388: this function's `bl` is its only call site in
 *           the image, so the relocation stays wildcarded.  Byte-correct
 *           otherwise (36 of 36 bytes, one wildcarded PC24).
 *
 * symbols:
 *   func_02069C14   0x02069C14  arm
 *   func_02061330   0x02061330  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206E364.c \
 *       --func func_0206E364 --addr 0x0206E364 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 func_02069C14(u32 a, u32 b);
extern void func_02061330(void *o, u32 v);

void func_0206E364(void *o, u32 a, u32 b)
{
    func_02061330(o, func_02069C14(a, b));
}
