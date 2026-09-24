/*
 * function: func_021C0ED8
 * address:  0x021C0ED8
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0ED8   0x021C0ED8  arm
 *
 * Low nibble of the word at +0x08 of the global object (4-bit field).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0ED8.c \
 *       --func func_021C0ED8 --addr 0x021C0ED8 --region ov016 --cc dsi/1.1p1 --arm
 */

struct Ov016Bits8 {
    char pad[8];
    unsigned int f : 4;
};

unsigned int func_021C0ED8(void)
{
    struct Ov016Bits8 *p = (struct Ov016Bits8 *)0x021DE56C;
    return p->f;
}
