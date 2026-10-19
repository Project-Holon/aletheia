/*
 * function: PARTICLE_EMITTER_SetBehavior3Half
 * address:  0x020519E4
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The class-3 slot carries only a halfword at +2.
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_SetBehavior3Half.c \
 *       --func PARTICLE_EMITTER_SetBehavior3Half --addr 0x020519E4 --cc 1.1p1 --arm
 *
 * symbols:
 *   PARTICLE_EMITTER_FindBehaviorData  0x020518AC  arm
 */
#include "../include/Obj16190.h"

typedef unsigned short u16;

extern void *PARTICLE_EMITTER_FindBehaviorData(void *obj, int kind);

void PARTICLE_EMITTER_SetBehavior3Half(void *p, u16 *q)
{
    char *r = PARTICLE_EMITTER_FindBehaviorData(p, 3);

    if (r != 0)
        ((struct Obj16190 *)r)->f2 = *q;
}
