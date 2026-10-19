/*
 * function: FATFSi_SendToPXI
 * address:  0x027040B4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DC_FlushRange  0x020862F0  arm twl a2
 *   PXI_SendWordByFifo  0x02088610  arm twl a2
 */

typedef unsigned int u32;

extern void DC_FlushRange(u32, u32);
extern int PXI_SendWordByFifo(u32, u32, u32);

void FATFSi_SendToPXI(u32 a0) {
    DC_FlushRange(a0, 0x800);
    while (PXI_SendWordByFifo(0x14, a0 >> 5, 0) < 0) {
    }
}
