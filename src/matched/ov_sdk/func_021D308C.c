/*
 * function: func_021D308C
 * address:  0x021D308C
 * packet:   pkt_021D308C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D308C 0x021D308C arm
 *   WM_EndKeySharing  0x02090BB8  arm  arm9
 *
 * Only in state 6, select port 3 and query the global tail for the ready answer.
 * Addresses are Black-image addresses.
 */

extern int WM_EndKeySharing(int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);

int func_021D308C(void)
{
    int *g = (int *)0x021DE660;

    if (*(int *)(g[1] + 0x40) != 6)
        return 0;
    func_021D29C8(3);
    if (WM_EndKeySharing(g[1] + 0x1e00) == 2)
        return 1;
    func_021D2A44();
    return 0;
}

