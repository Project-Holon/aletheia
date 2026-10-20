/*
 * function: FLDMMDL_MOVE_GetMapHeight
 * address:  0x02163E58
 * packet:   pkt_02163E58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_GetFieldG3dMapHit  0x02163E1C  thumb  ov010
 */
#include "../include/Obj17720.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } VecFx32;

extern int FLDMMDL_MOVE_GetFieldG3dMapHit(void *a, char *b, void *c);

int FLDMMDL_MOVE_GetMapHeight(void *a0, VecFx32 *a1, int *a2)
{
    unsigned char fr[16];
    int *t4;
    int t5;
    int r;
t4 = a2;
t5 = 0;
*t4 = t5;
    r = FLDMMDL_MOVE_GetFieldG3dMapHit(a0, (char *)a1, fr);
loc_02163E68:
    if (r != 1) goto loc_02163E76;
loc_02163E6C:
*t4 = ((struct Obj17720 *)fr)->fC;
    return 1;
loc_02163E76:
    return t5;
}
