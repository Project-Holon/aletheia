/*
 * function: func_02176344
 * address:  0x02176344
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Passes the word at +0x678 of the module block on.
 *
 * symbols:
 *   func_021763AC  0x021763AC  arm  ov009
 */

extern char *func_02175F3C(void);
extern void func_021763AC(int v);

void func_02176344(void)
{
    func_021763AC(*(int *)(func_02175F3C() + 0x678));
}

