/*
 * function: DWCi_Np_GetAppGameName
 * address:  0x02167EA0
 * packet:   pkt_ov009_02167EA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Np_GetAppGameName (libdwcnonport.TWL.HYB.a(dwc_nonport.o))
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   g_021AA828  0x021AA828  data
 *   g_021AA828_b  0x021AA828  data
 */

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern char g_021AA828[];
extern char g_021AA828_b[];

char *DWCi_Np_GetAppGameName(void)
{
	MI_CpuCopy8((void *)0x02fffe0c, g_021AA828, 4);
	g_021AA828_b[4] = 0;
	return g_021AA828;
}
