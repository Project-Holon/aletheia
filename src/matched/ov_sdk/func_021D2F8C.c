/*
 * function: DWCi_MOV_WH_StateInEndParentKeyShare
 * address:  0x021D2F8C
 * packet:   pkt_021D2F8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_StateInEndParentKeyShare 0x021D2F8C arm
 *   WM_EndKeySharing  0x02090BB8  arm  arm9
 *
 * Query the global object's tail, then reset on anything but the ready answer.
 * Addresses are Black-image addresses.
 */

extern int WM_EndKeySharing(int);
extern int func_021D2A44(void);

int DWCi_MOV_WH_StateInEndParentKeyShare(void)
{
    int *g = (int *)0x021DE660;

    if (WM_EndKeySharing(g[1] + 0x1e00) == 2)
        return 1;
    func_021D2A44();
    return 0;
}

