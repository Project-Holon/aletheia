/*
 * function: func_02155D2C
 * address:  0x02155D2C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Enables slot 9 then calls the wakeup.
 *
 * symbols:
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02155C8C  0x02155C8C  thumb  ov009
 */

extern void func_02155374(int v);
extern void func_02155C8C(void);

void func_02155D2C(void)
{
    func_02155374(9);
    func_02155C8C();
}

