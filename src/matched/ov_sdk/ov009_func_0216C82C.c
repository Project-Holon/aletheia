/*
 * function: DWCi_IsGetAIDValid
 * address:  0x0216C82C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 1 unless the current object is in mode 2 (always 1) or carries a zero
 * byte at +0x35d with a mode other than 2.
 *
 * symbols:
 *   gDwcGlobalState  0x021AA878  data

 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal gDwcGlobalState;

int DWCi_IsGetAIDValid(void)
{
    int r = 1;
    char *p = *(char **)(((char *)&gDwcGlobalState) + 4);

    if (*(unsigned char *)(p + 0x365) != 2)
        if (*(unsigned char *)(p + 0x35d) == 0) r = 0;
    return r;
}


