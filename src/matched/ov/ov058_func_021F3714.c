/*
 * function: GIMMICK58_Exit
 * address:  0x021F3714
 * packet:   pkt_ov058_021F3714
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Big;
extern void *FIELDMAP_GetGameSystem(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *p, u16 i);
extern void FIELDMAP_FreeCommonWork(unsigned char *p, int id);

void GIMMICK58_Exit(void *a0)
{
    GAME_DATA_GetFieldSave((struct Big *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0)));
    FLD_EXP_OBJ_RemoveUnit((u8 *)FIELDMAP_GetExpObj((int *)a0), 0);
    FIELDMAP_FreeCommonWork((unsigned char *)a0, 1);
}
