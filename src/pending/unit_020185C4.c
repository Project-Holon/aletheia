/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x020185C4..0x020185F0, 44 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * Why it is capped: this is the only caller of func_02018A7C in the image, so
 * the `label` class discards its only witness under the honesty rule and no
 * cut helps.  It closes the day the image acquires a second caller, or the
 * day func_02018A7C lands in a range that contains this call.
 *
 * The shape is the lock/recompute/unlock sandwich the whole region uses:
 * func_02017D30 takes the lock and returns whether it actually took it, and
 * that flag is what func_02017D70 is handed back.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_020185C4.c \
 *       --addr 0x020185C4 --thumb
 *
 * symbols:
 *   func_02017D30  0x02017D30  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018430  0x02018430  thumb
 *   func_02018A7C  0x02018A7C  thumb
 */

typedef unsigned int u32;

extern u32  func_02017D30(void *p);
extern u32  func_02017D70(void *p, u32 f);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32  func_02018430(void *p);
extern void func_02018A7C(void *p);

void func_020185C4(void *p)
{
    u32 f = func_02017D30(p);

    func_02017E40(p, 0x9E, func_02018430(p));
    func_02018A7C(p);
    func_02017D70(p, f);
}
