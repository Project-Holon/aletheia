/*
 * function: func_021C7CA0
 * address:  0x021C7CA0
 * packet:   pkt_021C7CA0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CA0 0x021C7CA0 arm
 *
 * When the wait is over, clear the low bits of the global status word.
 * Addresses are Black-image addresses.
 */

extern int func_021D157C(void);
extern void func_021C0E40(void *);

void func_021C7CA0(void)
{
    int *p;

    if (func_021D157C() != 0)
        return;
    p = *(int **)(*(int *)0x021DE5E4 + 4);
    *p &= 0xC1FFFCFF;
    func_021C0E40((void *)0x021C7314);
}

