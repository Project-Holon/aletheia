/*
 * function: ScrollTopScreen
 * address:  0x02183F68
 * packet:   pkt_ov009_02183F68
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ScrollTopScreen (screen)
 *
 * symbols:
 *   MIi_CpuCopyFast   0x02082B0C arm
 *   MIi_CpuClearFast  0x02082AC0 arm
 *   gScreenScrollBuffer        0x021AD1C8 data
 */

extern void MIi_CpuCopyFast(void * srcp, void * destp, unsigned long size);
extern void MIi_CpuClearFast(unsigned long data, void * destp, unsigned long size);
extern unsigned short gScreenScrollBuffer[768];

void ScrollTopScreen(void)
{
    int i;

    for (i = 0; i < 23; i++)
        MIi_CpuCopyFast(&gScreenScrollBuffer[(i + 1) * 32], &gScreenScrollBuffer[i * 32], 64);
    MIi_CpuClearFast(0, &gScreenScrollBuffer[23 * 32], 64);
}
