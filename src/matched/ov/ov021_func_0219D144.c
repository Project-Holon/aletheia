/*
 * function: FLDMMDL_BLACT_IsActorReservedByOther
 * address:  0x0219D144
 * packet:   pkt_ov021_0219D144
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 */
#include "../include/Obj07478.h"

typedef unsigned short u16;
extern u16 FLDMMDL_SysGetMmdlMax(void *p);

int FLDMMDL_BLACT_IsActorReservedByOther(int *obj, unsigned int a, int b)
{
    unsigned int i;
    unsigned int n;
    int *p;

    i = 0;
    n = FLDMMDL_SysGetMmdlMax((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] != 0 && p[1] != b && ((struct Obj07478 *)p)->f8 == a) {
            return 1;
        }
    }
    return 0;
}
