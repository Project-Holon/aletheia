/*
 * function: DWCi_Np_GetConsoleIdPrefix
 * address:  0x02167E94
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Address of the module state object.
 *
 * symbols:
 *   gDwcNonportPlatformName  0x021A1F68  data
 */

extern char gDwcNonportPlatformName[];

void *DWCi_Np_GetConsoleIdPrefix(void)
{
    return gDwcNonportPlatformName;
}

