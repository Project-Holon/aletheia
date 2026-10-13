/*
 * function: FLDMMDL_BLACT_FindReservedRes
 * address:  0x0219CF00
 * packet:   pkt_ov021_0219CF00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00429.h"
#include "../include/Obj09512.h"
#include "../include/Obj12675.h"

int FLDMMDL_BLACT_FindReservedRes(int *t, unsigned int id, unsigned short *out)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12675 *)p)->f0 == id) {
            *out = ((struct Obj12675 *)p)->f8;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (((struct Obj09512 *)q)->f8 == id && ((struct Obj09512 *)q)->f10 != 0) {
            *out = ((struct Obj09512 *)q)->f4;
            return 1;
        }
    }
    return 0;
}
