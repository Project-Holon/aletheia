/*
 * function: DWCi_GetGT2Connection
 * address:  0x0216BAF4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetGT2Connection: the connection whose aid matches, or zero.
 *
 * symbols:
 *   gDwcGlobalState  0x021AA878  data
 *   gDwcConnectionArray  0x021AA8A0  data
 *   gt2GetConnectionData  0x02195E78  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal gDwcGlobalState;
extern int gDwcConnectionArray[];
extern int gt2GetConnectionData(const int *p);

int DWCi_GetGT2Connection(int aid)
{
    int i;

    if (*(int *)(((char *)&gDwcGlobalState) + 4) == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (gDwcConnectionArray[i] != 0 && aid == ((unsigned char *)gt2GetConnectionData((const int *)gDwcConnectionArray[i]))[1]) {
            return gDwcConnectionArray[i];
        }
    }
    return 0;
}
