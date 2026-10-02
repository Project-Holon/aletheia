/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x0200530C
 * packet:   pkt_020051D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200530C
 *
 * symbols:
 *   sub_02005C28  0x02005C28  thumb
 *   sub_02008390  0x02008390  thumb
 *
 * One function of the boot path, 26 bytes: a test on a two-bit field of the
 * object passed in r0 (sub_02008390 reads it), whose two arms pass 1 and 0
 * to the same one argument routine.  Both arms keep their own call and their
 * own `pop`, which is what an `if`/`else` with a call in each arm compiles to;
 * they are not tail merged, so the call is inside the arms in the source and
 * not written once after the test.
 *
 * The polarity is fixed by the fall through, per
 * docs/idioms/the-fall-through-arm-is-the-source-order.md: the branch is
 * `bne`, so the `== 0` arm is the one the source wrote first and it is the arm
 * that passes 1.
 *
 * It is a range of one function because both of its neighbours are held open
 * by attestation, not because the original file stops here.  See the near miss
 * register in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200530C.c \
 *       --addr 0x0200530C --thumb
 */

typedef unsigned int u32;

extern u32  sub_02008390(void *obj);
extern void sub_02005C28(u32 on);

void sub_0200530C(void *obj)
{
    if (sub_02008390(obj) == 0) {
        sub_02005C28(1);
    } else {
        sub_02005C28(0);
    }
}
