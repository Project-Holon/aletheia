/*
 * function: func_02167EA0
 * address:  0x02167EA0
 * packet:   pkt_ov009_02167EA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_Np_GetAppGameName (libdwcnonport.TWL.HYB.a(dwc_nonport.o))
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   g_021AA828  0x021AA828  data
 */

extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern char g_021AA828[];

/* near miss: original loads the 0x021AA828 literal a second time for s[4] = 0
   (ldr r1,[pc]; strb r2,[r1,#4]); mine reuses r4 (8 B shorter). */
char *func_02167EA0(void)
{
	func_02082D44((void *)0x02fffe0c, g_021AA828, 4);
	g_021AA828[4] = 0;
	return g_021AA828;
}
