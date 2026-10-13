/*
 * function: DWCi_MOV_WH_End
 * address:  0x021D3AC8
 * packet:   pkt_021D3AC8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_End 0x021D3AC8 arm
 *   WM_End  0x0208F43C  arm  arm9
 *   OS_Terminate  0x02088234  arm  arm9
 *
 * Wake the sound system when idle, select port 3 and run the 0x021D3200 script.
 * Addresses are Black-image addresses.
 */

extern void OS_Terminate(void);
extern int WM_End(int);
extern int func_021D29C8(int);

int DWCi_MOV_WH_End(void)
{
    int *g = (int *)0x021DE660;

    if (*(int *)(g[1] + 0x40) != 1)
        OS_Terminate();
    func_021D29C8(3);
    if (WM_End((int)0x021D3200) == 2)
        return 1;
    func_021D29C8(9);
    return 0;
}

