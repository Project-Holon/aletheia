/*
 * function: func_021CE818
 * address:  0x021CE818
 * packet:   pkt_021CE050
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CE818   0x021CE818  arm
 *
 * Record v and hand the companion entry point to the timer helper.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE818.c \
 *       --func func_021CE818 --addr 0x021CE818 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CE844(void);
extern void func_021D7680(unsigned int, void *, unsigned int, unsigned int);

void func_021CE818(unsigned int v)
{
    char *g = (char *)0x021DE630;
    *(unsigned int *)(g + 4) = v;
    func_021D7680(1, func_021CE844, 0, 0x78);
}
