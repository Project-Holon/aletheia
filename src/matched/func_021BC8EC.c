/*
 * function: func_021BC8EC
 * address:  0x021BC8EC
 * packet:   pkt_021BC8EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BC8EC   0x021BC8EC  arm
 *   dat_021DE504    0x021DE504  data
 *   func_021D7744   0x021D7744  arm
 *   func_021D6F38   0x021D6F38  arm
 *   func_021D6438   0x021D6438  arm
 *
 * Push the shared record's word and its +4 neighbour through the setters, then hand the record off.
 * Addresses are Black-image addresses.
 */

extern void func_021D7744(int, int);
extern void func_021D6F38(int);
extern void func_021D6438(int);
extern unsigned char dat_021DE504[];

void func_021BC8EC(void)
{
    unsigned char *g = (unsigned char *)0x021DE504;

    func_021D7744(1, **(int **)g);
    func_021D6F38(*(int *)(*(int *)g + 4));
    func_021D6438((int)dat_021DE504);
}

