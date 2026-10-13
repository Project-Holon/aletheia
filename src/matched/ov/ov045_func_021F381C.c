/*
 * function: FIELD_GIMMICK_SWITCH_TOGGLE_Update
 * address: 0x021F381C
 * packet: pkt_ov045_021F381C
 * region: ov045
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb  arm9
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *,int);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_UpdateAnimes(void *);
void FIELD_GIMMICK_SWITCH_TOGGLE_Update(u32 a) { u32 p; p=FIELDMAP_GetExpObj((int *)a); FIELDMAP_GetCommonWork((char *)a,1); GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))),9); FLD_EXP_OBJ_UpdateAnimes((void *)p); }
