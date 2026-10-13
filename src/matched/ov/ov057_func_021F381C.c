/*
 * function: GIMMICK57_AdvanceModelScene
 * address:  0x021F381C
 * packet:   pkt_021F381C
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker resolved: 0x02047910 was matched in arm9 (src/matched/
 *           G3D_SYSTEM_LoopObjectAnimeFrame.c, shard pkt_02047910), so all four call sites now
 *           attest as `matched`; the fifth (G3D_SYSTEM_SetSwapBuffersMode) already resolved.
 *
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 */
#include "../include/Obj07671.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);

void GIMMICK57_AdvanceModelScene(void *a, void *b, u8 *p)
{
    u32 m = 1 << 12;

    G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj07671 *)p)->f38), 0, m);
    G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj07671 *)p)->f38), 3, m);
    G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj07671 *)p)->f3C), 1, m);
    G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj07671 *)p)->f40), 2, m);
    G3D_SYSTEM_SetSwapBuffersMode(1, 1);
}
