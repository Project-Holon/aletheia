/*
 * function: SPL_EMITTER_SetRotMtx
 * address: 0x02056420
 * packet: pkt_arm9_02056420
 * region: arm9
 * compiler: dsi/../1.2/sp2
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/button_man_p08.c and filed here.
 */

typedef signed int s32;
struct MtxFx43 { s32 m[12]; };
void SPL_EMITTER_SetRotMtx(s32 sn, s32 cs, struct MtxFx43 *m);

/*
 * Row 0 of the billboard basis table: the plain rotation about +Y, an unlabelled
 * leaf in front of SPL_EMITTER_CalcRotMtx.  It is written after SPL_EMITTER_CalcRotMtx because
 * this compiler places it first in the object only in that source order.
 */
void SPL_EMITTER_SetRotMtx(s32 sn, s32 cs, struct MtxFx43 *m)
{
    m->m[0] = cs;
    m->m[3] = 0;
    m->m[6] = sn;
    m->m[9] = 0;
    m->m[1] = 0;
    m->m[4] = 0x1000;
    m->m[7] = 0;
    m->m[10] = 0;
    m->m[2] = -sn;
    m->m[5] = 0;
    m->m[8] = cs;
    m->m[11] = 0;
}
