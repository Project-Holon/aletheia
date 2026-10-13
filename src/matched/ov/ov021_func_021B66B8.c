/*
 * function: SCRCMD_POKEMON_FLD_ControlLegendMon
 * address:  0x021B66B8
 * packet:   pkt_ov021_021B66B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_POKEMON_FLD_FindPartyLegend  0x021B6934  thumb
 *   SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend  0x021B6708  thumb
 *   SCRCMD_POKEMON_FLD_MoveLegendToFront  0x021B6904  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern int SCRCMD_POKEMON_FLD_FindPartyLegend(void *);
extern void SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend(u32 a, int idx);
extern void SCRCMD_POKEMON_FLD_MoveLegendToFront(void *);

u32 SCRCMD_POKEMON_FLD_ControlLegendMon(void *a, void *b)
{
    u32 op = SCRIPT_WORK_ReadWorkValue(a, b);
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a, b);
    void *x = SCRCMD_WORK_GetGameData(b);

    switch (op) {
    case 0:
        if (SCRCMD_POKEMON_FLD_FindPartyLegend(x) < 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 1:
        SCRCMD_POKEMON_FLD_MoveLegendToFront(b);
        break;
    case 2:
        SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend((u32)b, *out);
        SCRCMD_POKEMON_FLD_MoveLegendToFront(b);
        break;
    }
    return 0;
}
