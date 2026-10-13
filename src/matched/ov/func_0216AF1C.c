/*
 * function: SCRCMD_SYMBOL_CreateObjectPokemon
 * address:  0x0216AF1C
 * packet:   pkt_0216AF1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Overlay index on the first argument, then the pair call is staged with
 * the fourth argument.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData   0x0215A5E4  thumb  ov010
 *   INTRUDE_FIELD_GetMmdlParamPair   0x0217C274  thumb
 *   INTRUDE_FIELD_CreateSymbolMon   0x0217C2A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void INTRUDE_FIELD_GetMmdlParamPair(void *, void *);
extern void INTRUDE_FIELD_CreateSymbolMon(int, void *, void *);

void SCRCMD_SYMBOL_CreateObjectPokemon(void *a0, void *a1, void *a2, void *a3)
{
    void *v = SCRCMD_WORK_GetGameData(a0);

    INTRUDE_FIELD_GetMmdlParamPair(a3, a1);
    INTRUDE_FIELD_CreateSymbolMon(4, v, a3);
}

