/*
 * function: FIELD_G3D_MAPPER_CheckSlotReady
 * address:  0x0218DBD4
 * packet:   pkt_ov021_0218DBD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAP_IsVisible  0x021694FC  thumb ov010
 *   FIELD_G3D_MAP_CanQueryHits  0x021697E0  thumb ov010
 */
#include "../include/Obj01846.h"

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELD_G3D_MAP_IsVisible(u8 *p);
extern int FIELD_G3D_MAP_CanQueryHits(char *p);

int FIELD_G3D_MAPPER_CheckSlotReady(char *p, int i)
{
    if (((struct Obj01846 *)p)->f1C == 0)
        return 0;
    if (FIELD_G3D_MAP_IsVisible((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28))) == 0)
        return 0;
    return FIELD_G3D_MAP_CanQueryHits((char *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28)));
}
