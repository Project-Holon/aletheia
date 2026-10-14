/*
 * function: IRC_Shutdown
 * address:  0x0217A134
 * packet:   pkt_ov015_0217A134
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    2026-10-05 wave P27 lane 4: libirc shutdown. Calls IRCi_Finish with 0 (finish), then
 *           IRCi_End (IRCi_End).
 *
 * symbols:
 *   IRCi_Finish  0x0217A0CC  arm  ov015
 *   IRCi_End  0x0217A648  arm  ov015
 */

extern void IRCi_Finish(int n);
extern void IRCi_End(void);

void IRC_Shutdown(void)
{
    IRCi_Finish(0);
    IRCi_End();
}
