/*
 * function: OEKAKI_ApplySceneChange
 * address: 0x0218644C
 * packet: pkt_ov023_0218644C
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02186E84 0x02186E84 data a4
 */
#include "../include/Obj07610.h"
extern int d_02186E84[][2];
void OEKAKI_ApplySceneChange(char *p, int mode)
{
    int n;
    n = ((struct Obj07610 *)p)->f19C;
    if (((struct Obj07610 *)p)->f198 != n) {
        if (mode != 2) {
            ((struct Obj07610 *)p)->f198 = n;
            return;
        }
        if (d_02186E84[n][0] != 0)
            ((struct Obj07610 *)p)->f198 = n;
    }
}
