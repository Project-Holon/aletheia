/*
 * function: func_021D6F18
 * address:  0x021D6F18
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6F18   0x021D6F18  arm
 *
 * Tail-call func_021D54C4 with an indexed pointer out of the global table.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D6F18.c \
 *       --func func_021D6F18 --addr 0x021D6F18 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D54C4(void *);

void func_021D6F18(unsigned int i)
{
    char *p = *(char **)0x021DE6A8;
    func_021D54C4(*(void **)(p + (i << 2) + 0x800));
}
