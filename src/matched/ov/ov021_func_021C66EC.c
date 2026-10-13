/*
 * function: FIELD_G3DOBJ_LoopAnimeFrame
 * address:  0x021C66EC
 * packet:   pkt_ov021_021C66EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12953.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 k : 2; } K;

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

int FIELD_G3DOBJ_LoopAnimeFrame(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj12953 *)e)->f4 * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj12953 *)e)->f44), (u16)i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}
