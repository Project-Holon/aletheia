/*
 * function: FATFSi_IsInitialized
 * address:  0x02704318
 * packet:   pkt_02704318
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfatfs (TWL-resident): an unlabelled 12-byte leaf ahead of
 * FATFS_UnmountAll (0x02704328), named by OS_Terminate's relocation in the
 * vendor os_terminate_proc.o (tools/sdkobj.py OS_Terminate).  Returns the
 * library's initialised flag; the flag's vendor name is not in any object we
 * hold, so it keeps its address name.
 *
 * symbols:
 *   g_0273444C  0x0273444C  data
 */

typedef int BOOL;

extern BOOL g_0273444C;

BOOL FATFSi_IsInitialized(void)
{
    return g_0273444C;
}
