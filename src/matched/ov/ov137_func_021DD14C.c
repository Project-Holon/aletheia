/*
 * function: GURU2_RECEIPT_AnimatePalette
 * address: 0x021DD14C
 * packet: pkt_ov137_021DD14C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 * GX_LoadOBJPltt 0x0207E51C arm
 * gGuru2MemberPaletteStepThreshold 0x021E1AEE data a1
 * gGuru2MemberPaletteStepIndex 0x021E1AEF data a1
 *
 * note 2026-10-05 (wave P20 lane 2): DIFF 5/88, index/counter colour swap; recoup P29R8
 * and G2L6 tried 32 more forms at 5 B (see git history of the pending copy).
 *
 * pass 2 2026-10-06 P2L10: EXACT. The counter is read into its own local c BEFORE the
 * index local i, under #pragma opt_propagation off (the pragma keeps c from being
 * propagated back into the compare). That gives the index r4 and the counter r5 as in
 * the original. Without the pragma, or with i read first, it stays 5 B off.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct State { u32 enable; u32 index; int counter; u32 spare; u8 *object; };
extern const u8 gGuru2MemberPaletteStepThreshold[];
extern const u8 gGuru2MemberPaletteStepIndex[];
extern void GX_LoadOBJPltt(void *, int, int);
#pragma opt_propagation off
void GURU2_RECEIPT_AnimatePalette(void *unused, u8 *p)
{
    struct State *v = (struct State *)(p + 24);
    int c;
    u32 i;
    if (v->enable) {
        c = v->counter;
        i = v->index;
        if (c > gGuru2MemberPaletteStepThreshold[i * 2]) {
            v->index = i + 1;
            v->counter = 0;
            if (gGuru2MemberPaletteStepIndex[v->index * 2] == 255) v->index = 0;
            GX_LoadOBJPltt(*(u8 **)(v->object + 12) + (gGuru2MemberPaletteStepIndex[v->index * 2] << 5), 0, 32);
            return;
        }
        *(u32 *)(p + 32) += 1;
    }
}
#pragma opt_propagation reset
