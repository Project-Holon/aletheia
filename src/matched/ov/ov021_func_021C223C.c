/*
 * function: FLD3D_CI_UpdateTrackA
 * address:  0x021C223C
 * packet:   pkt_ov021_021C223C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 */
#include "../include/Obj05076.h"

typedef unsigned char u8;
typedef unsigned short u16;

unsigned int func_020489F4(u8 *a0, int i);
typedef unsigned int   u32;
u32 func_02048A18(u8 *a0, int i);
int G3D_SYSTEM_GetObjectAnimeCount(int *p);
int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);

int FLD3D_CI_UpdateTrackA(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05076 *)p)->f80 == 0)
        return 1;
    if (((struct Obj05076 *)p)->f60 != 0) {
        (((struct Obj05076 *)p)->f60)--;
    } else {
        a = func_02048A18((u8 *)(((struct Obj05076 *)p)->f14), (int)func_020489F4((u8 *)(((struct Obj05076 *)p)->f14), (u16)(((struct Obj05076 *)p)->f18)));
        n = G3D_SYSTEM_GetObjectAnimeCount((int *)a);
        for (k = 0; k < n; k++)
            r = G3D_SYSTEM_IncObjectAnimeFrame((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}
