/*
 * function: GIMMICK60_Exit
 * address:  0x021F3724
 * packet:   pkt_ov060_021F3724
 * region:   ov060
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

extern void *FIELDMAP_GetGameSystem(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *p, unsigned short i);
extern void FIELDMAP_FreeCommonWork(unsigned char *p, int id);

void GIMMICK60_Exit(unsigned char *p)
{
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(p)));
    FLD_EXP_OBJ_RemoveUnit((unsigned char *)FIELDMAP_GetExpObj((int *)p), 0);
    FIELDMAP_FreeCommonWork(p, 0);
}
