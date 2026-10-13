/*
 * function: DWCi_MOV_WH_GetSharedDataAdr
 * address:  0x021D38DC
 * packet:   pkt_021D38DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_GetSharedDataAdr 0x021D38DC arm
 *   WM_GetSharedDataAddress  0x02090B18  arm  arm9
 *
 * Tail-call WM_GetSharedDataAddress with two views of the block behind 0x021DE660.
 * Addresses are Black-image addresses.
 */

extern void WM_GetSharedDataAddress(void *, void *, int);

void DWCi_MOV_WH_GetSharedDataAdr(int a)
{
    int *g = (int *)0x021DE660;
    char *p = (char *)g[1];

    WM_GetSharedDataAddress(p + 0x13e0, p + 0x1c00, a);
}
