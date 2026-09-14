/*
 * unit:     yes
 * address:  0x02017E40
 * packet:   pkt_02017E1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02017E40
 *
 * 0x02017E40..0x02017E64, 36 bytes, one function.
 *
 * The write wrapper for the party area of the 0xDC byte record, and the twin
 * of src/matched/unit_02017E1C.c: unlock, and only if the unlock reports 1
 * call the party-area setter func_02019308 (src/matched/sub_02019308.c), then
 * lock again.  It is the counterpart of func_02017E64 in
 * src/matched/unit_02017E64.c, which does the same around func_02019388.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E56 is the only
 * branch to func_02019308 anywhere in the image, so no image class could
 * attest it from outside this range.  The `matched` class does:
 * 0x02019308 is src/matched/sub_02019308.c, an EXACT entry proved against the
 * original bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E40.c \
 *       --addr 0x02017E40 --thumb
 *
 * symbols:
 *   func_02019308  0x02019308  thumb
 */

typedef unsigned int u32;

extern u32  func_02018D10(void *p);
extern void func_02018D6C(void *p);
extern void func_02019308(void *p, u32 id, u32 v);

void func_02017E40(void *p, u32 id, u32 v)
{
    if (func_02018D10(p) == 1) {
        func_02019308(p, id, v);
    }
    func_02018D6C(p);
}
