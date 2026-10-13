/*
 * function: GAME_DATA_GetSaveBlock2A
 * address:  0x02012F44
 * packet:   pkt_02012F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_020071CC(*(void **)p, 0x2a).
 *
 * symbols:
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   func_020071CC  0x020071CC  thumb
 */
#include "../include/Obj00054.h"

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *GAME_DATA_GetSaveBlock2A(void *p)
{
    return func_020071CC(((struct Obj00054 *)p)->f0, 0x2a);
}
