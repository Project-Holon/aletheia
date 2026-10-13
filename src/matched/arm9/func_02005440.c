/*
 * function: GFL_USE_OnPreExit
 * address:  0x02005440
 * packet:   pkt_02005438
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02005454
 * symbols:
 *   _PreExitState      0x020A9E80  data
 *   func_02005454   0x02005454  arm
 */

extern int _PreExitState;
extern void func_02005454(int v);
void GFL_USE_OnPreExit(void)
{
    func_02005454(0);
    _PreExitState = 1;
}
