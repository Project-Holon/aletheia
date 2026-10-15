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
 *   gDwcConnectionArray         0x021AA8A0  data
 *   gDwcNodeInfoBuffer         0x021AA920  data
 */

extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
extern char gDwcConnectionArray[];
extern char gDwcNodeInfoBuffer[];

void DWCi_ClearGT2ConnectionList(void)
{
    MIi_CpuClear32(0, gDwcConnectionArray, 0x80);
    MIi_CpuClear32(0, gDwcNodeInfoBuffer, 0x100);
}
