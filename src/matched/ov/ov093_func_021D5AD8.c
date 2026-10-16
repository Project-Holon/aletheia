/*
 * function: BTL_POKEPARAM_GetStatForCrit
 * address:  0x021D5AD8
 * packet:   pkt_ov093_021D5AD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_RemapStatId  0x021D587C  thumb  ov093
 *   BTL_POKEPARAM_GetStatRaw  0x021D58A8  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 */
#include "../include/Obj00041.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_RemapStatId(void *p, int k);
extern int BTL_POKEPARAM_GetStatRaw(u8 *p, int k);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);

int BTL_POKEPARAM_GetStatForCrit(u8 *p, int k)
{
    int r = 0;
    switch (BTL_POKEPARAM_RemapStatId(p, k)) {
    case 8:
        if (((struct Obj00041 *)p)->fFC < 6) r = 1;
        break;
    case 10:
        if (((struct Obj00041 *)p)->fFE < 6) r = 1;
        break;
    case 9:
        if (((struct Obj00041 *)p)->fFD > 6) r = 1;
        break;
    case 11:
        if (((struct Obj00041 *)p)->fFF > 6) r = 1;
        break;
    }
    if (r) return BTL_POKEPARAM_GetStatRaw(p, k);
    return BTL_POKEPARAM_GetValue(p, k);
}
