/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005DF8
 * packet:   pkt_02005DAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005DF8, sub_02005E04
 *
 * symbols:
 *   sub_02005E04_State  0x020AA260  data
 *   sub_02005FBC        0x02005FBC  thumb
 *   sub_0200590C        0x0200590C  thumb
 *   func_02072F5C       0x02072F5C  arm
 *
 * Two of the five functions of the range the header of
 * src/matched/unit_02005DAC.c recorded as a near miss.  sub_02005E04 sets the
 * link's two power levels and remembers the first of them in the state block;
 * sub_02005DF8 is the twelve byte forwarder that supplies the fixed second
 * argument 0x7F.
 *
 * Why this is its own byte range, and where the file boundary comes from.
 * func_02072F5C is reached from exactly three `blx` sites in the whole image:
 * 0x02005E16 and 0x02005E22 inside sub_02005E04, and 0x02005E40 inside
 * sub_02005E30.  Matched as one range with sub_02005E30 all three witnesses
 * are inside the bytes under test, the honesty rule discards them all and the
 * range caps at MATCH.  Cut here, each of the two files is the other's
 * witness and both come out EXACT: this file's two sites attest
 * src/matched/unit_02005E30.c and that file's one site attests these two.
 * The cut cannot go anywhere else, because sub_02005DF8's pool word is the
 * only reference to sub_02005E04 in the image, so those two have to share a
 * range and be `local` to each other.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, and
 * `python tools/match.py tu --suggest-split`, which is what found the cut.
 *
 * sub_02005DE4, the function immediately before this range, stays open and is
 * deliberately not in this file.  It is the only caller of 0x02072E8C
 * anywhere in the image, so the single witness for that call is the call
 * itself: no cut can put it outside the range under test, and the address is
 * an ARM library routine that cannot be made `local` either.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005DF8.c \
 *       --addr 0x02005DF8 --thumb
 */

typedef unsigned int u32;

/* The wireless state block; src/matched/unit_02005F38.c has the whole of it,
 * this file touches one word. */
struct Sub02005E04State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

extern struct Sub02005E04State sub_02005E04_State;

extern void sub_02005FBC(void);
extern u32 *sub_0200590C(void);
extern void func_02072F5C(u32 *req, u32 a, u32 b);

void sub_02005E04(u32 a, u32 b);

void sub_02005DF8(u32 a)
{
    sub_02005E04(a, 0x7F);
}

void sub_02005E04(u32 a, u32 b)
{
    sub_02005FBC();
    func_02072F5C(sub_0200590C(), 0, 0);
    func_02072F5C(sub_0200590C(), b, a);
    sub_02005E04_State.unk08 = a;
}
