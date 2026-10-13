/*
 * function: OPTION_MENU_ExitSettings
 * address:  0x021BAF9C
 * packet:   pkt_ov068_021BAF9C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_02082BCC(p, 0, 0xc).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

void OPTION_MENU_ExitSettings(void *p)
{
    void func_02082BCC(void *, int, int);
    func_02082BCC(p, 0, 0xc);
}
