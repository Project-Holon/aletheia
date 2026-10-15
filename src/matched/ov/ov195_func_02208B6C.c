/*
 * function: SHINKA_DEMO_EFFECT_UpdateAnime
 * address:  0x02208B6C
 * packet:   pkt_02208B6C
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker resolved: 0x02047910 and 0x020478B8 were matched in arm9
 *           (src/matched/G3D_SYSTEM_LoopObjectAnimeFrame.c, src/matched/G3D_SYSTEM_IncObjectAnimeFrame.c;
 *           shards pkt_02047910 and pkt_020478B8), so their call sites now
 *           attest as `matched`.  0x02048A18 already resolved via matched;
 *           all 164 bytes are correct.
 * symbols:
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 */
#include "../include/Obj00789.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);

void SHINKA_DEMO_EFFECT_UpdateAnime(char *p)
{
    unsigned short i;
    int j = 0;
    int v2;

    for (i = 0; i < ((struct Obj00789 *)p)->f1C; i++) {
        unsigned short v = *(unsigned short *)(((struct Obj00789 *)p)->f20 + i * 0x44);
        int x = func_02048A18((u8 *)(((struct Obj00789 *)p)->f14), v);

        G3D_SYSTEM_LoopObjectAnimeFrame((void *)x, j, 0x1000);
    }
    ((struct Obj00789 *)p)->f24 = ((struct Obj00789 *)p)->f24 + 1;
    v2 = func_02048A18((u8 *)(((struct Obj00789 *)p)->f14),
                       *(unsigned short *)(((struct Obj00789 *)p)->f20 +
                                           ((struct Obj00789 *)p)->f1A * 0x44));
    if (((struct Obj00789 *)p)->f28 == 1) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 1, 0x5000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 2, 0x5000);

        if (a == 0 && b == 0)
            ((struct Obj00789 *)p)->f28 = 2;
    } else if (((struct Obj00789 *)p)->f28 == 3) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 1, -0x2000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 2, -0x2000);

        if (a == 0 && b == 0)
            ((struct Obj00789 *)p)->f28 = 0;
    }
}
