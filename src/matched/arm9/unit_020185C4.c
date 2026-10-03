/*
 * unit:     yes
 * address:  0x020185C4
 * packet:   pkt_020185C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020185C4
 *
 * 0x020185C4..0x020185F0, 44 bytes, one function.
 *
 * The shape is the lock/recompute/unlock sandwich the whole region uses:
 * func_02017D30 takes the lock and returns whether it actually took it, and
 * that flag is what func_02017D70 is handed back.  Between them it refreshes
 * the level (id 0x9E, from func_02018430) and then recalculates the six stats
 * with func_02018A7C.
 *
 * What held it open, and what closed it: this is the only caller of
 * func_02018A7C anywhere in the image, so the `label` class discards its only
 * witness under the honesty rule and no cut helps, because the range cannot be
 * made smaller than the one function that holds the call.  The `matched` class
 * carries it now: 0x02018A7C is src/matched/sub_02018A7C.c, an EXACT entry
 * proved byte for byte against the original over a range this file does not
 * touch.  It was parked in src/pending/ until that entry existed.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020185C4.c \
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

struct Sav;
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
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
