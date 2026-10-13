/*
 * function: MIi_SendToPxi
 * address:  0x02731154
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SVC_WaitByLoop 0x02004490 thumb
 *   PXI_SendWordByFifo 0x02088610 arm
 */
typedef unsigned int u32;

extern void SVC_WaitByLoop(u32);
extern int PXI_SendWordByFifo(u32, u32, u32);

void MIi_SendToPxi(u32 a, u32 b)
{
    while (PXI_SendWordByFifo(0x12, b, a) != 0) {
        SVC_WaitByLoop(1);
    }
}
