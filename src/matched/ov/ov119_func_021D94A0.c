/*
 * function: POKETRADE_PROC_ClearSideMon
 * address:  0x021D94A0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Arm or re-arm the three receivers depending on the object state.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferCardWindow  0x021E2438  thumb  ov119
 *   POKETRADE_2D_DeleteOfferIconActor  0x021E62D4  thumb  ov119
 */

extern int POKETRADE_PROC_IsHostSide(void *p);
extern void POKETRADE_3D_DeleteMcssSlot(void *p, int a);
extern void POKETRADE_SAVE_DeleteOfferCardWindow(char *p, int i);
extern void POKETRADE_2D_DeleteOfferIconActor(void *p, int a, int i);

void POKETRADE_PROC_ClearSideMon(void *p, int a)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0) {
        POKETRADE_3D_DeleteMcssSlot(p, a);
        POKETRADE_SAVE_DeleteOfferCardWindow(p, a);
        return;
    }
    for (i = 0; i < 3; i++)
        POKETRADE_2D_DeleteOfferIconActor(p, a, i);
}

