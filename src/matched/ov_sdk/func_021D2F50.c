/*
 * function: DWCi_MOV_WH_StateInStartParentKeyShare
 * address:  0x021D2F50
 * packet:   pkt_021D2F50
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_StateInStartParentKeyShare 0x021D2F50 arm
 *   WM_StartKeySharing  0x02090B9C  arm  arm9
 *
 * Select port 6, start key sharing on the global object's tail, then reset on mismatch.
 * Addresses are Black-image addresses.
 */

extern int WM_StartKeySharing(int, int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);

int DWCi_MOV_WH_StateInStartParentKeyShare(void)
{
    int *g = (int *)0x021DE660;

    func_021D29C8(6);
    if (WM_StartKeySharing(g[1] + 0x1e00, 0xd) == 2)
        return 1;
    func_021D2A44();
    return 0;
}

