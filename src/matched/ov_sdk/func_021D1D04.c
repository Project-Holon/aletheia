/*
 * function: DWCi_MOV_MBP_MemInit
 * address:  0x021D1D04
 * packet:   pkt_021D1D04
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_MBP_MemInit 0x021D1D04 arm
 *   DWCi_MOV_WH_MemInit  0x021D298C  arm
 *
 * Publish the object, initialise the tail region, and clear its two control words.
 * Addresses are Black-image addresses.
 */

extern void DWCi_MOV_WH_MemInit(int);

void DWCi_MOV_MBP_MemInit(int x)
{
    int *g = (int *)0x021DE65C;

    g[0] = x;
    DWCi_MOV_WH_MemInit(x + 0x160 + 0x1b000);
    *(int *)(g[0] + 0x1b000 + 0x140) = 0;
    *(int *)(g[0] + 0x1b000 + 0x144) = 0;
}

