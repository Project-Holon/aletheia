/*
 * function: SCRCMD_POKEMON_FLD_GetDailyGiftIndex
 * address:  0x021B73B8
 * packet:   pkt_ov021_021B73B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 *   SCRCMD_POKEMON_FLD_IsSpecialDate  0x021B7390  thumb  ov021
 *   _s32_div_f     0x0209C0A4  arm
 *   sDailyGiftIndexByDay     0x021D99DE  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern int FIELD_CLOCK_GetMonth(int a0);
extern int FIELD_CLOCK_GetDay(int a0);
extern int SCRCMD_POKEMON_FLD_IsSpecialDate(u32 a, int b);
extern u8 sDailyGiftIndexByDay[];

int SCRCMD_POKEMON_FLD_GetDailyGiftIndex(u32 a, u32 b)
{
    u16 *out;
    void *h;
    u32 x;
    int y;

    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    h = SCRCMD_WORK_GetGameData((void *)b);
    x = FIELD_CLOCK_GetMonth((int)h);
    y = FIELD_CLOCK_GetDay((int)h);
    if (SCRCMD_POKEMON_FLD_IsSpecialDate(x, y) == 1)
        *out = 10;
    else
        *out = sDailyGiftIndexByDay[y % 10];
    return 0;
}
