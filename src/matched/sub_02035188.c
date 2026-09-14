/*
 * function: sub_02035188
 * address:  0x02035188
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The clear half of the set/clear pair on the flag byte at +0x39. No lr
 * push, so disasm.py never labels it. Twin of sub_0203515C (set).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035188.c \
 *       --func sub_02035188 --addr 0x02035188 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Obj0203515C {
    unsigned char pad[0x39];
    u8 unk39;
};

void sub_02035188(struct Obj0203515C *p, u8 mask)
{
    p->unk39 &= ~mask;
}
