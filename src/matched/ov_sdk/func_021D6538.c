/*
 * function: func_021D6538
 * address:  0x021D6538
 * packet:   pkt_021D6538
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6538 0x021D6538 arm
 *
 * Drain the channel-4 queue, then post the event at 0x021DE68C.
 * Addresses are Black-image addresses.
 */

extern void func_0208AD14(void);
extern void func_0208B220(unsigned int command_flgs);
extern unsigned int func_0208B238(unsigned int command_flgs);
extern void func_021D6438(void **mem);

void func_021D6538(void)
{
    int v = 4;

    do {
        func_0208AD14();
        func_0208B220(v);
    } while (func_0208B238(v) != 0);
    func_021D6438((void *)0x021DE68C);
}
