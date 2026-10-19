/*
 * function: PARTICLE_EMITTER_SetBehavior5Data
 * address:  0x02051A04
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same 12-byte copy as BUTTON_MAN_SetRow2, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_SetBehavior5Data.c \
 *       --func PARTICLE_EMITTER_SetBehavior5Data --addr 0x02051A04 --cc 1.1p1 --arm
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

void PARTICLE_EMITTER_SetBehavior5Data(void *p, struct S12 *q)
{
    struct S12 *r = PARTICLE_EMITTER_FindBehaviorData(p, 5);

    if (r != 0)
        *r = *q;
}
