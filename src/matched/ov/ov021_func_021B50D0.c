/*
 * function: SCRCMD_PROC_FLD_StoreByteValue
 * address:  0x021B50D0
 * packet:   pkt_ov021_021B50D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   GAME_DATA_GetFieldMode  0x02012A44  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   EVENT_BATTLE_GetKindFlag  0x0216EFCC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned char  u8;
struct BigObj;
extern u32 GAME_DATA_GetFieldMode(const struct BigObj *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u8 EVENT_BATTLE_GetKindFlag(int i);

int SCRCMD_PROC_FLD_StoreByteValue(u32 a, u32 b)
{
    u32 x = GAME_DATA_GetFieldMode(SCRCMD_WORK_GetGameData((void *)b));
    u16 *o = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *o = EVENT_BATTLE_GetKindFlag(x);
    return 0;
}
