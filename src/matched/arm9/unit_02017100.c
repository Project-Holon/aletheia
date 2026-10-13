/*
 * unit:     yes
 * address:  0x02017100
 * packet:   pkt_02016FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MCSS_TOOL_MakeAddWorkFromPP, MCSS_TOOL_MakeAddWorkFromPPP, MCSS_TOOL_MakeAddWorkFromParam
 *
 * The first of two parallel fillers of the same nine word record.
 * MCSS_TOOL_MakeAddWorkFromParam builds it from the five values MCSS_TOOL_MakeAddWorkFromPPP reads out of the
 * save block and writes 0 into the last word; its twin at 0x02017214 builds
 * the same record from a pair of pointers and writes 1, so that word is the
 * tag saying which of the two produced it.  The twin is parked in
 * src/pending/unit_02017214.c: it is the only caller of six of its eight
 * callees.
 *
 * MCSS_TOOL_MakeAddWorkFromPP passes its first argument through POKE_TOOL_GetBoxParam rather than
 * holding it in a callee-saved register, which is only possible because that
 * function returns its argument: it is the two byte `bx lr` at 0x020185F4 that
 * src/matched/unit_020185F0.c matches as an empty hook.  Written as a void
 * call followed by MCSS_TOOL_MakeAddWorkFromPPP(p, ...) the first argument would have to be
 * saved across it and the function grows a register.
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_0202D060  0x0202D060  thumb
 *   POKEGRA_GetCbrArcIndex  0x0202D09C  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   POKEGRA_GetCelArcIndex  0x0202D110  thumb
 *   POKEGRA_GetAnmArcIndex  0x0202D144  thumb
 *   POKEGRA_GetMCelArcIndex  0x0202D178  thumb
 *   POKEGRA_GetMAnmArcIndex  0x0202D1AC  thumb
 *   POKEGRA_GetNcecArcIndex  0x0202D1E0  thumb
 */

typedef unsigned int u32;

extern u32   func_02017E88(void *p, u32 id, u32 v);
extern u32   POKE_TOOL_IsBoxShiny(void *p);
extern void *POKE_TOOL_GetBoxParam(void *p);

extern int func_0202D060(void);
typedef signed int     s32;
extern s32 POKEGRA_GetCbrArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetCelArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetAnmArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetMCelArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetMAnmArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetNcecArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);


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

void MCSS_TOOL_MakeAddWorkFromPPP(void *p, struct Stats *out, u32 lvl);
void MCSS_TOOL_MakeAddWorkFromParam(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6);

void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl)
{
    MCSS_TOOL_MakeAddWorkFromPPP(POKE_TOOL_GetBoxParam(p), out, lvl);
}

void MCSS_TOOL_MakeAddWorkFromPPP(void *p, struct Stats *out, u32 lvl)
{
    u32 a0 = func_02017E88(p, 5, 0);
    u32 a1 = func_02017E88(p, 0x6F, 0);
    u32 a2 = func_02017E88(p, 0x6E, 0);
    u32 a3 = POKE_TOOL_IsBoxShiny(p);
    u32 a4 = func_02017E88(p, 0x4C, 0);

    MCSS_TOOL_MakeAddWorkFromParam(a0, a1, a2, a3, a4, out, lvl);
}

void MCSS_TOOL_MakeAddWorkFromParam(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6)
{
    out->unk00 = func_0202D060();
    out->unk04 = POKEGRA_GetCbrArcIndex(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk08 = func_0202D0D4(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk0C = POKEGRA_GetCelArcIndex(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk10 = POKEGRA_GetAnmArcIndex(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk14 = POKEGRA_GetMCelArcIndex(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk18 = POKEGRA_GetMAnmArcIndex(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk1C = POKEGRA_GetNcecArcIndex(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk20 = 0;
}
