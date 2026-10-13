/*
 * function: DWCi_MOV_WH_StateInInitialize
 * address:  0x021D36D0
 * packet:   pkt_021D36D0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_StateInInitialize 0x021D36D0 arm
 *   WM_Initialize  0x0208F370  arm  arm9
 *
 * Select port 3, run the 0x021D371C script on the global tail, then fall back.
 * Addresses are Black-image addresses.
 */

extern int WM_Initialize(int, int, int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);

int DWCi_MOV_WH_StateInInitialize(void)
{
    int *g = (int *)0x021DE660;

    func_021D29C8(3);
    if (WM_Initialize(g[1] + 0x80, (int)0x021D371C, 2) == 2)
        return 1;
    func_021D2A44();
    func_021D29C8(0xa);
    return 0;
}

