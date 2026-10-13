/*
 * function: SCRCMD_CheckBeaconTrainerKey
 * address:  0x021D2710
 * packet:   pkt_ov021_021D2710
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned char  u8;
extern void *GAME_DATA_GetMiscSave(int *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *a, int i, void *b);

u32 SCRCMD_CheckBeaconTrainerKey(u32 a, u32 b)
{
    u32 r7;
    u16 *r5;
    u32 t;
    u32 r6;

    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r5 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    t = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)SCRCMD_WORK_GetGameSystem((void *)b));
    r6 = (u32)GAME_DATA_GetMiscSave((int *)t);
    *r5 = FIELD_G3D_MAP_CheckBeaconTrainerKey((void *)r6, r7, GAME_DATA_GetMyStatus((void *)t));
    return 0;
}
