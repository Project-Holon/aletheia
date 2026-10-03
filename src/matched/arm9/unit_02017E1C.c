/*
 * unit:     yes
 * address:  0x02017E1C
 * packet:   pkt_02017E1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02017E1C
 *
 * 0x02017E1C..0x02017E40, 36 bytes, one function.
 *
 * The read wrapper for the party area of the 0xDC byte record: unlock, call
 * the party-area dispatcher func_02018DB4 (src/matched/sub_02018DB4.c), lock
 * again and return its result.  It is the exact counterpart of func_02017E88
 * in src/matched/unit_02017E64.c, which does the same around func_02018E34,
 * and it is the entry point 240 call sites in the image use.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E2E is the only
 * branch to func_02018DB4 anywhere in the image, so the `label` class has no
 * witness once the compared range holds it, and the range cannot be cut
 * smaller than the one function.  The `matched` class carries it instead:
 * 0x02018DB4 is src/matched/sub_02018DB4.c, an EXACT entry whose own byte
 * comparison covered a range this file does not touch, so the witness is our
 * compiled proof rather than anything inside 0x02017E1C..0x02017E40.  Its
 * setter twin src/matched/unit_02017E40.c closes the same way over
 * func_02019308.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E1C.c \
 *       --addr 0x02017E1C --thumb
 *
 * symbols:
 *   func_02018DB4  0x02018DB4  thumb
 */

typedef unsigned int u32;

struct Mon;
struct Sav;
extern u32 func_02018D10(struct Sav *p);
extern void func_02018D6C(struct Sav *p);
extern u32 func_02018DB4(struct Mon *p, u32 id, u32 v);

u32 func_02017E1C(void *p, u32 id, u32 v)
{
    u32 r;

    func_02018D10(p);
    r = func_02018DB4(p, id, v);
    func_02018D6C(p);
    return r;
}
