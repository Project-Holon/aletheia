/*
 * function: func_0217A134
 * address:  0x0217A134
 * packet:   pkt_ov015_0217A134
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P27 lane 4: libirc shutdown. Calls func_0217A0CC with 0 (finish), then
 *           func_0217A648 (IRCi_End).
 *
 * symbols:
 *   func_0217A0CC  0x0217A0CC  arm  ov015
 *   func_0217A648  0x0217A648  arm  ov015
 */

extern void func_0217A0CC(int n);
extern void func_0217A648(void);

void func_0217A134(void)
{
    func_0217A0CC(0);
    func_0217A648();
}
