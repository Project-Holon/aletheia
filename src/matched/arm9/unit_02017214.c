/*
 * unit:     yes
 * function: MCSS_TOOL_MakeAddWorkFromTrainer
 * address:  0x02017214
 * packet:   pkt_02017214
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEGRA_GetTrainerArcID  0x0202D5CC  thumb
 *   POKEGRA_GetTrainerCbrArcIndex  0x0202D5F8  thumb
 *   POKEGRA_GetTrainerPalArcIndex  0x0202D61C  thumb
 *   POKEGRA_GetTrainerCelArcIndex  0x0202D640  thumb
 *   POKEGRA_GetTrainerAnmArcIndex  0x0202D664  thumb
 *   POKEGRA_GetTrainerMCelArcIndex  0x0202D688  thumb
 *   POKEGRA_GetTrainerMAnmArcIndex  0x0202D6AC  thumb
 *   POKEGRA_GetTrainerNcecArcIndex  0x0202D6D0  thumb
 *
 * Promoted from src/pending/ during a shard verify sweep: all six of its
 * previously witness-less callees (POKEGRA_GetTrainerCbrArcIndex, POKEGRA_GetTrainerCelArcIndex,
 * POKEGRA_GetTrainerAnmArcIndex, POKEGRA_GetTrainerMCelArcIndex, POKEGRA_GetTrainerMAnmArcIndex, POKEGRA_GetTrainerNcecArcIndex) are now
 * EXACT matched entries elsewhere in the tree, so the `matched` class
 * resolves every site that was stuck wildcarded and this closes to
 * EXACT with no change to the C.
 *
 * This is the twin of MCSS_TOOL_MakeAddWorkFromParam in src/matched/unit_02017100.c: the
 * same nine word record, built from a pair of pointers instead of from
 * five save block fields, with 1 in the last word where the other
 * writes 0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02017214.c \
 *       --addr 0x02017214 --thumb
 */

typedef unsigned int u32;

extern u32 POKEGRA_GetTrainerArcID(u32 a);
extern u32 POKEGRA_GetTrainerCbrArcIndex(u32 id, u32 flags);
extern u32 POKEGRA_GetTrainerPalArcIndex(u32 id, u32 flags);
extern u32 POKEGRA_GetTrainerCelArcIndex(u32 id, u32 flags);
extern u32 POKEGRA_GetTrainerAnmArcIndex(u32 id, u32 flags);
extern u32 POKEGRA_GetTrainerMCelArcIndex(u32 id, u32 flags);
extern u32 POKEGRA_GetTrainerMAnmArcIndex(u32 id, u32 flags);
extern u32 POKEGRA_GetTrainerNcecArcIndex(u32 id, u32 flags);

struct Stats {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
};

void MCSS_TOOL_MakeAddWorkFromTrainer(void *p, struct Stats *out, void *q)
{
    out->unk00 = POKEGRA_GetTrainerArcID((u32)q);
    out->unk04 = POKEGRA_GetTrainerCbrArcIndex((u32)p, (u32)q);
    out->unk08 = POKEGRA_GetTrainerPalArcIndex((u32)p, (u32)q);
    out->unk0C = POKEGRA_GetTrainerCelArcIndex((u32)p, (u32)q);
    out->unk10 = POKEGRA_GetTrainerAnmArcIndex((u32)p, (u32)q);
    out->unk14 = POKEGRA_GetTrainerMCelArcIndex((u32)p, (u32)q);
    out->unk18 = POKEGRA_GetTrainerMAnmArcIndex((u32)p, (u32)q);
    out->unk1C = POKEGRA_GetTrainerNcecArcIndex((u32)p, (u32)q);
    out->unk20 = 1;
}
