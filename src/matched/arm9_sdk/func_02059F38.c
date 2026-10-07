/*
 * function: func_02059F38
 * address:  0x02059F38
 * packet:   pkt_02059F38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Return whether the global word at 0x02146AA4 is non-zero.  The same
 * library name (CTRDGi_IsTaskAvailable) appears in layout/symbols_sdk.json
 * at several addresses, and the duplicate-name collapse in match.py's SDK
 * address index drops this one, so the `sdk` class cannot attest a call to
 * it; matching the bytes here supplies the missing witness.
 *
 * symbols:
 *   g_02146AA4  0x02146AA4  data  a4
 */

#include "../include/G_DWCErrorInfo.h"

extern struct DWCErrorInfo g_02146AA4;

int func_02059F38(void)
{
    return (*(int *)&g_02146AA4) != 0;
}
