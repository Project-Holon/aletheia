/*
 * function: SCRCMD_POKEMON_FLD_GetDailyGift
 * address:  0x021B7364
 * packet:   pkt_ov021_021B7364
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb ov010
 *   sDailyGifts     0x021D99E8  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 sDailyGifts[];

int SCRCMD_POKEMON_FLD_GetDailyGift(void *a, void *b)
{
    u32 v;
    u16 *p;

    v = SCRIPT_WORK_ReadWorkValue(a, b);
    p = SCRIPT_WORK_ReadWorkPointer(a, b);
    if (v >= 11) {
        v = 0;
    }
    *p = sDailyGifts[v];
    return 0;
}
