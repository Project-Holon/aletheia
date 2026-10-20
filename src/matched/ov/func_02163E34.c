/*
 * function: FLDMMDL_MOVE_GetMapAttr
 * address:  0x02163E34
 * packet:   pkt_02163E34
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
#include "../include/Obj17719.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } VecFx32;

extern int FLDMMDL_MOVE_GetFieldG3dMapHit(void *a, char *b, void *c);

int FLDMMDL_MOVE_GetMapAttr(void *a0, VecFx32 *a1, u32 *a2)
{
    unsigned char fr[16];
    u32 *t4;
    int t5;
    int r;
t4 = a2;
t5 = 0;
*t4 = t5;
    r = FLDMMDL_MOVE_GetFieldG3dMapHit(a0, (char *)a1, fr);
loc_02163E44:
    if (r != 1) goto loc_02163E52;
loc_02163E48:
*t4 = ((struct Obj17719 *)fr)->f8;
    return 1;
loc_02163E52:
    return t5;
}
