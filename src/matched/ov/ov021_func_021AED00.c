/*
 * function: SCRCMD_GetTrainerBattleParam
 * address:  0x021AED00
 * packet:   pkt_ov021_021AED00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);

int SCRCMD_GetTrainerBattleParam(u32 a, u32 b)
{
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = TPOKE_DATA_GetRecordField((void *)x, 0xb);
    return 0;
}
