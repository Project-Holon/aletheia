/*
 * function: FIELD_G3D_MAPPER_QuerySlotPlane
 * address:  0x0218DBAC
 * packet:   pkt_ov021_0218DBAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAP_QueryPlane  0x02169848  thumb  ov010
 */
#include "../include/Obj01846.h"
#include "../include/Obj12585.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_G3D_MAP_QueryPlane(void *a, u8 *b, u32 c, u32 d);

int FIELD_G3D_MAPPER_QuerySlotPlane(u8 *a, int idx, u32 c, u8 *d)
{
    u32 buf[0x41];
    FIELD_G3D_MAP_QueryPlane(buf, (u8 *)(*(u32 *)(*(u8 * *)&((struct Obj01846 *)a)->f24 + idx * 0x28)), c, ((struct Obj01846 *)a)->f4);
    ((struct Obj12585 *)d)->f8 = buf[2];
    ((struct Obj12585 *)d)->fC = buf[3];
    return 1;
}
