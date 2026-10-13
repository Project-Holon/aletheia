/*
 * function: GIMMICK40_CreateEvent
 * address: 0x021F37EC
 * packet: pkt_ov040_021F37EC
 * region: ov040
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
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   GIMMICK40_EventPlayAnime 0x021F381C thumb ov040
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
struct Desc;
struct Rec94;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *, u16);
extern void FLD_EXP_OBJ_UpdateAnimes(void *);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK40_EventPlayAnime(void *, int *);
void *GIMMICK40_CreateEvent(void *p, u32 i)
{
    u16 *q = (u16 *)FIELDMAP_GetCommonWork((char *)GAMESYSTEM_GetFieldMap(p), 1);
    void *r;
    if (i >= 1) return 0;
    r = func_020122C0(p, 0, GIMMICK40_EventPlayAnime, 0);
    *q = i;
    return r;
}
