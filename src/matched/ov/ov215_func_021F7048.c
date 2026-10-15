/*
 * function: EGG_DEMO_VIEW_UpdateModel
 * address:  0x021F7048
 * packet:   pkt_021F7048
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Flushes a 0x44-byte-stride descriptor table: one pass over the count at
 * p+0x50 submitting every entry at level 0, then the selected entry at
 * p+0x4e twice (level 1 then 2) whose result advances the p+0x5c state.
 *
 * symbols:
 *   func_02048A18    0x02048A18  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame    0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame    0x020478B8  arm
 */
#include "../include/Obj01083.h"

typedef unsigned short u16;

extern void *func_02048A18(void *p, int v);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *p, int a, int b);

void EGG_DEMO_VIEW_UpdateModel(char *p)
{
    u16 i;
    void *q;
    int a, b;

    for (i = 0; i < ((struct Obj01083 *)p)->f50; i++) {
        G3D_SYSTEM_LoopObjectAnimeFrame(func_02048A18(((struct Obj01083 *)p)->f48,
                        *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + i * 0x44)), 0, 0x1000);
    }
    ((struct Obj01083 *)p)->f58 = ((struct Obj01083 *)p)->f58 + 1;
    q = func_02048A18(((struct Obj01083 *)p)->f48,
                      *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + ((struct Obj01083 *)p)->f4E * 0x44));
    if (((struct Obj01083 *)p)->f5C == 1) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, 0x5000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, 0x5000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 2;
    } else if (((struct Obj01083 *)p)->f5C == 3) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, -0x2000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, -0x2000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 0;
    }
}
