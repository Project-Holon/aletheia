/*
 * function: PXI_Init
 * address:  0x02088498
 * packet:   pkt_02088498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * blocker:  ABS32 PXI_InitFifo at +0x08: the callee is the next function and nothing outside branches to it
 *
 * symbols:
 *   PXI_InitFifo  0x020884A4  arm
 */

extern void PXI_InitFifo(void);
void PXI_Init(void)
{
    PXI_InitFifo();
}
