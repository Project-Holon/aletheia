/*
 * file:     dwc_nonport.c
 * unit:     yes
 * function: DWCi_Np_GetConsoleId, DWCi_Np_GetConsoleIdPrefix, DWCi_Np_GetAppGameName
 * address:  0x02167E88
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Zero, in both halves of the 64-bit result register pair.
 * Returns the DWC login name prefix string, the text before the console id
 * in the "%s:%016llu" name built by the GameSpy connect response (dwc_login).
 * sdk:      DWCi_Np_GetAppGameName (libdwcnonport.TWL.HYB.a(dwc_nonport.o))
 *
 * symbols:
 *   gDwcNonportPlatformName  0x021A1F68  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   gDwcNonportMachineInfo  0x021AA828  data
 *   g_021AA828_b  0x021AA828  data
 */
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
long long DWCi_Np_GetConsoleId(void);
void *DWCi_Np_GetConsoleIdPrefix(void);
char *DWCi_Np_GetAppGameName(void);
extern char gDwcNonportPlatformName[];
extern char gDwcNonportMachineInfo[];
extern char g_021AA828_b[];

long long DWCi_Np_GetConsoleId(void)
{
    return 0;
}


void *DWCi_Np_GetConsoleIdPrefix(void)
{
    return gDwcNonportPlatformName;
}


char *DWCi_Np_GetAppGameName(void)
{
	MI_CpuCopy8((void *)0x02fffe0c, gDwcNonportMachineInfo, 4);
	g_021AA828_b[4] = 0;
	return gDwcNonportMachineInfo;
}
