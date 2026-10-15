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
 *   g_021AD1C8        0x021AD1C8 data
 */

extern void MIi_CpuCopyFast(void * srcp, void * destp, unsigned long size);
extern void MIi_CpuClearFast(unsigned long data, void * destp, unsigned long size);
extern unsigned short g_021AD1C8[768];

void ScrollTopScreen(void)
{
    int i;

    for (i = 0; i < 23; i++)
        MIi_CpuCopyFast(&g_021AD1C8[(i + 1) * 32], &g_021AD1C8[i * 32], 64);
    MIi_CpuClearFast(0, &g_021AD1C8[23 * 32], 64);
}
