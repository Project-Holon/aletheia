/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005E30
 * packet:   pkt_02005DAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005E30
 *
 * symbols:
 *   sub_02005E30_State  0x020AA260  data
 *   sub_02005FBC        0x02005FBC  thumb
 *   sub_0200590C        0x0200590C  thumb
 *   func_02072F5C       0x02072F5C  arm
 *
 * The one-level form of src/matched/unit_02005DF8.c's sub_02005E04: the same
 * state settle, one call instead of two, and the same word of the state block
 * written back.
 *
 * Its own byte range for an evidence reason and not a source one.  The three
 * `blx` sites that reach func_02072F5C image wide are 0x02005E16, 0x02005E22
 * and 0x02005E40; the first two are in unit_02005DF8.c and the third is this
 * function, so the two files witness each other's calls and neither may hold
 * all three.  See the header of unit_02005DF8.c and
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * The function after this range, sub_02005E50, is already matched on its own
 * as src/matched/sub_02005E50.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005E30.c \
 *       --addr 0x02005E30 --thumb
 */

typedef unsigned int u32;

struct Sub02005E30State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

extern struct Sub02005E30State sub_02005E30_State;

extern void sub_02005FBC(void);
extern u32 *sub_0200590C(void);
struct Obj02072F5C;
extern void func_02072F5C(struct Obj02072F5C * volatile *pp, u32 a, u32 b);

void sub_02005E30(u32 a)
{
    sub_02005FBC();
    func_02072F5C((struct Obj02072F5C * volatile*)sub_0200590C(), 0, a);
    sub_02005E30_State.unk08 = a;
}
