/*
 * function: POKETRADE_PROC_SetSideMon
 * address:  0x021D9468
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Start a transfer on the object when the length is non-zero.
 *
 * symbols:
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssFlipped  0x021E36A8  thumb  ov119
 *   POKETRADE_SAVE_DrawOfferCardWindow  0x021E1B14  thumb  ov119
 */

extern void POKETRADE_3D_DeleteMcssSlot(void *p, int idx);
extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_3D_AddPokemonMcssFlipped(void *p, int a, int b, void *c, int d, int e);
extern void POKETRADE_SAVE_DrawOfferCardWindow(char *p, int i, void *mon);

void POKETRADE_PROC_SetSideMon(void *p, int a, void *b)
{
    int t;

    if (b == 0)
        return;
    POKETRADE_3D_DeleteMcssSlot(p, a);
    t = POKETRADE_PROC_IsHostSide(p);
    POKETRADE_3D_AddPokemonMcssFlipped(p, a, 1 - a, b, 1, t);
    POKETRADE_SAVE_DrawOfferCardWindow(p, a, b);
}

