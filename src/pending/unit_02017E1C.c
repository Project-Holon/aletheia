/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x02017E1C..0x02017E40, 36 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * The read wrapper for the party area of the 0xDC byte record: unlock, call
 * the party-area dispatcher func_02018DB4 (src/matched/sub_02018DB4.c), lock
 * again and return its result.  It is the exact counterpart of func_02017E88
 * in src/matched/unit_02017E64.c, which does the same around func_02018E34,
 * and it is the entry point 240 call sites in the image use.
 *
 * Why it is capped: the `bl` at 0x02017E2E is the only branch to func_02018DB4
 * anywhere in the image, so the `label` class has no witness once the compared
 * range holds it, and the range cannot be cut smaller than the one function.
 * Its setter twin at 0x02017E40 has the same problem with func_02019308; the
 * two do not attest each other, because they call different functions.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02017E1C.c \
 *       --addr 0x02017E1C --thumb
 *
 * symbols:
 *   func_02018DB4  0x02018DB4  thumb
 */

typedef unsigned int u32;

extern u32  func_02018D10(void *p);
extern void func_02018D6C(void *p);
extern u32  func_02018DB4(void *p, u32 id, u32 v);

u32 func_02017E1C(void *p, u32 id, u32 v)
{
    u32 r;

    func_02018D10(p);
    r = func_02018DB4(p, id, v);
    func_02018D6C(p);
    return r;
}
