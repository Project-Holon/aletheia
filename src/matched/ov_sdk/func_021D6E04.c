/*
 * function: func_021D6E04
 * address:  0x021D6E04
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6E04   0x021D6E04  arm
 *
 * Tail-call func_021D6DC4 with the pointer held at +0x04.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D6E04.c \
 *       --func func_021D6E04 --addr 0x021D6E04 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D6DC4(void *pos, void *ob);

void func_021D6E04(char *p, void *ob)
{
    func_021D6DC4(*(void **)(p + 4), ob);
}
