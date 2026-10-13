/*
 * function: GIMMICK42_Exit
 * address: 0x021F380C
 * packet: pkt_ov042_021F380C
 * region: ov042
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FIELDMAP_GetExpObj(int *);
extern int *FIELDMAP_GetCommonWork(char *, int);
extern void FIELDMAP_FreeCommonWork(u8 *, int);
typedef signed int     s32;
struct Big;
struct Ctx;
struct Rec94;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *, u16);
extern void FLD_EXP_OBJ_UpdateAnimes(void *);
void GIMMICK42_Exit(u8 *p)
{
    int x = FIELDMAP_GetExpObj((int *)p);
    FIELDMAP_FreeCommonWork(p, 1);
    FLD_EXP_OBJ_RemoveUnit((u8 *)x, 0);
}
