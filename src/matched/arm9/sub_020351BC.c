/*
 * function: UI_TestFlags39
 * address:  0x020351BC
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The test half of the set/clear/test trio on the flag byte at +0x39.
 * No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_TestFlags39.c \
 *       --func UI_TestFlags39 --addr 0x020351BC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj0203515C {
    unsigned char pad[0x39];
    u8 unk39;
};

u32 UI_TestFlags39(struct Obj0203515C *p, u32 mask)
{
    return (p->unk39 & mask) != 0;
}
