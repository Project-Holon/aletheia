/*
 * function: FIELD_G3D_MAP_PickTextureRes
 * address:  0x02169A68
 * packet:   pkt_02169A68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 */
#include "../include/Obj02337.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Tagged;

extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);

void *FIELD_G3D_MAP_PickTextureRes(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj02337 *)((char *)a0))->f0;
    p = G3D_SYSTEM_GetResourceFile((struct Tagged *)a0);
loc_02169A74:
    if (p != 0) goto loc_02169A82;
loc_02169A78:
a0 = t4 + 0;
a0 = a0 + 0x94;
p = ((struct Obj02337 *)((char *)a0))->f0;
    if (p != 0) goto loc_02169A86;
loc_02169A82:
t4 = t4 + 0x88;
p = ((struct Obj02337 *)((char *)t4))->f0;
loc_02169A86:
    return p;}
