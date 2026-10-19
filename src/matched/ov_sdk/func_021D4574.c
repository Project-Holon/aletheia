/*
 * function: _DWCi_MOVEnd
 * address:  0x021D4574
 * packet:   pkt_021D4574
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _DWCi_MOVEnd 0x021D4574 arm
 *   DWCi_MOV_WH_End  0x021D3AC8  arm
 *
 * Enter state 1 once func_021D3250 reports ready.
 * Addresses are Black-image addresses.
 */

extern unsigned int func_021D3250(void);
extern int DWCi_MOV_WH_End(void);

int _DWCi_MOVEnd(void)
{
    if (func_021D3250() != 1)
        return 0;
    DWCi_MOV_WH_End();
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 1;
    return 1;
}
