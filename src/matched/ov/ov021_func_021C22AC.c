/*
 * function: FLD3D_CI_UpdateTrackB
 * address:  0x021C22AC
 * packet:   pkt_ov021_021C22AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 */
#include "../include/Obj05077.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
u32 func_020489F4(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
int G3D_SYSTEM_GetObjectAnimeCount(int *p);
int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);

int FLD3D_CI_UpdateTrackB(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05077 *)p)->f84 == 0)
        return 1;
    if (((struct Obj05077 *)p)->f62 != 0) {
        (((struct Obj05077 *)p)->f62)--;
    } else {
        a = (int)func_02048A18((u8 *)(((struct Obj05077 *)p)->f14), (u16)((int)func_020489F4((u8 *)(((struct Obj05077 *)p)->f14), (u16)(((struct Obj05077 *)p)->f18)) + 1));
        n = G3D_SYSTEM_GetObjectAnimeCount((int *)a);
        for (k = 0; k < n; k++)
            r = G3D_SYSTEM_IncObjectAnimeFrame((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}
