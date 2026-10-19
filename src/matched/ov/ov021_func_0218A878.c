/*
 * function: FIELD_EVENT_CHECK_CheckIntrudeEdge
 * address:  0x0218A878
 * packet:   pkt_ov021_0218A878
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When flag field 0x10 is set and FIELD_PLAYER_ChooseMoveDirFromKeys does not report 9, forwards
 * the object to ov018 INTRUDE_FIELD_CreateEdgeTask; returns 0 otherwise.
 *
 * symbols:
 *   INTRUDE_FIELD_CreateEdgeTask  0x0217B4D8  thumb ov018
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   FIELD_PLAYER_ChooseMoveDirFromKeys  0x021A2FA4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04981.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 ZONEDATA_IsEntralink(u32 id);
extern u16 FIELD_PLAYER_ChooseMoveDirFromKeys(u8 *p, u32 a1);
extern void *INTRUDE_FIELD_CreateEdgeTask(void *a, void *b, void *c, int *d, u16 e, int f);

void *FIELD_EVENT_CHECK_CheckIntrudeEdge(u8 *p, void *a, void *b)
{
    int r;

    if (ZONEDATA_IsEntralink(((struct Obj04981 *)p)->f10) == 0)
        return 0;
    r = FIELD_PLAYER_ChooseMoveDirFromKeys(((struct Obj04981 *)p)->f18, ((struct Obj04981 *)p)->f2C);
    if (r == 9)
        return 0;
    return INTRUDE_FIELD_CreateEdgeTask(a, b, ((struct Obj04981 *)p)->f18, *(int * *)&((struct Obj04981 *)p)->f34, ((struct Obj04981 *)p)->f24, r);
}
