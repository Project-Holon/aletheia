/*
 * function: PARTICLE_EMITTER_SetBehavior2Data
 * address:  0x020519C4
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies a 12-byte record into the slot PARTICLE_EMITTER_FindBehaviorData hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_SetBehavior2Data.c \
 *       --func PARTICLE_EMITTER_SetBehavior2Data --addr 0x020519C4 --cc 1.1p1 --arm
 *
 * symbols:
 *   PARTICLE_EMITTER_FindBehaviorData  0x020518AC  arm
 */

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern void *PARTICLE_EMITTER_FindBehaviorData(void *obj, int kind);

void PARTICLE_EMITTER_SetBehavior2Data(void *p, struct S12 *q)
{
    struct S12 *r = PARTICLE_EMITTER_FindBehaviorData(p, 2);

    if (r != 0)
        *r = *q;
}
