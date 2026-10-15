/*
 * function: CTRDGi_SendtoPxi
 * address:  0x02091150
 * packet:   pkt_02091150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 *   SVC_WaitByLoop  0x02004490  thumb
 */

typedef unsigned int u32;

extern u32 PXI_SendWordByFifo(u32 a, u32 b, u32 c);
extern void SVC_WaitByLoop(u32 v);

void CTRDGi_SendtoPxi(u32 a0)
{
    if (PXI_SendWordByFifo(0xd, a0, 0) == 0)
        return;

    do {
        SVC_WaitByLoop(1);
    } while (PXI_SendWordByFifo(0xd, a0, 0) != 0);
}
