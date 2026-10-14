/*
 * function: BTLV_INPUT_BlendWindowPalette
 * address:  0x02206A14
 * packet:   pkt_ov094_02206A14
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_GetBattleMain  0x021F8754  thumb  ov094
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTLV_EFFECT_IsRecordAllowed  0x021F8914  thumb  ov094
 *   PALANM_BlendColors  0x02021F64  thumb
 *   BTLV_EFFECT_GetPalanm  0x021F86E0  thumb  ov094
 *   PALANM_CopyToSlot  0x020215BC  thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;

struct PalAnmSlot;
extern int BTLV_EFFECT_GetBattleMain(void);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern int BTLV_EFFECT_IsRecordAllowed(void);
extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);
extern int BTLV_EFFECT_GetPalanm(void);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

void BTLV_INPUT_BlendWindowPalette(char *p)
{
    u16 buf[16];

    if ((int)BTL_MAIN_GetCompetitor((void ***)BTLV_EFFECT_GetBattleMain()) != 4 && BTLV_EFFECT_IsRecordAllowed() == 0) {
        PALANM_BlendColors((u16 *)(p + 0x284), buf, 0x10, 8, 0);
        PALANM_CopyToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), buf, 1, 0x20, 0x20);
    }
}
