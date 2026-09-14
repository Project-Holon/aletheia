/*
 * function: sub_02034A3C
 * address:  0x02034A3C
 * packet:   pkt_02034714
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_020792B8  0x020792B8  arm
 *
 * Forwards `p`'s first field to an extern with a constant 0, then clears
 * `p`'s second field regardless of what the call returns.
 *
 * Every concrete byte matches; func_020792B8 is called from exactly this
 * one site in the whole ROM, so that relocation stays unresolved under
 * the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034A3C.c \
 *       --func sub_02034A3C --addr 0x02034A3C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj02034A3C {
    u32 unk00;
    u32 unk04;
};

extern void func_020792B8(u32 a, u32 b);

void sub_02034A3C(struct Obj02034A3C *p)
{
    func_020792B8(0, p->unk00);
    p->unk04 = 0;
}
