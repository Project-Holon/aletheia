/*
 * function: DWCi_ClearGT2ConnectionList
 * address:  0x0216BB98
 * packet:   pkt_ov009_0216BB98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ClearGT2ConnectionList (dwc_main.o)
 *
 * symbols:
 *   MIi_CpuClear32     0x02082A7C  arm
 *   g_021AA8A0         0x021AA8A0  data
 *   g_021AA920         0x021AA920  data
 */

extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
extern char g_021AA8A0[];
extern char g_021AA920[];

void DWCi_ClearGT2ConnectionList(void)
{
    MIi_CpuClear32(0, g_021AA8A0, 0x80);
    MIi_CpuClear32(0, g_021AA920, 0x100);
}
