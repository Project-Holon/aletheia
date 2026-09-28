/*
 * function: func_021E191C
 * address:  0x021E191C
 * packet:   pkt_021E191C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0217CD94  0x0217CD94  arm  ov009
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_0217CE1C  0x0217CE1C  arm  ov009
 *
 * Starts the ov009 transaction, releases the null handle, then checks
 *  *  the status: unless 0x0217CE1C reports 2 the null handle is released a
 *  *  second time.
 */

extern void func_0217CD94(void);
extern void func_0217CCCC(void *p);
extern int  func_0217CE1C(void);

void func_021E191C(void)
{
    func_0217CD94();
    func_0217CCCC(0);
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
}

