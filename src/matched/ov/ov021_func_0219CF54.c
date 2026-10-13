/*
 * function: FLDMMDL_BLACT_CancelReservedRes
 * address:  0x0219CF54
 * packet:   pkt_ov021_0219CF54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */
#include "../include/Obj00429.h"
#include "../include/Obj06001.h"
#include "../include/Obj12676.h"

struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

int FLDMMDL_BLACT_CancelReservedRes(int *t, unsigned int id)
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
        if (((struct Obj12676 *)p)->f0 == id) {
            ((struct Obj12676 *)p)->f0 = 0xFFFF;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(int *)&((struct Obj06001 *)q)->f10 != 0 && ((struct Obj06001 *)q)->f8 == id) {
            *q = 0;
            G3D_SYSTEM_DeleteResource(((struct Obj06001 *)q)->f10);
            *(int *)&((struct Obj06001 *)q)->f10 = 0;
            return 1;
        }
    }
    return 0;
}
